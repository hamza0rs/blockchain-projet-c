#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linkedlist.h"  // Notez le chemin relatif
#include "../include/blockchain.h"
#include "../include/ledger.h"

int main() {
    // === 1. Initialisation ===
    printf("=== 1. Initialisation de la Blockchain ===\n");
    // On utilise initBlockchain() au lieu de createGenesisBlock()
    Block* ma_blockchain = initBlockchain(); 
    
    // Pointeur pour suivre le dernier bloc (nécessaire pour le chaînage)
    Block* dernier_bloc = ma_blockchain;

    // === 2. Minage de nouveaux blocs ===
    printf("\n=== 2. Minage de nouveaux blocs ===\n");

    // Création du Bloc 1
    // On crée d'abord le bloc avec createBlockNode
    Block* bloc1 = createBlockNode(1, "Transaction A: Alice paie 10 COIN a Bob", dernier_bloc->hash);
    // Ensuite on le mine
    mineBlock(bloc1);
    // Enfin on l'ajoute à la liste
    insertBlockEnd(&ma_blockchain, bloc1);
    dernier_bloc = bloc1; // On met à jour le dernier bloc

    // Création du Bloc 2
    Block* bloc2 = createBlockNode(2, "Transaction B: Bob retire 5 COIN", dernier_bloc->hash);
    mineBlock(bloc2);
    insertBlockEnd(&ma_blockchain, bloc2);
    
    // === 3. Affichage et Validation ===
    displayBlockchain(ma_blockchain);
    validateChain(ma_blockchain);

    // === 4. Sauvegarde (Ledger) ===
    printf("\n=== 3. Sauvegarde dans le Ledger ===\n");
    saveBlockchain(ma_blockchain, "ledger.dat");
    
    // Nettoyage de la mémoire avant de quitter
    freeBlockchain(ma_blockchain);

    return 0;
}