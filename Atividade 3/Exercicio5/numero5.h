#ifndef NUMERO5_H_INCLUDED
#define NUMERO5_H_INCLUDED

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct lista lista;

lista* criar_lista(int capacidade);
int inserir_lc(lista* l, int e);
int esta_cheia_lc(lista* l);
int esta_vazia_lc(lista* l);
int tamanho_lc(lista* l);
void exibir_lc(lista* l);
void exibir_n_vezes_lc(lista* l, int n);


#endif // NUMERO5_H_INCLUDED
