
#include <stdio.h>
#include <stdlib.h>
#include "curso.h"
#include "ucurricular.h"
#include "aluno.h"
#include "fileData.h"
#include <string.h>

void lerDadosDoFicheiro(pFileData dados) {
    FILE *fp;

    fp = fopen(FILENAME, "rb");

    fread(dados, sizeof(fileData), 1, fp);

}

void escreveDadosDoFicheiro(pFileData dados) {
    FILE *fp;

    fp = fopen(FILENAME, "wb");

    size_t a = fwrite(dados, sizeof(fileData), 1, fp);
    printf("escreveDadosDoFicheiro escrito: %d", a);
}

void recebeDadosDeAluno(paluno novoAluno) {
    printf("Insira nome:\n");
    scanf("%s", novoAluno->nome);
    printf("Insira Numero:\n");
    scanf("%d", &novoAluno->n);
    printf("Insira data nascimento:\n");
    scanf("%s", novoAluno->data_nasc);
    printf("Insira Ano:\n");
    scanf("%d", &novoAluno->ano);
}

void ficheiroBinario(){
    fileData dados;
    memset(&dados, '\0', sizeof(fileData));

    dados.alunos[0].n = 1;
    strcpy(dados.alunos[0].nome, "Andre");
    strcpy(dados.alunos[0].data_nasc, "17-1-1995");
    dados.alunos[0].ano = 2000;
    dados.alunos[0].id_curso = 3;

    dados.alunos[1].n = 2;
    strcpy(dados.alunos[1].nome, "Zeca");
    strcpy(dados.alunos[1].data_nasc, "17-1-1988");
    dados.alunos[1].ano = 2011;
    dados.alunos[1].id_curso = 2;

    dados.alunos[2].n = 3;
    strcpy(dados.alunos[2].nome, "Antonio");
    strcpy(dados.alunos[2].data_nasc, "17-1-1977");
    dados.alunos[2].ano = 2011;
    dados.alunos[2].id_curso = 1;


    dados.cursos[0].id = 1;
    dados.cursos[0].n_alunos = 10;
    strcpy(dados.cursos[0].nome, "ENGINF");


    dados.cursos[1].id = 2;
    dados.cursos[1].n_alunos = 4;
    strcpy(dados.cursos[1].nome, "MEC");

    dados.cursos[2].id = 3;
    dados.cursos[2].n_alunos = 5;
    strcpy(dados.cursos[2].nome, "ENGBIO");

    dados.cursos[3].id = 4;
    dados.cursos[3].n_alunos = 5;
    strcpy(dados.cursos[3].nome, "ENGBIO");

    dados.ucs[0].n_alunos = 20;
    dados.ucs[0].id_curricular = 1;
    strcpy(dados.ucs[0].nome, "AM1");

    dados.ucs[1].n_alunos = 20;
    dados.ucs[1].id_curricular = 2;
    strcpy(dados.ucs[1].nome, "AM2");

    dados.ucs[2].n_alunos = 2;
    dados.ucs[2].id_curricular = 3;
    strcpy(dados.ucs[2].nome, "GPS");

    dados.ucs[3].n_alunos = 3;
    dados.ucs[3].id_curricular = 4;
    strcpy(dados.ucs[3].nome, "ING");

    dados.ucs[4].n_alunos = 10;
    dados.ucs[4].id_curricular = 5;
    strcpy(dados.ucs[4].nome, "AA");

    escreveDadosDoFicheiro(&dados);


    fileData dadosLidos;
    lerDadosDoFicheiro(&dadosLidos);
}
/*
int main(){
    ficheiroBinario();
}*/

