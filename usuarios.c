#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"

//cabecera: void quita_salto_linea(char * cad)
//precondicion: recibe una cadena inicializada
//postcondicion: quita el salto de linea del final de una cadena si es que lo tiene
void quita_salto_linea(char * cad)
{
    int longitud = strlen(cad);
    if (cad[longitud - 1] == '\n')
        cad[longitud - 1] = '\0';
}

//cabecera: int n_lineas_usuarios(char * fichero)
//precondicion: fichero es el nombre del fichero cuyo numero de lineas quieres contar
//postcondicon: devuelve el numero de lineas que tiene fichero
int n_lineas_usuarios(char * fichero)
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen(fichero, "r")) == NULL)
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
//precondicion: recibe la direccion de un vector inicializado de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca al vector usuarios
void cargar_usuarios(usuario ** usuarios)
{
    num_usuarios = n_lineas_usuarios("usuarios.txt");    //variable global que guarda el numero de usuarios que hay en el vector de usuarios
    FILE *fich;
    *usuarios = (usuario *) malloc (sizeof(usuario) * num_usuarios); //la reserva de memoria la hago al principio porque ya sé el número de usuarios del fichero "usuarios.txt"
    int n_usuario;
    if ((fich = fopen("usuarios.txt", "r")) == NULL)
    {
        puts("No se pudo abrir el fichero usuarios.txt");
        exit(1);
    }
    else
    {
        for (n_usuario = 0; n_usuario < num_usuarios; n_usuario++)
        {
            fscanf(fich, "%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n", (*usuarios)[n_usuario].Id_usuario,
                   (*usuarios)[n_usuario].Nomb_usuario, (*usuarios)[n_usuario].Perfil_usuario,
                   (*usuarios)[n_usuario].Usuario, (*usuarios)[n_usuario].Contrasena);
        }
        fclose(fich);
    }
}

//cabecera: void escribir_usuarios(usuario ** v_usuarios)
//precondicion: recibe la direccion de un vector inicializado de usuarios
//postcondicion: escribe por pantalla los usuarios que hay cargados en las estructuras
void escribir_usuarios(usuario ** v_usuarios)
{
    int n_usuario;
    for(n_usuario = 0; n_usuario < num_usuarios ; n_usuario++)
    {
        printf("\nId de usuario: %s\n", (*v_usuarios)[n_usuario].Id_usuario);
        printf("Nombre de usuario: %s\n", (*v_usuarios)[n_usuario].Nomb_usuario);
        printf("Perfil de usuario: %s\n", (*v_usuarios)[n_usuario].Perfil_usuario);
        printf("Usuario: %s\n", (*v_usuarios)[n_usuario].Usuario);
        printf("Contrasena: %s\n\n", (*v_usuarios)[n_usuario].Contrasena);
    }
}

//cabecera: void guardar_usuarios(usuario ** v_usuarios)
//precondicion: recibe una direccion a un vector de usuarios inicializado
//postcondicion: guarda la informacion de usuarios en el fichero usuarios.txt
void guardar_usuarios(usuario ** v_usuarios)
{
    FILE * fich;
    int n_usuario;
    if((fich = fopen("usuarios.txt", "w")) == NULL)
    {
        printf("No se ha podido abrir el fichero usuarios.txt");
        exit(1);
    }
    else
    {
        for(n_usuario = 0; n_usuario < num_usuarios; n_usuario++)
        {
            fprintf(fich, "%s-%s-%s-%s-%s\n", (*v_usuarios)[n_usuario].Id_usuario, (*v_usuarios)[n_usuario].Nomb_usuario,
                    (*v_usuarios)[n_usuario].Perfil_usuario, (*v_usuarios)[n_usuario].Usuario,
                    (*v_usuarios)[n_usuario].Contrasena);
            //printf("\nUsuario %i guardado en el fichero", n_usuario + 1);
        }
        fclose(fich);
    }
}

//cabecera: void alta_usuario(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a vector de usuarios inicializado
//postcondicion: añade un usuario al vector de usuarios
void alta_usuario(usuario ** pv_usuarios)
{
    num_usuarios++;     //numero de usuarios + 1 porque se ha añadido un usuario nuevo
    char id[4];
    char nombre_usuario[21];
    char perfil_usuario[14];
    char usuario_usuario[6];
    char usuario_contrasena[9];
    strcpy(id, (*pv_usuarios)[num_usuarios - 2].Id_usuario);
    if(strcmp(id, "999") == 0)
        printf("\nNo hay espacio para mas usuarios\n");
    else
    {    //si cabe otro usuario
        (*pv_usuarios) = (usuario *) realloc(*pv_usuarios, num_usuarios * sizeof(usuario));

        if(id[2] == '9')    //nuevo id = id + 1
        {
            if(id[1] == '9')    //x99
            {
                id[0] = id[0] + 1;
                id[1] = '0';
                id[2] = '0';
            }
            else   //x(!=9)9
            {
            id[1] = id[1] + 1;
            id[2] = '0';
            }
        }
        else
            id[2] = id[2] + 1;
        strcpy((*pv_usuarios)[num_usuarios-1].Id_usuario, id);

        printf("\nIntroduzca nombre completo del nuevo usuario: ");
        fflush(stdin);
        fgets(nombre_usuario, 21, stdin);
        quita_salto_linea(nombre_usuario);
        strcpy((*pv_usuarios)[num_usuarios - 1].Nomb_usuario, nombre_usuario);

        printf("Perfil (administrador/profesor): ");
        fflush(stdin);
        fgets(perfil_usuario, 14, stdin);
        quita_salto_linea(perfil_usuario);
        strcpy((*pv_usuarios)[num_usuarios - 1].Perfil_usuario, perfil_usuario);

        printf("Introduzca usuario para acceder al sistema: ");
        fflush(stdin);
        fgets(usuario_usuario, 6, stdin);
        quita_salto_linea(usuario_usuario);
        strcpy((*pv_usuarios)[num_usuarios - 1].Usuario, usuario_usuario);

        printf("Introduzca una contrasena: ");
        fflush(stdin);
        fgets(usuario_contrasena, 14, stdin);
        //no le quito el \n del final porque termina la linea
        strcpy((*pv_usuarios)[num_usuarios - 1].Contrasena, usuario_contrasena);

        printf("Usuario %s leido correctamente\n\n", (*pv_usuarios)[num_usuarios - 1].Id_usuario);
    }
}

