#ifndef PERFILES_H_INCLUDED
#define PERFILES_H_INCLUDED
#include "usuarios.h"

//char * login(usuario ** pv_usuarios)
//precondicion: recibe una direccion de vector de usuarios inicializado
//postcondicion: devuelve el Id_usuario del usuario con ese usuario y contraseña, y llama al perfil correspondiente (de profesor o de administrador)
char * login(usuario ** pv_usuarios);

#endif // PERFILES_H_INCLUDED
