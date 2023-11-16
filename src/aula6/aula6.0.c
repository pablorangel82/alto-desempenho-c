// Aula 6.0: Exemplificação da estrutura de dados: lista.

#include <stdio.h>
#include <stdlib.h>

struct t_lista {
    int chave;
    struct t_lista *prox;
} typedef lista;

void inserir(lista **cabeca, int chave) {
	lista *no = (lista *) malloc(sizeof(lista));
	no->prox = NULL;
	no->chave = chave;
	if (*cabeca == NULL) { //O primeiro Nó
		*cabeca = no;
	} else { //Ou já existe outro nó
		lista *temp = *cabeca;
		while (temp->prox != NULL) {
			temp = temp->prox;
		}
		temp->prox = no;
	}
}

void imprimir(lista **cabeca) {
	lista *temp = *cabeca;

	while (temp != NULL) {
		printf("\n%d", temp->chave);
		temp = temp->prox;
	}

}

lista *buscar(lista **cabeca, int chave) {
	lista *temp = *cabeca;
	while (temp) {
		if (temp->chave == chave) {
			return temp;
		}
		temp = temp->prox;
	}
	return NULL;
}

int excluir(lista **cabeca, int chave) {
	lista *temp = *cabeca;
	lista *ant = NULL;
	while (temp != NULL) {
		if (temp->chave == chave) {
			if (ant != NULL) {
				ant->prox = temp->prox;
			} else { //Está removendo o primeiro elemento!
				*cabeca = temp->prox;
			}
			free(temp);
			temp = NULL;
			return 1;
		} else {
			ant = temp;
			temp = temp->prox;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	lista *cabeca;
	cabeca = NULL;
	inserir(&cabeca, 10);
	inserir(&cabeca, 20);
	inserir(&cabeca, 30);

	imprimir(&cabeca);

	excluir(&cabeca, 10);

	return EXIT_SUCCESS;
}