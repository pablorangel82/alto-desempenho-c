#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *rotina(void *arg) {
	while (1) {
		printf("%s\n", (char *) arg);
		sleep(10);
	}
	pthread_exit(arg);
}

int main(int argc, char *argv[]) {
	pthread_t thread_id;
	void *thread_res;
	int status;

	status = pthread_create(&thread_id, NULL, rotina, (void *) ("Thread A"));

	if (status != 0) {
		printf("Erro ao criar thread.\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread criada com sucesso!\n");
	status = pthread_join(thread_id, &thread_res);
	printf("Thread finalizada = %s\n", (char *) thread_res);

	status = pthread_create(&thread_id, NULL, rotina, (void *) ("Thread B"));
	if (status != 0) {
		printf("Erro ao criar thread.\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread criada com sucesso!\n");
	status = pthread_join(thread_id, &thread_res);
	printf("Thread finalizada = %s\n", (char *) thread_res);


	return 0;
}
