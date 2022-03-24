#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
//Estructura
typedef struct{
	char Id_alum[6]; //Identificador escolar
	char Nombre_alum[20]; //Nombre alumno
	char Direc_alum[30]; //Direccion alumno
	char Local_alum[30]; //Localidad del alumno
	char Curso[30]; // Curso al que pertenece
	char Grupo[10];
} r_alum;

// Cabecera: int nLineas(char* fichero)
//Precondición: Puntero a fichero
//Postcondición: Información cargada en el fichero

int nLineas(char* fichero);

//Cabecera: void inicializar(r_alum *alum,int n)
// Precondición: estructura realizada
//Postcondición: estructura inicializada

void inicializar(r_alum *alum);

#endif //Perfiles_H_included
