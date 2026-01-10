#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/blockchain.h"

// Internal hash simulation (DJB2) to avoid complex OpenSSL dependencies
void simple_sha256_simulation(const char* input, char* output) {
    unsigned long hash = 5381;
    int c;
    while ((c = *input++))
        hash = ((hash << 5) + hash) + c; 
    snprintf(output, 65, "%064lx", hash);
}

// Step 4: Calculate Hash based on data, nonce, and prevHash [cite: 13]
void calculateHash(Block* block, char* outputBuffer) {
    char input[1024];
    snprintf(input, sizeof(input), "%d%ld%s%s%lld",
             block->index,
             block->timestamp,
             block->data,
             block->previousHash,
             block->nonce);
             
    simple_sha256_simulation(input, outputBuffer);
}

// Step 5: Initialize with Genesis Block [cite: 16]
Block* initBlockchain() {
    Block* genesis = createBlockNode(0, "Genesis Block", "0000000000000000000000000000000000000000000000000000000000000000");
    calculateHash(genesis, genesis->hash);
    return genesis;
}

// Step 6: Mining (Proof of Work) [cite: 17, 18]
void mineBlock(Block* block) {
    char target[DIFFICULTY + 1];
    for(int i=0; i<DIFFICULTY; i++) target[i] = '0';
    target[DIFFICULTY] = '\0';
    
    printf("Mining Block #%d...\n", block->index);
    
    // Step 6: Find a valid hash [cite: 19]
    do {
        block->nonce++;
        calculateHash(block, block->hash);
    } while (strncmp(block->hash, target, DIFFICULTY) != 0);
    
    printf("Block Mined! Hash: %s\n", block->hash);
}

// Step 7: Display Blockchain Information [cite: 22]
void displayBlockchain(Block* head) {
    Block* current = head;
    printf("\n--- BLOCKCHAIN ---\n");
    while (current != NULL) {
        printf("Index: %d | Timestamp: %ld\n", current->index, current->timestamp); // [cite: 23]
        printf("Data: %s\n", current->data);
        printf("PrevHash: %s\n", current->previousHash);
        printf("Hash: %s\n", current->hash);
        printf("Nonce: %lld\n", current->nonce);
        printf("------------------\n");
        current = current->next;
    }
}

// Step 8: Validation [cite: 24, 25]
int validateChain(Block* head) {
    Block* current = head;
    char rehash[65];
    
    while (current != NULL) {
        // Check 1: Data Integrity (Does re-hashing match the stored hash?)
        calculateHash(current, rehash);
        if (strcmp(current->hash, rehash) != 0) {
            printf("Invalid Block #%d: Hash mismatch.\n", current->index);
            return 0;
        }
        
        // Check 2: Chain Integrity (Does prevHash match the previous block's hash?)
        if (current->next != NULL) {
            if (strcmp(current->hash, current->next->previousHash) != 0) {
                 printf("Broken Chain between #%d and #%d.\n", current->index, current->next->index);
                 return 0;
            }
        }
        current = current->next;
    }
    printf("Blockchain is Valid.\n");
    return 1;
}