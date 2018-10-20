//
// Created by victor on 19/10/18.
//

#include "insertions.h"

void saveTypePipeline(Pipe *p, int typePipeline){

};

void saveStagesPipeline(Pointer* pointer1, int stage){

};


int colectManualInsertion(Pipe* p) {

    handleTypePipeline(&p);

    handleStagesPipeline();


};

extern int colectAutoInsertion(struct test *ptr){
    printf("Data Recived: %x\n", ptr);
    printf("Data inside Struct: %x\n", ptr->dataTest);
    printf("Coleta Arquivo Invocada\n");

    return 0;
};

extern int informationDevelopers(){
    printf("Informações sobre os desenvolvedores");

    return 0;
};