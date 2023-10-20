/* Aula 2.0: Problema das lampadas
    Temos 8 lampadas, cada uma representada por um bit (0000 0000);
    Todas elas são armazenadas na variavel: unsigned char lampadas;
    A primeira lampada é representada pelo bit mais a esquerda e a ultima pelo bit mais a direita;
    Quando ligada a lampada recebe o valor 1, quando desligada recebe o valor 0;
*/

#include <stdio.h>

int ligar(unsigned char lampada, unsigned char lampadas) {
	lampadas = (1 << (8 - lampada)) | lampadas;
	return lampadas;
}

int desligar(unsigned char lampada, unsigned char lampadas) {
	lampadas = (1 << (8 - lampada)) & lampadas;
	return lampadas;
}

int main() {
	unsigned char lampadas = 0;

	lampadas = ligar(1, lampadas); // 1000 0000
	lampadas = ligar(2, lampadas); // 1100 0000
	printf("\nLampadas: %d", lampadas); // saida: 192
	lampadas = desligar(1, lampadas); // 1000 0000
	printf("\nLampadas: %d", lampadas); // saida: 128

	return 0;
}