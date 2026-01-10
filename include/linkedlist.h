#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <time.h>

// Step 3 & 7: Define the Block structure (acting as the Linked List Node) [cite: 7, 10]
typedef struct Block {
    int index;
    time_t timestamp;
    char data[256];
    char previousHash[65];
    char hash[65];
    long long nonce;
    struct Block* next; // Pointer to the next node 
} Block;

// Linked List Operations
Block* createBlockNode(int index, const char* data, const char* prevHash);
void insertBlockEnd(Block** head, Block* newBlock);
void freeBlockchain(Block* head);

#endif