// Aula 3.0: Introducao a ponteiro (passagem por referencia) e vetor

#include <stdio.h>

void imprimirItensVetor(int *vetor, int tamanhoVetor) {
	int item = 0;
	for (item = 0; item < tamanhoVetor; item++) {
		printf("%d", vetor[item]);
		vetor[item] = tamanhoVetor - item; // Invertendo o vetor
	}
}

void alterar(int *x) {
	*x = 10;
}

int main() {
	int vetor[5] = {1, 2, 3, 4, 5};
	int tamanhoVetor = 5;

	printf("Vetor na ordem crescente: ");
	imprimirItensVetor(vetor, tamanhoVetor);

	printf("\nVetor invertido: ");
	imprimirItensVetor(vetor, tamanhoVetor);

	int a;
	int *b;
	int c = 20;
	b = &a;
	*b = 20; // a = 20
	*b = c; // a = c

	alterar(&tamanhoVetor);
	printf("\nTamanho do vetor apos a funcao alterar: %d", tamanhoVetor);

	return 0;
}