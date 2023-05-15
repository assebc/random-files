#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/medico.h"
#include "../include/utente.h"

int main() {
    int opcao;
	Medico* listaMedicos = NULL;
    Utente* listaUtentes = NULL;
    int codigoMedico = 0, codMedico = 0; // inicializa o contador de codigos de utentes
    int codigoUtente=0, codUtente  = 0; //// inicializa o contador de codigos de utentes
    int len = 0, size = 0;
    Utente *t;
    while (1) {
    	menu_principal:
    	printf("*** Centro de Saude ***\n\n");
        printf("Selecione uma opcao:\n");
        printf("1. Gerir utentes\n");
        printf("2. Gerir medicos\n");
        printf("3. Gerir consultas\n");
        printf("4. Importar/Exportar dados\n\n");
        printf("0. Sair\n\n");
        printf("Opcao:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                while (1) {
                	
                    printf("*** Gerir Utentes ***\n\n");
                    printf("Selecione uma opcao:\n\n");
                    printf("1. Inserir Utente\n");
                    printf("2. Editar Utente\n");
                    printf("3. Consultar Utente\n");
                    printf("4. Remover Utente\n");
                    printf("5. Listar Utentes\n\n");
                    printf("6. Voltar ao Menu Principal\n");
                    printf("0. Sair\n\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1:
                            inserirUtente(&listaUtentes, &codigoUtente);
                            break;
                        case 2:
                            editarUtente(listaUtentes);
                            break;
                        case 3:
                            printf("Insira o codigo do utente que deseja consultar: ");
                            scanf("%d", &codUtente);
                            consultarUtente(listaUtentes, codUtente);
                            break;
                        case 4:
                            printf("Insira o codigo do utente que deseja remover: ");
                            scanf("%d", &codUtente);
                            removerUtente(&listaUtentes, codUtente);
                            break;
                        case 5:
                            listarUtentes(listaUtentes);
                            break;
                        case 6:
                            goto menu_principal;
                        case 0:
			                printf("Ate a proxima!\n");
			                exit(0);
			                break;
                        default:
                            printf("Opcao invalida. Por favor, tente novamente.\n");
                    }
                }
                break;
            case 2:
                while (1) {

                	
                    printf("*** Gerir Medicos ***\n\n");
                    printf("Selecione uma opcao:\n\n");
                    printf("1. Inserir Medico\n");
                    printf("2. Editar Medico\n");
                    printf("3. Consultar Medico\n");
                    printf("4. Remover Medico\n");
                    printf("5. Listar Medicos\n\n");
                    printf("6. Voltar ao Menu Principal\n");
                    printf("0. Sair\n\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1:
                            inserirMedico(&listaMedicos, &codigoMedico);
                            break;
                        case 2:
                            editarMedico(listaMedicos);
                            break;
                        case 3:
                            printf("Insira o codigo do medico que deseja consultar: ");
                            scanf("%d", &codMedico);
                            consultarMedico(listaMedicos, codMedico);
                            break;
                        case 4:
                            printf("Insira o codigo do medico que deseja remover: ");
                            scanf("%d", &codMedico);
                            removerMedico(&listaMedicos, codMedico);
                            break;
                        case 5:
                            listarMedicos(listaMedicos);
                            break;
                        case 6:
                            goto menu_principal;
                        case 0:
			                printf("Ate a proxima!\n");
			                exit(0);
			                break;
                        default:
                            printf("Opcao invalida. Por favor, tente novamente.\n");
                    }
                }
                break;
            case 3:
                while (1) {

                	
                    printf("*** Gerir Consultas ***\n\n");
                    printf("Selecione uma opcao:\n\n");
                    printf("1. Registar Entrada de Utente\n");
                    printf("2. Retirar Proximo Utente de um Medico\n");
                    printf("3. Listar Utentes de um Medico\n");
                    printf("4. Numero de Utentes em Espera de um Medico\n");
                    printf("5. Medico com Mais Utentes em Espera\n");
                    printf("6. Listar Todos os Utentes Ordenados por Medico\n\n");
                    printf("7. Voltar ao Menu Principal\n");                    
                    printf("0. Sair\n\n");
                    printf("\n	Opcao: ");
                    scanf("%d", &opcao);
                    
                    
                    switch (opcao) {
                        case 1:
                            printf("Insira o codigo do utente que deseja registar a entrada: ");
                            scanf("%d", &codUtente);
                            t = consultarUtente(listaUtentes,codUtente);
                            inserirFilaEspera(listaMedicos,t->codigoMedico,*t);
                            break;
                        case 2:
                            printf("Insira o codigo do medico: ");
                            scanf("%d", &codMedico);
                            proximoFila(listaMedicos, codMedico);
                            break;
                        case 3:
                            printf("Insira o codigo do medico que deseja consultar: ");
                            scanf("%d", &codMedico);
                            listarUtentes(consultarMedico(listaMedicos, codMedico)->fila_espera);
                            break;
                        case 4:
                            printf("Insira o codigo do medico que deseja consultar: ");
                            scanf("%d", &codMedico);
                            printf("Fila tem %d utentes\n", tamanhoFila(listaMedicos, codMedico));
                            break;
                        case 5:
                            while(listaMedicos->prox!=NULL){
                                size = tamanhoFila(listaMedicos, listaMedicos->codigoMedico);
                                if(len < size) len = size;
                                listaMedicos = listaMedicos->prox;
                            }
                            printf("Maior fila tem %d utentes\n", len);
                            break;
                        case 6: // nao é bem isto mas pronto
                            while(listaMedicos!=NULL){
                                listarUtentes(listaMedicos->fila_espera);
                                listaMedicos = listaMedicos->prox;
                            }
                            break;
                        case 7:
                            goto menu_principal;
                        case 0:
			                printf("Ate a proxima!\n");
			                exit(0);
			                break;
                        default:
                            printf("Opcao invalida. Por favor, tente novamente.\n");
                    }
                }
                break;
            case 4:
                while (1) {

                	
                    printf("*** Dados ***\n");
                    printf("Selecione uma opcao:\n\n");
                    printf("1. Importar dados de utentes\n");
                    printf("2. Importar dados de medicos\n");
                    printf("3. Importar dados de consultas\n\n");
                    printf("4. Exportar dados de utentes\n");
                    printf("5. Exportar dados de medicos\n");
                    printf("6. Exportar dados de consultas\n\n");
                    printf("7. Voltar ao Menu Principal\n");                   
                    printf("0. Sair\n\n");
                    printf("\n	Opcao: ");
                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1:
                            importarUtentes(&listaUtentes, &codigoUtente);
                            break;
                        case 2:
                            importarMedicos(&listaMedicos, &codigoMedico);
                            break;
                        case 3:
                            // Importar dados de consultas
                            break;
                        case 4:
                            guardarUtentes(listaUtentes);
                            break;
                        case 5:
                        	guardarMedicos(listaMedicos);
                            break;
                        case 6:
                            // Exportar dados de consultas
                            break;
                        case 7:
                            goto menu_principal;
                        case 0:
			                printf("	Aplicacao Terminada!\n");
			                exit(0);
			                break;
                        default:
                            printf("Opcao invalida. Por favor, tente novamente.\n");
                    }
                }
            case 0:
                printf("Aplicacao terminada!\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }
    }
	}
