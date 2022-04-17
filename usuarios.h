#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

int num_usuarios;   //variable global que contiene en todo momento el numero de usuarios que hay en el vector de usuarios
typedef struct{
    char Id_usuario[4];
    char Nomb_usuario[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];
}usuario;

//cabecera: void quita_salto_linea(char * cad)
//precondicion: recibe una cadena inicializada
//postcondicion: quita el salto de linea del final de una cadena si es que lo tiene
void quita_salto_linea(char * cad);

//cabecera: void cargar_usuarios(usuario ** usuarios)
//precondicion: recibe la direccion de un vector inicializado de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca al vector usuarios
void cargar_usuarios(usuario ** usuarios);

//cabecera: void escribir_usuarios(usuario ** v_usuarios)
//precondicion: recibe la direccion de un vector inicializado de usuarios
//postcondicion: escribe por pantalla los usuarios que hay cargados en las estructuras
void escribir_usuarios(usuario ** v_usuarios);

//cabecera: void guardar_usuarios(usuario ** v_usuarios)
//precondicion: recibe una direccion a un vector de usuarios inicializado
//postcondicion: guarda la informacion de usuarios en el fichero usuarios.txt
void guardar_usuarios(usuario ** v_usuarios);

//cabecera: int n_lineas(char * fichero)
//precondicion: fichero es el nombre del fichero cuyo numero de lineas quieres contar
//postcondicon: devuelve el numero de lineas que tiene fichero
int n_lineas(char * fichero);

//cabecera: void admin_usuarios(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a un vector de usuarios
//postcondicion: nos permite seleccionar cual de las 4 funciones de administrar usuarios queremos llamar
void admin_usuarios(usuario ** pv_usuarios);

#endif // USUARIOS_H_INCLUDED
