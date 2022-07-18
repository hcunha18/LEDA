#include <stdio.h>
#include <stdlib.h>
#include "numero5.h"

void main()
{
    int j;
    lista *l = criar_lista(5);
    j = inserir_lc(l,1);
    j = inserir_lc(l,2);
    j = inserir_lc(l,3);
    j = inserir_lc(l,4);


    exibir_lc(l);

    exibir_n_vezes_lc(l, 3);
}
