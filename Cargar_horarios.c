#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int ID_prof;
int dia_clase;
int hora_clase;
int ID_materia;
char grupo[10];
}horari;
horari *horarios;

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

void cargar_horarios(){

    FILE *f=fopen("horarios.txt", "r");

    horarios=(horari*)malloc(sizeof(horari)*nLineas("horarios.txt"));
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
        printf("Linea: %s-%s-%s-%s-%d\n ",horarios[a].ID_prof, horarios[a].dia_clase, horarios[a].hora_clase, horarios[a].ID_materia, horarios[a].grupo);
    }
}
