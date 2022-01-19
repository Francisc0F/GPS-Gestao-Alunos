
#include "ucurricular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pucurricular encontraCurricularPorId(pucurricular lista, int size, int num) {
    for (int i = 0; i < size; i++) {
        int id = lista[i].id_curricular;


        if (id != 0 && id == num) {
            return &lista[i];
        } else {
            break;
        }
    }
    return NULL;
}

void addToList(pucurricular results, pucurricular a) {
    int i = 0;
    if(results[i].id_curricular == 0){
        results[i].id_curricular = a->id_curricular;
        results[i].n_alunos = a->n_alunos;
        strcpy(results[i].nome, a->nome);
        return;
    }
    i++;
    while (results[i].id_curricular != 0) {
        i++;
    }
    results[i].id_curricular = a->id_curricular;
    results[i].n_alunos = a->n_alunos;
    strcpy(results[i].nome, a->nome);
}

void encontraCurricularPorNome(pucurricular lista, int size, char *tmp, pucurricular results) {
    for (int i = 0; i < size; i++) {
        int id = lista[i].id_curricular;

        char *ret = strstr(tmp, "literal");
        if (id != 0 && ret) {
            addToList(results, &lista[i]);
        } else {
            break;
        }
    }
}


void consultaCurricular(pucurricular listaUnidadesCurricular, int size) {

    char num[15];
    printf("Introduza o id do curso: \n");

    scanf("%s", num);

    pucurricular a = encontraCurricularPorId(listaUnidadesCurricular, size, atoi(num));
    if (a != NULL) {
        printf("Encontrou Curso\n");
        listaCurso(a);
    }
}

