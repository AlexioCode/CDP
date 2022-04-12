#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include "Materias.h"

//Estructura
typedef struct{
	char Id_alum[7]; //Identificador escolar
	char Nombre_alum[20]; //Nombre alumno
	char Direc_alum[30]; //Direccion alumno
	char Local_alum[30]; //Localidad del alumno
	char Curso[30]; // Curso al que pertenece
	char Grupo[10];
} r_alum;

//Cabecera: int tam_alumnos(char *fichero)
//Precondici�n: Puntero a fichero
//Postcondici�n: Tama�o del fichero alumnos.txt
int tam_alumnos(char *fichero);

//Cabecera: void cargar_estructura ()
//Precondici�n: Puntero a fichero
//Postcondici�n: Estructura cargada en fichero
void cargar_estructura ();

//Cabecera: void Guardar_Alumnos(r_alum *alum)
// Precondici�n: estructura realizada
//Postcondici�n: estructura cargada en fichero
void Guardar_Alumnos(r_alum **alum);

//Cabecera:void alta(r_alum* alum)
//Precondici�n: Recibe la estructura inicializada
//Postcondici�n: Da de alta al alumno seleccionado.
void alta(r_alum* alum);

//Cabecera:void baja(r_alum *alum)
//Precondici�n: Recibe la estructura inicializada
//Postcondici�n: Da de baja al alumno seleccionado.
void baja(r_alum *alum);

//Cabecera:void modalum(r_alum *alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum);

//Cabecera:void listaalumprof (r_alum *alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Devuelve lista de alumnos con opci�n a modificar alguno de ellos
void listaalumprof (r_alum *alum);

//Cabecera:void listaalumadm (r_alum *alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Devuelve lista de alumnos con opci�n a modificar alguno de ellos
void listaalumadm (r_alum *alum);

//Cabecera:ficha_alumno(char* id_alumno,r_alum *alum )
//Precondici�n: Recibe estructura inicializada y el id de un alumno en concreto
//Postcondici�n: Devuelve lista de un alumno con opcion a modificar datos
void ficha_alumno(char* id_alumno,r_alum *alum );

//Cabecera: void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat)
//Precondici�n: Recibe estructura inicializada, grupo de un alumno y materia
//Postcondici�n: Devuelve lista de alumnos del grupo determinado en la materia determinada
void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat);
#endif //Perfiles_H_included
