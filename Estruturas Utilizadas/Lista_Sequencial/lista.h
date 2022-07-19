#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct lista lista;

int buscar_lst(lista *l, int valor);
int capacidade_lst(lista *l);
lista* criar_lst(int capacidade); // lista* criar(void);
int esta_vazia_lst(lista *l);
int esta_cheia_lst(lista *l);
void exibir_lst(lista *l);
int inserir_inicio_lst(lista *l, int valor);
int inserir_meio_lst(lista *l, int valor, int pos);
int inserir_fim_lst(lista *l, int valor);
void liberar_lst(lista **l);
int remover_inicio_lst(lista *l, int *valor_removido);
int remover_meio_lst(lista *l, int *valor_removido, int pos);
int remover_fim_lst(lista *l, int *valor_removido);
int tamanho_lst(lista *l);

#endif // LISTA