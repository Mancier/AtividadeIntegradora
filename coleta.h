//
// Created by victor on 01/10/18.
//

#ifndef AT011018_COLETA_H
#define AT011018_COLETA_H
#endif //AT011018_COLETA_H

typedef struct pipe Pipe;

int isScaleOrSuperScale(Pipe* p){
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
};

int colectManualInsertion(Pipe* p) {

  isScaleOrSuperScale(&p);

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
  return 0;
};

extern int colectAutoInsertion(struct test *ptr){
  printf("Data Recived: %x\n", ptr);
  printf("Data inside Struct: %x\n", ptr->dataTest);
    printf("Coleta Arquivo Invocada\n");

  return 0;
};

extern int informationDevelopers(){
  printf("Informações sobre os desenvolvedores");

  return 0;
};