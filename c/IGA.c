//Trabalho pratico realizado por: Maria Ines, Mariana Gomes,Lara Marques e Lucas Costa
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>

#define ROWS    6
#define COLS   7
#define FOUR   4

//funcao para gerar numeros aleatorios
int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}


//jogo numero 1
void adivinhaNumero(){
	
	int numeroGerado=0, numeroUtilizador, tentativas = 0, pontuacao = 0;
	
	numeroGerado = generateRandomInt(0, 100);
	//printf("(numero gerado: %d)\n", numeroGerado);
	printf("Explicacao do jogo: o utilizador deve introduzir numeros aleatoriamente ate descobrir o numero gerado pelo computador\n"); 
	printf("e o programa vai informar se o numero sugerido e maior ou menor que o número gerado aleatoriamente\n");
	
	while (numeroGerado != numeroUtilizador){
		printf("Introduza um numero! \n");
		scanf("%d", &numeroUtilizador);
		if(numeroUtilizador < numeroGerado){
			printf("Tente um numero mais alto \n");
			tentativas++;
		}else if(numeroUtilizador > numeroGerado){
			printf("Tente um numero mais baixo \n");
			tentativas++;
		}
	} 
	
	printf("Acertaste!\n");
	printf("Nº de tentativas: %d \n", tentativas);
	
	pontuacao = 10 - tentativas;
	if(pontuacao < 0){
		printf("Pontuação Final: 0 \n");
	}else{
		printf("Pontuação Final: %d \n", pontuacao);
	}
}



//jogo numero 2

void adivinhaCarta() {
        
		char naipeComputador[1], naipeUtilizador[1]; //carater naipe com 1 posição
        int numeroComputador;
        int numeroUtilizador, tentativas = 0, pontuacao = 0;

        //o sistema gera o numero da carta
        numeroComputador = generateRandomInt(1, 13);

        //array com os naipes: Ouro, espada, paus, copas
        char naipes[4] = {'O','E','P','C' };
		
        //o sistema seleciona uma posi��o do array
        int naipe = generateRandomInt(0, 3);

        //conforme a posicao gerada do array
        //printf("Naipe: int = %d; char = %c\n", naipe, naipes[naipe]);
       
        
        printf("numero da carta gerada: %d\n", numeroComputador);
		//printf("numero da naipe gerada: %c\n", naipeComputador);
        //printf("naipe gerado: %d\n", naipeUtilizador);
		printf("numero do naipe gerado: %c\n", naipes [naipe]);

       printf("Introduza um numero \n");
       scanf("%d", &numeroUtilizador);
		getchar(); //LER UMA TECLA E CONTINUA
		
       printf("Introduza um naipe\n");
       scanf("%s", naipeUtilizador);
	   
	   printf("naipe utilizador: %s\n", naipeUtilizador);

    //se tanto o numero como o naipe estiverem errados
        while (numeroUtilizador != numeroComputador && naipeUtilizador != naipeComputador){

			printf("numero e naipe errados\n");
		
            if (numeroUtilizador < numeroComputador) {
                printf("Tente um numero mais alto\n");
                printf("Tente outro naipe\n");
                tentativas++;
            }
            else if (numeroUtilizador > numeroComputador) {
                printf("Tente um numero mais baixo \n");
                printf("Tente outro naipe\n");
                tentativas++;
            }

            printf("Introduza um numero \n");
            scanf("%d", &numeroUtilizador);
			getchar();
            printf("Introduza um naipe\n");
            scanf("%s", naipeUtilizador);
			printf("naipe utilizador: %s\n", naipeUtilizador);

        }

        //se o numero estiver errado, mas o naipe estiver correto
        while (numeroUtilizador != numeroComputador && naipeUtilizador == naipeComputador) {
			
			printf("numero errado naipe correto\n");
			
		    if (numeroUtilizador < numeroComputador) {
                printf("Tente um numero mais alto\n");
                tentativas++;
            }
            else if (numeroUtilizador > numeroComputador) {
                printf("Tente um numero mais baixo \n");
                tentativas++;
            }
			
            printf("Introduza um numero \n");
            scanf("%d", &numeroUtilizador);
        }

        //se o naipe estiver errado, mas o numero estiver correto
        while (numeroUtilizador == numeroComputador && naipeUtilizador != naipeComputador) {
		
		printf("numero correto e naipe errado\n");
			
			getchar();
            printf("Introduza um naipe\n");
            scanf("%s", naipeUtilizador);
            tentativas++;
        }

        printf("Boa, acertaste!\n");

        printf("N� de tentativas: %d \n", tentativas);

        pontuacao = 6 - tentativas;
        if (pontuacao < 0) {
            printf("Pontua��o Final: 0 \n");
        }
        else {
            printf("Pontua��o Final: %d \n", pontuacao);
        }
    }


