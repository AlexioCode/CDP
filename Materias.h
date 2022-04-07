#include <stdlib.h>
#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

typedef struct{
    char id[5];
    char nombre[51];
    char siglas[4];
}materia;

int tam_materia();
materia * cargar_materias();
void guardar_materias(materia *p, int tam_max);


void cambiar_id_mat(materia *p, int tam_max);

void cambiar_nombre_mat(materia *p, int tam_max);

void cambiar_siglas_mat(materia *p, int tam_max);

// tam_max debe de ser un valor devuelto por cargar_materias() o alta()
void ver_materias(materia *p, int tam_max);


void baja_materia(materia *p, char* id, int * tam_max);

// tam_max debe de ser un valor devuelto por cargar_materias o alta()
int alta_materia(materia **p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int tam_max);




#endif // MATERIAS_H_INCLUDED
