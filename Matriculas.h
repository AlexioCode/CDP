#include <stdlib.h>
#ifndef MATRICULAS_H_INCLUDED
#define MATRICULAS_H_INCLUDED

int tam_matric;
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
matricula* cargar_matriculas();
//void guardar_matriculas(matricula *p, int tam_matric);
//Tener el fichero matriculas.txt, puntero al vector de matriculas y tener el tamaño máximo (tam_matricula/alta_matricula)
//
void guardar_matriculas(matricula *p);
//void cambiar_id_matriculas(matricula *p);
//Puntero al vector de matricula
//
void cambiar_id_matriculas(matricula *p);
//void cambiar_alumid_matriculas(matricula *p);
//Puntero al vector de matricula
//
void cambiar_alumid_matriculas(matricula *p);
//void ver_matriculas(matricula *p, int tam_matric);
//Puntero al vector de matricula y tener el tamaño máximo (tam_matricula/alta_matricula)
//
void ver_matriculas(matricula *p, int tam_matric);
//void baja_matricula(matricula *p, char *matid);
//Puntero al vector de matricula e id de la matricula de baja
//
void baja_matricula(matricula *p, char *matid);
//int alta_matricula(matricula *p, char *matid, char *alumid, int tam_matric);
//id e id del alumno de la matricula, puntero al vector de matricula y tener el tamaño máximo (tam_matricula/alta_matricula)
//Devuelve el tamaño aumentado en uno
void alta_matricula(matricula *p, char *matid, char *alumid);

#endif // MATRICULAS_H_INCLUDED
