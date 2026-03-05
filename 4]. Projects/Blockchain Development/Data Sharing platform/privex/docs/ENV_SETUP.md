# 🛠️ Environment Setup Guide

Setting up environment variables is the most common point of failure in Web3 apps. This guide will help you get everything configured correctly for PriveX.

## 📋 Prerequisites
- A [Pinata](https://pinata.cloud) account (Free tier is fine).
- [MetaMask](https://metamask.io) installed in your browser.

---

## 1. Get Your Pinata Keys (IPFS Storage)

PriveX uses Pinata to store your encrypted files on the IPFS network.

1.  Log in to your [Pinata Dashboard](https://app.pinata.cloud/developers/api-keys).
2.  Click **"API Keys"** on the left sidebar.
3.  Click **"New Key"**.
4.  **Important:** Enable "Admin" permissions or specifically ensure `pinFileToIPFS` is checked.
5.  Copy the **API Key** and the **Secret API Key**.
6.  Open `privex/client/.env` and paste them:
    ```bash
    REACT_APP_PINATA_API_KEY=your_key_here
    REACT_APP_PINATA_SECRET_KEY=your_secret_here
    ```

---

## 2. Generate an Encryption Key

This key is used to encrypt your files **locally** in the browser before they are uploaded to IPFS.

1.  You can use any random string. For better security, generate one:
    - On Mac/Linux/GitBash: `openssl rand -hex 32`
    - Or just type a long, complex random string.
2.  Add it to `privex/client/.env`:
    ```bash
    REACT_APP_ENC_KEY=your_random_complex_string
    ```

---

## 3. Local Development (Hardhat)

If you are running a local blockchain using `npm run node`:

1.  Deploy the contract: `npm run deploy:local`.
2.  The terminal will print: `Contract address : 0x...`
3.  Copy that address and add it to `privex/client/.env`:
    ```bash
    REACT_APP_CONTRACT_ADDRESS=the_outputted_address
    ```

---

## 4. Public Testnet (Sepolia) - Optional

If you want to deploy to a real testnet like Sepolia:

1.  Get an Alchemy or Infura RPC URL.
2.  Open the **ROOT** `.env` file (at `privex/.env`).
3.  Add your RPC URL and your MetaMask Private Key:
    ```bash
    INFURA_URL=https://eth-sepolia.g.alchemy.com/v2/your-key
    PRIVATE_KEY=your_metamask_private_key
    ```
    > ⚠️ **CRITICAL:** Use a "Burner Wallet" for development. Never put a private key with real funds in a `.env` file.

---

## ✅ Final Check

Your `privex/client/.env` should look like this:

```bash
REACT_APP_CONTRACT_ADDRESS=0x5FbDB2315678afecb367f032d93F642f64180aa3
REACT_APP_PINATA_API_KEY=6b8...
REACT_APP_PINATA_SECRET_KEY=4a5...
REACT_APP_ENC_KEY=my-super-secret-local-key
```

### 🚨 Troubleshooting
- **Build Fails?** Ensure there are NO SPACES around the `=` sign in the `.env` file.
- **Upload Fails?** Double check your Pinata keys have "Admin" or "Write" permissions.
- **Contract Error?** Ensure you updated the address in `client/.env` after every fresh deployment.
