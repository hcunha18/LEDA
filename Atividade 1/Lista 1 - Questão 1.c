/*1. [3 pontos] Implemente uma função que utilize passagem de parâmetros por valor e por referência. A
função terá os parâmetros A, B que permitirão receber dois valores inteiros e um terceiro parâmetro C
do tipo ponteiro para inteiro. Utilize a variável C para armazenar e "retornar" o resultado do cálculo do
produto de A por B. Esta função deverá possuir retorno do tipo void. Segue uma sugestão de protótipo
para a função:
void produto(int a, int b, int *c).
Faça um programa principal para testar a funcionalidade. Declare três variáveis inteiras A, B e C.
Inicialize a terceira variável com o valor 0. Leia dois valores inteiros e os armazenem nas variáveis A e
B. Efetue uma chamada à função e passe como argumentos as três variáveis criadas, sendo que a
terceira (C) deverá ser passada por referência para poder ser acessada fora do escopo da função.
Imprima os valores de A, B e C antes e após a chamada à função.*/

#include <stdio.h>
#include <stdlib.h>

//Função para fazer o produto das variáveis
void produto(int a, int b, int *c){
*c = a * b;
}


int main()
{
    int a,b,c;
	
	//Lendo os valores
    printf("\nInforme o valor de A: ");
    scanf("%d",&a);
    printf("\nInforme  o valor de B: ");
    scanf("%d",&b);
    
	c=0; //a terceira variável com o valor 0
	
	//Apresentando os valores antes da chamada da função
    printf("\nValores ANTES da chamada da funcao:\nO valor de A: e %d, o de B: %d, e o de C: %d",a,b,c);
    produto(a,b,&c);
    printf("\n");
	
    printf("\nValores APOS a chamada da funcao:\nO valor de A: e %d, o de B: %d, e o de C: %d",a,b,c);
    printf("\nO produto de A com B e: %d",c);
    printf("\n");
    return 0;
}
