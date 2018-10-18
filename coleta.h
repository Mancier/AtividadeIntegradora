//
// Created by victor on 01/10/18.
//

#ifndef AT011018_COLETA_H
#define AT011018_COLETA_H
#endif //AT011018_COLETA_H

struct pipelineInformations{
  int typePipeline;
  int cores;
  int stagesPipeline;
  int fetchProcess;
  int decodeProcess;
  int readOperandsProcess;
  int executeProcess;
  int writeResultProcess;
} passTestMemory;

int isScaleOrSuperScale(){
  do{
    printf("Determine o tipo de pipeline: \n");
    printf("\t 1 - Escalar\n");
    printf("\t 2 - Super Escalar\n");
    scanf("%d", &passTestMemory.typePipeline);
  } while(passTestMemory.typePipeline < 1 || passTestMemory.typePipeline > 2);

  if (passTestMemory.typePipeline == 2){
    do{
      printf("\nQuantidade de núcleos: ");
      scanf("%d", &passTestMemory.cores);
        if(passTestMemory.cores < 2){
          printf("\nPara ser SUPER ESCALAR é necessário que o processador tenha 2 ou mais núcleos");
        };
    } while( passTestMemory.cores < 2);
  };
};

extern int colectManualInsertion() {

  isScaleOrSuperScale();

 do {
   printf("\nNúmero de estágios na pipeline: ");
   scanf("%d", &passTestMemory.stagesPipeline);
   switch (passTestMemory.stagesPipeline){
       case 4: printf("Pipeline de 4 estágios\n"); break;
       case 5: printf("Pipeline de 5 estágios\n"); break;
       default: printf("Valor inválido\n"); break;
   }
 } while (passTestMemory.stagesPipeline < 4 || passTestMemory.stagesPipeline > 1);

 printf("Entre com os tempos correspondentes a cada processo da pipeline:\n");

 if(passTestMemory.stagesPipeline == 5){
   printf("Busca de Instrução: ");
   scanf("%d", &passTestMemory.fetchProcess);
   printf("Decodificação da Instrução: ");
   scanf("%d", &passTestMemory.decodeProcess);
   printf("Busca de Operandos: ");
   scanf("%d", &passTestMemory.readOperandsProcess);
   printf("Execução: ");
   scanf("%d", &passTestMemory.executeProcess);
   printf("Escrita em memória: ");
   scanf("%d", &passTestMemory.writeResultProcess);
 } else {
   printf("Busca de Instrução: ");
   scanf("%d", &passTestMemory.fetchProcess);
   printf("Decodificação da Instrução: ");
   scanf("%d", &passTestMemory.decodeProcess);
   printf("Execução: ");
   scanf("%d", &passTestMemory.executeProcess);
   printf("Escrita em memória: ");
   scanf("%d", &passTestMemory.writeResultProcess);
 };
  return 0;
};

extern int colectAutoInsertion(struct test *){
  printf("Data Recived: %x\n", test);
  printf("Data inside Struct: %x\n", test->dataTest);
    printf("Coleta Arquivo Invocada\n");

  return 0;
};

extern int informationDevelopers(){
  printf("Informações sobre os desenvolvedores");

  return 0;
};