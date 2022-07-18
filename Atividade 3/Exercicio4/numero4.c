#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numero4.h"

struct no {
    int conteudo;
    struct no* prox;
};

struct lista {
    no *prim;
    int qtde;
};

lista* criar_lst() {
    lista* l = (lista*) calloc(1, sizeof(lista));
    if(l == NULL)
        return NULL;

    return l;
}

static no* criar_no(int valor) {
    no* novo = (no*) calloc(1, sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

void exibir_lst(lista* l) {
    if(l == NULL)
        return;

    no *temp = l->prim;
    while(temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
}

int inserir_fim_lst(lista* l, int valor) {
    no *cel = criar_no(valor);
    if(l == NULL || cel == NULL)
        return FALSO;

    if(l->qtde==0)
        l->prim = cel;
    else {
        no *temp = l->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }

    l->qtde++;

    return VERDADEIRO;
}

void trocar_valor(lista* l){
    if(l == NULL)
        return;

    no *temp = l->prim;
    for(int i=0; i<l->qtde; i++){
        if(temp->conteudo%2 == 0){
            temp->conteudo ++;
        }
        else{
            temp->conteudo --;
        }
        temp = temp->prox;
    }
}
