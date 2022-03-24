#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "alumnos.h"

r_alum *alum;
void cargar_estructura (){
	/*CARGAR PRODUCTOS*/
	//Abrimos fichero
	FILE *f;
	f=fopen("alumnos.txt", "r");

    alum=(r_alum*)malloc(sizeof(r_alum)*nLineas("alumnos.txt"));

    r_alum aux;

    char cadena[150];

    unsigned i=0;

    if(f){  //Controla si se ha podido abrir el fichero
		while(!feof(f)){
            fgets(cadena, 150, f);
            sscanf(cadena,"%[^-]/%[^-]/%[^-]/%[^-]/%d[^-]/%d[^-]/",aux.Id_alum, aux.Nombre_alum, aux.Direc_alum, aux.Local_alum, &aux.Curso,&aux.Grupo);
            alum[i]=aux;
            i++;
						}
			fclose(f);
        }
    else
    printf("Error al abrir el fichero alumnos.txt\n");

    int a;
    //Recorrer el vector de alumnos
    for(a=0;a<9;a++){
        printf("Linea: %s-%s-%s-%s-%d-%d\n ",alum[a].id_alum, alum[a].nombre_alum, alum[a].direc_alum, alum[a].local_alum, alum[a].curso, alum[a].grupo;
    }
}
// Cabecera: int nLineas(char* fichero)
//Precondici—n: Puntero a fichero
//Postcondici—n: Informaci—n cargada en el fichero

int nLineas(char* fichero){
    FILE *f=fopen(fichero, "r");
    char cadena[150];
    int cont=0;
    if(f){
        while(!feof(f))
        {fgets(cadena, 150, f);
            cont++;}
        fclose(f);}
    return cont;
    }
//Cabecera: void inicializar(r_alum *alum,int n)
// Precondici—n: estructura realizada
//Postcondici—n: estructura inicializada

void inicializar(r_alum *alum){
	int i;

	for(i=0;i<n;i++){
		fflush(stdin);
		printf("Identificador escolar del alumno %d: ",i);
		fgets(alum[i].Id_alum, 6,stdin);
		fflush(stdin);
		printf("Nombre del alumno %d: ",i);
		fgets(alum[i].Nombre_alum, 20, stdin);
		fflush(stdin);
		printf("Direccion del alumno %d: ",i);
		fgets(alum[i].Direc_alum, 30, stdin);
		fflush(stdin);
		printf("Localidad del alumno %d: ",i);
		fgets(alum[i].Direc_alum, 30, stdin);
		fflush(stdin);
		printf("Curso del alumno %d: ",i);
		fgets(alum[i].Curso, 30, stdin);
		fflush(stdin);
		printf("Grupo del alumno %d: ",i);
		fgets(alum[i].Grupo, 10, stdin);
	}


