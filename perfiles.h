#ifndef PERFILES_H_INCLUDED
#define PERFILES_H_INCLUDED
#include "usuarios.h"

//char * login(usuario ** pv_usuarios)
//precondicion: recibe punteros a vectores inicializados
//postcondicion: devuelve el Id_usuario del usuario con ese usuario y contraseña, y llama al perfil correspondiente (de profesor o de administrador)
char * login(alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios);

#endif // PERFILES_H_INCLUDED
