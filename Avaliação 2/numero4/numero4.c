#include <stdlib.h>
#include <stdio.h>
#include "numero4.h"

#define FALSO 0
#define VERDADEIRO 1
#define NULL_ERROR -1

struct lista {
    int *dados;
    int inicio, fim;
    int capacidade;
};

lista* criar_lc(int capacidade) {
    lista *temp = (lista*) malloc(sizeof(lista));
    if(temp == NULL)
        return NULL;

    temp->dados = (int*) malloc(capacidade * sizeof(int));
    if(temp->dados == NULL) {
        free(temp);
        return NULL;
    }

    temp->capacidade = capacidade;
    temp->inicio = -1;
    temp->fim = 0;

    return temp;
}

int inserir_fim_lc(lista* l, int e)  {
    if(esta_cheia_lc(l))
        return FALSO;

    if(l == NULL)
        return NULL_ERROR;

    if(esta_vazia_lc(l))
        l->inicio = l->fim = 0;

    l->dados[l->fim] = e;
    l->fim += 1;
    if(l->fim == l->capacidade)
        l->fim = 0;

    return VERDADEIRO;
}

int esta_cheia_lc(lista* l) {
    if(l == NULL)
        return NULL_ERROR;

    if(tamanho_lc(l) == l->capacidade)
        return VERDADEIRO;

    return FALSO;
}

void exibir_lc(lista* l) { 
    if(l == NULL || esta_vazia_lc(l))
        return;

    int i, id_pos = l->inicio;
    printf("\n");
    
    // Índices do vetor
    for(i = 1; i <= tamanho_lc(l); i++) {
        printf("%d ", id_pos++);
        if(id_pos == capacidade_lc(l))
            id_pos = 0;
    }
    printf("\n");

    // Elementos do vetor
    id_pos = l->inicio;
    for(i = 1; i <= tamanho_lc(l); i++) {
        printf("%d ", l->dados[id_pos]);
        id_pos = id_pos + 1;
        if(id_pos == capacidade_lc(l))
            id_pos = 0;
    }
}

int tamanho_lc(lista* l) {
    int tam;
    if(l->inicio == -1)
        return 0;
    if(l->fim > l->inicio)
        return l->fim - l->inicio;
    else
        return l->fim - l->inicio + capacidade_lc(l);
}

int esta_vazia_lc(lista* l) {
    if(l == NULL)
        return NULL_ERROR;

    if(tamanho_lc(l) == 0)
        return VERDADEIRO;

    return FALSO;
}

int capacidade_lc(lista *l) {
    return l->capacidade;
}

void dobrar_par(lista *l){
    int i, id_pos = l->inicio;
    for(i = 1; i <= tamanho_lc(l); i++) {
        if(l->dados[id_pos]%2==0){
            l->dados[id_pos]= l->dados[id_pos]*2;
        }
        if(id_pos == capacidade_lc(l))
            id_pos = 0;
        else{

        }
        id_pos = id_pos + 1;
        
    }
}

int remover_inicio_lc(lista* l, int *v) {
    if(l == NULL || v == NULL)
        return NULL_ERROR;

    if(esta_vazia_lc(l))
        return FALSO;

    *v = l->dados[l->inicio];
    l->inicio++;
    if(l->inicio == capacidade_lc(l))
        l->inicio = 0;
    
    if(l->inicio == l->fim) {
        esvaziar_lc(l);
    }

    return VERDADEIRO;
}
