#ifndef NUMERO3_H_INCLUDED
#define NUMERO3_H_INCLUDED

typedef struct c celula;
typedef struct lista lista;


lista* criar_lst();
static celula* criar_no(int valor);
void oposto_lst(lista *l);
int inserir_fim_lst(lista* l, int valor);
void exibir_lst(lista* l);

#endif // NUMERO1_H_INCLUDED