
#ifndef GPS_CURSO_H
#define GPS_CURSO_H

typedef struct c curso, *pcurso;
struct c {
    int id;
    char nome[50];
    int n_alunos;
};

void consultaCurso(pcurso curso, int size);

pcurso encontraCursoPorId(pcurso lista, int size, int num);

void listaCursos(pcurso aux, int size);

void listaCurso(pcurso aux);

#endif //GPS_CURSO_H
