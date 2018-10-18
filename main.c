#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pipeline.h"
#include "coleta.h"

int returnMemoryAddress(char *allocadedVar){
//    char * alloc = malloc(sizeof(allocadedVar));
//    printf("Memory address: %x\n", malloc(sizeof(allocadedVar)));
    return malloc(sizeof(allocadedVar));
};

struct test {
    int dataTest = 5;
} passTest;

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
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int shouldRepeat = 0;
    
    do{
        int option = welcomeMessage();
        switch (option){
            case 1: shouldRepeat = colectManualInsertion(); break;
            case 2: shouldRepeat = colectAutoInsertion(&passTest); break;
            case 3: shouldRepeat = informationDevelopers(); break;
            default: shouldRepeat = 1;
        };
    } while(shouldRepeat == 1);
};