#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"
#include "calificaciones.txt"
#include "horarios.txt"
#include "Materias.txt"
#include "Matriculas.txt"
#include "perfiles.h"
#include "usuarios.h"

//char * login(usuario ** pv_usuarios)
//precondicion: recibe una direccion de vector de usuarios inicializado
//postcondicion: devuelve el Id_usuario del usuario con ese usuario y contraseña, y llama al perfil correspondiente (de profesor o de administrador)
char * login(usuario ** pv_usuarios)
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
            if((strcmp(user, (*pv_usuarios)[n_usuario].Usuario) == 0)
            && (strcmp(passwd, (*pv_usuarios)[n_usuario].Contrasena) == 0))
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
                perfil_profesor((*pv_usuarios)[n_usuario].Id_usuario, pv_usuarios);
            else
                perfil_administrador((*pv_usuarios)[n_usuario].Id_usuario, pv_usuarios);
            return (*pv_usuarios)[n_usuario].Id_usuario;
        }
        else
            printf("Usuario o contrasena no validos");
    }while(encontrado == 0);
}

//cabecera: void perfil_profesor(char * id_prof, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del profesor en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de profesor
void perfil_profesor(char * id_prof, usuario ** pv_usuarios)
{
    int op;
    int op2;
    int pos_grupo;
    char grupo[10];
    char siglas_materia[4];
    char Id_materia[5];
    char Id_alumno[7];

    do
    {
        do
        {
            pos_grupo = elige_grupo(id_prof);   //mostrar todos los grupos y materias del profesor y adquirir la posicion en horarios.txt
            strcpy(grupo, horarios[pos_grupo].grupo);
            strcpy(Id_materia, horarios[pos_grupo].ID_materia);
            strcpy(siglas_materia, id_siglas_materia(Id_materia));
            printf("\nMenu:\nGRUPO %s MATERIA %s\n--------------\n"
                "1. Lista de alumnos\n2. Cambiar de grupo\n\n", grupo, siglas_materia);
            scanf("%i", &op);
            if(op != 1 && op != 2)
            printf("Opcion no valida");
        }while(op != 1);            //controlo que no metan numero distinto de 1. listar alumnos

        if(op == 1)                 //Opcion elegida: lista de alumnos
        {
            mostrar_alumnos_grupo_materia(grupo, Id_materia);
            printf("Selecciona un alumno (Identificador escolar): ");
            fflush(stdin);
            fgets(Id_alumno, 7, stdin);
            printf("\nMenu: Lista de alumnos:\nALUMNO: %s", Id_alumno);
            do
            {
                printf("\n1. Ficha del alumno\n2. Calificaciones del alumno\n3. Volver\n\n");
                scanf("%i", &op2);
                if(op2 == 1)
                    ficha_alumno(Id_alumno);
                if(op2 == 2)
                {
                    ver_nota(Id_alumno, Id_materia);
                    calif_profe(Id_alumno, Id_materia);
                }
                if(op2 != 1 && op2 != 2 && op2 != 3)
                    printf("Opcion incorrecta");
            }while(op2 != 1 && op2 != 2 && op2 != 3);   //controlo que está correcta la opcion
        }
    }while(op2 == 3);   //si queremos volver al menu anterior
}

//cabecera: void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
//precondicion: id_admin es el Id_usuario del administrador en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de administrador
void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
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
                    listaalumadm(alum);
                    break;
                case 3:
                    admin_materias();
                    break;
                case 4:
                    admin_hora();
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

//cabecera: void quita_salto_linea(char * cad)
//precondicion: recibe una cedena inicializada
//postcondicion: quita el salto de linea del final de una cadena si es que lo tiene
void quita_salto_linea(char * cad)
{
    int longitud = strlen(cad);
    if (cad[longitud - 1] == '\n')
        cad[longitud - 1] = '\0';
}
