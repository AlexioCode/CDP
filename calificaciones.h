#ifndef CALIFICACIONES_H_INCLUDED
#define CALIFICACIONES_H_INCLUDED
int tam_calif;
typedef struct{
int dia;
int mes;
int anno;
}fec;

typedef struct{
fec fecha;
char descrip[30];
int materia;
int alum;
int not;
}calificaciones;

calificaciones * nota;

/*
cabecera: int borrar(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar el ID de un alumno y de una materia
Postcondicion: Lista todas las notas de ese alumno en esa materia y le da la opcion de borrar una posicion del vector cada vez
*/
int borrar(int alum, int materia,calificaciones *nota);
/*
cabecera: void Guardar_calificaciones(calificaciones **nota, int N)
Precondicion: Le debe llegar el tamanio del vector de tipo calificaciones y esta misma
Postcondicion: Traspasa la informacion de la estructura al fichero "Calificaciones.txt" con un formato predeterminado
*/
void Guardar_calificaciones(calificaciones *nota);
/*
cabecera: calificaciones * cargar_calificaciones()
Postcondicion: Traspasa la informacion del fichero "Calificaciones.txt" a la estructura de calificaciones
*/
calificaciones * cargar_calificaciones();
/*
cabecera: void ver_nota(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Lista todas las notas del alumno en la materia correspondiente y te dice si tiene o no
*/
void ver_nota(int alum, int materia,calificaciones *nota);
/*
cabecera: void mod_nota(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Lista todas las notas que tiene el alumno hasta el momento, le pregunta si quiere modificarla y si es asi, la modifica
*/
void mod_nota(int alum, int materia,calificaciones *nota);
/*
cabecera: void eliminar_nota(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Llama a borrar nota y reestructura el vector eliminando la posicion deseada
*/
void eliminar_nota(int alum, int materia,calificaciones *nota);
/*
cabecera: void anadir_not(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Aniade una nota al vector
*/
void anadir_not(int alum, int materia,calificaciones *nota);
/*
cabecera: void aniadir_not(int alu, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Aumenta el vector en 1 y llama a anadir nota
*/
void aniadir_not(int alu, int materia,calificaciones *nota);
/*
cabecera: void calif_profe(int alum, int materia,calificaciones *nota,int N)
Precondicion: Le debe llegar la ID del alumno y de una materia
Postcondicion: Abre el menu para gestionar las calificaciones de sus alumnos, llamando a las diferentes funciones en cada caso
*/
void calif_profe(char *al, char *mat,calificaciones *nota);
#endif  //CALIFICACIONES_H_INCLUDED
