#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include "numero3.h"

void main()
{
    lista *l1 = criar_lst(50);

    if(l1 == NULL)
        printf("Erro na criacao da lista\n");
    else
        printf("Lista criada com sucesso!\n");
    int ex;
    for(int i = 0; i < 50; i++){
            ex = inserir_lst(l1, (rand() %5 +1) );
            if(ex =! 1)
                printf("ocorreu erro na inserção!");

            else{}
    }

    exibir_lst(l1);

    printf("\n1: %d", buscar_qtde_lst(l1,1));
    printf("\n2: %d", buscar_qtde_lst(l1,2));
    printf("\n3: %d", buscar_qtde_lst(l1,3));
    printf("\n4: %d", buscar_qtde_lst(l1,4));
    printf("\n5: %d", buscar_qtde_lst(l1,5));
}
