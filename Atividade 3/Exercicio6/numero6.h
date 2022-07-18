#ifndef NUMERO6_H_INCLUDED
#define NUMERO6_H_INCLUDED

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct no no;
typedef struct lista lista;

lista* criar_lst();
static no* criar_no(int valor);
int inserir_fim_lst(lista* l, int valor);
int remover_fim_lst(lista* l);
void liberar_lst(lista **l);
int esta_vazia_lst(lista* l);
void exibir_lst(lista* l);
int topo(lista* l);


#endif // NUMERO6_H_INCLUDED
