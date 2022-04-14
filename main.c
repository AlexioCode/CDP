#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include "usuarios.h"
#include "alumnos.h"
#include "horarios.h"
#include "calificaciones.h"
#include "Materias.h"
#include "Matriculas.h"
#include "perfiles.h"

int main()
{
    /*
    n=tam_calificaciones
    a=tam_alumnos
    y=tam_materias
    m=tam_usuarios
    b=tam_horarios
    c=tam_matriculas
    */
    int n=n_lineas("calificaciones.txt");
    int a=n_lineas("Alumnos.txt");
    int y=n_lineas("Materias.txt");
    int b=n_lineas("horarios.txt");
    int c=n_lineas("Matriculas.txt");
    int *N=&n;
    int *A=&a;
    int *Y=&y;
    int *B=&b;
    int *C=&c;
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
    login(&alum,&nota, &horarios, &p1, &p2, &v_usuarios, N, A, Y, B, C);

    free(v_usuarios);
    free(nota);
    free(horarios);
    free(p1);
    free(p2);
    free(alum);
    return 0;
    }
