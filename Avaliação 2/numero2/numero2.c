#include <stdlib.h>
#include <stdio.h>
#include "numero2.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct lst {
    int qtde, capacidade;
    int *dados;
};

lista* criar_lst(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(nova == NULL)
        return NULL;

    nova->qtde = 0;
    nova->dados = (int*) calloc(capacidade, sizeof(int));
    if(nova->dados == NULL) {
        free(nova);
        return NULL;
    }
    nova->capacidade = capacidade;

    return nova;
}

int inserir_fim_lst(lista *l, int valor) {
    if(l == NULL)
        return ERRO;
    
    if(l->qtde == l->capacidade)
        return FALSO;

    l->dados[l->qtde] = valor;
    l->qtde++;

    return VERDADEIRO;
}

int liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return FALSO;
    
    free((*l)->dados);
    free(*l);
    *l = NULL;
    
    return VERDADEIRO;
}

int remover_fim_lst(lista *l, int *valor_removido) {
    if(l == NULL)
        return ERRO;
    
    if(esta_vazia_lst(l))
        return FALSO;
    
    *valor_removido = l->dados[l->qtde-1];

    l->qtde--;

    return VERDADEIRO;
}

int esta_vazia_lst(lista *l) {
    if(l == NULL)
        return ERRO;

    if(l->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

void exibir_lst(lista *l) {
    if(l == NULL || esta_vazia_lst(l))
        return;
    
    int i;
    for(i = 0; i < l->qtde; i++)
        printf("%d ", l->dados[i]);
}
