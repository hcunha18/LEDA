#include <stdio.h>
#include <stdlib.h>
#include "numero4.h"

void main()
{
    lista* l = criar_lst();
    int temp;

    temp = inserir_fim_lst(l,1);
    temp = inserir_fim_lst(l,-2);
    temp = inserir_fim_lst(l,3);
    temp = inserir_fim_lst(l,4);
    temp = inserir_fim_lst(l,-5);
    temp = inserir_fim_lst(l,3);
    temp = inserir_fim_lst(l,4);
    temp = inserir_fim_lst(l,2);
    temp = inserir_fim_lst(l,3);

    exibir_lst(l);

    trocar_valor(l);

    printf("\n\n");

    exibir_lst(l);
}
