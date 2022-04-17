#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

//Incluimos archivos.h
#include"horarios.h"
#include"alumnos.h"
#include"Materias.h"
#include"Matriculas.h"
#include"calificaciones.h"
#include"usuarios.h"
#include"perfiles.h"

//INICIAMOS MAIN
int main(){
    /*Vectores*/
    horari * v_horarios;
    materia * v_materias;
    matricula *v_matriculas;
    r_alum  * v_alumno;
    usuario *v_usuarios;
    calificaciones * v_calificaciones;

    /*CARGAMOS*/
    cargar_estructura(v_alumno);
    cargar_horarios(v_horarios);
    v_materias= cargar_materias();
    v_matriculas=cargar_matriculas();
    cargar_calificaciones(v_calificaciones);
    cargar_usuarios(v_usuarios);

    /*Login*/
    login(v_alumno,v_calificaciones,v_horarios,v_materias,v_matriculas,v_usuarios);

    /*GUARDAMOS*/
    guardar_materias(v_materias);
    guardar_usuarios(v_usuarios);
    Guardar_Alumnos(v_alumno);
    Guardar_Horarios(v_horarios);
    Guardar_calificaciones(v_calificaciones);

    /*Liberar*/
    free(v_alumno);
    free(v_materias);
    free(v_usuarios);
    free(v_matriculas);
    free(v_calificaciones);
    free(v_horarios);

    return 0;}
