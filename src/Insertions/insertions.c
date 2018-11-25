//
// Created by victor on 19/10/18.
//
#include <lzma.h>
#include <stdlib.h>
#include <stdio.h>
#include "insertions.h"
#include "../Pipeline/pipeline.h"
#include "../Files/files.h"

Pipeline* manual_insertion_data() {
    int totalStage, totalInstruction, cores, type, stages[5], option;
    char filePath[1024];
    FILE *fileOpened;

    do {
        printf("\nDetermine o tipo de pipeline: \n");
        printf("\t 1 - Escalar\n");
        printf("\t 2 - Super Escalar\n");
        printf("Opcao: ");
        scanf("%d", &type);
    } while (type < 1 || type > 2);

    if (type == 2) {
        do {
            printf("\nQuantidade de nucleos: ");
            scanf("%d", &cores);
            if (cores < 2) {
                printf("\nPara ser SUPER ESCALAR e necessario que o processador tenha 2 ou mais nucleos");
            };
        } while (cores < 2);
    } else {
        cores = 1;
    };

    do{
        printf("\nEntre com a quantidade de instrucoes: ");
        scanf("%d", &totalInstruction);
        if(totalInstruction <= 0){
            printf("Valor Invalido\n");
        }
    } while (totalInstruction <= 0);

    do {
        printf("\nNumero de estagios na pipeline (4 ou 5): ");
        scanf("%d", &totalStage);
        switch (totalStage) {
            case 4:
                printf("\tPipeline de 4 estagios\n");
                break;
            case 5:
                printf("\tPipeline de 5 estagios\n");
                break;
            default:
                printf("Valor inválido\n");
                break;
        }
    } while (!(totalStage == 5 || totalStage == 4));
    printf("\nEntre com os tempos correspondentes a cada processo da pipeline\n");
    printf("\tBusca de Instrucao: ");
    scanf("%d", &stages[0]);
    printf("\tDecodificacao da Instrucao: ");
    scanf("%d", &stages[1]);
    printf("\tBusca de Operandos: ");
    scanf("%d", &stages[2]);
    printf("\tExecucao: ");
    scanf("%d", &stages[3]);
    if (totalStage == 5) {
        printf("\tEscrita em memoria: ");
        scanf("%d", &stages[4]);
    }

    Pipeline *pipeline = createPipeline(type, cores, totalStage, stages, totalInstruction);

    do{
        printf("\nDeseja salvar esses dados em um aqrquivo .txt?\n\t1 - Sim\n\t0 - Nao\nOpcao: ");
        scanf("%d", &option);
        if(option == 1){
            do{
                printf("Entre com o caminho e o nome do arquivo: ");
                scanf("%s", filePath);
                fileOpened = open_file(filePath, "w");
                fileOpened == NULL && printf("Caminho Invalido, digite novamente.\n");
            } while(fileOpened == NULL);
            write_files(pipeline, fileOpened);
        }
    } while (option != 1 && option != 0);

    return pipeline;
};

Pipeline* files_insertion_data(){
    char *filePath = malloc(sizeof(char)*128);
    FILE *file;
    do {
        printf("Entre com o caminho e o nome do arquivo: ");
        scanf("%s", filePath);
        file = open_file(filePath, "r");
    } while (!file);
    return read_files(file);
};

Pipeline* information_developers(){
    printf("Informacoes sobre os desenvolvedores\n");
    printf("\tLucas Hiroshi Tokuhara - 967639\n");
    printf("\tVictor Augusto de Souza e Silva- 985882\n");
    printf("\tE que a forca esteja com voce\n");
    system("pause");
    return NULL;
};

void print_calculations(char *message, int value){
    printf(message, value);
    printf("\n");
};

float calc_percentage(float complete, float part){
    return (1 - (part / complete)) * 100;
}

void print_save_time(char *message, Pipeline *pipeline){
    float time = calc_percentage((float)pipeline->sequentialInstruction, (float)pipeline->pipelineInstruction);
    printf(message);
    printf("\n");
    print_calculations("\tTempo total: %dns", time_saving(pipeline));
    printf("\tTempo em porcentagem: %.2f", time);
    printf("%\n");
};