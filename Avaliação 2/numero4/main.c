#include <stdlib.h>
#include <stdio.h>
#include "numero4.h"

void main(){
    lista *l = criar_lc(30);
    int temp;
    for(int i=-10; i<11; i++){
        temp = inserir_fim_lc(l,i);
    }
    
}