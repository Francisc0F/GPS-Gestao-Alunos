
#include "ucurricular.h"
#include <stdio.h>
#include <string.h>

pucurricular encontraCurricularPorId(pucurricular lista, int size, int num) {
    for (int i = 0; i < size; i++) {
        int id = lista[i].id_curricular;
        if (id != 0 && id == num) {
            return &lista[i];
        }
    }
    return NULL;
}

void addToList(pucurricular results, pucurricular a) {
    int i = 0;
    if (results[i].id_curricular == 0) {
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

void encontraCurricularPorNome(pucurricular lista, int size, char *termoPesquisa, pucurricular results) {

    for (int i = 0; i < size; i++) {
        char *ret = strstr(lista[i].nome, termoPesquisa);
        if (ret != NULL) {
            printf("ret %s \n", ret);
            addToList(results, &lista[i]);
            ret = NULL;
        }
    }
    listaUcs(results, 100);
}


void listaUc(pucurricular aux) {
    printf("Nome: %s\n", aux->nome);
    printf("Num alunos: %d\n", aux->n_alunos);
    printf("id_curricular: %d\n", aux->id_curricular);
}

void listaUcs(pucurricular aux, int size) {
    for (int i = 0; i < size; i++) {
        if (aux[i].id_curricular != 0) {
            listaUc(&aux[i]);
            printf("\n");
        } else {
            break;
        }
    }
}



