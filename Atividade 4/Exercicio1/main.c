#include <stdio.h>
#include <stdlib.h>

void imprimir_recursivo(int v[], int i, int tam){
        printf("%d ", v[i]);

        if(i < tam)
            imprimir_recursivo(v, i+1, tam);
}

void main()
{
    int v[15];
    for(int i=0; i<15; i++){
        v[i] = rand() %71 +12;
    }
    imprimir_recursivo(v, 0, 15);

}
