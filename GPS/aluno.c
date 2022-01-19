
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


void listaAluno(paluno aux) {
    printf("Numero: %d\n", aux->n);
    printf("Nome: %s\n", aux->nome);
    printf("Data_nasc: %s\n", aux->data_nasc);
    printf("id curso: %d\n", aux->id_curso);
    printf("ano: %d\n", aux->ano);
    printf("Regime: %s\n", aux->regime);
    printf("ano: %d\n", aux->ano);
}

void listaAlunos(paluno aux, int size) {
    for (int i = 0; i < size; i++) {
        if (aux[i].n != 0) {
            listaAluno(&aux[i]);
        } else {
            break;
        }
    }
}

paluno encontraAlunoPorNum(paluno lista, int size, int num) {
    for (int i = 0; i < size; i++) {
        int n = lista[i].n;
        if (n != 0 && n == num) {
            return &lista[i];
        } else {
            break;
        }
    }
    return NULL;
}


void consultaAluno(paluno listaAlunos, int size) {

    char num[15];
    printf("Introduza o numero do aluno: \n");

    scanf("%s", num);

    paluno a = encontraAlunoPorNum(listaAlunos, size, atoi(num));
    if (a != NULL) {
        printf("Encontrou aluno\n");
        listaAluno(a);
    }
}

void addAluno(paluno listaAlunos, int size, paluno al) {

    paluno a = encontraAlunoPorNum(listaAlunos, size, al->n);
    if(a == NULL){
        for (int i = 0; i < size; i++) {
            if(listaAlunos[i].n == 0){
                memcpy(&listaAlunos[i], al, sizeof(aluno));
            }
        }
        return;
    }

    printf("Ja existe\n");
}


void removeAluno(paluno listaAlunos, int size, paluno al) {
    paluno a = encontraAlunoPorNum(listaAlunos, size, al->n);
    if(a != NULL){
        for (int i = 0; i < size; i++) {
            if(listaAlunos[i].n == a->n){
                for (int j = i; j < size; j++) {
                    memcpy(&listaAlunos[j], &listaAlunos[j+1], sizeof(aluno));
                }
            }
        }
        return;
    }
}

void editAluno(paluno listaAlunos, int size, paluno novoAlunoEditado){
    for (int i = 0; i < size; i++) {
        if(listaAlunos[i].n == novoAlunoEditado->n){
            memcpy(&listaAlunos[i], novoAlunoEditado, sizeof(aluno));
        }
    }
}


