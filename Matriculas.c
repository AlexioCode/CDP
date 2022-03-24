#include <stdio.h>
#include "Matriculas.h"

int cargar_materias(){
    int i, j=0, cant = 0;
    matricula *p;
    FILE *matriculas = fopen("matriculas.txt","r"); //abre el fichero matriculas.txt para leer
    if(matriculas == NULL)
    {
        printf("ERROR al abrir el fichero");
        exit(1);
    }

    fseek(f, 0, SEEK_END); // busca el final del fichero
    tam = ftell(f); // devuelve la posicion final
    fseek(f, 0, SEEK_SET); // vuelve al principio

    p = (matriculas *)malloc(sizeof(matriculas)); //Se genera el primer elemento del array
    if(p==NULL)
        printf("ERROR al cargar datos");
    exit(1);
    else
        cant++;
        fgets(p->id,4,matriculas);
        p->id[5]='\0';

        fgets(p->alumid,6,matriculas);
        p->alumid[7]='\0';

        while(j<=cant); //se van cargando el resto de los elementos
        {
            p = (matriculas *)realloc(p,sizeof(matriculas));
        if(p==NULL)
            printf("ERROR al cargar datos");
        exit(1);
        else
        cant++;
        fgets(p->id,4,matriculas);
        p->id[5]='\0';

        fgets(p->alumid,6,matriculas);
        p->alumid[7]='\0';

       }
    fclose(matriculas);
    return cant;
}

    void guardar_matriculas(matriculas *p, int cant){
        int i = 0;
        FILE *matriculas = fopen("matriculas.txt","w"); //abre el fichero matriculas.txt para escribir
        if(matriculas == NULL)
        {
            printf("ERROR al abrir el fichero");
            exit(1);
        }
        else
        while(i<cant)
        {
            fprintf(matriculas,"%s",(p+i)->id);
            fprintf(matriculas,'-');
            fputs((p+i)->alumid,matriculas);
            i++;
        }
        fclose(matriculas);
    }


void cambiar_id_matriculas(matriculas *p, char *id,char *nuevo_id){
    int i = 0;
    while ((p+i)->id == id)
    {
        (p+i)->id = nuevo_id;
        i++;
    }
}


void cambiar_alumid_matriculas(matriculas *p, char *alumid, char *nuevo_alumid){
    int i = 0;
    while((p+i)->alumid == alumid)
    {
        (p+i)->alumid = nuevo_alumid;
        i++
    }
}

void ver_matriculas(matriculas *p, int cant){   //muestra las matriculas de linea en linea de forma: id-alumid
    int i;
    for(i=0; 0< cant; i++){
        printf(matriculas,"%s",(p+i)->id);
        printf(matriculas,'-');
        puts((p+i)->alumid,matriculas);
    }
}


void baja(matriculas *p, char *id){         //Libera la matricula indicada con id
    while((p+i)->id == id) {free(p+i);}
}

int alta(matriculas *p, char *nuevo_id, char *nuevo_alumid, int cant){
    p = (matriculas *)realloc(p,sizeof(matriculas));
        if(p==NULL)
            printf("ERROR al cargar datos");
        exit(1);
        else
        cant++;
        (p+cant)->id = nuevo_id;
        (p+cant)->alumid = nuevo_alumid;
        return cant;
}