//jogo numero 3 (jogo vinte e um)
 
void VinteEUm() {
	 
char opjogo;								//Variáveis que armazenam as opções dos jogadores em relação ao jogo.
int jogada,totalj = 0,totalc = 0;	
int total1 = 0,total2 = 0;						//Variáveis da jogada atual e do total de pontos.
printf ("Bem Vindo ao Jogo do 21!!\n");
		
	if (opjogo == 0 ) {
	//Vez do usuário.
	opjogo='S';
	system("cls");
	printf("Instrucoes : O objetivo do jogo e fazer 21 pontos para ganhar, porem sem ultrapassar esse limite, podendo parar após cada jogada.\n");
	printf("\n");
	totalj=0;
		while ((opjogo=='s') || (opjogo=='S')) {	//Laço que deixa as jogadas a critério do usuário.
			printf("Deseja fazer a jogada?[S/N]\n");
			scanf(" %c",&opjogo);
		if ((opjogo=='n') || (opjogo=='N'))
			break;		
		
		srand(time(NULL));	//inicializar o gerador de números aleatórios com o valor da função time (NULL)		
		jogada=(rand() % 10)+1;       //Gera números aleatórios de 1 até 10.
		totalj=(totalj+jogada);
		if (totalj >= 21)
			break;
			printf("\n");
			printf("Você tirou %d e até agora marcou %d pontos.\n",jogada,totalj);
			printf("\n");
				}
		printf("Você marcou %d pontos, vamos ver o computador...\n",totalj);
		//Vez do Computador
		printf("Agora é minha vez de jogar. Vejo que você fez %d pontos...\n",totalj);
		totalc=0;
		while (totalc < 21) {
		srand(time(NULL));				
			jogada=(rand() % 10)+1;    //Gera números aleatórios de 1 até 10.
			totalc=(totalc+jogada);
				if(totalc>=21) 
				break;
			printf("Tirei %d pontos e pretendo continuar jogando, pois ainda estou com %d.\n",jogada,totalc);
			usleep(1200000);    //paragem, o valor em milisegundos
			 }
			 printf("\n");
			printf("O jogador terminou com %d pontos e o computador com %d pontos, portanto...",totalj,totalc);
				if (totalj == 21) 
				printf("O jogador ganhou, fazendo os gloriosos 21 pontos =D...\n"); 
			else if (totalc == 21) 
				printf("O computador ganhou, fazendo os gloriosos 21 pontos =D...\n");
			else if (totalc > 21 && totalj <= 21) 
				printf("O computador tem um número maior de pontos do que é permitido...O jogador vence.\n");	
			else if (totalj > 21 && totalc <= 21) 
				printf("O jogador tem um número maior de pontos do que é permitido...O computador vence.\n");
			else if ((21 - totalc)>(21 - totalj)) 
				printf("O computador vence por estar mais perto de 21.\n");
			else
				printf("O jogador vence por estar mais perto de 21.\n");
			printf("\n");
			}
		
}	 


char matriz[3][3];

char verifica()
{
    int i;

    for (i = 0; i < 3; i++){ // verifica as linhas
        if (matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) return matriz[i][0];
        else if (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) return matriz[0][i]; 
       	else if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) return matriz[0][0];
        else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) return matriz[0][2];
    	else if (matriz[0][0] != ' ' && matriz[0][1] != ' ' && matriz[0][2] != ' ' && 
    			 matriz[1][0] != ' ' && matriz[1][1] != ' ' && matriz[1][2] != ' ' && 
    			 matriz[2][0] != ' ' && matriz[2][1] != ' ' && matriz[2][2] != ' ')
    			 return 'v';
   	}
   	return ' ';
}

void inicio()
{
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) matriz[i][j] = ' ';
}

void mostra_matriz()
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("                                     %c | %c | %c ", matriz[i][0], matriz[i][1], matriz[i][2]);
        if (i != 2)
            printf("\n                                    ---|---|---\n");
    }
    printf("\n\n\n");
}

