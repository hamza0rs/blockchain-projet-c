#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "linkedlist.h"

#define DIFFICULTY 4

// Blockchain specific operations
void calculateHash(Block* block, char* outputBuffer); // Step 4 [cite: 13]
Block* initBlockchain();                              // Step 5 [cite: 16]
void mineBlock(Block* block);                         // Step 6 [cite: 18]
void displayBlockchain(Block* head);                  // Step 7 [cite: 22]
int validateChain(Block* head);                       // Step 8 [cite: 25]

#endif