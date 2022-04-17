#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Guardar_Horarios(horari *horarios){
int cont;
FILE *f;
f=fopen("Horarios.txt","w");
if (f==NULL){ //Comprobaci�n de si el fichero se ha abierto.
    printf("Horarios.txt no pudo abrirse.\n");
    exit(-1);
}
for (cont=0;cont<tam_horari-1;cont++){
    fprintf(f,"%d-%d-%d-%d-%s\n",horarios[cont].ID_prof ,horarios[cont].dia_clase, horarios[cont].hora_clase,horarios[cont].ID_materia,horarios[cont].grupo);
}
    fprintf(f,"%d-%d-%d-%d-%s\n",horarios[cont].ID_prof ,horarios[cont].dia_clase, horarios[cont].hora_clase,horarios[cont].ID_materia,horarios[cont].grupo);
fclose(f); //Cierre del fichero.
}
