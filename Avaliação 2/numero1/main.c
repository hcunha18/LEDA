#include <stdio.h>
#include <stdlib.h>
#include "numero1.h"

void main()
{
    int temp;
    lista *l = criar_lst(100);

    for(int i=0; i<25; i++){
        temp = inserir_fim_lst(l,rand() %20 - 10);
    }
    exibir_lst(l);
    printf("\n quantidade de numeros negativos: %d", qtde_negativos_lst(l));
}
