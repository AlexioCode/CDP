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

//Cabecera: void Guardar_Alumnos(r_alum **alum, int *A)
// Precondici—n: estructura realizada y tamaño A
//Postcondici—n: estructura cargada en fichero
void Guardar_Alumnos(r_alum **alum, int *A);

//Cabecera:void baja(int alumno)
//Precondición: Recibe la estructura con un alumno.
//Postcondición: Da de alta al alumno seleccionado.

void alta(r_alum *alum);

//Cabecera:void baja(int alumno)
//Precondición: Recibe la estructura inicializada
//Postcondición: Da de baja al alumno seleccionado.
void baja(r_alum *alum);

//Cabecera:void modalum(r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum);

//Cabecera:void listaalumprof (r_alum*alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos
void listaalumprof (r_alum *alum);

//Cabecera:void listaalumadm (r_alum*alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos
void listaalumadm (r_alum *alum);

#endif //Perfiles_H_included
