#include <stdio.h>
#include <string.h>
#include "Matriculas.h"

int tam_matricula()
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("matriculas.txt", "r")) == NULL)
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

matricula* cargar_matriculas()
{
    int tam_matric = tam_matricula("matriculas.txt");
    int i;
    matricula *p;
    FILE *fich;

    p = (matricula *)malloc(sizeof(matricula)); //Se genera el primer elemento del array
    if(p==NULL)
        {
        printf("ERROR al cargar datos");
        exit(1);
        }
        else
        {
            if ((fich = fopen("matriculas.txt", "r")) == NULL)
            {
                puts("No se pudo abrir el fichero usuarios.txt");
                exit(1);
            }
            else
            {
                for (i = 0; i < tam_matric; i++)
                {
                    fscanf(fich, "%[^-]-%[^\n]\n", p[i].matid, p[i].alumid);    // %[^-]-%[^\n] esta ideado para leer una linea entera y guardar los valores correspondientes entre '-'
                }
                fclose(fich);
            }
        }
    return p;}

void guardar_matriculas(matricula *p)
{

    FILE * fich;
    int i;
    if((fich = fopen("matriculas.txt", "w")) == NULL)
    {
        printf("No se ha podido abrir el fichero matriculas.txt");
        exit(1);
    }
    else
    {
        for(i = 0; i < tam_matric; i++)
        {
            fprintf(fich, "%s-%s\n", p[i].matid, p[i].alumid);  //Los datos se guardan con el estandar de estar separados por '-' en cada linea
        }
        fclose(fich);
    }
}

void cambiar_id_matriculas(matricula *p){
    int i = 0;
    char* nuevo_matid;
    puts("Introduce nuevo id (max/4)");
    nuevo_matid = gets(stdin);
    while ((p+i)->matid == nuevo_matid && i<5)
    {
        strcpy((p+i)->matid, nuevo_matid);
        i++;
    }
}


void cambiar_alumid_matriculas(matricula *p){
    int i = 0;
    char* nuevo_alumid;
    puts("Introduce nuevo id de alumno (max/6)");
    nuevo_alumid = gets(stdin);
    while((p+i)->alumid == nuevo_alumid && i<7)
    {
        strcpy((p+i)->alumid, nuevo_alumid);
        i++;
    }
}

void ver_matriculas(matricula *p, int tam_matric){   //muestra las matriculas de linea en linea de forma: id-alumid
    int i;
    for(i=0; 0< tam_matric; i++){
        printf("%s",(p+i)->matid);
        printf("-");
        printf("%s\n",(p+i)->alumid);
    }
}


void baja_matricula(matricula *p, char *matid){         //Libera la matricula indicada con id
    int i=0,j;
    j = tam_matric;
    while((p+i)->matid == matid && i<j)
    {
        free(p+i);
        i++;
    }
    j--;
    tam_matric = j;
}

void alta_matricula(matricula *p, char *nuevo_matid, char *nuevo_alumid){
    p = (matricula *)realloc(p,sizeof(matricula));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
            else
            tam_matric++;
            strcpy((p+tam_matric)->matid, nuevo_matid);
            strcpy((p+tam_matric)->alumid, nuevo_alumid);
}


