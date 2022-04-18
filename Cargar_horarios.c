#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"horarios.h"

/*
// Cabecera: int nLineas(char* fichero)
// Precondicion: Le debe llegar el nombre de un fichero
// Postcondicion: Devuelve el numero de lineas (el tamanio de como debe ser el vector) que tiene el fichero

int nLineas(char* fichero){
    FILE *f=fopen(fichero, "r");
    char cadena[150];
    int cont=0;
    if(f){
        while(!feof(f))
        {fgets(cadena, 150, f);
            cont++;}
        fclose(f);}
    return cont;}
*/

/* Cabecera: void cargar_horarios()
Postcondicion: Guarda del fichero horarios.txt en la estructura */
void cargar_horarios(horari** horarios){
    FILE *f=fopen("horarios.txt", "r");
    tam_horari=n_lineas("horarios.txt");
    horarios=(horari**)malloc(sizeof(horari)*tam_horari);
    horari aux;
    char cadena[150];
    unsigned i=0;
    if(f){ //Controla si se ha podido abrir el fichero
        while(!feof(f)){
            fgets(cadena, 150, f);
            sscanf(cadena,"%d[^-]-%d[^-]-%d[^-]-%d[^-]-%s[^-]",&aux.ID_prof , &aux.dia_clase, &aux.hora_clase, &aux.ID_materia, aux.grupo);
            (*horarios)[i]=aux;
            i++;
            }
        fclose(f);}
    else{
        printf("Error al abrir el fichero Productos.txt\n");}
}
