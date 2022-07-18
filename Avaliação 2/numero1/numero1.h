#ifndef NUMERO1_H_INCLUDED
#define NUMERO1_H_INCLUDED

typedef struct lst lista;

lista* criar_lst(int capacidade);
void exibir_lst(lista *l);
int inserir_fim_lst(lista *l, int valor);
int qtde_negativos_lst(lista *l);

#endif // NUMERO1_H_INCLUDED
