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
    char *filePath;
    do {
        printf("Determine o tipo de pipeline: \n");
        printf("\t 1 - Escalar\n");
        printf("\t 2 - Super Escalar\n");
        printf("Opção: ");
        scanf("%d", &type);
    } while (type < 1 || type > 2);

    if (type == 2) {
        do {
            printf("Quantidade de núcleos: ");
            scanf("%d", &cores);
            if (cores < 2) {
                printf("\nPara ser SUPER ESCALAR é necessário que o processador tenha 2 ou mais núcleos");
            };
        } while (cores < 2);
    } else {
        cores = 1;
    };

    do{
        printf("Entre com a quantidade de instrucoes: ");
        scanf("%d", &totalInstruction);
        if(totalInstruction <= 0){
            printf("Valor Invalido\n");
        }
    } while (totalInstruction <= 0);

    do {
        printf("Número de estágios na pipeline (4 ou 5): ");
        scanf("%d", &totalStage);
        switch (totalStage) {
            case 4:
                printf("Pipeline de 4 estágios\n");
                break;
            case 5:
                printf("Pipeline de 5 estágios\n");
                break;
            default:
                printf("Valor inválido\n");
                break;
        }
    } while (!(totalStage == 5 || totalStage == 4));
    printf("Entre com os tempos correspondentes a cada processo da pipeline\n");
    printf("Busca de Instrução: ");
    scanf("%d", &stages[0]);
    printf("Decodificação da Instrução: ");
    scanf("%d", &stages[1]);
    printf("Busca de Operandos: ");
    scanf("%d", &stages[2]);
    printf("Execução: ");
    scanf("%d", &stages[3]);
    if (totalStage == 5) {
        printf("Escrita em memória: ");
        scanf("%d", &stages[4]);
    }

    Pipeline *pipeline = createPipeline(type, cores, totalStage, stages, totalInstruction);

    do{
        printf("\nDeseja salvar esses dados em um aqrquivo .txt?\n1 - Sim\n0 - Nao\nOpcao: ");
        scanf("%d", &option);
        if(option){
            printf("Entre com o caminho e o nome do arquivo: ");
            scanf("%s", &filePath);
            write_files(pipeline, open_file(&filePath, "w"));
        } else {
            printf("Valor Invalido!\n");
        }
    } while (option != 1 && option != 0);

    return pipeline;
};

Pipeline* files_insertion_data(){
    char *filePath;
    FILE *file;
    do {
        printf("Entre com o caminho e o nome do arquivo: ");
        scanf("%s", &filePath);
        file = open_file(&filePath, "r");
    } while (!file);
    return read_files(file);
}

void information_developers(){
    printf("Informações sobre os desenvolvedores");
};