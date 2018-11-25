//
// Created by victor on 19/10/18.
//
#include <stdio.h>
#include "pipeline.h"
#include <stdlib.h>
#include "../Pipeline/pipeline.h"

Pipeline *createPipeline(int type, int cores, int totalStage, int stages[5],  int totalInstruction){
    Pipeline* pipeline = malloc(sizeof(pipeline)); //(pipeline*)
    if(pipeline == NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }
    pipeline->typePipeline = type;
    pipeline->cores = cores;
    pipeline->stagesPipeline = totalStage;
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
    pipeline->sequentialInstruction = pipeline->singleInstruction * pipeline->totalInstrunction;

    return pipeline->sequentialInstruction;
};

int pipeline_calculation(Pipeline *pipeline){
    int time = pipeline->arrayStages[0];

    //Procurando o maior tempo de execucao
    for(int i = 0; i < pipeline->stagesPipeline; i++) {
        if(pipeline->arrayStages[i] > time){
            time = pipeline->arrayStages[i];
        }
    };
    pipeline->pipelineInstruction = 0;
    for (int j = 0; j < pipeline->totalInstrunction-pipeline->cores; j+=pipeline->cores) {
        if((pipeline->cores != 1 && j+pipeline->cores > pipeline->totalInstrunction && j != pipeline->stagesPipeline)){
            pipeline->pipelineInstruction += time;
        }
        pipeline->pipelineInstruction += time;
    }
    pipeline->pipelineInstruction += pipeline->singleInstruction;

    return pipeline->pipelineInstruction;
}

int time_saving(Pipeline *pipeline){
    int sequencial = sequencial_instruction_calculation(pipeline);
    int parallel = pipeline_calculation(pipeline);
    pipeline->timeSaving = sequencial - parallel;

    return pipeline->timeSaving;
}

void free_pipeline(Pipeline* pipeline){
    free(pipeline);
}