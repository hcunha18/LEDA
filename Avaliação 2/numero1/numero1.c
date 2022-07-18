#include <stdlib.h>
#include <stdio.h>
#include "numero1.h"

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

void exibir_lst(lista *l) {
    if(l == NULL || l->qtde == 0)
        return;

    int i;
    for(i = 0; i < l->qtde; i++)
        printf("%d ", l->dados[i]);
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

int qtde_negativos_lst(lista *l){
    int n = 0;
    if(l==NULL)
        return ERRO;
    for(int i = 0; i<l->qtde; i++){
        if(l->dados[i] < 0){
            n++;
        }
        else{

        }
    }
    return n;
}
