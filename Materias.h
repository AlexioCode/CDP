#include <stdlib.h>
#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

typedef struct{
    char id[5];
    char nombre[51];
    char siglas[4];
}materia;


int cargar_materias();
void guardar_materias(materia *p, int cant);


void cambiar_id_mat(materia *p, char* id, char* nuevo_id);

void cambiar_nombre_mat(materia *p, char* nombre, char* nuevo_nombre);

void cambiar_siglas_mat(materia *p, char* siglas, char* nuevo_siglas);

// cant debe de ser un valor devuelto por cargar_materias() o alta()
void ver_materias(materia *p, int cant);


void baja(materia *p, char* id);

// cant debe de ser un valor devuelto por cargar_materias o alta()
int alta(materia *p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int cant);




#endif // MATERIAS_H_INCLUDED
