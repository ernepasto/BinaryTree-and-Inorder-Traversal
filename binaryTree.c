#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <math.h>

enum Level { LOW = 1, MEDIUM = 2, HIGH = 3 };

struct NodeData {
    int number;
};

struct Node {
    struct NodeData data;
    struct Node *left;
    struct Node *right;
};

/* Funzione per la creazione di un nuovo nodo con i dati passati come parametro */
struct Node * createNode(int number) {

    struct NodeData data = { number };

    // Allocazione dinamica della memoria per il nuovo nodo
    struct Node *node = (struct Node *) calloc(1, sizeof(struct Node));

    // Assegnazione dei dati del nodo e inizializzazione dei sui figli
    // Dato che è un puntatore si usa '->' per acceder alle proprietà della struttura
    node->data = data;
    node->left = NULL;
    node->right = NULL;
};

/* Funzione per la visita del nodo passato come parametro */
void visitNode(struct Node *node) {
    
    struct NodeData data = node->data;
    printf("\nThe node number is: %i", data.number);

};

/* Funzione per la visita Inorder Traversal (left-current-right) */
void visitTree(struct Node *current) {

    struct Node *leftChild = current->left;
    struct Node *rightChild = current->right;

    if (leftChild) {
        visitTree(leftChild); // Esecuzione in maniera ricorsiva della visita
        visitNode(current);
        if (rightChild) visitTree(rightChild); // Se c'è un figlio destro la visita continua in maniera ricorsiva
    } else {
        visitNode(current); // In assenza del figlio sinistro visito il nodo corrente
    }
};

int main() {

    // Creazione del nodo root
    struct Node *root = createNode(1);

    // Creazione dei figli del nodo root
    root->left = createNode(2);
    root->right = createNode(3);

    // Creazione dei figli del nodo 2
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Creazione dei figli del nodo 3
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    visitTree(root);

    return 0;
};