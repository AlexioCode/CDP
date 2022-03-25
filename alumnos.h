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
//Precondici�n: Puntero a fichero
//Postcondici�n: Informaci�n cargada en el fichero

int nLineas(char* fichero);

//Cabecera: void Guardar_Alumnos(r_alum **alum, int *A)
// Precondici�n: estructura realizada y tama�o A
//Postcondici�n: estructura cargada en fichero
void Guardar_Alumnos(r_alum **alum, int *A);

//Cabecera:void baja(int alumno)
//Precondici�n: Recibe la estructura con un alumno.
//Postcondici�n: Da de alta al alumno seleccionado.

void alta(r_alum *alum);

//Cabecera:void baja(int alumno)
//Precondici�n: Recibe la estructura inicializada
//Postcondici�n: Da de baja al alumno seleccionado.
void baja(r_alum *alum);

//Cabecera:void modalum(r_alum *alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum);

//Cabecera:void listaalumprof (r_alum*alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Devuelve lista de alumnos con opci�n a modificar alguno de ellos
void listaalumprof (r_alum *alum);

//Cabecera:void listaalumadm (r_alum*alum)
//Precondici�n: Recibe estructura inicializada
//Postcondici�n: Devuelve lista de alumnos con opci�n a modificar alguno de ellos
void listaalumadm (r_alum *alum);

#endif //Perfiles_H_included
