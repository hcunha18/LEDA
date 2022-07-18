#include <stdio.h>
#include <stdlib.h>
#include "numero2.h"

void main()
{
    lista *l1 = criar_lst(50);

    if(l1 == NULL)
        printf("Erro na criacao da lista\n");
    else
        printf("Lista criada com sucesso!\n");
    int ex;
    for(int i = 0; i < 50; i++){
            ex = inserir_lst(l1, (rand() %15 +1) );
            if(ex =! 1)
                printf("ocorreu erro na inserção!");

            else{}
    }

    exibir_lst(l1);

    printf("\nnumero de repeticoes do algarismo (3) na lista e: %d", buscar_qtde_lst(l1,3));
    printf("\nnumero de repeticoes do algarismo (8) na lista e: %d", buscar_qtde_lst(l1,8));
    printf("\nnumero de repeticoes do algarismo (15) na lista e: %d", buscar_qtde_lst(l1,15));
}
