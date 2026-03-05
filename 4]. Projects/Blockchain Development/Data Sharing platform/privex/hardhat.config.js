require("@nomicfoundation/hardhat-toolbox");
require("dotenv").config();

/** @type import('hardhat/config').HardhatUserConfig */
module.exports = {
    solidity: {
        version: "0.8.19",
        settings: {
            optimizer: {
                enabled: true,
                runs: 200,
            },
        },
    },
    networks: {
        hardhat: {
            chainId: 31337,
        },
        localhost: {
            url: "http://127.0.0.1:8545",
            chainId: 31337,
        },
        sepolia: {
            url: process.env.INFURA_URL || "",
            accounts: (process.env.PRIVATE_KEY && process.env.PRIVATE_KEY.length === 64)
                ? [process.env.PRIVATE_KEY]
                : [],
        },
    },
    paths: {
        artifacts: "./client/src/artifacts",
    },
};
