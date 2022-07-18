#ifndef NUMERO4_H_INCLUDED
#define NUMERO4_H_INCLUDED

typedef struct lista lista;

lista* criar_lc(int capacidade);
int inserir_fim_lc(lista* l, int e);
int esta_cheia_lc(lista* l);
void exibir_lc(lista* l);
int tamanho_lc(lista* l);
int esta_vazia_lc(lista* l);
int capacidade_lc(lista *l);
void dobrar_par(lista *l);
int remover_inicio_lc(lista* l, int *v);

#endif // NUMERO4_H_INCLUDED