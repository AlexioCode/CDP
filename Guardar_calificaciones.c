#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include"calificaciones.h"

void Guardar_calificaciones(calificaciones **nota, int *tam){
int cont;
FILE *f;
f=fopen("Calificaciones.txt","w");
if (f==NULL){ //Comprobación de si el fichero se ha abierto.
    printf("Calificaciones.txt no pudo abrirse.\n");
    exit(-1);
}
int x=*tam;
for (cont=0;cont<x-1;cont++){
    fprintf(f,"%d-%s-%s-%s-%s-%s-%d\n",(*nota)[cont].fecha.dia ,(*nota)[cont].fecha.mes, (*nota)[cont].fecha.anno,(*nota)[cont].descrip,(*nota)[cont].materia,(*nota)[cont].alum,(*nota)[cont].not);
}
    fprintf(f,"%d-%s-%s-%s-%s-%s-%d\n",(*nota)[cont].fecha.dia ,(*nota)[cont].fecha.mes, (*nota)[cont].fecha.anno,(*nota)[cont].descrip,(*nota)[cont].materia,(*nota)[cont].alum,(*nota)[cont].not);
fclose(f); //Cierre del fichero.
}
