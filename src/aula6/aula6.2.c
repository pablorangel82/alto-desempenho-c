#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct t_fila{
    int elementos [TAM];
    int frente;
    int tras;
    int qtd;
}typedef fila;

int enfileirar(fila *f, int valor){
    if (f->qtd == TAM){
        return 0;
    }
    f->elementos [f->tras]=valor;
    f->tras = f->tras == TAM-1? 0 : f->tras +1;
    //f->tras++;
    f->qtd++;
    return 1;
}

int desenfileirar (fila *f){
    if (f->qtd == 0){
        return 0;
    }
    int valor = f->elementos [f->frente];
    f->frente = f->frente == TAM-1? 0 : f->frente +1;
    //f->frente++;
    f->qtd--;
    return valor;
}

int main(int argc, char** argv) {
    fila f;
    f.frente = 0;
    f.tras = 0;
    f.qtd=0;

    enfileirar (&f, 10);
    enfileirar (&f, 20);
    enfileirar (&f, 30);
    enfileirar (&f, 40);
    enfileirar (&f, 50);
    enfileirar (&f, 60);
    return 0;
}