void jogador1()
{
    int x, y;
    printf("\nVez do jogador 1 (input : x y) -> X: \n");
    putchar('\n');
    scanf("%d %d", &x, &y);
    x--;
    y--;

    if (matriz[x][y] != ' ')
    {
        printf("\n\nPosicao invalida, tenta novamente!! \n\n");
        sleep(2);
        system("cls");
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
    }
    else matriz[x][y] = 'X';
}

void jogador2()
{

    mostra_matriz();
    int x, y;

    printf("\nVez do jogador 2 (input : x y) -> O: \n");
    putchar('\n');
    scanf("%d %d", &x, &y);
    x--;
    y--;

    if (matriz[x][y] != ' ')
    {
        printf("\n\nPosicao invalida, tenta novamente!! \n\n");
        sleep(2);
        system("cls");
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        jogador2();
    }
    else matriz[x][y] = 'O';
}

void jogadorCOM()
{
    int x, y;
    x = generateRandomInt(1,3);
    y = generateRandomInt(1,3);
    mostra_matriz();
   

    putchar('\n');

    if (matriz[x][y] != ' ')
    {
        sleep(2);
        system("cls");
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        jogadorCOM();
    }
    else matriz[x][y] = 'O';
}

char * rooster2P(){ // main funtion for 2 players

	
    char fim;
    char * result = malloc(sizeof(char)*5);

    fim = ' ';
    inicio();
    do
    {

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
        fim = verifica();
        system("cls");
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");

        if (fim != ' ')  break;
        jogador2();
        fim = verifica();
        system("cls");

    } while (fim == ' ');

    if (fim == 'X')
    {
    	mostra_matriz();
        printf("\n                         ###   JOGADOR 1 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win1");
    }
    else if (fim == 'O')
    {
    	printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        printf("\n                         ###   JOGADOR 2 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win2");
    }
    else
    {
       	mostra_matriz();
        printf("\n                         ###   EMPATE!!!   ###\n");
        putchar('\n');
        strcpy(result,"draw");
            
    }
    
    // "win1" == player 1 wins "win2" == player 2 wins 
    return result;
}

char * rooster(){ // main function

	char fim;
    char * result = malloc(sizeof(char)*5);

    fim = ' ';
    inicio();
    do
    {

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        jogador1();
        fim = verifica();
        system("cls");

        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");

        if (fim != ' ') break;
        jogadorCOM();
        fim = verifica();
        system("cls");

    } while (fim == ' ');

    if (fim == 'X')
    {
        mostra_matriz();
        printf("\n                         ###   JOGADOR 1 GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win1");
    }
    else if (fim == 'O')
    {
        printf("                         ###  J O G O   D O   G A L O  ###\n\n\n");
        mostra_matriz();
        printf("\n                         ###   COMPUTADOR GANHOU!!!   ###\n");
        putchar('\n');
        strcpy(result,"win2");
    }
    else
    {
        mostra_matriz();
        printf("\n                         ###   EMPATE!!!   ###\n");
        putchar('\n');
        strcpy(result,"draw");
            
    }

    return result;
}



// jogo numero 6 (jogo da forca)  

