#include <stdio.h>
#include <stdlib.h>
#include "numero6.h"

void main()
{
    lista *l1 = criar_lst();
    int temp;
    for(int i = 0; i<15; i++){
        temp = inserir_fim_lst(l1, i);
    }
    exibir_lst(l1);

    for(int i = 0; i<3; i++){
        temp = remover_fim_lst(l1);
    }
    printf("\n");
    exibir_lst(l1);

    temp = topo(l1);
    printf("\n%d", temp);
    if(esta_vazia_lst(l1) == VERDADEIRO)
        printf("\nLista vazia");
    else
        printf("\nEsta cheia");
    liberar_lst(&l1);
}
