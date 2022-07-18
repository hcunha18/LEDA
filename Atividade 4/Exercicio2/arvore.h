#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct no no;
typedef struct arv arvore;

int adicionar_no_arv(arvore* a, int valor);
arvore* criar_arv(int valor_raiz);
no* criar_no(int valor);
void pre_ordem_arv(no *n);
no* get_raiz_arv(arvore* a);
int qtd_folhas(no *raiz);

#endif // ARVORE_H_INCLUDED
