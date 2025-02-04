namespace taraxa::cli {

const char *devnet_json = R"foo({
  "node_secret": "",
  "vrf_secret": "",
  "data_path": "",
  "network_is_boot_node": false,
  "network_listen_ip": "0.0.0.0",
  "network_tcp_port": 10002,
  "network_udp_port": 10002,
  "network_simulated_delay": 0,
  "network_transaction_interval": 100,
  "network_bandwidth": 40,
  "network_ideal_peer_count": 5,
  "network_max_peer_count": 15,
  "network_sync_level_size": 25,
  "network_packets_processing_threads": 14,
  "network_peer_blacklist_timeout" : 600,
  "deep_syncing_threshold" : 10,
  "network_boot_nodes": [
    {
      "id": "fdcf4c860d9bb1f17608cbf2dd10ac3ae8d0ba41aa20b3e43fb85a72617a356f8609475d68b44e25dd508a0e5b36da75e7ae9aaf93360f4f002464d1d75fd353",
      "ip": "boot-node-0.devnet.taraxa.io",
      "tcp_port": 10002,
      "udp_port": 10002
    },
    {
      "id": "5dad63f090ab5b5960dfd33b2deed974fd2e058b2af47b3d1a4682a192a47880f7b1de9aa6c80758aaabb40972a196634774373be27e0bdc52572194ad57acc2",
      "ip": "boot-node-1.devnet.taraxa.io",
      "tcp_port": 10002,
      "udp_port": 10002
    },
    {
      "id": "8a919928e2ee8908d3ef7cf49f245b79d228a86fd2c1c0b8c687007e62b5777aff11e748d0b29fcebd321780ce9e0544717a4c221271252a66bd50b3db6eb532",
      "ip": "boot-node-2.devnet.taraxa.io",
      "tcp_port": 10002,
      "udp_port": 10002
    }
  ],
  "rpc": {
    "http_port": 7777,
    "ws_port": 8777,
    "threads_num": 10
  },
  "test_params": {
    "max_transactions_pool_warn": 0,
    "max_transactions_pool_drop": 0,
    "max_block_queue_warn": 0,
    "db_snapshot_each_n_pbft_block": 10000,
    "db_max_snapshots": 5,
    "block_proposer": {
      "shard": 1,
      "transaction_limit": 250
    }
  },
  "logging": {
    "configurations": [
      {
        "name": "standard",
        "on": true,
        "verbosity": "ERROR",
        "channels": [
          {
            "name": "SUMMARY",
            "verbosity": "INFO"
          }
        ],
        "outputs": [
          {
            "type": "console",
            "format": "%ThreadID% %Channel% [%TimeStamp%] %SeverityStr%: %Message%"
          },
          {
            "type": "file",
            "file_name": "Taraxa_N1_%m%d%Y_%H%M%S_%5N.log",
            "rotation_size": 10000000,
            "time_based_rotation": "0,0,0",
            "format": "%ThreadID% %ShortNodeId% %Channel% [%TimeStamp%] %SeverityStr%: %Message%",
            "max_size": 1000000000
          }
        ]
      },
      {
        "name": "network",
        "on": false,
        "verbosity": "ERROR",
        "channels": [
          {
            "name": "PBFT_CHAIN",
            "verbosity": "INFO"
          },
          {
            "name": "PBFT_MGR",
            "verbosity": "DEBUG"
          },
          {
            "name": "GET_PBFT_SYNC_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "PBFT_SYNC_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "GET_DAG_SYNC_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "DAG_SYNC_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "DAG_BLOCK_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "PBFT_BLOCK_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "TARCAP",
            "verbosity": "DEBUG"
          },
          {
            "name": "NETWORK",
            "verbosity": "DEBUG"
          },
          {
            "name": "TRANSACTION_PH",
            "verbosity": "DEBUG"
          },
          {
            "name": "DAGBLKMGR",
            "verbosity": "INFO"
          },
          {
            "name": "DAGMGR",
            "verbosity": "INFO"
          }
        ],
        "outputs": [
          {
            "type": "console",
            "format": "%ThreadID% %Channel% [%TimeStamp%] %SeverityStr%: %Message%"
          },
          {
            "type": "file",
            "file_name": "TaraxaNetwork_N1_%m%d%Y_%H%M%S_%5N.log",
            "rotation_size": 10000000,
            "time_based_rotation": "0,0,0",
            "format": "%ThreadID% %ShortNodeId% %Channel% [%TimeStamp%] %SeverityStr%: %Message%",
            "max_size": 1000000000
          }
        ]
      }
    ]
  },
  "chain_config": {
    "chain_id": "0x3",
    "dag_genesis_block": {
      "level": "0x0",
      "pivot": "0x0000000000000000000000000000000000000000000000000000000000000000",
      "sig": "0xb7e22d46c1ba94d5e8347b01d137b5c428fcbbeaf0a77fb024cbbf1517656ff00d04f7f25be608c321b0d7483c402c294ff46c49b265305d046a52236c0a363701",
      "timestamp": "0x60aee104",
      "tips": [],
      "transactions": []
    },
    "final_chain": {
      "genesis_block_fields": {
        "author": "0x0000000000000000000000000000000000000000",
        "timestamp": "0x60aee104"
      },
      "state": {
        "disable_block_rewards": true,
        "dpos": {
          "deposit_delay": "0x5",
          "withdrawal_delay": "0x5",
          "eligibility_balance_threshold": "0xd3c21bcecceda1000000",
          "vote_eligibility_balance_step": "0x152d02c7e14af6800000",
          "genesis_state": {
            "0x7e4aa664f71de4e9d0b4a6473d796372639bdcde": {
              "0x780fe8b2226cf212c55635de399ee4c2a860810c": "0x84595161401484a000000",
              "0x56e0de6933d9d0453d0363caf42b136eb5854e4e": "0x84595161401484a000000",
              "0x71bdcbec7e3642782447b0fbf31eed068dfbdbb1": "0x84595161401484a000000"
            }
          }
        },
        "eth_chain_config": {
          "byzantium_block": "0x0",
          "constantinople_block": "0x0",
          "dao_fork_block": "0xffffffffffffffff",
          "eip_150_block": "0x0",
          "eip_158_block": "0x0",
          "homestead_block": "0x0",
          "petersburg_block": "0x0"
        },
        "execution_options": {
          "disable_gas_fee": false,
          "disable_nonce_check": true
        },
        "genesis_balances": {
          "2cd4da7d3b345e022ca7e997c2bb3276a4d3d2e9": "0x1027e72f1f12813088000000",
          "7e4aa664f71de4e9d0b4a6473d796372639bdcde": "0x1027e72f1f12813088000000"
        },
        "hardforks": {
          "fix_genesis_fork_block": "0x0"
        }
      }
    },
    "pbft": {
      "committee_size": "0x3e8",
      "number_of_proposers": "0x14",
      "dag_blocks_size": "0x32",
      "ghost_path_move_back": "0x0",
      "lambda_ms_min": "0x29a",
      "run_count_votes": false
    },
    "replay_protection_service": {
      "range": "0xa"
    },
    "sortition": {
      "changes_count_for_average": "0x5",
      "max_interval_correction": "0x3E8",
      "dag_efficiency_targets": ["0x12C0", "0x1450"],
      "changing_interval": "0xC8",
      "computation_interval": "0x32",
      "vrf": {
        "threshold_upper": "0xafff",
        "threshold_range": "0x1800"
      },
      "vdf": {
        "difficulty_max": "0x15",
        "difficulty_min": "0x10",
        "difficulty_stale": "0x17",
        "lambda_bound": "0x64"
      }
    }
  }
}
)foo";
}
