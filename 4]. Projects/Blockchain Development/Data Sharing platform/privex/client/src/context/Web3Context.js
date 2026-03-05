import React, { createContext, useContext, useState, useEffect, useCallback } from "react";
import { ethers } from "ethers";
import UploadABI from "../artifacts/contracts/Upload.sol/Upload.json";

const Web3Context = createContext(null);

const CONTRACT_ADDRESS = process.env.REACT_APP_CONTRACT_ADDRESS || "";

export const Web3Provider = ({ children }) => {
    const [account, setAccount] = useState("");
    const [contract, setContract] = useState(null);
    const [provider, setProvider] = useState(null);
    const [isConnecting, setIsConnecting] = useState(false);
    const [error, setError] = useState("");
    const [chainId, setChainId] = useState(null);

    const loadContract = useCallback(async (signer) => {
        if (!CONTRACT_ADDRESS) {
            setError("Contract address not configured. Check your .env file.");
            return null;
        }
        try {
            const c = new ethers.Contract(CONTRACT_ADDRESS, UploadABI.abi, signer);
            setContract(c);
            return c;
        } catch (err) {
            setError("Failed to load contract.");
            return null;
        }
    }, []);

    const connectWallet = useCallback(async () => {
        setError("");
        if (!window.ethereum) {
            setError("MetaMask is not installed. Please install it to use PriveX.");
            return;
        }

        setIsConnecting(true);
        try {
            const web3Provider = new ethers.providers.Web3Provider(window.ethereum);
            await web3Provider.send("eth_requestAccounts", []);
            const signer = web3Provider.getSigner();
            const address = await signer.getAddress();
            const network = await web3Provider.getNetwork();

            setAccount(address);
            setProvider(web3Provider);
            setChainId(network.chainId);
            await loadContract(signer);
        } catch (err) {
            if (err.code === 4001) {
                setError("Wallet connection rejected by user.");
            } else {
                setError("Failed to connect wallet. Please try again.");
            }
        } finally {
            setIsConnecting(false);
        }
    }, [loadContract]);

    const disconnectWallet = useCallback(() => {
        setAccount("");
        setContract(null);
        setProvider(null);
        setChainId(null);
    }, []);

    // Listen for MetaMask events
    useEffect(() => {
        if (!window.ethereum) return;

        const handleAccountsChanged = (accounts) => {
            if (accounts.length === 0) {
                disconnectWallet();
            } else {
                setAccount(accounts[0]);
                // Reload contract with new signer
                const web3Provider = new ethers.providers.Web3Provider(window.ethereum);
                loadContract(web3Provider.getSigner());
            }
        };

        const handleChainChanged = () => {
            window.location.reload();
        };

        window.ethereum.on("accountsChanged", handleAccountsChanged);
        window.ethereum.on("chainChanged", handleChainChanged);

        return () => {
            window.ethereum.removeListener("accountsChanged", handleAccountsChanged);
            window.ethereum.removeListener("chainChanged", handleChainChanged);
        };
    }, [disconnectWallet, loadContract]);

    const value = {
        account,
        contract,
        provider,
        chainId,
        isConnecting,
        error,
        isConnected: Boolean(account),
        connectWallet,
        disconnectWallet,
        setError,
    };

    return <Web3Context.Provider value={value}>{children}</Web3Context.Provider>;
};

export const useWeb3 = () => {
    const ctx = useContext(Web3Context);
    if (!ctx) throw new Error("useWeb3 must be used inside <Web3Provider>");
    return ctx;
};
