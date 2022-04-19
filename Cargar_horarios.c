#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"horarios.h"
/* Cabecera: void cargar_horarios()
Postcondicion: Guarda del fichero horarios.txt en la estructura */
void cargar_horarios(horari** horarios){
    tam_horari=n_lineas("horarios.txt");
    FILE *f=fopen("horarios.txt", "r");
    *horarios=(horari*)malloc(sizeof(horari)*tam_horari);
    unsigned i=0;
    if((f=fopen("horarios.txt","r"))!=NULL){ //Controla si se ha podido abrir el fichero
            for(i=0;i<tam_horari;i++){
            fscanf(f,"%[^-]-%[^-]-%[^-]-%[^-]-%[^\n]\n",
                    (*horarios)[i].ID_prof,
                    (*horarios)[i].dia_clase,
                    (*horarios)[i].hora_clase,
                    (*horarios)[i].ID_materia,
                    (*horarios)[i].grupo);}
        fclose(f);}
    else{
        printf("Error al abrir el fichero Productos.txt\n");
        exit(-1);}
fclose(f);}
