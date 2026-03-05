const hre = require("hardhat");

async function main() {
    console.log("Deploying Upload contract...\n");

    const [deployer] = await hre.ethers.getSigners();
    console.log(`Deployer address : ${deployer.address}`);
    console.log(`Account balance  : ${hre.ethers.utils.formatEther(await deployer.getBalance())} ETH\n`);

    const Upload = await hre.ethers.getContractFactory("Upload");
    const upload = await Upload.deploy();
    await upload.deployed();

    console.log(" Upload contract deployed!");
    console.log(`   Contract address : ${upload.address}`);
    console.log(`   Transaction hash : ${upload.deployTransaction.hash}`);

    // Automatically update client/.env
    const fs = require("fs");
    const path = require("path");
    const envPath = path.join(__dirname, "..", "client", ".env");

    let envContent = "";
    if (fs.existsSync(envPath)) {
        envContent = fs.readFileSync(envPath, "utf8");
    }

    const newLabel = `REACT_APP_CONTRACT_ADDRESS=${upload.address}`;
    if (envContent.includes("REACT_APP_CONTRACT_ADDRESS=")) {
        envContent = envContent.replace(/REACT_APP_CONTRACT_ADDRESS=.*/, newLabel);
    } else {
        envContent += `\n${newLabel}\n`;
    }

    fs.writeFileSync(envPath, envContent);
    console.log("\n✅ Updated client/.env with new contract address.");
}

main().catch((error) => {
    console.error(error);
    process.exitCode = 1;
});
