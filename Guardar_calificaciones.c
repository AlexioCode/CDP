#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "calificaciones.h"
/* Cabecera: void Guardar_calificaciones(calificaciones **nota, int N)
   Precondicion: Le debe llegar el tamanio del vector de tipo calificaciones y esta misma
   Postcondicion: Traspasa la informacion de la estructura al fichero "Calificaciones.txt" con un formato predeterminado */
void Guardar_calificaciones(calificaciones **nota){
int cont;
FILE *f;
f=fopen("Calificaciones.txt","w");
if (f==NULL){ //Comprobaci—n de si el fichero se ha abierto.
    printf("Calificaciones.txt no pudo abrirse.\n");
    exit(-1);
    }
for (cont=0;cont<tam_calif;cont++){
    fprintf(f,"%d-%d-%d-%s-%d-%d-%d\n",(*nota)[cont].fecha.dia ,(*nota)[cont].fecha.mes, (*nota)[cont].fecha.anno,(*nota)[cont].descrip,(*nota)[cont].materia,(*nota)[cont].alum,(*nota)[cont].not);
    }
fclose(f); //Cierre del fichero.
}
