#include <stdlib.h>
#include <stdio.h>
#include "numero5.h"

struct lista{
    int *dados;
    int inicio, fim;
    int capacidade;
};

lista* criar_lista(int capacidade){
    lista *temp = (lista*) malloc(sizeof(lista));
    temp->dados = (int*) malloc(capacidade * sizeof(int));
    temp->capacidade = capacidade;
    temp->inicio = -1;
    temp->fim = 0;
    return temp;
}

int inserir_lc(lista* l, int e)  {
    if(esta_cheia_lc(l))
        return FALSO;

    if(l == NULL)
        return NULL;

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
        return NULL;

    if(tamanho_lc(l) == l->capacidade)
        return VERDADEIRO;

    return FALSO;
}

int esta_vazia_lc(lista* l) {
    if(l == NULL)
        return NULL;

    if(tamanho_lc(l) == 0)
        return VERDADEIRO;

    return FALSO;
}

int tamanho_lc(lista* l) {
    int tam;
    if(l->inicio == -1)
        return 0;
    if(l->fim > l->inicio)
        return l->fim - l->inicio;
    else
        return l->fim - l->inicio + l->capacidade;
}

void exibir_lc(lista* l) {
    if(l == NULL || esta_vazia_lc(l))
        return;

    int i, id_pos = l->inicio;
    printf("\n");

    printf("pos: ");
    for(i = 1; i <= tamanho_lc(l); i++) {
        printf(" %d ", id_pos++);
        if(id_pos == l->capacidade)
            id_pos = 0;
    }
    printf("\n");


    id_pos = l->inicio;
    printf("val: ");
    for(i = 1; i <= tamanho_lc(l); i++) {
        printf(" %d ", l->dados[id_pos++]);
        if(id_pos == l->capacidade)
            id_pos = 0;
    }
}

void exibir_n_vezes_lc(lista* l, int n){
    if(l == NULL || esta_vazia_lc(l))
        return;

    for(int j=0; j<n; j++){
        int i, id_pos = l->inicio;
        id_pos = l->inicio;
        for(i = 1; i <= tamanho_lc(l); i++) {
            printf(" %d ", l->dados[id_pos++]);
            if(id_pos == l->capacidade)
                id_pos = 0;
        }
    }
}
