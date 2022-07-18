#ifndef NUMERO1_H_INCLUDED
#define NUMERO1_H_INCLUDED

typedef struct lista lista;
#define ERRO -1
#define FALSO 0
#define VERDADEIRO 1

lista* criar_lst(int capacidade);
int buscar_qtde_lst(lista *l, int valor);
int inserir_lst(lista *l, int valor);
void exibir_lst(lista *l);


#endif // NUMERO1_H_INCLUDED
