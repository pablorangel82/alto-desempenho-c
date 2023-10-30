// Aula 4.0: Diferencas entre armazenar dados na stack e no heap

#include <stdio.h>
#include <stdlib.h>

int imprimir(int *vetor, int tamanho) {
    int item = 0;
    for (item = 0; item < tamanho; ++item) {
        printf("%d", vetor[item]);
    }
}

int * retornar_memoria() {
    int a = 10;
    return &a;
}

int main() {
    unsigned char *area_heap;

    int vetor[5] = {1, 2, 3, 4, 5};

    area_heap = (unsigned char*) malloc(sizeof(int) * 2);
    *area_heap = 1;
    *(area_heap + 4) = 80;

    printf("Item na quarta posicao do vetor: %d", *(vetor + 4));
    printf("\nItem na segunda posicao do vetor: %d", *(vetor + 1));
    printf("\nEndereco de memoria do segundo item do vetor: %p", (vetor + 1));
    printf("\n%d", *(retornar_memoria()));

    free(area_heap);

	return 0;
}
