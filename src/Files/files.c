//
// Created by victor on 13/11/18.
//
#include "../Insertions/insertions.h"
#include "files.h"
#include <stdio.h>

Pipeline* read_files(char* path, FILE* pointerFile){
    Pipeline *pipe;
};

void write_files(char* pathWithNameFile){
    //FILE* openedFile = openedFile(pathWithNameFile);
    //if(!!openedFile)
};

FILE* open_file(char* filePath){
    return fopen(filePath, "w+");

};

int close_file(FILE* filePath){
    fclose(filePath) ? 1 : 0;
};