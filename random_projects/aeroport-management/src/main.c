#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/modules/avioes.h"
#include "includes/modules/aeroporto.h"
#include "includes/modules/voo.h"
#include "includes/modules/ticket.h"

#include "includes/btree.h"
#include "includes/grafos.h"
#include "includes/parser.h"
#include "includes/parsing.h"
#include "includes/define.h"

void delete_line(int delete_line, char * filename){
	FILE *fileptr1, *fileptr2;
    char ch;
    int temp = 1;

    //open file in read mode
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
   	while (ch != EOF){
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    //rewind
    rewind(fileptr1);
    //open new file in write mode
    fileptr2 = fopen("replica.csv", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.csv", filename);
    fileptr1 = fopen(filename, "r");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
}

void print_f5(char * ap, char * ac, int opt, int N, int matriz[N][N]){

	char ** flight = get_choices(ap, ac, opt, N, matriz);

	btree * tree = btree_organizer();
 
	int ocu_lugares, lugares, num_voos, num_1, num_2, num_3, num_4; int * num_flights = malloc(sizeof(int)*4);
	float  t_espera, t_voo, t_total, costs;
	char * flights = NULL; char ** horarios = malloc(sizeof(char*)*8); 
	char * aviao = NULL; char * aviao2 = NULL; char * aviao3 = NULL; char * aviao4 = NULL;

	switch(opt){

		case 0: // output para voo mais barato

			num_voos = get_len_pointer(flight);

			if (num_voos != 1) print_f5(ap,ac,num_voos,N,matriz);
			else print_f5(ap,ac,num_voos,N,matriz);

			break;

		case 1: // output para voo mais rápido

			for(int a = 0;a<2;a++){
				strcpy(flights,flight[a]);

				VOOS vs = create_voo();
				set_voo(vs, flights);

				num_flights[0] = get_num_voo(vs);
				num_flights[1] = 0;
				num_flights[2] = 0;
				num_flights[3] = 0;

				ocu_lugares = id_wanted2(tree,num_flights[0]);
				horarios[0] = get_data_partida(vs);
				horarios[1] = get_data_chegada(vs);
				horarios[2] = "";
				horarios[3] = "";
				horarios[4] = "";
				horarios[5] = "";
				horarios[6] = "";
				horarios[7] = "";

				AVIOES as = create_aviao();
				aviao = get_aviao_voo(vs);
				set_aviao(as, aviao);
				lugares = get_num_lugares(as);
				delete_aviao(as);

				delete_voo(vs);
			}

			t_espera = 0;
			t_voo = horas(num_flights[0]);
			t_total = t_espera + t_voo;

			costs = cost(ocu_lugares, t_voo, distancia(num_flights[0]));

			break;

		case 2:	// output para viagem com 2 escalas

			num_1 = directly_connected_num(flight[0],flight[1]);
			num_2 = directly_connected_num(flight[1],flight[2]);

			num_flights[0] = num_1;
			num_flights[1] = num_2;
			num_flights[2] = 0;
			num_flights[3] = 0;

			ocu_lugares = id_wanted2(tree,num_1) + id_wanted2(tree,num_2);
			horarios[0] = get_data_partida_num(num_1);
			horarios[1] = get_data_chegada_num(num_1);
			horarios[2] = get_data_partida_num(num_2);
			horarios[3] = get_data_chegada_num(num_2);
			horarios[4] = "";
			horarios[5] = "";
			horarios[6] = "";
			horarios[7] = "";

			AVIOES as1 = create_aviao();
			AVIOES as2 = create_aviao();
			aviao = get_aviao_nvoo(num_1);
			aviao2 = get_aviao_nvoo(num_2);
			set_aviao(as1, aviao);
			set_aviao(as2, aviao2);
			lugares = get_num_lugares(as1) + get_num_lugares(as2);
			delete_aviao(as1);
			delete_aviao(as2);

			t_espera = date_compare(horarios[1],horarios[2]);
			t_voo = horas(num_1) + horas(num_2);
			t_total = t_espera + t_voo;

			costs = cost(ocu_lugares, t_voo, distancia(num_1) + distancia(num_2));

			break;

		case 3: // output para viagem com 3 escalas

			num_1 = directly_connected_num(flight[0],flight[1]);
			num_2 = directly_connected_num(flight[1],flight[2]);
			num_3 = directly_connected_num(flight[2],flight[3]);

			num_flights[0] = num_1;
			num_flights[1] = num_2;
			num_flights[2] = num_3;
			num_flights[3] = 0;

			ocu_lugares = id_wanted2(tree,num_1) + id_wanted2(tree,num_2) + id_wanted2(tree,num_3);
			horarios[0] = get_data_partida_num(num_1);
			horarios[1] = get_data_chegada_num(num_1);
			horarios[2] = get_data_partida_num(num_2);
			horarios[3] = get_data_chegada_num(num_2);
			horarios[4] = get_data_partida_num(num_3);
			horarios[5] = get_data_chegada_num(num_3);
			horarios[6] = "";
			horarios[7] = "";

			
			as1 = create_aviao();
			as2 = create_aviao();
			AVIOES as3 = create_aviao();
			aviao = get_aviao_nvoo(num_1);
			aviao2 = get_aviao_nvoo(num_2);
			aviao3 = get_aviao_nvoo(num_3);
			set_aviao(as1, aviao);
			set_aviao(as2, aviao2);
			set_aviao(as3, aviao3);
			lugares = get_num_lugares(as1) + get_num_lugares(as2) + get_num_lugares(as3);
			delete_aviao(as1);
			delete_aviao(as2);
			delete_aviao(as3);

			t_espera = date_compare(horarios[1],horarios[2]) + date_compare(horarios[3],horarios[4]);
			t_voo = horas(num_1) + horas(num_2) + horas(num_3);
			t_total = t_espera + t_voo;

			costs = cost(ocu_lugares, t_voo, distancia(num_1) + distancia(num_2) + distancia(num_3));

			break;

		case 4: // output para viagem com 4 escalas

			num_1 = directly_connected_num(flight[0],flight[1]);
			num_2 = directly_connected_num(flight[1],flight[2]);
			num_3 = directly_connected_num(flight[2],flight[3]);
			num_4 = directly_connected_num(flight[3],flight[4]);

			num_flights[0] = num_1;
			num_flights[1] = num_2;
			num_flights[2] = num_3;
			num_flights[3] = num_4;

			ocu_lugares = id_wanted2(tree,num_1) + id_wanted2(tree,num_2) + id_wanted2(tree,num_3) + id_wanted2(tree,num_4);
			horarios[0] = get_data_partida_num(num_1);
			horarios[1] = get_data_chegada_num(num_1);
			horarios[2] = get_data_partida_num(num_2);
			horarios[3] = get_data_chegada_num(num_2);
			horarios[4] = get_data_partida_num(num_3);
			horarios[5] = get_data_chegada_num(num_3);
			horarios[6] = get_data_partida_num(num_4);
			horarios[7] = get_data_chegada_num(num_4);

			as1 = create_aviao();
			as2 = create_aviao();
			as3 = create_aviao();
			AVIOES as4 = create_aviao();
			aviao = get_aviao_nvoo(num_1);
			aviao2 = get_aviao_nvoo(num_2);
			aviao3 = get_aviao_nvoo(num_3);
			aviao4 = get_aviao_nvoo(num_4);
			set_aviao(as1, aviao);
			set_aviao(as2, aviao2);
			set_aviao(as3, aviao3);
			set_aviao(as4, aviao4);
			lugares = get_num_lugares(as1) + get_num_lugares(as2) + get_num_lugares(as3) + get_num_lugares(as4);
			delete_aviao(as1);
			delete_aviao(as2);
			delete_aviao(as3);
			delete_aviao(as4);

			t_espera = date_compare(horarios[1],horarios[2]) + date_compare(horarios[3],horarios[4])  + date_compare(horarios[5],horarios[6]);
			t_voo = horas(num_1) + horas(num_2) + horas(num_3) + horas(num_4);
			t_total = t_espera + t_voo;

			costs = cost(ocu_lugares, t_voo, distancia(num_1) + distancia(num_2) + distancia(num_3) + distancia(num_4));

			break;

	}
	if(t_total>72) printf("impossivel com tantas escalas");
	else{
		printf("numero lugares ocupados (total) / numero lugares do(s) voo(s) (total) => %d/%d\n", ocu_lugares, lugares);
		printf("tempo de espera entre voo(s) (total) => %.2f h\n", t_espera);
		printf("tempo total do(s) voo(s) => %.2f h\n", t_voo);
		printf("tempo total entre partida e chegada => %.2f h\n", t_total);
		printf("voo(s) a apanhar => %s\n", flights);
		printf("numero do(s) voo(s) a apanhar => %d %d %d %d\n", num_flights[0], num_flights[1], num_flights[2], num_flights[3]);
		printf("horarios do(s) voo(s) => partida: %s chegada: %s partida: %s chegada: %s partida: %s chegada: %s partida: %s chegada: %s\n", horarios[0], horarios[1], horarios[2], horarios[3] ,horarios[4], horarios[5], horarios[6], horarios[7]);
		printf("custo total de todas as viagens para a(s) franquia(s) => %.2f €\n", costs);
	}
}

int info(int f1){

	int f1_1;
	printf("O que deseja?\n");
	printf("Aviao : 1\n");
	printf("Aeroporto : 2\n");
	printf("Voo: 3\n");
	printf("Bilhete : 4\n");
	scanf("%d", &f1_1);
	return f1_1;

}

void insert_f1(int f1_1){

	char * cod_registo = NULL; char * marca = NULL; char * modelo = NULL;
	int num_lugares;
	float velocidade_cruzeiro, consumo_medio;

	char * cod_IATA = NULL; char * nome = NULL; char * cidade = NULL;
	int altitude;

	int num_voo;
	char * data_partida = NULL; char * data_chegada = NULL; 
	char * aeroport_partida = NULL;  char * aeroport_chegada = NULL; 
	char * aviao_voo = NULL;

	char * nome_passageiro = NULL; char * voo_ticket = NULL; char * lugar = NULL;
	int nif;
	float preco; float distancia;

	switch(f1_1){		

		case 1: // aviao

			printf("Insere codigo de registo: ");
			scanf("%s", cod_registo);
			putchar('\n');
			printf("Insere marca: ");
			scanf("%s", marca);
			putchar('\n');
			printf("Insere modelo: ");
			scanf("%s", modelo);
			putchar('\n');
			printf("Insere numero de lugares: ");
			scanf("%d", &num_lugares);
			putchar('\n');
			printf("Insere velocidade de cruzeiro: ");
			scanf("%f", &velocidade_cruzeiro);
			putchar('\n');
			printf("Insere consumo medio: ");
			scanf("%f", &consumo_medio);
			putchar('\n');

			FILE * p = fopen(PLANE,"w");
			fprintf(p, "%s;%s;%s;%d;%.2f;%.2f\n", cod_registo, marca, modelo, num_lugares, velocidade_cruzeiro, consumo_medio);
			fclose(p);

			break;

		case 2: // aeroporto

			printf("Insere codigo IATA: ");
			scanf("%s", cod_IATA);
			putchar('\n');
			printf("Insere nome: ");
			scanf("%s", nome);
			putchar('\n');
			printf("Insere cidade: ");
			scanf("%s", cidade);
			putchar('\n');
			printf("Insere altitude: ");
			scanf("%d", &altitude);
			putchar('\n');

			FILE * a = fopen(AERO,"w");
			fprintf(a, "%s;%s;%s;%d\n", cod_IATA, nome, cidade, altitude);
			fclose(a);

			break;

		case 3: // voo

			printf("Insere numero de voo: ");
			scanf("%d", &num_voo);
			putchar('\n');
			printf("Insere data de partida: ");
			scanf("%s", data_partida);
			putchar('\n');
			printf("Insere data de chegada: ");
			scanf("%s", data_chegada);
			putchar('\n');
			printf("Insere aeroporto de partida: ");
			scanf("%s", aeroport_partida);
			putchar('\n');
			printf("Insere aeroporto de chegada: ");
			scanf("%s", aeroport_chegada);
			putchar('\n');
			printf("Insere aviao: ");
			scanf("%s", aviao_voo);
			putchar('\n');

			FILE * v = fopen(FLIGHT,"w");
			fprintf(v, "%d;%s;%s;%s;%s;%s\n", num_voo, data_partida, data_chegada, aeroport_partida, aeroport_chegada, aviao_voo);
			fclose(v);

			break;

		case 4: // bilhete

			printf("Insere nome do passageiro: ");
			scanf("%s", nome_passageiro);
			putchar('\n');
			printf("Insere nif: ");
			scanf("%d", &nif);
			putchar('\n');
			printf("Insere voo: ");
			scanf("%s", voo_ticket);
			putchar('\n');
			printf("Insere lugar: ");
			scanf("%s", lugar);
			putchar('\n');
			printf("Insere preco: ");
			scanf("%f", &preco);
			putchar('\n');
			printf("Insere distancia: ");
			scanf("%f", &distancia);
			putchar('\n');

			FILE * t = fopen(TICKET,"w");
			fprintf(t, "%s;%d;%s;%s;%.2f;%.2f\n", nome_passageiro, nif, voo_ticket, lugar, preco, distancia);
			fclose(t);

			break;

	}

}

void remove_f1(int f1_1){
	int nif, num_voo, i = 0;
	char line[LINE_BUFFER]; char * iata = NULL; char * registo = NULL;
	switch(f1_1){
		case 1:

			printf("Qual o codigo de registo?\n");
			scanf("%s", registo);

			FILE * av = fopen(PLANE, "r");
			while(fgets(line,LINE_BUFFER,av)!=NULL){
				AVIOES a = create_aviao();
				set_aviao(a,line);
				if(strcmp(get_cod_registo(a),registo) == 0){
					delete_line(i,PLANE);
					delete_aviao(a);
					break;
				}
				i++;
				delete_aviao(a);
			}
			fclose(av);

			break;

		case 2:
			printf("Qual o codigo IATA?\n");
			scanf("%s", iata);

			FILE * a = fopen(AERO, "r");
			while(fgets(line,LINE_BUFFER,a)!=NULL){
				AEROPORTO as = create_aeroporto();
				set_aeroporto(as,line);
				if(strcmp(get_cod_IATA(as),iata) == 0){
					delete_line(i,AERO);
					delete_aeroporto(as);
					break;
				}
				i++;
				delete_aeroporto(as);
			}
			fclose(a);

			break;

		case 3:
			printf("Qual o numero de voo?\n");
			scanf("%d", &num_voo);

			FILE * f = fopen(FLIGHT, "r");
			while(fgets(line,LINE_BUFFER,f)!=NULL){
				VOOS vs = create_voo();
				set_voo(vs,line);
				if(get_num_voo(vs) == num_voo){
					delete_line(i,FLIGHT);
					delete_voo(vs);
					break;
				}
				i++;
				delete_voo(vs);
			}
			fclose(f);

			break;

		case 4:
			printf("Qual o nif do bilhete que pretende remover do sistema?\n");
			scanf("%d", &nif);

			FILE * t = fopen(TICKET, "r");
			while(fgets(line,LINE_BUFFER,t)!=NULL){
				BILHETES bs = create_ticket();
				set_ticket(bs,line);
				if(get_nif(bs) == nif){
					delete_line(i,TICKET);
					delete_ticket(bs);
					break;
				}
				i++;
				delete_ticket(bs);
			}
			fclose(t);

			break;
	}

}

int main(){

	btree * vs = btree_organizer();
	
	int funcionalidade, opt, f1, f1_1, num_voo, opts;
	int N = aeroportos();
	int matriz[N][N];
	char * ap = NULL; char * ac = NULL;

	for (int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			matriz[i][j] = 0;
		}
	}
	
	printf("Que funcionalidade? 1, 4 ou 5?\n");
	scanf("%d",&funcionalidade);
	putchar('\n');

	switch(funcionalidade){

		case 1 :
			printf("O que deseja fazer?\n");
			printf("Inserir : 1\n");
			printf("Remover : 2\n");
			scanf("%d", &f1);
			putchar('\n');

			switch(f1){

				case 1 :
					f1_1 = info(f1);
					insert_f1(f1_1);
					break;
					
				case 2 :
					f1_1 = info(f1);
					remove_f1(f1_1);
					break;
			}
			
			break;

		case 4 :
			printf("Insira seu numero de voo: ");
			scanf("%d",&num_voo);
			putchar('\n');
			opts = another_num_voo(num_voo, vs);
			printf("Seu voo de opção será %d\n", opts);


			break;
		case 5 :
			printf("Partida : \n");
			scanf("%s", ap);
			printf("Destino : \n");
			scanf("%s", ac);
			putchar('\n');

			printf("Tipo de viagem : \n");
			printf("Voo mais barato : 0\n");
			printf("Voo mais rápido : 1\n");
			printf("2 escalas : 2\n");
			printf("3 escalas : 3\n");
			printf("4 escalas : 4\n");
			scanf("%d", &opt);
			putchar('\n');

			print_f5(ap, ac, opt, N, matriz);
			break;
	}
		

	return 0;
}