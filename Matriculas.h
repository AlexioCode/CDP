#include <stdlib.h>
#ifndef MATRICULAS_H_INCLUDED
#define MATRICULAS_H_INCLUDED

typedef struct{
    char matid[5];
    char alumid[7];
}matricula;

//int tam_matricula();
//Tener el matriculas.txt
//Devuelve el tamaño máximo del fichero, el mismo que el numero de matriculas
int tam_matricula();
//char* cargar_matriculas();
//Tener el ficher matriculas.txt
//Devuelve el puntero al primer elemento del vector matriculas
char* cargar_matriculas();
//void guardar_matriculas(matricula *p, int tam_max);
//Tener el fichero matriculas.txt, puntero al vector de matriculas y tener el tamaño máximo (tam_matricula/alta_matricula)
//
void guardar_matriculas(matricula *p, int tam_max);
//void cambiar_id_matriculas(matricula *p);
//Puntero al vector de matricula
//
void cambiar_id_matriculas(matricula *p);
//void cambiar_alumid_matriculas(matricula *p);
//Puntero al vector de matricula
//
void cambiar_alumid_matriculas(matricula *p);
//void ver_matriculas(matricula *p, int tam_max);
//Puntero al vector de matricula y tener el tamaño máximo (tam_matricula/alta_matricula)
//
void ver_matriculas(matricula *p, int tam_max);
//void baja_matricula(matricula *p, char *matid);
//Puntero al vector de matricula e id de la matricula de baja
//
int baja_matricula(matricula *p, char *matid, int tam_max);
//int alta_matricula(matricula *p, char *matid, char *alumid, int tam_max);
//id e id del alumno de la matricula, puntero al vector de matricula y tener el tamaño máximo (tam_matricula/alta_matricula)
//Devuelve el tamaño aumentado en uno
int alta_matricula(matricula *p, char *matid, char *alumid, int tam_max);

#endif // MATRICULAS_H_INCLUDED
