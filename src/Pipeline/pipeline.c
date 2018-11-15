//
// Created by victor on 19/10/18.
//
#include <stdio.h>
#include "pipeline.h"
#include "../Insertions/insertions.h"
#include "../Pipeline/pipeline.h"

Pipeline *createPipeline(int totalStage, int cores, int type, int totalInstruction, int stages[5]){
    Pipeline* pipeline = malloc(sizeof(pipeline)); //(pipeline*)
    if(pipeline == NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }
    pipeline->typePipeline = type;
    pipeline->cores = cores;
    pipeline->stagesPipeline = totalStage;
    pipeline->fetchProcess = stages[0];
    pipeline->decodeProcess = stages[1];
    pipeline->readOperandsProcess = stages[2];
    pipeline->executeProcess = stages[3];
    pipeline->writeResultProcess = pipeline->stagesPipeline == 5 ? stages[4] : 0;
    for (int i = 0; i < pipeline->stagesPipeline; ++i) {
        pipeline->arrayStages[i] = stages[i];
    }
    pipeline->totalInstrunction = totalInstruction;

    return pipeline;
}

int single_instruction_calculation(Pipeline *pipeline){
    pipeline->singleInstruction = 0;
    for (int i = 0; i < pipeline->stagesPipeline; i++) // i = Estagios da pipe
    {
        pipeline->singleInstruction += pipeline->arrayStages[i];
    };
    return pipeline->singleInstruction;
};

int sequencial_instruction_calculation(Pipeline *pipeline) {
    pipeline->multipleSequentialInstruction = 0;
    for (int i = 0; i < pipeline->stagesPipeline; ++i) {
        pipeline->multipleSequentialInstruction += pipeline->arrayStages[i];
    }
    pipeline->multipleSequentialInstruction *= pipeline->stagesPipeline;
    return pipeline->multipleSequentialInstruction;
};

int parellel_multiple_instruction(Pipeline *pipeline){
    int time = pipeline->arrayStages[0];
    //Procurando o maior tempo de execucao
    for(int i = 0; i < pipeline->stagesPipeline; i++) {
        if(pipeline->arrayStages[i] > time){
            time = pipeline->arrayStages[i];
        }
    };
    pipeline->multipleParellelInstruction = 0;
    for (int j = 0; j < pipeline->stagesPipeline-1; j+=pipeline->cores) {
        if((pipeline->cores != 1 && j+pipeline->cores > pipeline->stagesPipeline && j != pipeline->stagesPipeline)){
            pipeline->multipleParellelInstruction += time;
        }
        pipeline->multipleParellelInstruction += time;
    }
    pipeline->multipleParellelInstruction += pipeline->singleInstruction;

    return pipeline->multipleParellelInstruction;
}

int time_saving(Pipeline *pipeline){
    int sequencial = sequencial_instruction_calculation(pipeline);
    int parallel = parellel_multiple_instruction(pipeline);
    pipeline->timeSaving = sequencial - parallel;

    return pipeline->timeSaving;
}

void free_pipeline(Pipeline* pipeline){
    free(pipeline);
    pipeline = NULL;
}