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
    int multipleSequentialInstruction;
    int multipleParellelInstruction;
    int timeSaving;
} Pipeline;

Pipeline *createPipeline(int totalStage, int cores, int type, int totalInstruction, int stages[5]);

int single_instruction_calculation(Pipeline *pipeline);

int sequencial_instruction_calculation(Pipeline *pipeline);

int parellel_multiple_instruction(Pipeline *pipeline);

void free_pipeline(Pipeline* pipeline);

#endif //AT011018_PIPELINE_H
