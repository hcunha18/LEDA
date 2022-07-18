#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void main()
{
    int temp;
    arvore *a = criar_arv(50);
    no* r = get_raiz_arv(a);

    for(int i=0; i<10; i++){
        temp = adicionar_no_arv(a, (rand() %99 +1));
    }

    pre_ordem_arv(r);
    printf("\n");
    int folhas = qtd_folhas(r);
    printf("%d ", folhas);

}
