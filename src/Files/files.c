//
// Created by victor on 13/11/18.
//
#include "../Insertions/insertions.h"
#include "../Pipeline/pipeline.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

Pipeline *read_files(FILE* pointerFile){
    int type, cores, totalStages, arrayStages[5], totalInstruction;
    fscanf(pointerFile,"Type: %d"
         "\nCores: %d"
         "\nTotal of Stages: %d"
         "\nStages: [%d,%d,%d,%d,%d]"
         "\nInstructions: %d\n",
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

void write_files(Pipeline *pipeline, FILE *file){
    fprintf(file,"Type: %d"
             "\nCores: %d"
             "\nTotal of Stages: %d"
             "\nStages: [%d,%d,%d,%d,%d]"
             "\nInstructions: %d",
             pipeline->typePipeline,
             pipeline->cores,
             pipeline->stagesPipeline,
             pipeline->arrayStages[0],
             pipeline->arrayStages[1],
             pipeline->arrayStages[2],
             pipeline->arrayStages[3],
             pipeline->arrayStages[4],
             pipeline->totalInstrunction
            );
    close_file(file);
};

FILE* open_file(char filePath[], char* mode){
    return fopen(filePath, mode);
};

void close_file(FILE* filePath){
    fclose(filePath);
};