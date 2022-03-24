#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int tam=6;
typedef struct{
int ID_prof;
int dia_clase;
int hora_clase;
int ID_materia;
char grupo[10];
}horari;
horari horarios[tam];

void Guardar_calificaciones(horari **horarios, int *tam){
int cont;
FILE *f;
f=fopen("Horarios.txt","w");
if (f==NULL){ //Comprobación de si el fichero se ha abierto.
    printf("Horarios.txt no pudo abrirse.\n");
    exit(-1);
}
for (cont=0;cont<*tam-1;cont++){
    fprintf(f,"%s-%s-%s-%s-%s\n",(*horarios)[cont].ID_prof,(*horarios)[cont].dia_clase,(*horarios)[cont].hora_clase,(*horarios)[cont].ID_materia,(*horarios)[cont].grupo);
}
fprintf(f,"%s-%s-%s-%s-%s\n",(*horarios)[cont].ID_prof,(*horarios)[cont].dia_clase,(*horarios)[cont].hora_clase,(*horarios)[cont].ID_materia,(*horarios)[cont].grupo);
fclose(f); //Cierre del fichero.
}
