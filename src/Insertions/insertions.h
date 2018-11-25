//
// Created by victor on 19/10/18.
//

#ifndef ATIVIDADEINTEGRADORA_INSERTIONS_H
#define ATIVIDADEINTEGRADORA_INSERTIONS_H
#include "../Pipeline/pipeline.h"

Pipeline* manual_insertion_data();

Pipeline* files_insertion_data();

Pipeline* information_developers();

void print_calculations(char *message, int value);

void print_save_time(char *message, Pipeline *pipeline);

float calc_percentage(float complete, float part);

#endif //ATIVIDADEINTEGRADORA_INSERTIONS_H
