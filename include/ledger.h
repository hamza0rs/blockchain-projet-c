#ifndef LEDGER_H
#define LEDGER_H

#include "linkedlist.h"

// Step 9: Save and Load functions [cite: 28]
int saveBlockchain(Block* head, const char* filename);
Block* loadBlockchain(const char* filename);

#endif