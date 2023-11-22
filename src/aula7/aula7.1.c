#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define TAM 5

pthread_mutex_t mutex;

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
    f->qtd++;
    return 1;
}

int desenfileirar (fila *f, int *valor){
    if (f->qtd == 0){
        return 0;
    }
    *valor = f->elementos [f->frente];
    f->frente = f->frente == TAM-1? 0 : f->frente +1;
    f->qtd--;
    return 1;
}

void * produzir(void *arg){
    fila *f = (fila *) arg;
    int i=0;
    while (1){
        pthread_mutex_lock(&mutex);
        int ret = enfileirar(f,i);
        pthread_mutex_unlock(&mutex);
        if (ret){
            i = i== 1000?0:i+1;
        }else{
            printf("\nFila Cheia");
        }

    }
    pthread_exit(arg);
}

void * consumir(void *arg) {
    fila *f = (fila *) arg;
    int valor;
    while (1) {
        pthread_mutex_lock(&mutex);
        int ret = desenfileirar(f, &valor);
        pthread_mutex_unlock(&mutex);
        if (ret){
            printf("\n%i", valor);
        }else{
            printf("\nFila Vazia");
        }

    }
    pthread_exit(arg);
}

int main (int argc, char *argv[]){
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread_id_consumidor;
    pthread_t thread_id_produtor;
    void * thread_res;
    int status;
    fila *f = (fila *) malloc(sizeof (fila));
    f->frente=0;
    f->tras = 0;
    f->qtd = 0;
    pthread_create (&thread_id_consumidor, NULL, consumir, (void*)f);
    pthread_create (&thread_id_produtor, NULL, produzir, (void*)f);
    pthread_join (thread_id_consumidor, &thread_res);
    pthread_mutex_destroy(&mutex);
    return 0;
}

