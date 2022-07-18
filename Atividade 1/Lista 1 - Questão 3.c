/*3.[3 pontos] Crie um programa que preencha um vetor do tipo int de N posições, onde N é definido
pelo usuário. Os valores “aleatórios” para preenchimento deverão ser gerados aleatoriamente no
intervalo [10, 100]. Após o preenchimento, imprima o conteúdo de cada posição desse vetor separados
por um espaço.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int tam, i, *vet;
	
    srand(time(NULL));
    printf("\nInforme o tamanho do vetor: ");
    scanf("%d",&tam);
    
	//Alocando dinamicamente o vetor
	vet = (int *) malloc( tam * sizeof(int));

    for(i=0; i<tam; i++){
		//a posição do vetor recebe o numero randômico que vai de 10 a 100. 
		//10 é o piso, a abrangência de valores é 90 (100 - 10, ou seja, max - min) e o +1 é porque as extremidades entram
		//fórmula do rand: min + rand() % (max-min) +1
        vet[i] = 10 + rand()% 90 +1;
        printf("%d ", vet[i]);
    }
    return 0;
}
