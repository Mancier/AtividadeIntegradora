//
// Created by victor on 13/11/18.
//

#ifndef ATIVIDADEINTEGRADORA_FILES_H
#define ATIVIDADEINTEGRADORA_FILES_H

//#include <bits/types/FILE.h>
#include <stdio.h>
#include "../Insertions/insertions.h"

Pipeline *read_files(FILE* pointerFile);

void write_files(Pipeline *pipeline, FILE *file);

FILE* open_file(char filePath[1024], char* mode);

void close_file(FILE* filePath);

#endif //ATIVIDADEINTEGRADORA_FILES_H
