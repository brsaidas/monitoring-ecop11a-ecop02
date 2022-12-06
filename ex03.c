#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int lin[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int valido(int l, int c) {
	if (0 <= l && l < 10 && 0 <= c && c < 5) {
		return 1;
	} else {
		return 0;
	}
}

void filtroSuave(int mat[][5][3]) {
	int vermelho = 0, verde = 0, azul = 0;
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 8; k++) {
				int novaLin = i + lin[k];
				int novaCol = j + col[k];
				
				if (valido(novaLin, novaCol) == 1) {
					vermelho += mat[novaLin][novaCol][0];
					verde += mat[novaLin][novaCol][1];
					azul += mat[novaLin][novaCol][2];
				}
			}
		
			mat[i][j][0] = vermelho / 9;
			mat[i][j][1] = verde / 9;
			mat[i][j][2] = azul / 9;
		}
	}
}

int main() {	
	srand(time(NULL));

	// Criando a matriz que representa uma imagem
	int img[10][5][3];
		
	// Gerando valores aleatórios
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 3; k++) {
				img[i][j][k] = rand() % 10;
			}
		}
	}
	
	filtroSuave(img);
	
	/*
		0 -> RED
		1 -> GREEN
		2 -> BLUE
	*/
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 5; j++) {
			printf("[(%d)(%d)(%d)]", img[i][j][0], img[i][j][1], img[i][j][2]);
		}
		printf("\n");
	}
	
	return 0;
}
