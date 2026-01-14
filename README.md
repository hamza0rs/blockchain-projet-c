# Simple Blockchain Simulation in C (Linked List & Binary Ledger)

## 📌 Project Overview
This project is a comprehensive simulation of a Blockchain architecture implemented using the **C programming language**. It utilizes **Linked Lists** as the underlying data structure to manage blocks
and demonstrates core blockchain mechanics including cryptographic hashing, mining and data persistence via a binary ledger.

## 🏗️ Project Structure
The project is organized into modular components as per software engineering best practices:
- `linkedlist.c/h`: Core linked list operations (nodes, insertion, deletion).
- `blockchain.c/h`: Blockchain-specific logic (Genesis block, mining, validation).
- `ledger.c/h`: Binary file I/O operations for saving and loading the chain.
- `main.c`: Integration and testing of all modules.

## 🛠️ Key Features
- **Cryptographic Hashing:** Implementation of a hash function based on block data, nonce, and the previous block's hash.
- **Proof of Work (Mining):** A simulation of the mining process to find a valid hash satisfying specific criteria.
- **Chain Validation:** A dedicated function to ensure integrity by verifying that hashes match across the chain.
- **Persistence:** Capability to save and load the entire blockchain to/from a **binary ledger file**.
- **Genesis Initialization:** Automatic creation of the foundational "Genesis Block".


## 💻 Technical Specifications
- **Data Structures:** Doubly-linked concepts within a blockchain node (Index, Timestamp, Data, Hash, Nonce, Next Pointer).
- **Algorithms:** Linear search for validation and iterative mining for PoW.
- **Language:** C (Standard).

## 🚀 How to Run
1. **Compilation:**
   ```bash
   gcc -I include src/main.c src/linkedlist.c src/blockchain.c src/ledger.c -o blockchain
2. **Execution:**    
   ```bash
   blockchain.exe
