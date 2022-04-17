#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"horarios.h"
#include "usuarios.h"
/* Cabecera: void cargar_horarios()
Postcondicion: Guarda del fichero horarios.txt en la estructura */
void cargar_horarios(){
    FILE *f=fopen("horarios.txt", "r");

    horarios=(horari*)malloc(sizeof(horari)*n_lineas("horarios.txt"));
    horari aux;
    char cadena[150];
    unsigned i=0;
    if(f){ //Controla si se ha podido abrir el fichero
        while(!feof(f)){
            fgets(cadena, 150, f);
            sscanf(cadena,"%d[^-]-%d[^-]-%d[^-]-%d[^-]-%[^-]",&aux.ID_prof , &aux.dia_clase, &aux.hora_clase, &aux.ID_materia, aux.grupo);
            horarios[i]=aux;
            i++;
            }
        fclose(f);}
    else{
        printf("Error al abrir el fichero Productos.txt\n");}
    int a;
    for(a=0;a<9;a++){   //Recorrer el vector de clientes
        printf("Linea: %d-%d-%d-%d-%s\n ",horarios[a].ID_prof, horarios[a].dia_clase, horarios[a].hora_clase, horarios[a].ID_materia, horarios[a].grupo);
    }
}
