#include "aula01.h"

int buscar(int* v, int tam, int num);

int main(){
    int vetor[5] = {2, 4, 5, 7, 9};
    int i;
    i = buscar(vetor, 5, 2);
    printf("%d", i);
    return 0;
}

int buscar(int* v, int tam, int num){
    int inicio, final, meio;
    inicio = 0;
    final = tam-1;

    while (inicio<=final){
        meio = (inicio+final)/2;
        if(num <v[meio])
            final = meio-1;
        else if(num >v[meio])
            inicio = meio+1;
        else
            return meio;
    }

    return -1;
}
