#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct Nó {
    int dados;
    struct Nó* left;
    struct Nó* right;
};

// Função para criar um novo nó
struct Nó* NovoNó(int dados) {
    struct Nó* Nó = (struct Nó*)malloc(sizeof(struct Nó));
    Nó->dados = dados;
    Nó->left = NULL;
    Nó->right = NULL;
    return Nó;
}

// Função para inserir um nó na árvore
struct Nó* insert(struct Nó* raiz, int dados) {
    if (raiz == NULL) {
        return NovoNó(dados);
    }
    if (dados < raiz->dados) {
        raiz->left = insert(raiz->left, dados);
    } else if (dados > raiz->dados) {
        raiz->right = insert(raiz->right, dados);
    }
    return raiz;
}

// Função para encontrar o menor valor na sub-árvore direita
struct Nó* minValueNó(struct Nó* Nó) {
    struct Nó* atual = Nó;
    while (atual && atual->left != NULL) {
        atual = atual->left;
    }
    return atual;
}

// Função para remover um nó da árvore
struct Nó* removeNó(struct Nó* raiz, int dados) {
    if (raiz == NULL) {
        return raiz;
    }
    if (dados < raiz->dados) {
        raiz->left = removeNó(raiz->left, dados);
    } else if (dados > raiz->dados) {
        raiz->right = removeNó(raiz->right, dados);
    } else {
        // Caso o nó tenha apenas um filho ou nenhum filho
        if (raiz->left == NULL) {
            struct Nó* temp = raiz->right;
            free(raiz);
            return temp;
        } else if (raiz->right == NULL) {
            struct Nó* temp = raiz->left;
            free(raiz);
            return temp;
        }
        // Caso o nó tenha dois filhos, encontra o sucessor e o remove
        struct Nó* temp = minValueNó(raiz->right);
        raiz->dados = temp->dados;
        raiz->right = removeNó(raiz->right, temp->dados);
    }
    return raiz;
}

// Função para percorrer a árvore em ordem
void inorderTraversal(struct Nó* Nó) {
    if (Nó != NULL) {
        inorderTraversal(Nó->left);
        printf("%d ", Nó->dados);
        inorderTraversal(Nó->right);
    }
}