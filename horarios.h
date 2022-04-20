#ifndef HORARIOS_H_INCLUDED
#define HORARIOS_H_INCLUDED
#include"usuarios.h"
#include"Materias.h"
#include"alumnos.h"
int tam_horari;
typedef struct{
int ID_prof; //3 digitos
int dia_clase;
int hora_clase;
int ID_materia;
char grupo[10];
}horari;
horari *horarios;
/*
cabecera: int busca_hora(int hora,int dia, int ID_pro,int B,horari *horarios)
Precondicion: le debe llegar la hora, el dia y la ID de un profesor valido
Postcondicion: busca si el profesor tiene clase en la hora y el dia indicados
*/
int busca_hora(int hora,int dia, int ID_pro,horari *horarios);
/*
cabecera: void modi_hora(int i,int *Y,materia *mater)
Precondicion: Le debe llegar una posicion del vector
Postcondicion: Modifica la materia a la que va a dar clase un profesor
*/
void modi_hora(int i,materia *mater,horari* horarios);
/*
cabecera: void grupo_hora(int i, int *A,r_alum *alum)
Precondicion: Le debe llegar la posicion del vector
Postcondicion: Cambia el grupo al que dara clase el profesor
*/
void grupo_hora(int i,r_alum *alum,horari* horarios);
/*
cabecera: void cambia_hora(int i, int B,horari *horarios)
Precondicion:Le debe llegar la posicion del vector
Postcondicion: Cambia una clase de hora a otra que hora que este libre
*/
void cambia_hora(int i,horari *horarios);
/*
cabecera: void modificar_hora(int ID_pro, int B,horari *horarios,r_alum *alum,materia *mater)
Precondicion:Le debe llegar la el ID del profesor
Postcondicion: Abre un menu para seleccionar que quiere hacer con la hora seleccionada
*/
void modificar_hora(int pos,horari *horarios,r_alum *alum,materia *mater,char ID_pro[]);
/*
cabecera: int elige_grupo(char *ID, int B,horari *horarios)
Precondicion: Le debe llegar la ID del profesor
Postcondicion: Le dice que clases tiene ese dia y devuelve la posicion del vector de la clase elegida sino devuelve -1
*/
int elige_grupo(char *ID,horari *horarios);
/*
cabecera: void aniadir_hora(int ID_pro, int B,horari *horarios,r_alum *alum,materia *mater)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Le deja aniadir a un admin una clase a un profesor siempre que el hueco elegido este libre
*/
void aniadir_hora(int pos,horari *horarios,r_alum *alum,materia *mater,char ID_pro[]);
/*
cabecera: void eliminar_hora(int ID_pro, int B,horari *horarios)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Le permite al admin eliminar una clase a un profesor
*/
void eliminar_hora(int pos,horari *horarios,char ID_pro[]);
/*
cabecera: int busca(int ID_pro, int *M,usuario *usuar)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Devuelve 1 si encuentra la ID del profesor y 5 si no lo ha hecho.
*/
int busca(char *ID_pro,usuario *usuar);
/*
cabecera: void admin_hora(int B,horari *horarios,r_alum *alum,usuario *usuar,materia *mater)
Postcondicion: Le abre el menu de horarios al admin y le manda a las respectivas funciones
*/
void admin_hora(horari *horarios,r_alum *alum,usuario *usuar,materia *mater);
/*
cabecera: void Guardar_Horarios(horari **horarios, int *tam)
Precondicion: Le debe llegar la estructura de horarios rellenada y el tamanio del vector
Postcondicion: Guarda en ficheros el vector de estructuras
*/
void Guardar_Horarios(horari **horarios);
/*
cabecera: int nLineas(char* fichero)
Precondicion: Le debe llegar el nombre de un fichero
Postcondicion: Devuelve el numero de lineas (el tamanio de como debe ser el vector) que tiene el fichero
*/
int nLineas(char* fichero);

/*
//cabecera: void cargar_horarios(horari** horarios)
//Postcondicion: Guarda del fichero horarios.txt en la estructura
*/
void cargar_horarios(horari** horarios);

#endif  //HORARIOS_H_INCLUDED