void JogoForca(int errado){
	 
	 if(errado==0){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==1){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==2){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|          |");
	   printf("\n|");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==3){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|         -|");
	   printf("\n|           ");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==4){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|         -|-");
	   printf("\n|           ");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==5){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|         -|-");
	   printf("\n|         /  ");
	   printf("\n|");
	   printf("\n|");
	   printf("\n-");
	 } else if(errado==6){
	   printf("\n------------");
	   printf("\n|          |");
	   printf("\n|          0");
	   printf("\n|         -|-");
	   printf("\n|         / \\ ");
	   printf("\n|");
	   printf("\n|    Perdeu o jogo!");
	   printf("\n-");
	 }
   }
   void limpa_tela(){
	 for(int i=0;i<30;i++){
	   printf("\n");            //LIMPA TELA COM 30 ENTERS
	 }
   }


   int mainForca(void) {
	 char * palavrasecreta;
	 printf("Introduza a palavra para o jogador seguinte advinhar\n");
	 getchar();
	 scanf(" %s", palavrasecreta);
	 printf("Palavra secreta: %s\n", palavrasecreta);
	 printf("A palavra tem %lu caracteres", strlen(palavrasecreta));  //QUANTO CARATERES TEM
	 limpa_tela();

	 //retira o ultimo caracter de p_sec que esta a mais devido a captura ser com fgets()
	 //palavrasecreta[strlen(palavrasecreta)-1]='\0';
	 char p_tela[100];//palavra para tela
	 strcpy(p_tela, palavrasecreta);//copia de p_sec
	 //substitui letras por '_'
	 for(int i=0;i<strlen(p_tela);i++){
	   p_tela[i]='_';
	 }

	 int erros = 0;
	 while(1){
	   //imprimir a forca
	   limpa_tela();
	   JogoForca(erros);
	   //imprimir os underline/underscores '_' para cada letra da palavra secreta, ou seja, imprimir p_tela
	   printf("\nAdivinhe: ");
	   for(int i=0;i<strlen(p_tela);i++){
		 printf(" %c ", p_tela[i]);
	   }
	   //recebe a letra
	   printf("\nLetra: ");
	   char letra;
	   scanf(" %c", &letra);//o espa�o antes do % � por conta do repl.it usado via web...
	   //se letra correta atualiza palavra na tela
	   //verifica se a letra esta correta
	   int sera_que_errou=1;//1=sim 0=nao
	   for(int i=0;i<strlen(p_tela); i++){
		 if(letra==palavrasecreta[i]){//certo
		   p_tela[i]=letra;
		   sera_que_errou=0;
		 }
	   }
	   //senao, incrementa erros
	   if(sera_que_errou==1){
		 erros++;
	   }
	   //verifica se o jogo acabou
	   //verifica se ganhou
	   //verifica se p_sec � igual a p_tela
	   if(!strcmp(p_tela,palavrasecreta)){
		 //ENTAO ganhou
		 printf("\nAcertou: ");
		 for(int i=0;i<strlen(p_tela);i++){
		   printf("%c ", p_tela[i]);
		 }
		 printf("\nVenceu! Parabens!!!");
		 break;
	   }
	   //verifica se perdeu
	   if(erros==6){
		 //perdeu
		 JogoForca(erros);
		 break;
	   }
	 }
   }

                   
char tabuleiro[6][7];


void inicia_tabuleiro()
{
    int x, y;

    for (x = 0; x < 6; x++)
        for (y = 0; y < 7; y++)
            tabuleiro[x][y] = ' ';
}

