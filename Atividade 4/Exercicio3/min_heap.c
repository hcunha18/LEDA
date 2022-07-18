#include <stdlib.h>
#include <stdio.h>
#include "min_heap.h"

#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

int pai_heap(heap *h, int id_f);
void trocar_heap(heap *h, int p1, int p2);

struct heap {
    unsigned int *dados;
    unsigned int capacidade;
    unsigned int qtde;
};

heap *criar_heap(int n) {
    heap* h = (heap*) malloc(sizeof(heap));
    if (h == NULL)
        return NULL;

    h->dados = (int*) malloc(n * sizeof(int));
    if(h->dados == NULL) {
        free(h);
        return NULL;
    }

    h->qtde = 0;
    h->capacidade = n;

    return h;
}

int indice_filho_esq(heap *h, int id_p) {
    int esq = 2*id_p + 1;
    if(esq >= h->qtde)
        return FLAG_ERRO;

    return esq;
}

int indice_filho_dir(heap *h, int id_p) {
    int dir = 2*id_p + 2;
    if (dir >= h->qtde)
        return FLAG_ERRO;

    return dir;
}

 void exibir_heap(heap *h){
    int i, nivel = 1;
    for (i = 1; i <= h->qtde; i++) {
        if(i == nivel) {
            printf("\n");
            nivel = 2*i;
        }
        printf("%d ", h->dados[i-1]);
    }
}

int inserir_heap(heap *h, unsigned int v) {
    if(!inserir_fim_heap(h, v))
        return FALSO;

    int id_v = h->qtde - 1;
    int id_p = indice_pai(h, id_v);
    while(id_p >= 0 && h->dados[id_v] < h->dados[id_p]) {
        trocar_heap(h, id_v, id_p);
        id_v = id_p;
        id_p = indice_pai(h, id_v);
    }

    return VERDADEIRO;
}


int inserir_fim_heap(heap* h, unsigned int v) {
    if (h == NULL || esta_cheia_heap(h))
        return FALSO;

    h->dados[h->qtde] = v;
    h->qtde++;

    return VERDADEIRO;
}

int indice_pai(heap *h, int id_f) {
    if (id_f <= 0)
        return FLAG_ERRO;

    return (id_f-1)/2;
}

int esta_cheia_heap(heap* h) {
    if(h == NULL)
        return FALSO;

    return h->qtde == h->capacidade;
}

int esta_vazia_heap(heap* h) {
    if(h == NULL)
        return FALSO;

    return h->qtde == 0;
}

void min_heapify(heap *h, int id_p) {
    if(h == NULL || id_p < 0 || id_p >= h->qtde)
        return;

    int id_fe = indice_filho_esq(h, id_p),
        id_fd = indice_filho_dir(h, id_p);
    while((id_fe > 0 && h->dados[id_p] > h->dados[id_fe]) ||
          (id_fd > 0 && h->dados[id_p] > h->dados[id_fd])) {

        if(id_fd >= h->qtde) {
            trocar_heap(h, id_p, id_fe);
            return;
        } else if(h->dados[id_fe] <= h->dados[id_fd]) {
            trocar_heap(h, id_p, id_fe);
            id_p = id_fe;
        } else {
            trocar_heap(h, id_p, id_fd);
            id_p = id_fd;
        }
        id_fe = indice_filho_esq(h, id_p);
        id_fd = indice_filho_dir(h, id_p);
    }
}

int remover_heap(heap *h) {
    if(h == NULL || esta_vazia_heap(h))
        return FLAG_ERRO;

    int retorno = h->dados[0];
    h->dados[0] = h->dados[h->qtde - 1];
    h->qtde--;

    min_heapify(h, 0);

    return retorno;
}


void trocar_heap(heap *h, int id1, int id2) {
    int aux = h->dados[id1];
    h->dados[id1] = h->dados[id2];
    h->dados[id2] = aux;
}
