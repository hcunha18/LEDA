#ifndef MIN_HEAP_H_INCLUDED
#define MIN_HEAP_H_INCLUDED

typedef struct heap heap;

heap* criar_heap(int n);
void exibir_heap(heap *h);
int inserir_heap(heap *h, unsigned int v);
void trocar_heap(heap *h, int id1, int id2);
int esta_cheia_heap(heap* h);
int esta_vazia_heap(heap* h);
int remover_heap(heap *h);
void min_heapify(heap *h, int id_p);


#endif // MIN_HEAP_H_INCLUDED
