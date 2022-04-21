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

materia* cargar_materias()
{
    int tam_mat = tam_materia("materias.txt");
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
                for (i = 0; i < tam_mat; i++)
                {
                    fscanf(fich, "%[^-]-%[^-]-%[^\n]\n", p[i].id, p[i].nombre, p[i].siglas);    // %[^-]-%[^-]-%[^\n] esta ideado para leer una linea entera y guardar los valores correspondientes entre '-'
                }
                fclose(fich);
            }
        }
    return p;
}

void guardar_materias(materia *p)
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
        for(i = 0; i < tam_mat; i++)
        {
            fprintf(fich, "%s-%s-%s\n", p[i].id, p[i].nombre, p[i].siglas);  //Los datos se guardan con el estandar de estar separados por '-' en cada linea
        }
        fclose(fich);
    }
}

void admin_materias(materia *p)
{
    int op,i=7;
    ver_materias(p, tam_mat);
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
    char nuevo_id[4];
    puts("Introduce nuevo id (max/4)");
    gets(nuevo_id);
    while (i<5)
    {
        if ((p+i)->id == nuevo_id)
        {
        strcpy((p+i)->id, nuevo_id);
        }
        i++;
    }
}

void cambiar_nombre_mat(materia *p){
    int i = 0;
    char nuevo_nombre[50];
    puts("Introduce nuevo nombre (max/50)");
    gets(nuevo_nombre);
    while (i<51)
    {
        if((p+i)->nombre == nuevo_nombre)
        {
        strcpy((p+i)->id, nuevo_nombre);    
        }
        i++;
    }
}

void cambiar_siglas_mat(materia *p){
    int i = 0;
    char nuevo_siglas[3];
    puts("Introduce nuevas siglas (max/3)");
    gets(nuevo_siglas);
    while (i<4)
    {
        if((p+i)->siglas == nuevo_siglas)
        {
        strcpy((p+i)->siglas, nuevo_siglas);    
        }
        i++;
    }
}

void ver_materias(materia *p, int tam_mat){    //muestra las materias de linea en linea de forma: id-nombre-siglas
    int i;
    for(i=0; 0< tam_mat; i++){
        printf("%s",(p+i)->id);
        printf("-");
        printf("%s",(p+i)->nombre);
        printf("-");
        printf("%s\n",(p+i)->siglas);
    }
}

void baja_materia(materia *p, char* id){
    int i=0,j;
    j = tam_mat;
    while((p+i)->id == id && i<j)

    {
        free(p+i); //Libera la materia indicada con id
        i++;
    }
    j--;
    tam_mat = j;
}

void alta_materia(materia ** p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas){
    *p = (materia *)realloc(p,sizeof(materia));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
        else
        tam_mat++;
        strcpy((*p+tam_mat)->id, nuevo_id);
        strcpy((*p+tam_mat)->nombre, nuevo_nombre);
        strcpy((*p+tam_mat)->siglas, nuevo_siglas);
}

char* id_siglas_materia(materia ** p, char* id_materia)
{
    int i=0;
    while((*p+i)->id == id_materia && i<5)
    {
            i++;
    }
    return (*p+i)->siglas;
}

