#include <stdio.h>
#define TAM 5

struct t_pilha{
    int v[TAM];
    int topo;
}typedef pilha;

int qtd_espaco (pilha *p){
    return 5 - (p->topo+1);
}

int qtd_elementos(pilha *p){
    return p->topo+1;
}

int pilha_cheia(pilha *p){
    if (p->topo == TAM-1){
        return 1;
    }
    return 0;
}

int pilha_vazia(pilha *p){
    if (p->topo == -1){
        return 1;
    }
    return 0;
}

int empilhar(pilha *p, int valor){
    if (pilha_cheia(p)){
        return 0;
    }
    p->topo++;
    p->v[p->topo] = valor;
    return 1;
}

int desempilhar(pilha *p, int *valor){
    if (pilha_vazia(p)){
        return 0;
    }
    *valor = p->v[p->topo];
    p->topo--;
    return 1;
}

int main(int argc, char** argv) {
    pilha p;
    p.topo=-1;
    empilhar (&p,10);
    empilhar (&p,20);
    empilhar (&p,30);
    empilhar (&p,40);
    empilhar (&p,50);
    empilhar (&p,60);
    return 0;
}
