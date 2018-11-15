//
// Created by victor on 13/11/18.
//
#include "../Insertions/insertions.h"
#include "files.h"
#include <stdio.h>

Pipeline* read_files(FILE* pointerFile, Pipeline *pipeline){
    fscanf(pointerFile,"Type: %d"
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
             pipeline->arrayStages[0],
             pipeline->arrayStages[1],
             pipeline->arrayStages[2],
             pipeline->arrayStages[3],
             pipeline->arrayStages[4],
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