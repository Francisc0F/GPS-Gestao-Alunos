
#ifndef GPS_UCURRICULAR_H
#define GPS_UCURRICULAR_H

#include "aluno.h"

typedef struct i ucurricular, *pucurricular;
struct i {
    int id_curricular;
    char nome[50];
    int n_alunos;
};

pucurricular encontraCurricularPorId(pucurricular lista, int size, int num);

void encontraCurricularPorNome(pucurricular lista, int size, char *termoPesquisa, pucurricular results);

void listaUc(pucurricular aux);

void listaUcs(pucurricular aux, int size);

#endif
