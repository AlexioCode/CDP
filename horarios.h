#ifndef HORARIOS_H_INCLUDED
#define HORARIOS_H_INCLUDED
/*
cabecera: int busca_hora(int hora,int dia, int ID_pro)
Precondicion: le debe llegar la hora, el dia y la ID de un profesor valido
Postcondicion: busca si el profesor tiene clase en la hora y el dia indicados
*/
int busca_hora(int hora,int dia, int ID_pro);
/*
cabecera: void modi_hora(int i)
Precondicion: Le debe llegar una posicion del vector
Postcondicion: Modifica la materia a la que va a dar clase un profesor
*/
void modi_hora(int i);
/*
cabecera: void grupo_hora(int i)
Precondicion: Le debe llegar la posicion del vector
Postcondicion: Cambia el grupo al que dara clase el profesor
*/
void grupo_hora(int i);
/*
cabecera: void cambia_hora(int i)
Precondicion:Le debe llegar la posicion del vector
Postcondicion: Cambia una clase de hora a otra que hora que este libre
*/
void cambia_hora(int i);
/*
cabecera: void modificar_hora(int ID_pro)
Precondicion:Le debe llegar la el ID del profesor
Postcondicion: Abre un menu para seleccionar que quiere hacer con la hora seleccionada
*/
void modificar_hora(int ID_pro);
/*
cabecera: char conver_char(char *A, int B, int tam)
Precondicion: Le debe llegar un vector de caracteres pero que contengan numeros enteros, el tamanio de dicho vector y el numero a introducir en el
Postcondicion: Devuelve en el vector, el numero separado por unidades
*/
char conver_char(char *A, int B, int tam);
/*
cabecera: int conver_int(char *A, int tam)
Precondicion: Le debe llegar un vector de caracteres pero que contengan numeros enteros y el tamanio de dicho vector
Postcondicion: Devuelve el numero que hay en el vector en formato de entero
*/
int conver_int(char *A, int tam);
/*
cabecera: int elige_grupo(char *ID)
Precondicion: Le debe llegar la ID del profesor
Postcondicion: Le dice que clases tiene ese dia y devuelve la posicion del vector de la clase elegida sino devuelve -1

*/
int elige_grupo(char *ID);
/*
cabecera: void aniadir_hora(int ID_pro)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Le deja aniadir a un admin una clase a un profesor siempre que el hueco elegido este libre
*/
void aniadir_hora(int ID_pro);
/*
cabecera: void eliminar_hora(int ID_pro)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Le permite al admin eliminar una clase a un profesor
*/
void eliminar_hora(int ID_pro);
/*
cabecera: int busca(int ID_pro)
Precondicion: Le debe llegar la ID de un profesor
Postcondicion: Devuelve 1 si encuentra la ID del profesor y 5 si no lo ha hecho.
*/
int busca(int ID_pro);
/*
cabecera: void admin_hora()
Postcondicion: Le abre el menu de horarios al admin y le manda a las respectivas funciones
*/
void admin_hora();
/*
cabecera: void Guardar_calificaciones(horari **horarios, int *tam)
Precondicion: Le debe llegar la estructura de horarios rellenada y el tamanio del vector
Postcondicion: Guarda en ficheros el vector de estructuras
*/
void Guardar_calificaciones(horari **horarios, int *tam);
/*
cabecera: int nLineas(char* fichero)
Precondicion: Le debe llegar el nombre de un fichero
Postcondicion: Devuelve el numero de lineas (el tamanio de como debe ser el vector) que tiene el fichero
*/
int nLineas(char* fichero);
/*
cabecera: void cargar_horarios()
Postcondicion: Guarda del fichero horarios.txt en la estructura
*/
void cargar_horarios();
#endif  //HORARIOS_H_INCLUDED
