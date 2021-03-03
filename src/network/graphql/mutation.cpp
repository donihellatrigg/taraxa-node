#include "mutation.hpp"

#include <algorithm>
#include <array>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <string_view>
#include <tuple>
#include <vector>

#include "account.hpp"
#include "graphqlservice/GraphQLSchema.h"
#include "graphqlservice/GraphQLService.h"
#include "graphqlservice/JSONResponse.h"
#include "graphqlservice/introspection/Introspection.h"
#include "libdevcore/CommonJS.h"
#include "transaction.hpp"

using namespace std::literals;

namespace graphql::taraxa {

Mutation::Mutation(std::shared_ptr<dev::rpc::Eth::NodeAPI> node_api) : node_api_(node_api) {}

service::FieldResult<response::Value> Mutation::applySendRawTransaction(service::FieldParams&&,
                                                                        response::Value&& transaction) const {
  return response::Value(
      dev::toJS(node_api_->importTransaction(jsToBytes(transaction.get<std::string>(), dev::OnFailed::Throw))));
}

}  // namespace graphql::taraxa