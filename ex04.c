#include <stdio.h>

char mat[10][10];

int lin[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int valido(int l, int c) {
	if (0 <= l && l < 10 && 0 <= c && c < 5) {
		return 1;
	} else {
		return 0;
	}
}

void pintar(int l, int c) {
	mat[l][c] = '#';
	
	printf("------------------------------\n");
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("[%c]", mat[i][j]);
		}
		printf("\n");
	}
	
	for (int k = 0; k < 8; k++) {
		int novaLin = l + lin[k];
		int novaCol = c + col[k];
		
		if (valido(novaLin, novaCol) == 1 && mat[novaLin][novaCol] != '#') {
			pintar(novaLin, novaCol);
		}
	}
}

int main() {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			mat[i][j] = ' ';
		}
	}
	
	for (int i = 1; i < 6; i++) {
		mat[1][i] = '#';
	}
	
	for (int i = 1; i < 6; i++) {
		mat[i][1] = '#';
	}
	
	for (int i = 1; i < 6; i++) {
		mat[5][i] = '#';
	}
	
	for (int i = 1; i < 6; i++) {
		mat[i][5] = '#';
	}
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("[%c]", mat[i][j]);
		}
		printf("\n");
	}
	
	pintar(3, 3);
	
	printf("------------------------------\n");
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("[%c]", mat[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
