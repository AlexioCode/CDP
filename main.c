#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "alumnos.h"
#include "horarios.h"
#include "calificaciones.h"
#include "Materias.h"
#include "Matriculas.h"
#include "perfiles.h"

int main()
{
    int n=nLineas("calificaciones.txt");
    int a=nLineas("alumnos.txt");
    int y=nLineas("materia.txt");
    int m=nLineas("usuarios.txt");
    int b=nLineas("horarios.txt");
    int *N=&n;
    int *A=&a;
    int *Y=&y;
    int *M=&m;
    int *B=&b;
    usuario * v_usuarios;
    calificaciones * nota;
    horari *horarios;
    materia *p1;
    matricula *p2;
    r_alum *alum;
    cargar_calificaciones();
    cargar_horarios();
    cargar_matriculas();
    cargar_usuarios(&v_usuarios);
    cargar_estructura();
    cargar_estructura();
    login(&v_usuarios);


    return 0;}
