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

char* cargar_matriculas()
{
    int tam_max = tam_matricula("matriculas.txt");
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
                for (i = 0; i < tam_max; i++)
                {
                    fscanf(fich, "%[^-]-%[^\n]\n", p[i].matid, p[i].alumid);    // %[^-]-%[^\n] esta ideado para leer una linea entera y guardar los valores correspondientes entre '-'
                }
                fclose(fich);
            }
        }
    return p;
}

void guardar_matriculas(matricula *p, int tam_max)
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
        for(i = 0; i < tam_max; i++)
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

void ver_matriculas(matricula *p, int tam_max){   //muestra las matriculas de linea en linea de forma: id-alumid
    int i;
    for(i=0; 0< tam_max; i++){
        printf("%s",(p+i)->matid);
        printf("-");
        printf("%s\n",(p+i)->alumid);
    }
}


int baja_matricula(matricula *p, char *matid, int tam_max){         //Libera la matricula indicada con id
    int i=0,j;
    j = tam_max;
    while((p+i)->matid == matid && i<j)
    {
        free(p+i);
        i++;
    }
    j--;
    return j;
}

int alta_matricula(matricula *p, char *nuevo_matid, char *nuevo_alumid, int tam_max){
    p = (matricula *)realloc(p,sizeof(matricula));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
            else
            tam_max++;
            strcpy((p+tam_max)->matid, nuevo_matid);
            strcpy((p+tam_max)->alumid, nuevo_alumid);
            return tam_max;
}