void mostra_tabuleiro()
{
    int x;
    printf("    | 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("    |---|---|---|---|---|---|---|\n");
    for (x = 1; x < 6; x++) {
        printf("    | %c | %c | %c | %c | %c | %c | %c |\n", tabuleiro[x][0], tabuleiro[x][1], tabuleiro[x][2], tabuleiro[x][3], tabuleiro[x][4], tabuleiro[x][5], tabuleiro[x][6]);
        if (x != 0)
            printf("    |---|---|---|---|---|---|---|\n");
    }
    printf("\n");
}

void print_jogada(int n){
	printf("Jogada %d\n", n);
}

void jogada_Player(int jog)
{
    int x, y, z, w, a, b, c, d, e;

    z = 6;
    w = 6;
    a = 6;
    b = 6;
    c = 6;
    d = 6;
    e = 6;


    for (x = 1; x <= 6; x++) {
        if (tabuleiro[x][0] != ' ') z--;
        if (tabuleiro[x][1] != ' ') w--;
        if (tabuleiro[x][2] != ' ') a--;
        if (tabuleiro[x][3] != ' ') b--;
        if (tabuleiro[x][4] != ' ') c--;
        if (tabuleiro[x][5] != ' ') d--;
        if (tabuleiro[x][6] != ' ') e--;
    }
    
    printf("Selecione a coluna pretendida: ");
    scanf("%d", &y);
    putchar('\n');


    if (y == 1) {
        if (jog == 1) tabuleiro[z][0] = 'X'; else tabuleiro[z][0] = 'O';
    }
    else if (y == 2) {
        if (jog == 1) tabuleiro[w][1] = 'X'; else tabuleiro[w][1] = 'O';
    }
    else if (y == 3) {
        if (jog == 1) tabuleiro[a][2] = 'X'; else tabuleiro[a][2] = 'O';
    }
    else if (y == 4) {
        if (jog == 1) tabuleiro[b][3] = 'X'; else tabuleiro[b][3] = 'O';
    }
    else if (y == 5) {
        if (jog == 1) tabuleiro[c][4] = 'X'; else tabuleiro[c][4] = 'O';
    }
    else if (y == 6) {
        if (jog == 1) tabuleiro[d][5] = 'X'; else tabuleiro[d][5] = 'O';
    }
    else if (y == 7) {
        if (jog == 1) tabuleiro[e][6] = 'X'; else tabuleiro[e][6] = 'O';
    }

    // check if play is valid
    if (z<1 && y == 1) {
        printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (w<1 && y == 2){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (a<1 && y == 3){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (b<1 && y == 4){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (c<1 && y == 5){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (d<1 && y == 6){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    } else if (e<1 && y == 7){
    	printf("Jogada invalida!\n");
        putchar('\n');
        jogada_Player(jog);
    }

    if (y < 1 || y>7) {
        printf("Jogada Invalida, tente novamente.\n");
        putchar('\n');
        jogada_Player(jog);
    }

}

void jogada_COM(int jog)
{	
	int z, w, a, b, c, d, e;

    z = 6;
    w = 6;
    a = 6;
    b = 6;
    c = 6;
    d = 6;
    e = 6;

    int play = generateRandomInt(1,7);

    for (int x = 1; x <= 6; x++) {
        if (tabuleiro[x][0] != ' ') z--;
        if (tabuleiro[x][1] != ' ') w--;
        if (tabuleiro[x][2] != ' ') a--;
        if (tabuleiro[x][3] != ' ') b--;
        if (tabuleiro[x][4] != ' ') c--;
        if (tabuleiro[x][5] != ' ') d--;
        if (tabuleiro[x][6] != ' ') e--;
    }

    if (play == 1) tabuleiro[z][play-1] = 'O';
    else if (play == 2) tabuleiro[w][play-1] = 'O';
    else if (play == 3) tabuleiro[a][play-1] = 'O';
    else if (play == 4) tabuleiro[b][play-1] = 'O';
    else if (play == 5) tabuleiro[c][play-1] = 'O';
    else if (play == 6) tabuleiro[d][play-1] = 'O';
    else if (play == 7) tabuleiro[e][play-1] = 'O';
    
    if (z<1 && play == 1) jogada_COM(jog);
    else if (w<1 && play == 2) jogada_COM(jog);
    else if (a<1 && play == 3) jogada_COM(jog);
    else if (b<1 && play == 4) jogada_COM(jog);
    else if (c<1 && play == 5) jogada_COM(jog);
    else if (d<1 && play == 6) jogada_COM(jog);
    else if (e<1 && play == 7) jogada_COM(jog);

    if (play < 1 || play > 7) jogada_COM(jog);

}


char fim_jogo(int n)                                //objectivo: avaliar se o jogo acabou (4emlinha empate) ou nao
{
    int i;
    int j;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {                                   //testar 4 em linha linhas
            if (tabuleiro[i][j] == tabuleiro[i][j + 1] && tabuleiro[i][j + 2] == tabuleiro[i][j + 3] && tabuleiro[i][j] == tabuleiro[i][j + 3] && tabuleiro[i][j] != ' ')
                return tabuleiro[i][j];
        }
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) {                                   //testar 4 em linha nas colunas
            if (tabuleiro[j][i] == tabuleiro[j + 1][i] && tabuleiro[j + 2][i] == tabuleiro[j + 3][i] && tabuleiro[j][i] == tabuleiro[j + 2][i] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {                                   //testar 4 em linha diagonais1 começar em cima
            if (tabuleiro[j][i] == tabuleiro[j + 1][i + 1] && tabuleiro[j + 2][i + 2] == tabuleiro[j + 3][i + 3] && tabuleiro[j][i] == tabuleiro[j + 2][i + 2] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 5; j > 2; j--) {                                   //testar 4 em linha diagonais2 começar em baixo
            if (tabuleiro[j][i] == tabuleiro[j - 1][i + 1] && tabuleiro[j - 2][i + 2] == tabuleiro[j - 3][i + 3] && tabuleiro[j][i] == tabuleiro[j - 2][i + 2] && tabuleiro[j][i] != ' ')
                return tabuleiro[j][i];
        }
    }


    if (n == 42) return 'E';

    return ' ';

}


char * finaliza(int tipo, char venc)
{
    char * result = NULL;
	if (tipo == 1){
		if (venc == 'X'){
			printf("O jogador 1 ganhou, parabéns!!\n");
			putchar('\n');
			result = "win";
		} else if (venc == 'O'){
			sleep(1);
			printf("O jogador 2 ganhou, parabéns!!\n");
			putchar('\n');
			result = "loose";
		} else if (venc == 'E'){
			sleep(1);
			printf("O jogo terminou empatado!!\n");
			putchar('\n');
			result = "draw";
		}

	} else if (tipo == 2){

		if (venc == 'X'){
			printf("O jogador 1 ganhou, parabéns!!\n");
			putchar('\n');
			result = "win";
		} else if (venc == 'O'){
			printf("O computador ganhou, mais sorte para a próxima!!\n");
			putchar('\n');
			result = "loose";
		} else if (venc == 'E'){
			printf("O jogo terminou empatado!!\n");
			putchar('\n');
			result = "draw";
		}
	}

	return result;

}

char * fourline2P(){ // main function for 2 players


	char fim;
	char * result = NULL;
    int n = 0, jog;
    int tipo = 1;

    fim = ' '; jog = 1;
    inicia_tabuleiro();

     if (tipo == 1) {
    	
    	}

    do {
    	system("cls");
    	++n;
    	putchar('\n');
    	print_jogada(n);
    	putchar('\n');
        mostra_tabuleiro();
        if (jog == 1){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 2;
    		system("cls");
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 1;

    	} else if (jog == 2){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 1;
    		system("cls");
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 2;
    	}

        fim = fim_jogo(n);
    } while (fim == ' ');

    result = finaliza(tipo, fim);

    return result;
}


char * fourline(){ // main function

		char fim;
	char * result = NULL;
    int n = 0, jog;
    int tipo = 1;

    fim = ' '; jog = 1;
    inicia_tabuleiro();

     if (tipo == 1) {
    	
    	}

    do {
    	system("cls");
    	++n;
    	putchar('\n');
    	print_jogada(n);
    	putchar('\n');
        mostra_tabuleiro();
        if (jog == 1){
    		jogada_Player(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 2;
    		system("cls");
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_COM(jog);
    		jog = 1;

    	} else if (jog == 2){
    		jogada_COM(jog);
    		fim = fim_jogo(n);
    		if (fim != ' ') break;
    		jog = 1;
    		system("cls");
    		++n;
    		putchar('\n');
    		print_jogada(n);
    		putchar('\n');
    		mostra_tabuleiro();
    		jogada_Player(jog);
    		jog = 2;
    	}

        fim = fim_jogo(n);
    } while (fim == ' ');

    result = finaliza(tipo, fim);

    return result;
}


//menu para selecionar os jogos
void selecionarJogo(){
	
	int jogoSelecionado;
	
	do{
		
		printf("Selecione um dos jogos abaixo! \n");
		printf("Prima 1: Adivinha o numero \n");
		printf("Prima 2: Adivinha a carta \n");
		printf("Prima 3: Vinte-e-um \n");
		printf("Prima 4: Jogo do Galo (para dois) \n");
		printf("Prima 5: Jogo do Galo vs CPU \n");
		printf("Prima 6: Jogo da Forca \n");
		printf("Prima 7: Quatro-em-linha \n");
		printf("Prima 8: Quatro-em-linha vs CPU \n");	
		printf("Prima 9: Voltar ao menu principal \n");
		scanf("%d", &jogoSelecionado);
		system("cls");
		
		switch(jogoSelecionado){
			case 1:
				adivinhaNumero();
				break;
			case 2:
				adivinhaCarta();
				break;
			case 3:
				VinteEUm();
				break;
			case 4:
				rooster2P();
				break;
			case 5:
				rooster();
				break;
			case 6:
				mainForca();
				break;
			case 7:
				fourline2P();
				break;
			case 8:
				fourline();
				break;
			case 9:
				break;
			default:
				printf("Opção inválida!");
		}
	}while(0 < jogoSelecionado && jogoSelecionado < 9);
}


//menu principal
void main(){
	
	int option;

	do{
		system("cls");
		printf("Bem-vindo ao IGA! \n");
	
		printf("Escolha uma das seguintes opcoes: \n");
		printf("Prima 1: Selecionar um jogo\n");
		printf("Prima 2: Visualizar os seus pontos or jogo e pontos globais\n");
		printf("Prima 3: Visualizar a tabela de pontos dos 10 melhores jogadores de cada jogo\n");
		printf("Prima 4: Visualizar a tabela de pontos global dos 10 melhores jogadores.\n");
		printf("Prima 5: Introduzir dados de 2 jogadores.\n");
		printf("Prima 6: Sair do IGA\n");
	
		scanf("%d", &option);
		system("cls");
		
			switch(option){
			case 1:
				selecionarJogo();
				break;
			/*case 2:
				visualizarPontos();
				break;
			case 3:
				dezMelhoresJogadores();
				break;
			case 4:
				pontosGlobaisMelhoresJOgadores();
				break;
			case 5:
				introduzirDados();
				break;*/
			case 6:
				printf("Obrigado por jogar!\n");
				break;
			default:
				printf("Opção inválida!");
			}
	} while(option < 0 && option > 7);

}
	