// Aula 5.0: Leitura, escrita e copia de buffer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcao() {
	int vetor1[10];
	int vetor2[10];
	int i = 0;
	for (i = 0; i < 10; i++) {
		vetor1[i] = i;
	}
	// Metodo lento de copiar um vetor
	for (i = 0; i < 10; i++) {
		vetor2[i] = vetor1[1];
	}
	// Metodo rapido de copiar um vetor
	memcpy(vetor2, vetor1, sizeof(int) * 10);
}

// Exemplo de como criar buffer
unsigned char *criar_buffer1(int id, float salario) {
	unsigned char *buffer = (unsigned char *) malloc(sizeof(int) + sizeof(float));
	memcpy(buffer, &id, sizeof(int));
	memcpy(buffer + sizeof(int), &salario, sizeof(float));
	return buffer;
}

// Exemplo de como criar buffer
unsigned char *criar_buffer2(int id, float salario) {
	unsigned char *buffer = (unsigned char *) malloc(sizeof(int) + sizeof(float));
	unsigned char *offset = buffer;

	memcpy(offset, &id, sizeof(int));
	offset = offset + sizeof(int);
	memcpy(offset, &salario, sizeof(float));

	return buffer;
}

// Exemplo de como ler buffer
void ler_buffer1(unsigned char *buffer) {
	int id;
	float salario;

	memcpy(&id, buffer, sizeof(int));
	memcpy(&salario, buffer + sizeof(int), sizeof(float));

	printf("\n%d", id);
	printf("\n%f", salario);
	free(buffer);
}

// Exemplo de como ler buffer
void ler_buffer2(unsigned char *buffer) {
	int id;
	float salario;

	memcpy(&id, buffer, sizeof(int));
	buffer = buffer + sizeof(int);
	memcpy(&salario, buffer, sizeof(float));

	printf("\n%d", id);
	printf("\n%f", salario);
	free(buffer);
}

// Exemplo de como ler buffer
void ler_buffer3(unsigned char *buffer) {
	unsigned char *buffer_copia;
	buffer_copia = (unsigned char *) malloc(sizeof(int) + sizeof(float));
	memcpy(buffer_copia, buffer, sizeof(int) + sizeof(float));

	printf("\n%d", *buffer_copia);
	printf("\n%f", *(buffer_copia + sizeof(int)));

	free(buffer);
}


int main() {

	unsigned char *buffer;

	buffer = criar_buffer2(10, 400);
	ler_buffer3(buffer);
	funcao();


	return 0;
}
