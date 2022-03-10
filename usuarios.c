#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
//cabecera: void cargar_usuarios(usuario * usuarios)
//precondicion: recibe un vector de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca a sus registros
void cargar_usuarios(usuario ** usuarios)
{
    FILE *fich;
    int n_usuario = 0;
    char c;
    char cad_aux[MAX];
    if((fich = fopen("usuarios.txt", "r")) == NULL)
        puts("No se ha podido abrir el fichero usuarios.txt");
    else                                                       //se ha abierto el fichero para lectura
    {
        c = getc(fich);
        while(c != EOF)                                         //leer mientras no se llegue al final del fichero
        {
            printf("\n\nUSUARIO %i\n", n_usuario);
            //campo Id_usuario
            while(c != '-')                                        //mientras no se llegue al fin del campo (mismo campo)
            {
                if(c == '\n')                                     //cuando c tenga el salto de línea (a partir del segunddo usuario, pasar al siguiente caracter
                    fseek(fich, sizeof(char), SEEK_CUR);
                if(c == EOF)                                      //si al bajar a la siguiente linea, nos topamos con EOF, terminar
                    break;
                printf("\nCaracter de Id_usuario%i leido: %c", n_usuario, c);
                strcat(&usuarios[n_usuario].Id_usuario, &c);       //construccion de la cadena Id_usuario
                c = getc(fich);
            }
            //campo Nomb_usuario
            c = getc(fich);
            while(c != '-' && c != EOF)
            {
                printf("\nCaracter de Nomb_usuario%i leido: %c", n_usuario, c);
                strcat(&usuarios[n_usuario].Nomb_usuario, &c);
                c = getc(fich);
            }
            //campo Perfil_usuario
            c = getc(fich);
            while(c != '-' && c != EOF)
            {
                printf("\nCaracter de Perfil_usuario%i leido: %c", n_usuario, c);
                strcat(&usuarios[n_usuario].Perfil_usuario, &c);
                c = getc(fich);
            }
            //campo Usuario
            c = getc(fich);
            while(c != '-' && c != EOF)
            {
                printf("\nCaracter de Usuario%i leido: %c", n_usuario, c);
                strcat(&usuarios[n_usuario].Usuario, &c);
                c = getc(fich);
            }
            //campo Contrasena
            c = getc(fich);
            while(c != '\n' && c != EOF)
            {
                printf("\nCaracter de Contrasena%i leido: %c", n_usuario, c);
                strcat(&usuarios[n_usuario].Contrasena, &c);
                c = getc(fich);
            }
            n_usuario++;
        }
        close(fich);
    }
}
//cabecera: n_usuarios(usuario * usuarios)
//precondicion: recibe un vector del tipo de estructura usuario
//postcondicon: devuelve el numero de usuarios que residen en usuarios.txt
int n_usuarios()
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("usuarios.txt", "r")) == NULL)
        puts("No se ha podido abrir el fichero usuarios.txt");
    else
    {
        c = getc(fich);
        while(c != EOF)
        {
            c = getc(fich);
            if(c == '\n')
                n++;
        }
    }
    return n;
}


fscanf(fich, "%[^-]-%[^-]-%[^-]  ", atemp.id)

*vector = (locker *) realloc (*vector, (*num+1)*sizeof(locker))
