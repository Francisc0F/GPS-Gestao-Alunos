
#include <stdio.h>
#include <stdlib.h>
#include "curso.h"


void listaCurso(pcurso aux) {
    printf("Id: %d\n", aux->id);
    printf("Nome: %s\n", aux->nome);
    printf("Numero alunos: %d\n", aux->n_alunos);

}

void listaCursos(pcurso aux, int size) {
    for (int i = 0; i < size; i++) {
        if (aux[i].id != 0) {
            listaCurso(&aux[i]);
        } else {
            break;
        }
    }
}

pcurso encontraCursoPorId(pcurso lista, int size, int num) {
    for (int i = 0; i < size; i++) {
        int id = lista[i].id;
        if (id != 0 && id == num) {
            return &lista[i];
        }
    }
    return NULL;
}

void consultaCurso(pcurso listaCursos, int size) {

    char num[15];
    printf("Introduza o id do curso: \n");

    scanf("%s", num);

    pcurso a = encontraCursoPorId(listaCursos, size, atoi(num));
    if (a != NULL) {
        printf("Encontrou Curso\n");
        listaCurso(a);
    }else{
        printf("Nao encontrou Curso\n");
    }
}




