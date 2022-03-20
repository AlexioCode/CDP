#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

typedef struct
{

    char Id_usuario[4];
    char Nomb_usuario[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];
    /*
    char Id_usuario[30];
    char Nomb_usuario[30];
    char Perfil_usuario[30];
    char Usuario[30];
    char Contrasena[30];
    */
}usuario;

//cabecera: int n_lineas(char * fichero))
//precondicion: fichero es el nombre del fichero cuyo numero de lineas quieres contar
//postcondicon: devuelve el numero de lineas que tiene fichero
int n_lineas(char * fichero);

//cabecera: void cargar_usuarios(usuario ** usuarios)
//precondicion: recibe un puntero a un vector de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca al vector usuarios
void cargar_usuarios(usuario ** usuarios);

//cabecera: void guardar_usuarios(usuario ** v_usuarios)
//precondicion: recibe un puntero a un vector de usuarios inicializado
//postcondicion: guarda la informacion de usuarios en el fichero usuarios.txt
void guardar_usuarios(usuario ** v_usuarios);

//cabecera: void escribir_usuarios(usuario ** v_usuarios)
//precondicion: recibe la direccion de un vector de usuarios
//postcondicion: escribe por pantalla los usuarios que hay cargados en las estructuras
void escribir_usuarios(usuario ** v_usuarios);

#endif // USUARIOS_H_INCLUDED
