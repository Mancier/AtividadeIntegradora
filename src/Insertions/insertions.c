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
    int totalStage, totalInstruction, cores, type, stages[5];
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
    return pipeline;
};

/*
 * TODO Terminar a leitura de arquivos, e salva-los na struct
 */
Pipeline* files_insertion_data(){
    char *filePath;
    printf("Entre com o caminho e o nome do arquivo: ");
    scanf("%s", filePath);
    return read_files(open_file(filePath));
}

void information_developers(){
    printf("Informações sobre os desenvolvedores");
};