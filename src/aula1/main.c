// Aula 1: Tipos básicos e Passagem por valor

#include <stdio.h>

int xpto(int a) {
	a = 40;
	return a;
}

int main(int args, char *argv[]) {
	char letra = 'p';
	unsigned char idade = 19;
	unsigned int x = 10;
	long numero;
	float salario = 100.2f;
	double latitude = -22.17777777;

	int notas[5];
	notas[0] = 7;
	notas[4] = 8;

	char nome[10];
	nome[0] = 'P';
	nome[0] = 'A';
	nome[0] = 'B';
	nome[0] = 'L';
	nome[0] = 'O';
	nome[0] = '\0';

	printf("Nota: %d", notas[0]);
	printf("\nValor da variavel X: %d", x);
	printf("\nValor da variavel X como parametro na funcao xpto (passagem de valor): %d", xpto(x));
	return 0;
}
