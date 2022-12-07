#include <stdio.h>

void mover() {
	int linOrig, colOrig, linDest, colDest;

	printf("Entre com a linha e coluna: ");
	scanf("%d %d", &linOrig, &colOrig);
	
	if (0 <= linOrig && linOrig < 25 && 0 <= colOrig && colOrig <= 50) {
		switch(tanque[linOrig][colOrig]) {
			case '-':
				break;
			case 'x':
				break;
			case 'X':
				break;
			default:
				break;
		}

		printf("Entre com a linha e coluna: ");
		scanf("%d %d", &linDest, &colDest);

		if (0 <= linDest && linDest < 25 && 0 <= colDest && colDest <= 50) {
			
		}
	}
}

int main() {

	return 0;
}
