#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir (arvore raiz, int valor) {
    //caso base
    if(raiz == NULL) {
        //alocar espaço em memória para o novo no
        no* novo = (no *) malloc(sizeof(no));

        //inicializar os valores do novo no
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;

        //fazer a ligação do nó com o restante da árvore
        return novo ;
    } else {
        if(valor > raiz->valor) {
            //caso recursivo inserir na sub-árvore direita
            raiz->dir = inserir(raiz->dir, valor);   
        } else {
            //caso recursivo inserir na sub-árvore esquerda
            raiz->esq = inserir(raiz->esq, valor);   
        }
        return raiz;	
    }
}

arvore remover (arvore raiz, int valor) {
    if(raiz == NULL)
        return NULL;

    if(raiz->valor == valor) {
        //caso 1 - zero filho
        if(raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
            }
        //caso 2
        if(raiz->esq == NULL && raiz->dir != NULL) { // 1 Filho à direita
            arvore retorno = raiz->dir;
            free(raiz);
            return retorno;
        }
        
        if(raiz->esq != NULL && raiz->dir == NULL) { // 1 Filho à esquerda
            arvore retorno = raiz->esq;
            free(raiz);
            return retorno;
        }

        if(raiz->esq != NULL && raiz->dir != NULL){
        	arvore retorno = raiz->esq;
        	while(retorno->dir != NULL){
        		retorno = retorno->dir;
        	}
        	raiz->valor = retorno->valor;
        	retorno->valor = valor;
        	raiz->esq = remover(raiz->esq, valor);
        	return raiz;
        }

    } else {
        if(valor < raiz->valor) {
            raiz->esq = remover(raiz->esq, valor);
        } else {
            raiz->dir = remover(raiz->dir, valor);
        }
    }
    return raiz;
}



void preorder(arvore raiz) {
    if(raiz != NULL) {
           printf("[%d]", raiz->valor);
           preorder(raiz->esq);
           preorder(raiz->dir);
    } 
}

void inorder(arvore raiz) {
    if(raiz != NULL) {
           inorder(raiz->esq);
           printf("[%d]", raiz->valor);
           inorder(raiz->dir);
    } 
}

void posorder(arvore raiz) {
    if(raiz != NULL) {
           posorder(raiz->esq);
           posorder(raiz->dir);
           printf("[%d]", raiz->valor);
    } 
}

void reverso(arvore raiz) {
	if(raiz != NULL){
			reverso(raiz->dir);
			printf("[%d]", raiz->valor);
			reverso(raiz->esq);
	}
}

int primo(int n){

    if(n <= 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
     
    if(n % 2 == 0){
        return 0; 
    }
     
    int d;
    for(d = 3; d * d <= n; d+=2){
        if(n % d == 0){
            return 0;
        }
    }
    return 1;
}


int qtdPrimo(arvore raiz){
    int cont = 0;
	if (raiz == NULL){
        return 0;
        
	}
    else{
        if(primo(raiz->valor) == 1){
            cont++;
        }
        return cont + qtdPrimo(raiz->esq) + qtdPrimo(raiz->dir);

    }
}

void reajusta(arvore raiz, float porcento){
	float cobaia = 0;
	cobaia = porcento/100;
	if (raiz != NULL){
		raiz->valor = raiz->valor * cobaia;
		reajusta(raiz->esq, porcento);
		reajusta(raiz->dir, porcento);
	}
}

int existe(arvore raiz, int chave){
	if(raiz == NULL){
		return 0;
	}
	if(raiz->valor == chave){
		return 1;
	} else{
		if(chave > raiz->valor){
			return existe(raiz->dir, chave);
		} else{
			return existe(raiz->esq, chave);
		}
	}

}