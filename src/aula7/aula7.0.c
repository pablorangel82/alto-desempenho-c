#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * rotina(void *arg){
    while(1){
        printf("%s\n", (char *)arg);
        sleep(10);
    }
    pthread_exit(arg);
}

int main (int argc, char *argv[]){
    pthread_t thread_id_1;
    pthread_t thread_id_2;
    void * thread_res1;
    void * thread_res2;
    int status1,status2;

    status1 = pthread_create (&thread_id_1, NULL, rotina, (void*)("Thread A"));

    if(status1 != 0){
        printf ("Erro ao criar thread.\n");
        exit(EXIT_FAILURE);
    }
    //printf ("Thread criada com sucesso!\n");
    //status = pthread_join (thread_id, &thread_res);
    //printf ("Thread finalizada = %s\n", (char *)thread_res1);

    status2 = pthread_create (&thread_id_2, NULL, rotina, (void*)("Thread B"));
    if(status2 != 0){
        printf ("Erro ao criar thread.\n");
        exit(EXIT_FAILURE);
    }
    //printf ("Thread criada com sucesso!\n");
    status2 = pthread_join (thread_id_2, &thread_res2);
    //printf ("Thread finalizada = %s\n", (char *)thread_res);


    return 0;
}

