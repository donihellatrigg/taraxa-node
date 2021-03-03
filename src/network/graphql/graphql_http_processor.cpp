#include "graphql_http_processor.hpp"

#include <jsoncpp/json/reader.h>

#include "graphqlservice/GraphQLService.h"
#include "graphqlservice/JSONResponse.h"

namespace taraxa::net {

GraphQlHttpProcessor::GraphQlHttpProcessor(const std::shared_ptr<FinalChain>& final_chain)
    : HttpProcessor(),
      final_chain_(final_chain),
      query_(std::make_shared<graphql::taraxa::Query>(final_chain_, 0)),
      mutation_(std::make_shared<graphql::taraxa::Mutation>()),
      operations_(query_, mutation_) {}

HttpProcessor::Response GraphQlHttpProcessor::process(const Request& request) {
  try {
    const std::string& request_str = request.body();

    graphql::peg::ast query_ast;
    graphql::response::Value variables{graphql::response::Type::Map};
    std::string operation_name{""};

    // Differenciate content type: 'application/json' vs 'application/graphql'
    // according to https://graphql.org/learn/serving-over-http/
    if (request.count("Content-Type") && request["Content-Type"] == "application/graphql") {
      query_ast = graphql::peg::parseString(request_str);
    } else {  // default is "application/json"
      Json::Reader reader;
      Json::Value json_request;

      if (!reader.parse(request_str, json_request, false)) {
        return createErrResponse("Unable to parse request json data");
      }

      if (!json_request.isMember("query")) {
        return createErrResponse("Invalid request json data: Missing \'query\' in graphql request");
      }
      query_ast = graphql::peg::parseString(json_request["query"].asString());

      // operationName field is optional
      if (json_request.isMember("operationName")) {
        operation_name = json_request["operationName"].asString();
      }

      // variables field is optional
      if (json_request.isMember("variables")) {
        variables = graphql::response::parseJSON(json_request["variables"].toStyledString());
        if (variables.type() != graphql::response::Type::Map) {
          return createErrResponse("Invalid request  json data: Variables object must be of map type");
        }
      }
    }

    auto result =
        operations_.resolve(std::launch::async, nullptr, query_ast, operation_name, std::move(variables)).get();
    return createOkResponse(graphql::response::toJSON(std::move(result)));

  } catch (const Json::Exception& e) {
    return createErrResponse("Unable to process request json data: " + std::string(e.what()));
  } catch (const std::exception& e) {
    return createErrResponse("Unable to process request: " + std::string(e.what()));
  }
}

HttpProcessor::Response GraphQlHttpProcessor::createErrResponse(const std::string& response_body) {
  std::string graphql_er_json = "{\"data\":null,\"errors\":[{\"message\":\"" + response_body + "\"}]}";
  return HttpProcessor::createErrResponse(graphql_er_json);
}

}  // namespace taraxa::net