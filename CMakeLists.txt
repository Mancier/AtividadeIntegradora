cmake_minimum_required(VERSION 3.12)
project(AtividadeIntegradora)
set(CMAKE_C_STANDARD 11)

add_executable(AtividadeIntegradora main.c src/Pipeline/pipeline.c src/Insertions/insertions.c src/Insertions/insertions.h src/Files/files.c src/Files/files.h)