#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int tam=6;
typedef struct{
int dia;
int mes;
int anno;
}fec;

typedef struct{
fec fecha;
char descrip[30];
int materia;
int alum;
int not;
}calificaciones;
calificaciones nota[tam];

void Guardar_calificaciones(calificaciones **nota, int *tam){
int cont;
FILE *f;
f=fopen("Calificaciones.txt","w");
if (f==NULL){ //Comprobación de si el fichero se ha abierto.
    printf("Calificaciones.txt no pudo abrirse.\n");
    exit(-1);
}
for (cont=0;cont<*tam-1;cont++){
    fprintf(f,"%s-%s-%s-%s-%s-%s-%s\n",(*nota)[cont].fecha.dia ,(*nota)[cont].fecha.mes, (*nota)[cont].fecha.anno,(*nota)[cont].descrip,(*nota)[cont].materia,(*nota)[cont].alum,(*nota)[cont].not);
}
fprintf(f,"%s-%s-%s-%s-%s-%s-%s",(*nota)[cont].fecha.dia ,(*nota)[cont].fecha.mes, (*nota)[cont].fecha.anno,(*nota)[cont].descrip,(*nota)[cont].materia,(*nota)[cont].alum,(*nota)[cont].not);
fclose(f); //Cierre del fichero.
}
