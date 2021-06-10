#pragma once

#include <json/json.h>
#include <libdevcrypto/Common.h>

#include <consensus/vrf_wrapper.hpp>
#include <string>

#include "cli/config.hpp"

namespace taraxa::cli {

class Tools {
 public:
  static constexpr const char* DEFAULT_TARAXA_DIR_NAME = ".taraxa";
  static constexpr const char* DEFAULT_TARAXA_DB_DIR_NAME = ".taraxa/db";
  static constexpr const char* DEFAULT_WALLET_FILE_NAME = "wallet.json";
  static constexpr const char* DEFAULT_CONFIG_FILE_NAME = "config.json";

  // Account generation
  static void generateAccount();
  static void generateAccount(const dev::KeyPair& account);
  static void generateAccountFromKey(const std::string& key);

  // VRF generation
  static void generateVrf();
  static void generateVrf(const taraxa::vrf_wrapper::vrf_sk_t& sk, const taraxa::vrf_wrapper::vrf_pk_t& pk);
  static void generateVrfFromKey(const std::string& key);

  // Generate default config and wallet files
  static void generateConfig(const std::string& config, const std::string& data_dir, bool boot_node,
                             cli::Config::NetworkIdType network_id);
  static void generateWallet(const std::string& wallet);

  static std::string getHomeDir();
  static std::string getTaraxaDefaultDir();
  static std::string getTaraxaDataDefaultDir();
  static std::string getTaraxaDefaultConfigFile();
  static std::string getWalletDefaultFile();
  static Json::Value createWalletJson(const dev::KeyPair& account, const taraxa::vrf_wrapper::vrf_sk_t& sk,
                                      const taraxa::vrf_wrapper::vrf_pk_t& pk);

  static void writeJsonToFile(const std::string& file_name, const Json::Value& json);
  static Json::Value readJsonFromFile(const std::string& file_name);
  static Json::Value readJsonFromString(const std::string& str);
};
}  // namespace taraxa