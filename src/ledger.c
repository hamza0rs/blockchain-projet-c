#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ledger.h"

// Step 9: Write to binary file [cite: 28]
int saveBlockchain(Block* head, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) return 0;
    
    Block* current = head;
    while (current != NULL) {
        // We write the block struct, but NOT the pointer address (next), 
        // because pointers change every run.
        fwrite(current, sizeof(Block) - sizeof(struct Block*), 1, file);
        current = current->next;
    }
    fclose(file);
    printf("Blockchain saved to %s\n", filename);
    return 1;
}

// Step 9: Read from binary file [cite: 28]
Block* loadBlockchain(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;
    
    Block temp;
    Block* head = NULL;
    Block* last = NULL;
    
    // We read size of Block minus the pointer size
    while (fread(&temp, sizeof(Block) - sizeof(struct Block*), 1, file)) {
        Block* newNode = createBlockNode(temp.index, temp.data, temp.previousHash);
        
        // Restore mined data
        newNode->timestamp = temp.timestamp;
        newNode->nonce = temp.nonce;
        strncpy(newNode->hash, temp.hash, 64);
        
        // Link it
        if (head == NULL) {
            head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }
    
    fclose(file);
    return head;
}