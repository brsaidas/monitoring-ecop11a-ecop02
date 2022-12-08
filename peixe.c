#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{false, true} bool;

int larva=0;
int alga=1;
int sais=1;
int jogadas=1;
char tanque[25][50];

int lin[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void inicializa(){
    int i, j, lin, col;
    //espaço
    for(i=0;i<25;i++){
        for(j=0;j<50;j++){
            tanque[i][j]=' ';
        }
    }
    //areia triangulo 1-3
    for(i=0;i<3;i++){
        lin=rand()%(25-1);
        col=rand()%(50-2);
        tanque[lin][col+1]=':';
        tanque[lin+1][col]=':';
        tanque[lin+1][col+1]=':';
        tanque[lin+1][col+2]=':';
    }
    //areia triangulo 1-3-5
    for(i=0;i<2;i++){
        lin=rand()%(25-2);
        col=rand()%(50-4);
        tanque[lin][col+2]=':';
        tanque[lin+1][col+1]=':';
        tanque[lin+1][col+2]=':';
        tanque[lin+1][col+3]=':';
        tanque[lin+2][col]=':';
        tanque[lin+2][col+1]=':';
        tanque[lin+2][col+2]=':';
        tanque[lin+2][col+3]=':';
        tanque[lin+2][col+4]=':';
    }
    //10 conchas
    for(i=0;i<10;i++){
        lin=rand()%25;
        col=rand()%50;
        if(tanque[lin][col]==' '){
            tanque[lin][col]='@';
        }else{
            i--;
        }
    }
    //5 broto algas
    for(i=0;i<5;i++){
        lin=rand()%25;
        col=rand()%50;
        if(tanque[lin][col]==' '){
            tanque[lin][col]='y';
        }else{
            i--;
        }
    }
    //3 peixes jovens
    for(i=0;i<3;i++){
        lin=rand()%25;
        col=rand()%50;
        if(tanque[lin][col]==' '){
            tanque[lin][col]='x';
        }else{
            i--;
        }
    }
}

void imprime(){
    int i,j;
    printf("              1111111111222222222233333333334444444444\n");
    printf("    01234567890123456789012345678901234567890123456789\n");
    for(i=0;i<25;i++){
        printf("[%2d]", i);
        for(j=0;j<50;j++){
            printf("%c", tanque[i][j]);
        }
        printf("\n");
    }
}

void cultivar(){
    int lin, col;
    if(alga>0){
        printf("cultivar alga [linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(tanque[lin][col]==' '){
               tanque[lin][col]='y';
               alga--;
               jogadas++;
            }else{
                printf("coordenada não esta vazia");
            }
        }else{
            printf("coordenadas invalidas");
        }
    }else{
        printf("sem saldo de alga\n");
    }
}

void fertilizar(){
    int lin, col;
    if(sais>0){
        printf("fertilizar alga [linha coluna]:");
        scanf("%d %d", &lin, &col);
        getchar();//captura enter
        if((lin>=0)&&(lin<=24)&&(col>=0)&&(col<=49)){
            if(tanque[lin][col]=='y'){
               tanque[lin][col]='Y';
               sais--;
               jogadas++;
            }else{
                printf("coordenada não tem broto alga");
            }
        }else{
            printf("coordenadas invalidas");
        }
    }else{
        printf("sem saldo de sais\n");
    }
}

bool valido(int l, int c) {
	if (0 <= l && l < 10 && 0 <= c && c < 5) {
		return true;
	} else {
		return false;
	}
}

void mover() {
	int linOrig, colOrig, linDest, colDest;

	printf("Entre com a linha e coluna origem: ");
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

		printf("Entre com a linha e coluna destino: ");
		scanf("%d %d", &linDest, &colDest);

		if (0 <= linDest && linDest < 25 && 0 <= colDest && colDest <= 50) {
			int bandeira = false;
			
			for (int k = 0; k < 8; k++) {
				int novaLin = linOrig + lin[k];
				int novaCol = colOrig + col[k];
				
				if (valido(novaLin, novaCol) == 1 && novaLin == linDest && novaCol == colDest) {
					bandeira = true;
					break;
				}
			}
			
			if (bandeira == true) {
				if (tanque[linDest][colDest] == ' ') {
					tanque[linDest][colDest] = tanque[linOrig][colOrig];
					tanque[linOrig][colOrig] = ' ';
					jogadas++;
				} else if (tanque[linDest][colDest] == ':' || tanque[linDest][colDest] == '@') {
					tanque[linOrig][colOrig] = ' ';
					jogadas++;
				} else if (tanque[linOrig][colOrig] == 'X' && tanque[linDest][colDest] == 'x') {
					if (larva > 0) {
						larva--;
						tanque[linOrig][colOrig] = '-';
						jogadas++;
					} else {
						printf("Sem saldo de larva");
					}
				} else if (tanque[linDest][colDest] == 'y' || tanque[linDest][colDest] == 'Y') {
					if (tanque[linOrig][colOrig] == '-') {
						tanque[linDest][colDest] = 'x';
					} else if (tanque[linOrig][colOrig] == 'x') {
						tanque[linDest][colDest] = 'X';
					} else if (tanque[linOrig][colOrig] == 'X') {
						tanque[linDest][colDest] = 'X';
					}
					tanque[linOrig][colOrig] = ' ';
				}
			} else {
				printf("Nao e uma das 8 posicoes vizinhas");
			}
		} else {
			printf("Destino invalido");
		}
	} else {
		printf("Origen invalida");
	}
}

int main( int argc, char * arv[]){
    char op=' ';
    srand(time(NULL));
    //funcao inicializa
    inicializa();
    while(op != 's'){
        //funcao imprime
        imprime();
        printf("larva=%d alga=%d sais=%d\n", larva, alga, sais);
        printf("(c)ultivar / (f)ertilizar / (m)over / (q)uebrar / (p)escar / (n)oite / (s)air");
        printf("[Jogada %d] opcao:", jogadas);
        op = getchar();
        printf("%c\n", op);
        switch(op){
            case 'c' : //cultivar
                cultivar();
                break;
            case 'f' : //fertilizar
                fertilizar();
                break;
            case 'm': //e
                mover();
                break;
            case 'q' : //f
                break;
            case 'p' : //g
                break;
            case 'n' : //h
                break;
            case 's' :
                break;
            default:
                printf("[opcao invalida]\n");
				break;
        }
        if(jogadas > 7){
            //b+h
        }
    }
    return 0;
}
