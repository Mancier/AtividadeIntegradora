//
// Created by victor on 19/10/18.
//
#include <lzma.h>
#include "pipeline.h"

struct Pipeline{
    int typePipeline;
    int cores;
    int stagesPipeline;
    int fetchProcess;
    int decodeProcess;
    int readOperandsProcess;
    int executeProcess;
    int writeResultProcess;
};

struct Pipeline* createData(int arrayData[8]){
    struct Pipeline* pipe = (struct Pipeline*) malloc(sizeof(struct Pipeline));
    if(pipe == NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }
}

void addNewValue(struct Pipeline* pipe, char dataName, int newValue){
    pipe->typePipeline = newValue;
}