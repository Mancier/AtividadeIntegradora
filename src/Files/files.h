//
// Created by victor on 13/11/18.
//

#ifndef ATIVIDADEINTEGRADORA_FILES_H
#define ATIVIDADEINTEGRADORA_FILES_H

#include <bits/types/FILE.h>
#include "../Insertions/insertions.h"

Pipeline* read_files(FILE* pointerFile, Pipeline *pipeline);

void write_files(Pipeline *pipeline, char * pathWithNameFile);

FILE* open_file(char* filePath);

void close_file(FILE* filePath);

#endif //ATIVIDADEINTEGRADORA_FILES_H
