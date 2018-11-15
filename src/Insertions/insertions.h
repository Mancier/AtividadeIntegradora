//
// Created by victor on 19/10/18.
//

#ifndef ATIVIDADEINTEGRADORA_INSERTIONS_H
#define ATIVIDADEINTEGRADORA_INSERTIONS_H

typedef struct pipeline Pipeline; //Novo tipo de dado

// Alocando Struct
Pipeline* createPipeline(int totalStage, int cores, int type, int totalInstructions, int stages[5]);

// Liberando espaço em memória da Pipe
void free_pipeline(Pipeline* Pipeline);

#endif //ATIVIDADEINTEGRADORA_INSERTIONS_H
