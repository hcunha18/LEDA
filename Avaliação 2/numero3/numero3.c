#include <stdlib.h>
#include <stdio.h>
#include "numero3.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct c {
    int conteudo;
    celula *prox;
};

struct lista {
    celula *prim;
    int qtde;
};

lista* criar_lst() {
    lista* l = (lista*) calloc(1, sizeof(lista));
    if(l == NULL)
        return NULL;

    l->prim = NULL;
    l->qtde = 0;

    return l;
}

static celula* criar_no(int valor) {
    celula* novo = (celula*) calloc(1, sizeof(celula));
    if(novo == NULL)
        return NULL;
    
    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

void oposto_lst(lista *l){
    if(l ==NULL)
        return;
    celula *temp = l->prim;
    for(int i=0; i<l->qtde; i++){
        temp->conteudo = temp->conteudo/(-1);
        temp = temp->prox;
    }
}

int inserir_fim_lst(lista* l, int valor) {
    celula *cel = criar_no(valor);
    if(l == NULL || cel == NULL)
        return FALSO;
    
    if(l->qtde ==0)
        l->prim = cel;
    else {
        celula *temp = l->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }

    l->qtde++;

    return VERDADEIRO;
}

void exibir_lst(lista* l) {
    if(l == NULL)
        return;
    
    celula *temp = l->prim;
    while(temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
}