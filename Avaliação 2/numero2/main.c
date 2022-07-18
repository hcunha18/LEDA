#include <stdlib.h>
#include <stdio.h>
#include "numero2.h"

void main(){
    lista *l = criar_lst(100);
    int temp;
    for(int i=1; i<50; i+=2){
        temp = inserir_fim_lst(l, i);
    }
    exibir_lst(l);
    int j;
    printf("\n");
    for(int i=49; i>0; i-=2){
        temp = remover_fim_lst(l, &j);
        printf(" %d", j);
    }

}