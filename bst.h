#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq, *dir;
} no;

typedef no * arvore;

arvore inserir (arvore raiz, int valor);

void preorder(arvore raiz);

void inorder(arvore raiz);

void posorder(arvore raiz);

void reverso(arvore raiz);

int primo(int n);

int qtdPrimo(arvore raiz);

void reajusta(arvore raiz, float porcento);

int existe(arvore raiz, int chave);

arvore remover (arvore raiz, int valor);

#endif
