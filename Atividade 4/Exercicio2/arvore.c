#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

#define FALSO 0
#define VERDADEIRO 1

struct no {
    int info;
    no *sae;
    no *sad;
};

struct arv {
    no *raiz;
};

int adicionar_no_arv(arvore* a, int valor) {
    if(a == NULL)
        return FALSO;

    no *temp = a->raiz;
    while(temp != NULL) {
        if(valor <= temp->info) {
            if(temp->sae == NULL) {
                temp->sae = criar_no(valor);
                break;
            }
            temp = temp->sae;
        } else {
            if(temp->sad == NULL) {
                temp->sad = criar_no(valor);
                break;
            }
            temp = temp->sad;
        }
    }

    return VERDADEIRO;
}

arvore* criar_arv(int valor_raiz) {
    arvore *a = (arvore*) malloc(sizeof(arvore));
    if(a == NULL)
        return NULL;

    no *raiz = (no*) criar_no(valor_raiz);
    if(raiz != NULL)
        a->raiz = raiz;
    else
        return NULL;

    return a;
}

no* criar_no(int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->info = valor;
    novo->sad = NULL;
    novo->sae = NULL;

    return novo;
}

void pre_ordem_arv(no *n) {
    if(n != NULL) {
        printf("%d ", n->info);
        pre_ordem_arv(n->sae);
        pre_ordem_arv(n->sad);
    }
}

no* get_raiz_arv(arvore* a) {
    if(a == NULL)
        return NULL;

    return a->raiz;
}

int qtd_folhas(no *raiz){
    if(raiz == NULL)
        return FALSO;
    int folhas = 0;
    no *temp = raiz;

    if(temp != NULL) {
        if(temp->sad == NULL && temp->sae == NULL) {
            folhas ++;
        } else {
            folhas += qtd_folhas(temp->sad);
            folhas += qtd_folhas(temp->sae);
        }
    }

    return folhas;
}
