#include <stdio.h>
#include <stdlib.h>
#include "numero1.h"

void main()
{
    lista *l1 = criar_lst(10);

    if(l1 == NULL)
        printf("Erro na criacao da lista\n");
    else
        printf("Lista criada com sucesso!\n");

    int ex;
        //FAZENDO SEGUNDO O EXEMPLO DADO
        ex = inserir_lst(l1, 1);
        ex = inserir_lst(l1, 2);
        ex = inserir_lst(l1, 3);
        ex = inserir_lst(l1, 4);
        ex = inserir_lst(l1, 5);
        ex = inserir_lst(l1, 3);
        ex = inserir_lst(l1, 4);
        ex = inserir_lst(l1, 2);
        ex = inserir_lst(l1, 3);

    exibir_lst(l1);

    printf("\nnumero de repeticoes do algarismo (3) na lista e: %d", buscar_qtde_lst(l1,3));
    printf("\nnumero de repeticoes do algarismo (4) na lista e: %d", buscar_qtde_lst(l1,4));
    printf("\nnumero de repeticoes do algarismo (6) na lista e: %d", buscar_qtde_lst(l1,6));
}