//cabecera: void baja_usuario(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a vector de usuarios inicializado
//postcondicion: da de baja a un usuario del vector de usuarios
void baja_usuario(usuario ** pv_usuarios, char * id)
{
    int n_usuario = 0;
    int encontrado = 0;

    while((encontrado == 0) && (n_usuario < num_usuarios))  //buscar el n_usuario con ese id
    {
        if (strcmp(id, (*pv_usuarios)[n_usuario].Id_usuario) == 0)
            encontrado = 1;
        else
            n_usuario++;
    }
    if(encontrado == 1)     //si encuentra el id en el vector
    {
        while(n_usuario < num_usuarios-1)
        {
            strcpy((*pv_usuarios)[n_usuario].Nomb_usuario, (*pv_usuarios)[n_usuario + 1].Nomb_usuario);
            strcpy((*pv_usuarios)[n_usuario].Perfil_usuario, (*pv_usuarios)[n_usuario + 1].Perfil_usuario);
            strcpy((*pv_usuarios)[n_usuario].Usuario, (*pv_usuarios)[n_usuario + 1].Usuario);
            strcpy((*pv_usuarios)[n_usuario].Contrasena, (*pv_usuarios)[n_usuario + 1].Contrasena);
            n_usuario++;
        }
        num_usuarios--;
        (*pv_usuarios) = (usuario *) realloc(*pv_usuarios, (num_usuarios) * sizeof(usuario));    //le quitamos al vector la reserva del último elemento
    }
    else
        printf("\nNo se ha encontrado al usuario con ese Id");
}
//cabecera: void modificar_usuario(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a vector de usuarios inicializado
//postcondicion: nos permite modificar los campos del usuario cuyo id introduzcamos
void modificar_usuario(usuario ** pv_usuarios)
{
    char id[4];
    int op;
    int n_usuario = 0;
    int encontrado = 0;
    printf("\nQue usuario desea modificar? Introduzca su Id: ");
    fflush(stdin);
    fgets(id, 4, stdin);
    while(n_usuario < num_usuarios && encontrado == 0)
    {
        if(strcmp((*pv_usuarios)[n_usuario].Id_usuario, id) == 0)
            encontrado = 1;
        else
        {
            n_usuario++;
        }
    }
    if (encontrado == 1)    //n_usuario es el usuario a modificar y existe
    {
        do
        {
            printf("\nQue campo desea modificar?\n1. Nombre completo\n2. Perfil\n3. Usuario\n4. Contrasena\n\n");
            scanf("%i", &op);
            if(op < 1 || op > 4)
                printf("\nOpcion no valida");
        }while(op < 1 || op > 4);

        char nombre[21];
        char perfil[14];
        char user[6];
        char contra[9];
        printf("\nIntroduce el nuevo valor: ");
        switch(op)
        {
        case 1:
                fflush(stdin);
                fgets(nombre, 21, stdin);
                quita_salto_linea(nombre);
                strcpy((*pv_usuarios)[n_usuario].Nomb_usuario, nombre);
                break;
        case 2:
                fflush(stdin);
                fgets(perfil, 14, stdin);
                quita_salto_linea(perfil);
                strcpy((*pv_usuarios)[n_usuario].Perfil_usuario, perfil);
                break;
            case 3:
                fflush(stdin);
                fgets(user, 6, stdin);
                quita_salto_linea(user);
                strcpy((*pv_usuarios)[n_usuario].Usuario, user);
                break;
        case 4:
                fflush(stdin);
                fgets(contra, 9, stdin);
                quita_salto_linea(contra);
                strcpy((*pv_usuarios)[n_usuario].Contrasena, contra);
                break;
        }
        printf("\nUsuario modificado satisfactoriamente");
    }
    else
        printf("El id de usuario no existe");
}

//cabecera: void admin_usuarios(usuario ** pv_usuarios)
//precondicion: pv_usuarios es un puntero a un vector de usuarios
//postcondicion: nos permite seleccionar cual de las 4 funciones de administrar usuarios queremos llamar
void admin_usuarios(usuario ** pv_usuarios)
{
    int op;
    char id[4];
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
                printf("\nIntroduce el id del usuario a dar de baja: ");
                fflush(stdin);
                fgets(id, 4, stdin);
                baja_usuario(pv_usuarios, id);
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