int main() {

    int opt1, opt2, opt3, optadd, skip, flag = 0;

    int tam = 100;
    fileData dados;
    memset(&dados, '\0', sizeof(fileData));
    ucurricular ucs[100];

    lerDadosDoFicheiro(&dados);

    do {
        printf("1- Consultar\n2- Editar\n0- Sair \n");
        scanf("%d", &opt1);
        switch (opt1) {
            case 1:
                do {
                    if (flag == 1) {
                        flag = 0;
                        break;
                    }
                    printf("1- Consultar Curso\n2- Consultar UC\n3- Consultar Aluno\n9- Voltar\n0- Sair\n");
                    scanf("%d", &opt2);
                    switch (opt2) {
                        case 1:
                            consultaCurso(dados.cursos, tam);
                            printf("Prima tecla para voltar...\n");
                            getchar();
                            getchar();
                            break;
                        case 2: {
                            printf("Insira termo de pesquisa\n");
                            char termo[100];
                            scanf("%s", termo);
                            encontraCurricularPorNome(dados.ucs, tam, termo, ucs);

                            printf("Prima tecla para voltar...\n");
                            getchar();
                            getchar();
                            break;
                        }
                        case 3:
                            consultaAluno(dados.alunos, tam);
                            printf("Consulta de aluno:\n");
                            printf("Prima tecla para voltar...\n");
                            getchar();
                            getchar();
                            break;
                        case 9:
                            flag = 1;
                            break;
                        case 0:
                            exit(0);
                        default:
                            printf("Opção inválida, prima ENTER para voltar a introduzir\n");
                            getchar();
                            getchar();
                    }
                } while (opt2 != 0);
                break;
            case 2:
                do {
                    if (flag == 1) {
                        flag = 0;
                        break;
                    }
                    printf("1- Adicionar\n2- Remover\n3- Editar\n9- Voltar\n0- Sair\n");
                    scanf("%d", &opt3);
                    switch (opt3) {
                        case 1:
                            do {
                                if (flag == 1) {
                                    flag = 0;
                                    break;
                                }
                                printf("1-Aluno\n2- Professor\n9- Voltar\n0- Sair\n");
                                scanf("%d", &optadd);
                                switch (optadd) {
                                    case 1: {

                                        aluno novoAluno;
                                        printf("Insira dados do aluno novo\n");
                                        recebeDadosDeAluno(&novoAluno);
                                        addAluno(dados.alunos, tam, &novoAluno);
                                        printf("Aluno adicionado\n");
                                        printf("Prima tecla para voltar...\n");
                                        getchar();
                                        getchar();
                                        break;
                                    }
                                    case 2:
                                        //addProfessor();
                                        printf("Adicionar professor:\n");
                                        printf("Prima tecla para voltar...\n");
                                        getchar();
                                        getchar();
                                        break;
                                    case 9:
                                        flag = 1;
                                        break;
                                    case 0:
                                        exit(0);
                                    default:
                                        printf("Opção inválida, prima ENTER para voltar a introduzir\n");
                                        getchar();
                                        getchar();
                                }
                            } while (optadd != 0);
                            break;
                        case 2: {
                            printf("Remover aluno:\n");
                            aluno novoAluno;
                            printf("Insira num do aluno:\n");
                            scanf("%d", &novoAluno.n);

                            removeAluno(dados.alunos, tam, &novoAluno);

                            printf("Prima tecla para voltar...\n");
                            getchar();
                            getchar();
                            break;
                        }

                        case 3: {
                            printf("Editar aluno:\n");
                            printf("Insira dados do aluno a editar:\n");
                            aluno novoAluno;
                            recebeDadosDeAluno(&novoAluno);
                            editAluno(dados.alunos, tam,&novoAluno);
                            printf("Prima tecla para voltar...\n");
                            getchar();
                            getchar();
                            break;
                        }

                        case 9:
                            flag = 1;
                            break;
                        case 0:
                            exit(0);
                        default:
                            printf("Opção inválida, prima ENTER para voltar a introduzir\n");
                            getchar();
                            getchar();
                    }
                } while (opt3 != 0);
                break;
            case 0:
                exit(0);
            default:
                printf("Opção inválida, prima ENTER para voltar a introduzir\n");
                getchar();
                getchar();
        }
    } while (opt1 != 0);
}

