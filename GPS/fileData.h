
#ifndef GPS_FILEDATA_H
#define GPS_FILEDATA_H

#include "aluno.h"

#define FILENAME              "../../dados"

typedef struct data fileData, * pFileData;
struct data {
    aluno alunos[100] ;
    curso cursos[100] ;
    ucurricular ucs[100] ;
};



#endif
