#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"calificaciones.h"
/* Cabecera: int nLineas(char* fichero)
   Precondicion: Le debe llegar el nombre de un fichero
   Postcondicion: Devuelve el numero de lineas que tiene dicho fichero */
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

/* Cabecera: void cargar_calificaciones()
   Postcondicion: Traspasa la informacion del fichero "Calificaciones.txt" a la estructura de calificaciones */
calificaciones * cargar_calificaciones(){

    FILE *f=fopen("calificaciones.txt", "r");

    nota=(calificaciones*)malloc(sizeof(calificaciones)*nLineas("calificaciones.txt"));
    calificaciones aux;
    char cadena[150];
    unsigned i=0;
    if(f){ //Controla si se ha podido abrir el fichero
        while(!feof(f)){
            fgets(cadena, 150, f);
            sscanf(cadena,"%d[^-]-%d[^-]-%d[^-]/-%[^-]-%d[^-]-%d[^-]-%d[^-]-",&aux.fecha.dia, &aux.fecha.mes, &aux.fecha.anno, aux.descrip, &aux.materia,&aux.alum,&aux.not);
            nota[i]=aux;
            i++;
            }
        fclose(f);}
    else{
        printf("Error al abrir el fichero Productos.txt\n");}
    int a;
    for(a=0;a<9;a++){   //Recorrer el vector de clientes
        printf("Linea: %d-%d-%d-%s-%d-%d-%d\n ",nota[a].fecha.dia, nota[a].fecha.mes, nota[a].fecha.anno, nota[a].descrip, nota[a].materia, nota[a].alum, nota[a].not);
    }
    return nota;
}
