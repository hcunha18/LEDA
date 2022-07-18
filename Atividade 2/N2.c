#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tam 20

struct data{
    int dia;
    int mes;
    int ano;
};

struct horario{
    int hora;
    int minuto;
    int segundo;
};

typedef struct horario horario;
typedef struct data data;

struct compromisso{
    char nome[50];
    char texto[200];
    data d_compromisso;
    horario h_compromisso;
};

typedef struct compromisso compromisso;

horario inserir_horario();
data inserir_data();
compromisso inserir_compromisso();
void imprimir_compromisso(compromisso c);
void imprimir_data(data d);
compromisso inicializar_valeatorio();
data inicializar_d_aleatorio();
horario inicializar_h_aleatorio();


void main(){
    printf("========Lista Compromisso========");
    compromisso c[tam];
    printf("\nPREENCHER VETOR");
    for(int i=0; i<tam; i++){
        c[i] = inicializar_valeatorio();
    }

    printf("\n\nINFORMACOES");

    for(int i=0; i<tam; i++){
        printf("\n posicao %d\n", i+1);
        imprimir_compromisso(c[i]);
    }

}

horario inicializar_h_aleatorio(){
    horario h;
    h.hora = rand() %23;
    h.minuto = rand() %59;
    h.segundo = rand() %59;
    return h;
}

data inicializar_d_aleatorio(){
    data d;
    d.dia = rand() %19 + 1;
    d.mes = rand() %11 + 1;
    d.ano = rand() %3 + 2016;
    return d;
}

compromisso inicializar_valeatorio(){
    compromisso c;
    strcpy(c.nome, "aleatorio");
    strcpy(c.texto, "Compromisso de teste gerado aleatoriamente");
    c.d_compromisso = inicializar_d_aleatorio();
    c.h_compromisso = inicializar_h_aleatorio();
    return c;
}

horario inserir_horario(){
    horario h;
    printf("\nDigite a hora: ");
    scanf("%d", &h.hora);
    if(h.hora<0 || h.hora>23){
        printf("hora invalida");
    }
    printf("\nDigite o minuto: ");
    scanf("%d", &h.minuto);
    if(h.minuto<0 || h.minuto>59){
        printf("\nMinuto invalido");
    }
    printf("\nDigete o segundo: ");
    scanf("%d", &h.segundo);
    if(h.segundo<0 || h.segundo>59){
        printf("\nSegundo invalido");
    }
    return h;
}

data inserir_data(){
    data d;
    printf("\nDigite o dia: ");
    scanf("%d", &d.dia);
    if(d.dia<0 || d.dia>31){
        printf("\nDia invalido");
    }
    printf("\nDigite o mes: ");
    scanf("%d", &d.mes);
    if(d.mes<0 || d.mes>12){
        printf("\nMes invalido");
    }
    printf("\nDigete o ano: ");
    scanf("%d", &d.ano);
    if(d.ano<2021){
        printf("\nAno invalido");
    }
    return d;
}

compromisso inserir_compromisso(){
    compromisso c;
    printf("\nNome do Compromisso:");
    scanf("%s", &c.nome);
    fflush(stdin);
    printf("\nDescricao do Compromisso: ");
    scanf("%[^\n]s", &c.texto);
    c.d_compromisso = inserir_data();
    c.h_compromisso = inserir_horario();
    return c;
}

void imprimir_data(data d){
    printf("\nData: %d/%d/%d", d.dia, d.mes, d.ano);
}

void imprimir_hora(horario h){
    printf("\nHorario: %d:%d:%d", h.hora, h.minuto, h.segundo);
}

void imprimir_compromisso(compromisso c){
    printf("Compromisso %s:", c.nome);
    imprimir_data(c.d_compromisso);
    imprimir_hora(c.h_compromisso);
    printf("\nTexto: %s", c.texto);
}
