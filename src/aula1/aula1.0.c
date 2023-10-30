// Aula 1: Tipos basicos e passagem por valor

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
	nome[1] = 'A';
	nome[2] = 'B';
	nome[3] = 'L';
	nome[4] = 'O';
	nome[5] = '\0';

	printf("\nNota: %d", notas[0]);
	printf("\nValor da variavel X: %d", x);
	printf("\nValor da variavel X como parametro na funcao xpto (passagem de valor): %d", xpto(x));
	printf("\nNome: %s", nome);

	return 0;
}
