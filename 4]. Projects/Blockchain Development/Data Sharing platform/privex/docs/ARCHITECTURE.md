# PriveX — Architecture Overview

## System Architecture

```
┌──────────────────────────────────────────────────────────────────────┐
│                         USER'S BROWSER                               │
│                                                                      │
│   ┌────────────────────────────────────────────────────────────┐     │
│   │                  React Frontend (port 3000)                │     │
│   │                                                            │     │
│   │   Home.js   Dashboard.js   FileUpload.js   Display.js     │     │
│   │                    ↕                ↕                      │     │
│   │             Web3Context.js   (Ethers.js v5)               │     │
│   │                    ↕                ↕                      │     │
│   │            MetaMask Wallet   AES-256 (CryptoJS)           │     │
│   └────────────────────────┬────────────────┬──────────────────┘     │
│                            │                │                        │
└────────────────────────────┼────────────────┼────────────────────────┘
                             │                │
             ┌───────────────▼───┐   ┌────────▼─────────────┐
             │  Ethereum Network │   │  IPFS (via Pinata)   │
             │                   │   │                      │
             │  Upload.sol       │   │  Encrypted File Blob │
             │  ┌─────────────┐  │   │  stored at a unique  │
             │  │ add()       │  │   │  CID (hash)          │
             │  │ allow()     │  │   │                      │
             │  │ disallow()  │  │   └──────────────────────┘
             │  │ display()   │  │
             │  │ createGroup()│ │
             │  └─────────────┘  │
             │  (Hardhat local   │
             │  or Sepolia)      │
             └───────────────────┘
```

---

## Data Flow: Uploading a File

```
User picks file
      │
      ▼
CryptoJS AES-256 encrypts it in browser
      │
      ▼
Encrypted blob sent to Pinata API
      │
      ▼
Pinata returns IPFS hash (CID)
      │
      ▼
contract.add(userAddress, fileName, ipfsUrl) called via MetaMask
      │
      ▼
On-chain transaction recorded ✅
```

---

## Data Flow: Sharing & Access Control

```
Owner calls contract.allow(recipientAddr, [fileIds])
      │
      ▼
Smart contract stores access mapping on-chain
  accessList[owner][recipient] = {access: true, fileIds: [...]}
      │
      ▼
Recipient calls contract.display(ownerAddr)
      │
      ▼
Contract checks accessList → returns only allowed files
      │
      ▼
Recipient fetches encrypted blob from IPFS
      │
      ▼
CryptoJS decrypts it in recipient's browser
      │
      ▼
File opens in a new tab ✅
```

---

## Data Flow: Revoking Access

```
Owner calls contract.disallow(recipientAddr)
      │
      ▼
Smart contract sets access = false for that address
      │
      ▼
Next call to display() by recipient → reverts ❌ "Upload: access not granted"
```

---

## Smart Contract Storage Layout (`Upload.sol`)

```
contract Upload {

  struct FileData {
    uint256 id;
    string  fileName;
    string  url;        ← IPFS URL (encrypted blob)
  }

  struct Access {
    address user;
    bool    access;
  }

  // owner → array of uploaded files
  mapping(address => FileData[]) private files;

  // owner → global ID counter
  mapping(address => uint256)    private fileCount;

  // owner → recipient → list of shared file IDs
  mapping(address => mapping(address => uint256[])) private ownership;

  // owner → list of access grants (for shareAccess() view)
  mapping(address => Access[])   private accessList;

  // owner → list of groups
  mapping(address => Group[])    private groups;
}
```

---

## Tech Stack Map

```
privex/
│
├── contracts/Upload.sol          ← Solidity 0.8.19
│                                    Compiled by Hardhat
│                                    Artifacts → client/src/artifacts/
│
├── scripts/deploy.js             ← Deploys contract
│                                    Auto-updates client/.env
│
├── test/Upload.test.js           ← 17 Chai/Ethers tests
│
├── hardhat.config.js             ← Network: localhost | Sepolia
│
└── client/
    ├── src/
    │   ├── context/Web3Context.js ← Wallet state (MetaMask events)
    │   ├── components/
    │   │   ├── Home.js            ← Landing page + connect wallet
    │   │   ├── Dashboard.js       ← Slide-up vault overlay
    │   │   ├── FileUpload.js      ← Dropzone + encrypt + Pinata upload
    │   │   ├── Display.js         ← Fetch, decrypt, open files
    │   │   ├── Modal.js           ← Share/revoke access manager
    │   │   ├── Navbar.js          ← Responsive nav + wallet status
    │   │   └── UserManual.js      ← Accordion how-to guide
    │   ├── App.js                 ← Router shell
    │   └── index.css              ← Design system (CSS variables)
    └── public/index.html          ← SEO meta + Google Fonts
```
