#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedlist.h"

// Creates a new node (Block) with memory allocation [cite: 8]
Block* createBlockNode(int index, const char* data, const char* prevHash) {
    Block* newBlock = (Block*)malloc(sizeof(Block));
    if (newBlock == NULL) {
        perror("Failed to allocate memory for block");
        exit(1);
    }
    
    newBlock->index = index;
    newBlock->timestamp = time(NULL);
    strncpy(newBlock->data, data, 255);
    newBlock->data[255] = '\0'; // Ensure null-termination
    
    strncpy(newBlock->previousHash, prevHash, 64);
    newBlock->previousHash[64] = '\0';
    
    newBlock->nonce = 0;
    newBlock->next = NULL; // Step 7: Pointer to next node
    
    return newBlock;
}

// Inserts a node at the end of the list [cite: 8]
void insertBlockEnd(Block** head, Block* newBlock) {
    if (*head == NULL) {
        *head = newBlock;
        return;
    }
    
    Block* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newBlock;
}

// Helper to clean up memory
void freeBlockchain(Block* head) {
    Block* current = head;
    while (current != NULL) {
        Block* temp = current;
        current = current->next;
        free(temp);
    }
}