#include <stdio.h>
#include <string.h>
#include "Materias.h"


int tam_materia()
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("materias.txt", "r")) == NULL)
    {
        printf("No se ha podido abrir el fichero");
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

char* cargar_materias()
{
    int tam_max = tam_materia("materias.txt");
    int i;
    materia *p;
    FILE *fich;

    p = (materia *)malloc(sizeof(materia)); //Se genera el primer elemento del array
    if(p==NULL)
        {
        printf("ERROR al cargar datos");
        exit(1);
        }
        else
        {
            if ((fich = fopen("materias.txt", "r")) == NULL)
            {
                puts("No se pudo abrir el fichero materias.txt");
                exit(1);
            }
            else
            {
                for (i = 0; i < tam_max; i++)
                {
                    fscanf(fich, "%[^-]-%[^-]-%[^\n]\n", p[i].id, p[i].nombre, p[i].siglas);    // %[^-]-%[^-]-%[^\n] esta ideado para leer una linea entera y guardar los valores correspondientes entre '-'
                }
                fclose(fich);
            }
        }
    return p;
}

void guardar_materias(materia *p, int tam_max)
{

    FILE * fich;
    int i;
    if((fich = fopen("materias.txt", "w")) == NULL)
    {
        printf("No se ha podido abrir el fichero materias.txt");
        exit(1);
    }
    else
    {
        for(i = 0; i < tam_max; i++)
        {
            fprintf(fich, "%s-%s-%s\n", p[i].id, p[i].nombre, p[i].siglas);  //Los datos se guardan con el estandar de estar separados por '-' en cada linea
        }
        fclose(fich);
    }
}

void admin_materias(materia *p, int tam_max)
{
    int op,i=7;
    ver_materias(p, tam_max);
    puts("1.cambiar id");
    puts("2.cambiar nombre");
    puts("3.cambiar siglas");
    puts("Seleciona que hacer(1/2/3)");
    scanf("%d",&op);
    while(i==7)
    {
        switch(op)
        {
            case 1:
                i=0;
                cambiar_id_mat(p);
            case 2:
                i=0;
                cambiar_nombre_mat(p);
            case 3:
                i=0;
                cambiar_siglas_mat(p);
            default:
                puts("ERROR, valor introducido incorrecto, vuelva a probar");
        }
    }
}

void cambiar_id_mat(materia *p){
    int i = 0;
    char* nuevo_id;
    puts("Introduce nuevo id (max/4)");
    nuevo_id = gets(stdin);
    while ((p+i)->id == nuevo_id && i<5)
    {
        strcpy((p+i)->id, nuevo_id);
        i++;
    }
}

void cambiar_nombre_mat(materia *p){
    int i = 0;
    char* nuevo_nombre;
    puts("Introduce nuevo nombre (max/50)");
    nuevo_nombre = gets(stdin);
    while ((p+i)->nombre == nuevo_nombre && i<51)
    {
        strcpy((p+i)->id, nuevo_nombre);
        i++;
    }
}

void cambiar_siglas_mat(materia *p){
    int i = 0;
    char* nuevo_siglas;
    puts("Introduce nuevas siglas (max/3)");
    nuevo_siglas = gets(stdin);
    while ((p+i)->siglas == nuevo_siglas && i<4)
    {
        strcpy((p+i)->siglas, nuevo_siglas);
        i++;
    }
}

void ver_materias(materia *p, int tam_max){    //muestra las materias de linea en linea de forma: id-nombre-siglas
    int i;
    for(i=0; 0< tam_max; i++){
        printf("%s",(p+i)->id);
        printf("-");
        printf("%s",(p+i)->nombre);
        printf("-");
        printf("%s\n",(p+i)->siglas);
    }
}

int baja_materia(materia *p, char* id, int tam_max){
    int i=0,j;
    j = tam_max;
    while((p+i)->id == id && i<j)

    {
        free(p+i); //Libera la materia indicada con id
        i++;
    }
    j--;
    return j;
}

int alta_materia(materia ** p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int tam_max){
    *p = (materia *)realloc(p,sizeof(materia));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
        else
        tam_max++;
        strcpy((*p+tam_max)->id, nuevo_id);
        strcpy((*p+tam_max)->nombre, nuevo_nombre);
        strcpy((*p+tam_max)->siglas, nuevo_siglas);
        return tam_max;
}

char* id_siglas_materia(materia *p, char* id_materia)
{
    int i=0;
    while((p+i)->id == id_materia && i<5)
    {
            i++;
    }
    return(p+i)->siglas;
}

