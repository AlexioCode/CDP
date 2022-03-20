#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perfiles.h"
#include "usuarios.h"
#define hey {puts("\n\nHEY!!!\n\n");}

//char * login(usuario ** v_usuarios)
//precondicion: recibe un vector de usuarios inicializado
//postcondicion: devuelve el Id_usuario del usuario con ese usuario y contrase�a y "000" si no existe, y llama al perfil correspondiente (de profesor o de administrador)
char * login(usuario ** v_usuarios)
{
    char user[6];
    char passwd[9];
    int usuarios_max = n_lineas("usuarios.txt");
    int n_usuario = 0;
    int encontrado = 0;

    printf("Usuario: ");
    fflush(stdin);
    fgets(user, 6, stdin);
    printf("Contrasena: ");
    fflush(stdin);
    fgets(passwd, 9, stdin);    //ya tenemos un usuario y una contrase�a leidos

    quita_salto_linea(user);
    quita_salto_linea(passwd);

    while(n_usuario < usuarios_max && encontrado == 0)  //buscar si el usuario y la contrase�a son v�lidos
    {
        if((strcmp(user, (*v_usuarios)[n_usuario].Usuario) == 0)
           && (strcmp(passwd, (*v_usuarios)[n_usuario].Contrasena) == 0))
        {
            encontrado = 1;
        }
        else
        {
            n_usuario++;
        }
    }

    if(encontrado == 1)  //si el usuario y contrase�a son validos, comprobamos si es profe o admin y llamamos a su funcion perfil
    {
        if(strcmp((*v_usuarios)[n_usuario].Perfil_usuario, "profesor") == 0)
            perfil_profesor((*v_usuarios)[n_usuario].Id_usuario, &v_usuarios);
        else
            perfil_administrador((*v_usuarios)[n_usuario].Id_usuario, &v_usuarios);
        return (*v_usuarios)[n_usuario].Id_usuario;
    }
    else
    {
        printf("Usuario o contrasena no validos");
        return "000";
    }
}

//cabecera: void perfil_profesor(char * id_prof, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del profesor en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de profesor
void perfil_profesor(char * id_prof, usuario ** pv_usuarios)
{
    int op;
    int op2;
    printf("\nListado de grupos y materias\n");
    menu_listado_seleccion_grupos_materias_profesor();
    do
    {
        menu_seleccion_grupo_materia();
        do
        {
            printf("1. Lista de alumnos\n2.Cambiar de grupo\n");
            scanf("%i", &op);
        }while(op != 1 && op != 2); //controlo que no metan numero distinto de 1 y 2
        if(op == 1)     //si seleccionamos 1. lista de alumnos
        {
            do
            {
                lista_alumnos();
                //imprimir nombre del alumno
                printf("1. Ficha del alumno\n2. Calificaciones del alumno\n3.Volver");
                scanf("%i", &op2);
            }while(op2 == 3);   //si op2=3 entonces volver a lista de alumnos
        }
    }
    while(op == 2); //si meten un 2 volvemos a seleccionar grupo y materia
}

//cabecera: void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
//precondicion: id_prof es el Id_usuario del administrador en cuestion y pv_usuarios es un puntero a un vector de usuarios
//postcondicion: realiza las funciones del perfil de administrador
void perfil_administrador(char * id_admin, usuario ** pv_usuarios)
{
    int op;
    printf("1.- Usuarios\n2.- Alumnos\n3.- Materias\n4.- Horarios");
    switch(op)
    {
        case 1:
            admin_usuarios();
            break;
        case 2:
            admin_alumnos();
        case 3:
            admin_materias();
        case 4:
            admin_horarios();
    }
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
