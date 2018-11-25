//
// Created by victor on 01/10/18.
//
#ifndef AT011018_PIPELINE_H
#define AT011018_PIPELINE_H
typedef struct pipeline{
    int typePipeline;
    int cores;
    int stagesPipeline;
    int arrayStages[5];
    int totalInstrunction;
    int singleInstruction;
    int sequentialInstruction;
    int pipelineInstruction;
    int timeSaving;
} Pipeline;

Pipeline *createPipeline(int type, int cores, int totalStage, int stages[5], int totalInstruction);

int single_instruction_calculation(Pipeline *pipeline);

int sequencial_instruction_calculation(Pipeline *pipeline);

int pipeline_calculation(Pipeline *pipeline);

void free_pipeline(Pipeline* pipeline);

int time_saving(Pipeline *pipeline);

#endif //AT011018_PIPELINE_H
