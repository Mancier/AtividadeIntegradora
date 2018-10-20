#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "src/Pipeline/pipeline.h"
#include "src/Insertions/insertions.h"

int welcomeMessage(){
    int option = 0;
    printf("Bem Vindo ao Projeto Integrador");
    printf("\nPara começarmos, selecione uma das opções abaixo: \n");
    printf("\t1 - Entre com os dados da pipeline MANUALMENTE\n");
    printf("\t2 - Entre com os dados por ARQUIVO TXT\n");
    printf("\t3 - Informações sobre os programdores\n");

        do{
            printf("Selecione a opção: ");
            scanf("%d", &option);
            if ((option < 1) || (option > 3)) {
                printf("\nOpção Inválida! Digite novamente \n");
            }
        } while (option < 1 || option > 3);

    return option;
};
void insertionManual();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int shouldRepeat = 0;
    
    do{
        int option = welcomeMessage();
        switch (option){
            case 1: insertionManual(); break;
            case 2: shouldRepeat = colectAutoInsertion(); break;
            case 3: shouldRepeat = informationDevelopers(); break;
            default: shouldRepeat = 1;
        };
    } while(shouldRepeat == 1);
};

void insertionManual(){
    do{
        printf("Determine o tipo de pipeline: \n");
        printf("\t 1 - Escalar\n");
        printf("\t 2 - Super Escalar\n");
        scanf("%d", p->typePipeline);
    } while(p->typePipeline < 1 || p->typePipeline > 2);

    if (p->typePipeline == 2){
        do{
            printf("\nQuantidade de núcleos: ");
            scanf("%d", &p->cores);
            if(p->cores < 2){
                printf("\nPara ser SUPER ESCALAR é necessário que o processador tenha 2 ou mais núcleos");
            };
        } while( p->cores < 2);
    };

    do {
        printf("\nNúmero de estágios na pipeline: ");
        scanf("%d", &p->stagesPipeline);
        switch (p->stagesPipeline){
            case 4: printf("Pipeline de 4 estágios\n"); break;
            case 5: printf("Pipeline de 5 estágios\n"); break;
            default: printf("Valor inválido\n"); break;
        }
    } while (p->stagesPipeline < 4 || p->stagesPipeline > 1);

    printf("Entre com os tempos correspondentes a cada processo da pipeline:\n");

    if(p->stagesPipeline == 5){
        printf("Busca de Instrução: ");
        scanf("%d", &p->fetchProcess);
        printf("Decodificação da Instrução: ");
        scanf("%d", &p->decodeProcess);
        printf("Busca de Operandos: ");
        scanf("%d", &p->readOperandsProcess);
        printf("Execução: ");
        scanf("%d", &p->executeProcess);
        printf("Escrita em memória: ");
        scanf("%d", &p->writeResultProcess);
    } else {
        printf("Busca de Instrução: ");
        scanf("%d", &p->fetchProcess);
        printf("Decodificação da Instrução: ");
        scanf("%d", &p->decodeProcess);
        printf("Execução: ");
        scanf("%d", &p->executeProcess);
        printf("Escrita em memória: ");
        scanf("%d", &p->writeResultProcess);
    };

    //printf("Deseja salv")
    return 0;
}