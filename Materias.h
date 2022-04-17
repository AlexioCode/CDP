#include <stdlib.h>
#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

int tam_mat;
typedef struct{
    char id[5];
    char nombre[51];
    char siglas[4];
}materia;

//int tam_materias()
//Tener el fichero materias.txt
//Devuelve el tamaño máximo del fichero, el mismo que el numero de materias
int tam_materia();

//char* cargar_materias()
//Tener el ficher materias.txt
//Devuelve el puntero al primer elemento del vector materias
materia* cargar_materias();
//void guardar_materias(materia *p, int tam_mat);
//Tener el fichero materias.txt, puntero al vector de materias y tener el tamaño máximo (tam_materia/alta_materia)
//
void guardar_materias(materia *p);
//void admin_materias(materia *p, int tam_mat);
//Puntero al vector de materias y tener el tamaño máximo (tam_materia/alta_materia)
//Llama a una función según el valor dado
void admin_materias(materia *p);
//void cambiar_id_mat(materia *p);
//Puntero al vector de materias
//
void cambiar_id_mat(materia *p);
//void cambiar_nombre_mat(materia *p);
//Puntero al vector de materias
//
void cambiar_nombre_mat(materia *p);
//void cambiar_siglas_mat(materia *p);
//Puntero al vector de materias
//
void cambiar_siglas_mat(materia *p);
//void ver_materias(materia *p, int tam_mat);
//Puntero al vector de materias y tener el tamaño máximo (tam_materia/alta_materia)
//
void ver_materias(materia *p, int tam_mat);
//void baja_materia(materia *p, char* id);
//Puntero al vector de materias e id de la materia de baja
//
void baja_materia(materia *p, char* id);
//int alta_materia(materia *p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int tam_mat);
//id, nombre y siglas de la materia, puntero al vector de materias y tener el tamaño máximo (tam_materia/alta_materia)
//Devuelve el tamaño aumentado en uno
void alta_materia(materia ** p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas);
//char* id_siglas_materia(materia *p, char* id_materia);
//puntero al vector de materias e id de la materia
//Devuelve las siglas de la materia
char* id_siglas_materia(materia *p, char* id_materia);

#endif // MATERIAS_H_INCLUDED
