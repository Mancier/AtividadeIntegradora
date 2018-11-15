//
// Created by victor on 13/11/18.
//
#include "../Insertions/insertions.h"
#include "files.h"
#include <stdio.h>

Pipeline* read_files(FILE* pointerFile, Pipeline *pipeline){
    fscanf(pointerFile,"\nType: %d"
                         "\nCores: %d"
                         "\nTotal of Stages: %d"
                         "\nStages: %d"
                         "\nInstructions: %d", &pipeline->typePipeline, &pipeline->cores, &pipeline->stagesPipeline, &pipeline->arrayStages, &pipeline->totalInstrunction );
};

void write_files(Pipeline *pipeline, char* pathWithNameFile){
    fprintf(pathWithNameFile,"\nType: %d"
                             "\nCores: %d"
                             "\nTotal of Stages: %d"
                             "\nStages: %d"
                             "\nInstructions: %d", pipeline->typePipeline, pipeline->cores, pipeline->stagesPipeline, pipeline->arrayStages, pipeline->totalInstrunction);
};

FILE* open_file(char* filePath){
    return fopen(filePath, "w+");
};

void close_file(FILE* filePath){
    fclose(filePath);
};