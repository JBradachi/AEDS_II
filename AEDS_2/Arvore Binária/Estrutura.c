#include "Estrutura.h"

int main() {
    struct Nó* raiz = NULL;
    raiz = insert(raiz, 50);
    insert(raiz, 30);
    insert(raiz, 20);
    insert(raiz, 40);
    insert(raiz, 70);
    insert(raiz, 60);
    insert(raiz, 80);
    printf("Árvore inicial: ");
    inorderTraversal(raiz);
    printf("\n");
    raiz = removeNó(raiz, 20);
    printf("Árvore após remoção do valor 20: ");
    inorderTraversal(raiz);
    printf("\n");
    raiz = removeNó(raiz, 70);
    printf("Árvore após remoção do valor 70: ");
    inorderTraversal(raiz);
    printf("\n");
    return 0;
}