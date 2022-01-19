
#ifndef GPS_ALUNO_H
#define GPS_ALUNO_H

#include "curso.h"

typedef struct x aluno, *paluno;
struct x {
    int n;
    char nome[50];
    char data_nasc[10];
    int id_curso;
    int ano;
    char regime[50];
    struct ucurricular *uclist;
};

void consultaAluno(paluno listaAlunos, int size);

void addAluno(paluno listaAlunos, int size, paluno al);

void removeAluno(paluno listaAlunos, int size, paluno aluno);

void editAluno(paluno listaAlunos, int size, paluno novoAlunoEditado);

void listaAlunos(paluno aux, int size);

#endif //GPS_ALUNO_H
