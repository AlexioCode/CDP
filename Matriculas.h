#include <stdlib.h>
#ifndef MATRICULAS_H_INCLUDED
#define MATRICULAS_H_INCLUDED

typedef struct{
    char matid[5];
    char alumid[7];
}matricula;

int tam_matricula();
void cargar_matriculas();
// tam_max debe de ser un valor devuelto por cargar_materias() o alta()
void guardar_matriculas(matricula *p, int tam_max);

void cambiar_id_matriculas(matricula *p, char *matid, char *nuevo_matid);

void cambiar_alumid_matriculas(matricula *p, char *alumid, char *nuevo_alumid);

// tam_max debe de ser un valor devuelto por cargar_materias() o alta()
void ver_matriculas(matricula *p, int tam_max);


void baja_matricula(matricula *p, char *matid);

// tam_max debe de ser un valor devuelto por cargar_materias o alta()
int alta_matricula(matricula *p, char *matid, char *alumid, int tam_max);

#endif // MATRICULAS_H_INCLUDED
