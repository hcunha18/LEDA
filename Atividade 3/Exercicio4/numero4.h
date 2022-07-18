#ifndef NUMERO4_H_INCLUDED
#define NUMERO4_H_INCLUDED

typedef struct no no;
typedef struct lista lista;
#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

lista* criar_lst();
static no* criar_no(int valor);
void exibir_lst(lista* l);
int inserir_fim_lst(lista* l, int valor);
void trocar_valor(lista* l);

#endif // NUMERO4_H_INCLUDED
