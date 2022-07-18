#ifndef NUMERO2_H_INCLUDED
#define NUMERO2_H_INCLUDED

typedef struct lst lista;

lista* criar_lst(int capacidade);
void exibir_lst(lista *l);
int inserir_fim_lst(lista *l, int valor);
int liberar_lst(lista **l);
int remover_fim_lst(lista *l, int *valor_removido);
int esta_vazia_lst(lista *l);

#endif // NUMERO1_H_INCLUDED