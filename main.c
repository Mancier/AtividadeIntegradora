#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <mshtml.h>
#include "src/Files/files.h"
#include "src/Pipeline/pipeline.h"
#include "src/Insertions/insertions.h"

#define KGRN  "\x1B[32m"
#define KNML   "\x1b[0m"

Pipeline* manual_insertion_data();
Pipeline* files_insertion_data();

int repeat = 0;
int welcome_message();

int main() {
    setlocale(LC_ALL, "Portuguese");
    Pipeline *pipeline;
    int option;
    do {
        option = 0;

        do {
            option = welcome_message();
            switch (option) {
                case 1:
                    pipeline = manual_insertion_data();
                    break;
                case 2:
                    pipeline = files_insertion_data();
                    break;
                case 3:
                    pipeline = information_developers();
                    system("cls");
                    break;
                default:
                    break;
            };
        } while (!pipeline);

        printf("==== Resultado ====\n");
        print_calculations("Tempo de uma unica instrucao: %dns", single_instruction_calculation(pipeline));
        print_calculations("Instrucoes sequsnciais: %dns", sequencial_instruction_calculation(pipeline));
        print_calculations("Instrucoes em Pipeline: %dns", pipeline_calculation(pipeline));
        print_save_time("Economia de Tempo", pipeline);
        free_pipeline(pipeline);

        do {
            printf("\nDeseja realizar outro calculo?\n\t1 - Sim\n\t0 - Nao\nOpcao: ");
            scanf("%d", &repeat);
            if(repeat != 1 && repeat != 0){
                printf("Valor Invalido\n");
            }
        } while (repeat != 1 && repeat != 0);
    } while (repeat);

    printf("Encerrando o programa\nMuito Obridado\n");
    system("pause");
};

int welcome_message(){
    int option = 0;
    repeat ? system("cls") : printf("Bem Vindo ao Projeto Integrador\n");
    printf("Para comecarmos, selecione uma das opcoes abaixo: \n");
    printf("\t1 - Entre com os dados da pipeline MANUALMENTE\n");
    printf("\t2 - Entre com os dados por ARQUIVO TXT\n");
    printf("\t3 - Informacoes sobre os programdores\n");

    do{
        printf("Selecione a opcao: ");
        scanf("%d", &option);
        if ((option < 1) || (option > 3)) {
            printf("\nOpcao Invalida! Digite novamente \n");
        }
    } while (option < 1 || option > 3);

    return option;
};