#ifndef PERFILES_H_INCLUDED
#define PERFILES_H_INCLUDED
#include "alumnos.h"
#include "calificaciones.h"
#include "horarios.h"
#include "Materias.h"
#include "Matriculas.h"
#include "usuarios.h"

//void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
//precondicion: recibe punteros a vectores inicializados
//postcondicion: llama al perfil correspondiente (de profesor o de administrador)
void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios);

#endif // PERFILES_H_INCLUDED
