#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"

void main(){
    heap *h = criar_heap(rand()%49 + 1);
    int temp;
    for(int i = 0; i<15; i++){
        temp = inserir_heap(h, rand()%49 +1);
    }

    exibir_heap(h);

    printf("\n\n");

    for(int i = 0; i<15; i++){
        temp = remover_heap(h);
        printf("%d ", temp);
        }

}
