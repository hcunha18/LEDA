/*2. [4 pontos] Implemente uma função para inverter a ordem dos elementos presentes em um vetor. A
inversão deve ser feita utilizando o próprio vetor, ou seja, sem utilizar estruturas auxiliares. Após a
utilização da função, o primeiro elemento do vetor tem que ter sido trocado com o último, o segundo
com o penúltimo e, assim, sucessivamente. Esta função poderá ser definida sem valor de retorno e com
dois parâmetros: um para representar o vetor e outro para o seu tamanho. Possível protótipos para a
função:
void inverter(int vet[], int tam)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverter_vetor(int *vet, int tam){
	int aux, i;
    for(i=0; i < tam/2; i++){
        aux = vet[i];
        vet[i]=vet[tam-i-1];
        vet[tam-i-1]=aux;
    }

}

//Outra solução para a função de inverter o vetor
/*void inverter(int *vet, int tam)
{
    int inicio = 0, fim = tam-1, aux;

    while(inicio < fim){
        aux = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = aux;

        inicio++;
        fim--;
    }
}*/

int main()
{
    int tam, i, *vet;
    printf("Informe o tamanho do vetor:\n");
    scanf("%d",&tam);
    
	//Alocando dinamicamente o vetor
	vet = (int *) malloc( tam * sizeof(int));
	
	//Preechendo com solicitação ao usuário
    /*for (i=0; i<tam; i++){
        scanf("%d",&vet[i]);
    }*/
	
	//Preechendo com numeros aleatórios de 1 a 100
	for(i=0; i<tam; i++){
        vet[i] = rand()% 100;
    }
	
	//Imprimindo o vetor antes da impressão
    printf("\nVetor:\n");
    for (i=0; i<tam; i++){
        printf("%d ",vet[i]);

    }
    inverter_vetor(vet,tam);

    printf("\nVetor Invertido:\n");
    for (i=0; i<tam; i++){
        printf("%d ",vet[i]);
    }

    return 0;
}

