#pragma once

#include <json/json.h>
#include <libdevcrypto/Common.h>

#include <string>

#include "cli/config.hpp"
#include "common/vrf_wrapper.hpp"

namespace taraxa::cli {

class Tools {
 public:
  static constexpr const char* DEFAULT_TARAXA_DIR_NAME = ".taraxa";
  static constexpr const char* DEFAULT_TARAXA_DATA_DIR_NAME = ".taraxa/data";
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
  static void generateConfig(const std::string& config, cli::Config::NetworkIdType network_id);
  static Json::Value generateConfig(Config::NetworkIdType network_id);
  static void generateWallet(const std::string& wallet);

  // Override existing config and wallet files
  static Json::Value overrideConfig(Json::Value& config, std::string& data_dir, bool boot_node,
                                    std::vector<std::string> boot_nodes, std::vector<std::string> log_channels,
                                    std::vector<std::string> log_configurations,
                                    const std::vector<std::string>& boot_nodes_append,
                                    const std::vector<std::string>& log_channels_append);
  static Json::Value overrideWallet(Json::Value& wallet, const std::string& node_key, const std::string& vrf_key);

  static std::string getHomeDir();
  static std::string getTaraxaDefaultDir();
  static std::string getTaraxaDataDefaultDir();
  static std::string getTaraxaDefaultConfigFile();
  static std::string getWalletDefaultFile();
  static Json::Value createWalletJson(const dev::KeyPair& account, const taraxa::vrf_wrapper::vrf_sk_t& sk,
                                      const taraxa::vrf_wrapper::vrf_pk_t& pk);
};
}  // namespace taraxa::cli