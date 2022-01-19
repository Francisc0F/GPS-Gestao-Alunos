
#ifndef GPS_UCURRICULAR_H
#define GPS_UCURRICULAR_H

#include "aluno.h"

typedef struct i ucurricular, *pucurricular;
struct i {
    int id_curricular;
    char nome[50];
    int n_alunos;
};

void consultaUC();

void consultaCurricular(pucurricular listaUnidadesCurricular, int size);

void encontraCurricularPorNome(pucurricular lista, int size, char *tmp, pucurricular results);

#endif
