#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//letra a
struct ponto {
    double x, y;
};

typedef struct ponto Ponto;

//letra b
struct retangulo{
    Ponto *sup_esq, *inf_dir;
};

typedef struct retangulo Retangulo;

//letra c
double distancia (Ponto *p1, Ponto *p2){
    double dist;

    dist = sqrt (((p2->x - p1->x) * (p2->x - p1->x)) + ((p2->y - p1->y) * (p2->y - p1->y)));
    return dist;
}

//letra d
Ponto maisProximoOrigem (Ponto *vet, int tam){
    Ponto mais_proximo, origem={0.0, 0.0};
    double dist_atual, menor_distancia=99999.99;

    for (int i=0; i<tam; i++){
        dist_atual = distancia(&vet[i], &origem);
        if(dist_atual < menor_distancia){
            menor_distancia = dist_atual;
            mais_proximo = vet[i];
        }
    }
    return mais_proximo;
}

//letra e
int estaContido (Ponto *p, Retangulo *r){
    if((r->sup_esq->x < p->x && p->x < r->inf_dir->x) && (r->inf_dir->y < p->y && p->y < r->sup_esq->y)){
        return 1;
    }

    return 0;
}

//letra f
int main(){
    int tam=5, i;
    
	//Criando o Retângulo
    Retangulo *r = (Retangulo*) calloc(1, sizeof(Retangulo));
	//Criando o ponto inferior direito do retângulo
    r->inf_dir = (Ponto*) calloc(1, sizeof(Ponto));
    r->inf_dir->x = 19.0;
    r->inf_dir->y = -8.0;
    //Criando o ponto Superior esquerdo do retângulo
	r->sup_esq = (Ponto*) calloc(1, sizeof(Ponto));
    r->sup_esq->x = -6.0;
    r->sup_esq->y = 24.0;

    Ponto pontos[tam];
    
    srand(time(NULL));
	
	//Cria os pontos
    for (i=0; i<tam; i++){
        
        pontos[i].x = (rand() % 50)-15;
        pontos[i].y = (rand() % 50)-15;
        printf("\nPonto %d: (%.2lf, %.2lf)", i+1, pontos[i].x, pontos[i].y);
    }

	//Encontra o ponto mais próximo da origem
    Ponto mais_proximo = maisProximoOrigem(pontos, tam);
    printf("\nPonto mais proximo da origem: (%.2lf, %.2lf)", mais_proximo.x, mais_proximo.y);

	
	//Encontra o ponto mais distante
    Ponto *mais_distante, origem={0.0, 0.0};
    double maior_dist=0.0, dist_atual;

    for (i=0; i<tam; i++){
        dist_atual = distancia (&pontos[i], &origem);
        if(dist_atual>maior_dist){
            maior_dist = dist_atual;
            mais_distante = &pontos[i];
        }
    }

    printf("\n\nPonto mais distante da origem: (%.2lf, %.2lf)", mais_distante->x, mais_distante->y);
 
	//Apresenta se os pontos estão contidos no retângulo
    for (i=0; i<tam; i++){
        if (estaContido(&pontos[i], r)){
            printf("\n\nPonto (%.2lf, %.2lf) esta contido no retangulo!", pontos[i].x, pontos[i].y);
        }else{
            printf("\n\nPonto (%.2lf, %.2lf) NAO esta contido no retangulo!", pontos[i].x, pontos[i].y);
        }
        
    }
 
    return 0;
}