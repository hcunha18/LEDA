#include <stdio.h>
#include <stdlib.h>

//letra a
void maior_menor (int *vetor, int tam, int *maior, int *menor){
    int i;

    for (i=0; i<=tam; i++){
        if(vetor[i] <= *menor)
            *menor = vetor[i];
        
        if(vetor[i] >= *maior)
            *maior = vetor[i];
    }
}

//letra b
int main(){
    int i, maior=0, menor=999, tam=20, min = -50, max = 200 ;
    int vetor[tam]; //Criando o vetor

    /*Preenchendo o Vetor*/
    srand(time(NULL));
    for (i = 0; i <20; i++){
        vetor[i] = rand() % ((max-min)+1) + min;
    }


    /*Apresentando o Vetor*/
    printf("\n\nVetor: ");
    for (i = 0; i<tam; i++){
        printf("%d ", vetor[i]);
    }

    //Mostando o maior e o menor
    maior_menor(vetor, tam, &maior, &menor);
    printf("\n\nMaior e menor valores do vetor: %d %d", maior, menor);

    return 0;
}