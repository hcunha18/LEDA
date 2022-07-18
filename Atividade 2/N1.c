#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct bolsa{
    char nome[50];
    char atuacao[50];
    double v_atual;
    double v_anterior;
    int variacao;
};

typedef struct bolsa bolsa;

bolsa preencherstruct();
void imprimirstruct(bolsa b);
double valoratual(bolsa b);
void i_abaixo(double v, bolsa b[], int tam);
void media_dp(bolsa b[], int tam);
bolsa novovalor(bolsa b, double valor);
void ordenar_cres(bolsa b[], int tam);

void main(){
    int tam = 5;
    bolsa b[tam];
    double v = 10;
    for(int i=0; i<tam; i++){
        printf("\n\n Dados %d", i+1);
        b[i] = preencherstruct();
        fflush(stdin);
    }
    for(int i=0; i<tam; i++){

        printf("\nDados %d", i+1);
        imprimirstruct(b[i]);
        fflush(stdin);
    }
    printf("\n\n\n");
    i_abaixo(v, b, tam);

    printf("\n\n\n");
    printf("Meida e Desvio Padrao:");
    media_dp(b, tam);

    printf("\n\n\n");
    printf("Adicionando novo valor:");
    b[tam - 1] =novovalor(b[tam - 1], 10);
    //imprimindo o valor adicionado
    imprimirstruct(b[tam-1]);

    printf("\n\n\n");
    ordenar_cres(b, tam);

}

void ordenar_cres(bolsa b[], int tam){
    printf("\nOrdenando ordem crescente:");
    for(int j=tam-1;j>0;j--){
        for(int i=0;i<j;i++){
            if(b[i].v_atual>b[i+1].v_atual){
                bolsa temp;
                temp = b[i];
                b[i]=b[i+1];
                b[i+1] = temp;
            }
        }
    }

    for(int i=0;i<tam;i++){
        imprimirstruct(b[i]);
    }
}

bolsa novovalor(bolsa b, double valor){
    b.v_anterior = b.v_atual;
    b.v_atual = valor;
    b.variacao =(abs(b.v_atual - b.v_anterior)*100)/b.v_atual;
    return b;
}

void media_dp(bolsa b[], int tam){
    double media = 0;
    for(int i=0;i<tam;i++){
        media += b[i].v_atual;
    }
    media = media/tam;
    printf("media = %.2lf", media);
    double dp = 0;
    for(int i=0;i<tam;i++){
        dp += (b[i].v_atual - media)*(b[i].v_atual - media);
    }
    dp = sqrt(dp/(tam-1));
    printf("\ndesvio padrao: %.2lf");
}

bolsa preencherstruct(){
    bolsa b;
    printf("\nInsira o nome da empresa: ");
    scanf("%[^\n]s", &b.nome);

    printf("\nInsira a area de atuacao: ");
    scanf("%s", &b.atuacao);

    printf("\nInsira o valor atual: ");
    scanf("%lf", &b.v_atual);

    printf("Insira o valor anterior: ");
    scanf("%lf", &b.v_anterior);

    b.variacao =(abs(b.v_atual - b.v_anterior)*100)/b.v_atual;

    return b;
}

void imprimirstruct(bolsa b){
    printf("\nNome da empresa: %s", b.nome);
    printf("\nArea de atuacao: %s", b.atuacao);
    printf("\nValor atual da acao: %lf", b.v_atual);
    printf("\nValor anterior da acao: %lf", b.v_anterior);
    double j = abs(b.v_atual - b.v_anterior);
    int v = (j*100)/b.v_atual;
    printf("\nValor da variacao em porcentagem: %d", v);
}

double valoratual(bolsa b){
    return b.v_atual;
}

void i_abaixo(double v, bolsa b[], int tam){
    for(int i=0;i<tam; i++){
        if(valoratual(b[i])<v){
                printf("\nValores abaixo: ");
            imprimirstruct(b[i]);
        }
        else{

        }
    }
}
