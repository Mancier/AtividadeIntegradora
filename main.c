#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h> //Boolean Lib
#include "src/Files/files.h"
#include "src/Pipeline/pipeline.h"
#include "src/Insertions/insertions.h"

/*
 * TODO TERMINAR DE CRIAR A APRENSTAÇÃO DO CALCULO INDIVIDUALIZADO
 * Para 1 única instrução
 * Para múltiplas instruções sequenciais
 * Para múltiplas instruções paralelas (em pipeline)
 * Economia de tempo
 */

Pipeline* manual_insertion_data();
Pipeline* files_insertion_data();

int welcome_message();

int main() {
    setlocale(LC_ALL, "Portuguese");
    Pipeline *pipeline;
    FILE *file;
    int option;
    char filePath[50];
    do{
        //!!pipeline ? free_pipeline(pipeline) : "";
        option = welcome_message();
        switch (option){
            case 1: pipeline = manual_insertion_data(); break;
            case 2: pipeline = files_insertion_data(); break;
            case 3: information_developers(); break;
            default: break;
        };
    } while(!pipeline);

};

int welcome_message(){
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