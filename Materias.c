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

void cargar_materias()
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


void cambiar_id_mat(materia *p, char* id,char* nuevo_id){
    int i = 0;
    while ((p+i)->id == id)
    {

        strcpy((p+i)->id, nuevo_id);

        i++;
    }
}


void cambiar_nombre_mat(materia *p, char* nombre, char* nuevo_nombre){
    int i = 0;
    while((p+i)->nombre == nombre)
    {
        strcpy((p+i)->nombre, nuevo_nombre);
        i++;
    }
}

void cambiar_siglas_mat(materia *p, char* siglas, char* nuevo_siglas){
    int i = 0;
    while((p+i)->siglas == siglas)
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


void baja_materia(materia *p, char* id){
    while(p->id == id) {free(p);} //Libera la materia indicada con id
}

int alta_materia(materia *p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int tam_max){
    p = (materia *)realloc(p,sizeof(materia));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
        else
        tam_max++;
        strcpy((p+tam_max)->id, nuevo_id);
        strcpy((p+tam_max)->nombre, nuevo_nombre);
        strcpy((p+tam_max)->siglas, nuevo_siglas);
        return tam_max;
}



