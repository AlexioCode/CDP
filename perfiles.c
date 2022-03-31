#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perfiles.h"
#include "usuarios.h"
/*
#include "alumnos.h"
#include "materias.txt"
#include "matriculas.txt"
#include "calificaciones.txt"
#include "horarios.txt"
*/

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
        fgets(passwd, 9, stdin);    //ya tenemos un usuario y una contrase�a leidos

        quita_salto_linea(user);
        quita_salto_linea(passwd);

        while(n_usuario < num_usuarios && encontrado == 0)  //buscar si el usuario y la contrase�a son v�lidos
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
    printf("\n\nListado de grupos y materias\n");
    printf("\nListado grupos materias: \n");
    //menu_listado_seleccion_grupos_materias_profesor();
    do
    {
        printf("\nSelecciona grupo materia: \n");
        //menu_seleccion_grupo_materia();
        do
        {
            do
            {
                printf("\n1. Lista de alumnos\n2. Cambiar de grupo\n\n");
                scanf("%i", &op);
                if(op != 1 && op != 2)
                    printf("Opcion no valida");
            }while(op != 1 && op != 2); //controlo que no metan numero distinto de 1 y 2
            if(op == 1)                 //si seleccionamos 1. vamos a lista de alumnos
            {
                printf("\nLista de alumnos:\n");
                //lista_alumnos();
                printf("\nAlumno noseque: ");
                do
                {
                    printf("\n1. Ficha del alumno\n2. Calificaciones del alumno\n3. Volver\n\n");
                    scanf("%i", &op2);
                    if(op2 != 1 && op2 != 2 && op2 != 3)
                        printf("Opcion incorrecta");
                    if(op2 == 1)
                        printf("\nLlamo a ficha_alumno(): ");
                        //ficha_alumno();
                    if(op2 == 2)
                        printf("\nLlamo a calif_alum(): ");
                        //calif_alum();
                }while(op2 != 1 && op2 != 2 && op2 != 3);
            }
        }while(op2 == 3);   //si op2=3 entonces volver a lista de alumnos
    }while(op == 2); //si meten un 2 volvemos a seleccionar grupo y materia
}

//cabecera: void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del administrador en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de administrador
void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
{
    int op;
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
                    printf("Llamo a admin_alumnos(): ");
                    //admin_alumnos();
                    break;
                case 3:
                    printf("Llamo a admin_materias(): ");
                    //admin_materias();
                    break;
                case 4:
                    printf("Llamo a admin_horarios(): ");
                    //admin_horarios();
                    break;
            }
            if(op < 1 || op > 4)
                printf("Opcion no valida\n");
        }while(op < 1 || op > 4);

        /*printf("Desea realizar otra operacion de administrador (s/n): ");
        fflush(stdin);
        op2 = getchar();
    }while(op2 == 's');         //por si quiere realizar otra operacion de administrador*/
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

//cabecera: void admin_usuarios(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a un vector de usuarios
//postcondicion: nos permite seleccionar cual de las 4 funciones de administrar usuarios queremos llamar
void admin_usuarios(usuario ** pv_usuarios)
{
    int op;
    do
    {
        printf("\n1. Dar de alta\n2. Dar de baja\n3. Modificar usuario\n4. Listar usuarios\n\n");
        scanf("%i", &op);
        switch(op)
        {
            case 1:
                alta_usuario(pv_usuarios);
                break;
            case 2:
                baja_usuario(pv_usuarios);
                break;
            case 3:
                modificar_usuario(pv_usuarios);
                break;
            case 4:
                escribir_usuarios(pv_usuarios);
                break;
        }
        if(op < 1 || op > 4)
            printf("\nOpcion no valida");
    }while(op < 1 || op > 4);   //comprobar si opción es válida
}
