#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    arvore raiz;
    int opcao, temp, chave,valor;
    float porcento;
    raiz = NULL;

    while(1==1) {
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                scanf("%d", &temp);
                raiz = inserir(raiz, temp);
                break;
            case 2:
                preorder(raiz);
                printf("\n");
                break;
            case 3:
                inorder(raiz);
                printf("\n");
                break;
            case 4:
                posorder(raiz);
                printf("\n");
                break;
            case 5:
                reverso(raiz);
                printf("\n");
                break;
            case 6:
                printf("%d\n", qtdPrimo(raiz));
                break;
            case 7:
                scanf("%f", &porcento);
                reajusta(raiz, porcento);
                break;
            case 8:     //existe
                scanf("%d", &chave);
                printf("%d\n", existe(raiz, chave) );
                break;
            case 9:     //remover
                scanf("%d", &valor);
                raiz = remover(raiz, valor);                
                break;
            case 99:
                exit(0);
        }
    }
}
