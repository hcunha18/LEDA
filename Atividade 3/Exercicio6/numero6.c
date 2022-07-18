#include <stdlib.h>
#include <stdio.h>
#include "numero6.h"

struct no {
    int conteudo;
    no *prox;
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

int inserir_fim_lst(lista* l, int valor) {
    no *cel = criar_no(valor);
    if(l == NULL || cel == NULL)
        return FALSO;

    if(esta_vazia_lst(l))
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

int remover_fim_lst(lista* l) {
    if(l == NULL || esta_vazia_lst(l))
        return FALSO;

    no* temp = l->prim;
    if(l->qtde == 1) {
        free(temp);
        l->prim = NULL;
    } else {
        int i;
        for(i = 1; i <= l->qtde - 2; i++)
            temp = temp->prox;
        no *aux = temp->prox;
        free(aux);
        temp->prox = NULL;
    }

    l->qtde--;

    return VERDADEIRO;
}

void liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return;

    no *temp = (*l)->prim;
    while(temp != NULL) {
        (*l)->prim = (*l)->prim->prox;
        free(temp);
        temp = (*l)->prim;
        (*l)->qtde--;
    }

    free(*l);
    *l = NULL;
}

int esta_vazia_lst(lista* l) {
    if(l == NULL)
        return ERRO;

    if(l->qtde == 0)        // if(l->prim == NULL)
        return VERDADEIRO;

    return FALSO;
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

int topo(lista* l) {
    if(l == NULL)
        return;

    no *temp = l->prim;
    if(l->qtde == 0)
        return FALSO;
    while(temp != NULL) {
        temp = temp->prox;
        if(temp->prox ==NULL)
            return temp->conteudo;
    }

}
