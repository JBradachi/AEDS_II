#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    int valor = NULL;
    CelulaArvore* esquerda = NULL;
    CelulaArvore* direita = NULL;
}CelulaArvore;

typedef struct{
    CelulaArvore* raiz = NULL;
}Arvore;

int insere(CelulaArvore* celula, int* valor){
    if(celula->valor==NULL){
        CelulaArvore* p = (CelulaArvore*) malloc(sizeof(CelulaArvore));
        p->valor = valor;
        celula = &p;
    }else{
        insere(celula, valor);
    }
}