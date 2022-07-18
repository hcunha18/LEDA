#include <stdlib.h>
#include <stdio.h>
#include "numero2.h"

struct lista{
    int qtd, capacidade;
    int *dado;
};

lista* criar_lst(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(nova == NULL)
        return NULL;

    nova->qtd = 0;
    nova->dado = (int*) calloc(capacidade, sizeof(int));
    if(nova->dado == NULL) {
        free(nova);
        return NULL;
    }
    nova->capacidade = capacidade;

    return nova;
}

int buscar_qtde_lst(lista *l, int valor){
    if(l == NULL || l->qtd == 0)
        return ERRO;
    int recorrencia = 0;
    for(int i=0; i<l->qtd; i++){
        if(l->dado[i] == valor){
            recorrencia +=1;
        }
        else{}
    }
    return recorrencia;
}

int inserir_lst(lista *l, int valor) {
    if(l == NULL)
        return ERRO;

    if(l->qtd == l->capacidade)
        return FALSO;

    if(l->qtd == 0)
        l->dado[0] = valor;
    else {
        l->dado[l->qtd] = valor;
    }
    l->qtd++;

    return VERDADEIRO;
}

void exibir_lst(lista *l) {
    if(l == NULL || l->qtd == 0)
        return;

    int i;
    for(i = 0; i < l->qtd; i++)
        printf("%d ", l->dado[i]);
}
