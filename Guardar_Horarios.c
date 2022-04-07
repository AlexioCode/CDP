#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void Guardar_Horarios(horari **horarios, int *tam){
int cont;
FILE *f;
f=fopen("Horarios.txt","w");
if (f==NULL){ //Comprobación de si el fichero se ha abierto.
    printf("Horarios.txt no pudo abrirse.\n");
    exit(-1);
}
int x=*tam;
for (cont=0;cont<x-1;cont++){
    fprintf(f,"%s-%s-%s-%s-%s\n",(*horarios)[cont].ID_prof,(*horarios)[cont].dia_clase,(*horarios)[cont].hora_clase,(*horarios)[cont].ID_materia,(*horarios)[cont].grupo);
}
fprintf(f,"%s-%s-%s-%s-%s\n",(*horarios)[cont].ID_prof,(*horarios)[cont].dia_clase,(*horarios)[cont].hora_clase,(*horarios)[cont].ID_materia,(*horarios)[cont].grupo);
fclose(f); //Cierre del fichero.
}
