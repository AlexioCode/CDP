#include <stdio.h>
#include <string.h>
#include "Materias.h"


int cargar_materias(){
    int i = 0, j=0, cant = 0;
    materia *p;
    FILE *materias = fopen("materias.txt","r"); //abre el fichero materias.txt para leer
    if(materias == NULL)
    {
        printf("ERROR al abrir el fichero");
        exit(1);
    }
    else

    p = (materia *)malloc(sizeof(materia)); //Se genera el primer elemento del array
    if(p==NULL)
    {
        printf("ERROR al cargar datos");
        exit(1);
    }
    else
        cant++;

        while((p->id[i] = fgetc(materias))!=(EOF||"-")||i<4)
        {
            i++;
        }
        p->id[5]='\0';
        i = 0;
        while((p->nombre[i] = fgetc(materias))!=(EOF||"-")||i<50)
       {
           i++;
       }
       p->nombre[i+1]='\0';
       i = 0;
        while((p->siglas[i] = fgetc(materias))!=(EOF||"-")||i<3)
               {
                   i++;
               }
        p->siglas[4]='\0';
        i = 0;

        while(j<=cant); //se van cargando el resto de los elementos
        {
            p = (materia *)realloc(p,sizeof(materia));
            if(p==NULL)
            {
                printf("ERROR al cargar datos");
                exit(1);
            }
        else
        cant++;
        fgets(p->id,4,materias);
        p->id[5]='\0';

        while((p->nombre[i] = fgetc(materias))!=(EOF||"-")||i<50)
       {
           i++;
       };
       p->nombre[i+1]='\0';
       i = 0;
        fgets(p->siglas,3,materias);
        p->siglas[4]='\0';
        j++;
       }
    fclose(materias);
    return cant;
}

    void guardar_materias(materia *p, int cant){
        int i = 0;
        FILE *materias = fopen("materias.txt","w"); //abre el fichero materias.txt para escribir
        if(materias == NULL)
        {
            printf("ERROR al abrir el fichero");
            exit(1);
        }
        else
        while(i<cant)
        {
            fprintf(materias,"%s",(p+i)->id);
            fprintf(materias,"-");
            fprintf(materias,"%s",(p+i)->nombre);
            fprintf(materias,"-");
            fputs((p+i)->siglas,materias);
            i++;
        }
        fclose(materias);
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

void ver_materias(materia *p, int cant){    //muestra las materias de linea en linea de forma: id-nombre-siglas
    int i;
    for(i=0; 0< cant; i++){
        printf("%s",(p+i)->id);
        printf("-");
        printf("%s",(p+i)->nombre);
        printf("-");
        printf("%s\n",(p+i)->siglas);
    }
}


void baja(materia *p, char* id){
    while(p->id == id) {free(p);} //Libera la materia indicada con id
}

int alta(materia *p, char* nuevo_id, char* nuevo_nombre, char* nuevo_siglas, int cant){
    p = (materia *)realloc(p,sizeof(materia));
        if(p==NULL)
        {
            printf("ERROR al cargar datos");
            exit(1);
        }
        else
        cant++;
        strcpy((p+cant)->id, nuevo_id);
        strcpy((p+cant)->nombre, nuevo_nombre);
        strcpy((p+cant)->siglas, nuevo_siglas);
        return cant;
}



