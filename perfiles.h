#ifndef PERFILES_H_INCLUDED
#define PERFILES_H_INCLUDED
#include "alumnos.h"
#include "calificaciones.h"
#include "horarios.h"
#include "Materias.h"
#include "Matriculas.h"
#include "usuarios.h"

//cabecera: void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios, int *tam_calif, int *tam_alum, int *tam_mat, int *tam_horari, int *tam_matric)
//precondicion: recibe punteros a vectores inicializados
//postcondicion: llama al perfil correspondiente (de profesor o de administrador)
void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios, int *tam_calif, int *tam_alum, int *tam_mat, int *tam_horari, int *tam_matric);

#endif // PERFILES_H_INCLUDED
