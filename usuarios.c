#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define hey {puts("\n\nHEY!!!\n\n");}

//cabecera: int n_lineas(char * fichero))
//precondicion: fichero es el nombre del fichero cuyo numero de lineas quieres contar
//postcondicon: devuelve el numero de lineas que tiene fichero
int n_lineas(char * fichero)
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("usuarios.txt", "r")) == NULL)
    {
        printf("No se ha podido abrir el fichero %s", fichero);
        exit(1);
    }
    else
    {
        c = getc(fich);
        while(c != EOF)
        {
            c = getc(fich);
            if(c == '\n')   //una linea por cada caracter '\n'
                n++;
        }
        fclose(fich);
    }
    return n;
}

//cabecera: void cargar_usuarios(usuario ** usuarios)
//precondicion: recibe un puntero a un vector de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca al vector usuarios
void cargar_usuarios(usuario ** usuarios)
{
    int usuarios_max = n_lineas("usuarios.txt");
    FILE *fich;
    usuario * aux;
    //*usuarios = (usuario *) realloc (*usuarios, n_lineas("usuarios.txt") * sizeof(usuario));
    *usuarios = (usuario *) malloc (sizeof(usuario) * usuarios_max); //la reserva de memoria la hago al principio porque ya s� el n�mero de usuarios del fichero "usuarios.txt"
    int n_usuario;
    if ((fich = fopen("usuarios.txt", "r")) == NULL)
    {
        puts("No se pudo abrir el fichero usuarios.txt");
        exit(1);
    }
    else
    {
        for (n_usuario = 0; n_usuario < usuarios_max; n_usuario++)
        {
            fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", (*usuarios)[n_usuario].Id_usuario,
                   (*usuarios)[n_usuario].Nomb_usuario, (*usuarios)[n_usuario].Perfil_usuario,
                   (*usuarios)[n_usuario].Usuario, (*usuarios)[n_usuario].Contrasena);
            printf("Usuario %i leido\n", n_usuario);
        }
        fclose(fich);
    }
}

//cabecera: void escribir_usuarios(usuario ** v_usuarios)
//precondicion: recibe la direccion de un vector de usuarios
//postcondicion: escribe por pantalla los usuarios que hay cargados en las estructuras
void escribir_usuarios(usuario ** v_usuarios)
{
    int usuarios_max = n_lineas("usuarios.txt");
    int n_usuario;
    for(n_usuario = 0; n_usuario < usuarios_max; n_usuario++)
    {
        printf("\nNumero de Usuario %i\n", n_usuario);
        printf("Id_usuario: %s\n", (*v_usuarios)[n_usuario].Id_usuario);
        printf("Nomb_usuario: %s\n", (*v_usuarios)[n_usuario].Nomb_usuario);
        printf("Perfil_usuario: %s\n", (*v_usuarios)[n_usuario].Perfil_usuario);
        printf("Usuario: %s\n", (*v_usuarios)[n_usuario].Usuario);
        printf("Contrasena: %s\n\n", (*v_usuarios)[n_usuario].Contrasena);
    }
}

//cabecera: void guardar_usuarios(usuario ** v_usuarios)
//precondicion: recibe un puntero a un vector de usuarios inicializado
//postcondicion: guarda la informacion de usuarios en el fichero usuarios.txt
void guardar_usuarios(usuario ** v_usuarios)
{
    int usuarios_max = n_lineas("usuarios.txt");
    FILE * fich;
    int n_usuario;
    if((fich = fopen("usuarios.txt", "w")) == NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt");
        exit(1);
    }
    else
    {
        for(n_usuario = 0; n_usuario < usuarios_max; n_usuario++)
        {
            fprintf(fich, "%s-%s-%s-%s-%s\n", (*v_usuarios)[n_usuario].Id_usuario, (*v_usuarios)[n_usuario].Nomb_usuario,
                    (*v_usuarios)[n_usuario].Perfil_usuario, (*v_usuarios)[n_usuario].Usuario,
                    (*v_usuarios)[n_usuario].Contrasena);
            printf("Usuario %i leido\n", n_usuario);
        }
    }
}
