#include <stdlib.h>
#include <stdio.h>
#include "numero3.h"

void main(){
    lista *l = criar_lst();
    int temp;
    for(int i=0; i<20; i++){
        temp = inserir_fim_lst(l, rand() %25 -15);
    }
    exibir_lst(l);
    oposto_lst(l);
    printf("\n");
    exibir_lst(l);
}