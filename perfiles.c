#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "calificaciones.h"
#include "horarios.h"
#include "Materias.h"
#include "Matriculas.h"
#include "perfiles.h"
#include "usuarios.h"

//cabecera: void perfil_profesor(char * id_prof, r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del profesor en cuestion y recibe punteros a vectores inicializados
//postcondicion: realiza las funciones del perfil de profesor
void perfil_profesor(char * id_prof, r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
{
    int op;
    int op2;
    int pos_grupo=0;
    char grupo[10];
    char siglas_materia[4];
    char Id_materia[5];
    char Id_alumno[7];
    int a=0;
    do
    {
        do
        {
            pos_grupo = elige_grupo(id_prof, *v_fechas);   //mostrar todos los grupos y materias del profesor y adquirir la posicion en horarios.txt
            if(pos_grupo == -1){
                do{
                puts("No se ha encontrado grupos para usted. ¿Desea seguir buscando? \n1 para si y 0 para no\n");

                scanf("%d",&a);
                }while(a!=0 && a!=1);
                    if(a==0){return;}
                    else{perfil_profesor(id_prof,alumnos, v_calif, v_fechas, materias, v_matriculas,pv_usuarios);}
                }
            strcpy(grupo, (*v_fechas)[pos_grupo].grupo);
            itoa((*v_fechas)[pos_grupo].ID_materia,Id_materia,10);   //el que haya puesto esto que lo arregle
            strcpy(siglas_materia, id_siglas_materia(materias, Id_materia));

            printf("\nMenu:\nGRUPO %s MATERIA %s\n--------------\n"
                "1. Lista de alumnos\n2. Cambiar de grupo\n\n", grupo, siglas_materia);
            scanf("%i", &op);
            if(op != 1 && op != 2)
            printf("Opcion no valida");
        }while(op != 1);            //controlo que no metan numero distinto de 1. listar alumnos

        if(op == 1)                 //Opcion elegida: lista de alumnos
        {
            mostrar_alumnos_grupo_materia(grupo, Id_materia, alumnos, materias);
            printf("Selecciona un alumno (Identificador escolar): \n");
            fflush(stdin);
            fgets(Id_alumno, 7, stdin);
            printf("Menu: Lista de alumnos:\nALUMNO: %s \n", Id_alumno);
            do
            {
                printf("\n1. Ficha del alumno\n2. Calificaciones del alumno\n3. Volver\n\n");
                scanf("%i", &op2);
                if(op2 == 1)
                    ficha_alumno(Id_alumno, *alumnos);
                if(op2 == 2)
                {
                    ver_nota((int)strtol(Id_alumno,NULL,10),(int)strtol(Id_materia,NULL,10), *v_calif);
                    calif_profe(Id_alumno, Id_materia, *v_calif);
                }
                if(op2 != 1 && op2 != 2 && op2 != 3)
                    printf("Opcion incorrecta");
            }while(op2 != 1 && op2 != 2 && op2 != 3);   //controlo que está correcta la opcion
        }
    }while(op2 == 3);   //si queremos volver al menu anterior
}

//cabecera: void perfil_administrador(char * id_admin, r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
//precondicion: id_admin es el Id_usuario del administrador en cuestion y recibe punteros a vectores inicializados
//postcondicion: realiza las funciones del perfil de administrador
void perfil_administrador(char * id_admin, r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
{
    int op, op2;
    do
    {
        do
        {
            printf("\n1.- Usuarios\n2.- Alumnos\n3.- Materias\n4.- Horarios\n\n");
            scanf("%i", &op);
            switch(op)
            {
                case 1:
                    admin_usuarios(pv_usuarios);
                    break;
                case 2:
                    listaalumadm(*alumnos);
                    break;
                case 3:
                    admin_materias(*materias);
                    break;
                case 4:
                    admin_hora(*v_fechas, *alumnos, *pv_usuarios, *materias);
                    break;
                default:
                    printf("Opcion no valida\n");
            }
        }while(op < 1 || op > 4);

        printf("Desea realizar otra operacion de administrador (s/n): ");
        fflush(stdin);
        op2 = getchar();
    }while(op2 == 's'); //por si quiere realizar otra operacion de administrador*/
}

//cabecera: void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
//precondicion: recibe punteros a vectores inicializados
//postcondicion: llama al perfil correspondiente (de profesor o de administrador)
void login(r_alum ** alumnos, calificaciones ** v_calif, horari ** v_fechas, materia ** materias, matricula ** v_matriculas, usuario ** pv_usuarios)
{
    char user[6];
    char passwd[9];
    int n_usuario;
    int encontrado = 0;

    do
    {
        n_usuario = 0;
        printf("\n------------------\nUsuario: ");
        fflush(stdin);
        fgets(user, 6, stdin);
        printf("Contrasena: ");
        fflush(stdin);
        fgets(passwd, 9, stdin);    //ya tenemos un usuario y una contrasena leidos

        quita_salto_linea(user);
        quita_salto_linea(passwd);

        while(n_usuario < num_usuarios && encontrado == 0)  //buscar si el usuario y la contrasena son validos
        {
            if((strcmp(user, (*pv_usuarios)[n_usuario].Usuario) == 0) && (strcmp(passwd, (*pv_usuarios)[n_usuario].Contrasena) == 0))
            {
                encontrado = 1;
                printf("\nBienvenido %s\n", (*pv_usuarios)[n_usuario].Nomb_usuario);
            }
            else
            {
                n_usuario++;
            }
        }

        if(encontrado == 1)  //si el usuario y contrasena son validos, comprobamos si es profe o admin y llamamos a su funcion perfil
        {
            if(strcmp((*pv_usuarios)[n_usuario].Perfil_usuario, "profesor") == 0)
                perfil_profesor((*pv_usuarios)[n_usuario].Id_usuario, alumnos, v_calif, v_fechas, materias, v_matriculas, pv_usuarios);       //llamo a perfil_profesor
            else
                perfil_administrador((*pv_usuarios)[n_usuario].Id_usuario, alumnos, v_calif, v_fechas, materias, v_matriculas, pv_usuarios);  //llamo a perfil_admin
        }
        else
            printf("Usuario o contrasena no validos");
    }while(encontrado == 0);
}
