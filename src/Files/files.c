//
// Created by victor on 13/11/18.
//
#include "../Insertions/insertions.h"
#include "../Pipeline/pipeline.h"
#include "files.h"
#include <stdio.h>
#include "stdbool.h"

Pipeline *read_files(FILE* pointerFile){
    int type, cores, totalStages, arrayStages[5], totalInstruction;
    fscanf(pointerFile,"Type: %d"
         "\nCores: %d"
         "\nTotal of Stages: %d"
         "\nStages: [%d,%d,%d,%d,%d]"
         "\nInstructions: %d",
         &type,
         &cores,
         &totalStages,
         &arrayStages[0],
         &arrayStages[1],
         &arrayStages[2],
         &arrayStages[3],
         &arrayStages[4],
         &totalInstruction
     );
    close_file(pointerFile);
    return createPipeline(type, cores, totalStages, arrayStages, totalInstruction);
};

void write_files(Pipeline *pipeline, char* pathWithNameFile){
    FILE *file;
    file = open_file(pathWithNameFile);
    fprintf(file,"Type: %d"
             "\nCores: %d"
             "\nTotal of Stages: %d"
             "\nStages: [%d,%d,%d,%d,%d]"
             "\nInstructions: %d",
             pipeline->typePipeline,
             pipeline->cores,
             pipeline->stagesPipeline,
             totalStages[0],
             totalStages[1],
             totalStages[2],
             totalStages[3],
             totalStages[4],
             pipeline->totalInstrunction
            );
    close_file(file);
};

FILE* open_file(char* filePath){
    return fopen(filePath, "w+");
};

void close_file(FILE* filePath){
    fclose(filePath);
};