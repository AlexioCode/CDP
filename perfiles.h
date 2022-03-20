#ifndef PERFILES_H_INCLUDED
#define PERFILES_H_INCLUDED
#include "usuarios.h"

//char * login(usuario ** v_usuarios)
//precondicion: recibe un vector de usuarios inicializado
//postcondicion: devuelve el Id_usuario del usuario con ese usuario y contraseña y "000" si no existe, y llama al perfil correspondiente (de profesor o de administrador)
char * login(usuario ** v_usuarios);

//cabecera: void perfil_profesor(char * id_prof, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del profesor en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de profesor
void perfil_profesor(char * id_prof, usuario ** pv_usuarios);

//cabecera: void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del administrador en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de administrador
void perfil_administrador(char * id_admin, usuario ** pv_usuarios);

#endif // PERFILES_H_INCLUDED
