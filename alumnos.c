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
        printf("Linea: %s-%s-%s-%s-%d-%d\n ",alum[a].Id_alum, alum[a].Nombre_alum, alum[a].Direc_alum, alum[a].Local_alum, alum[a].Curso, alum[a].Grupo);
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

//Cabecera: void Guardar_Alumnos(r_alum **alum, int *A)
// Precondici—n: estructura realizada y tamaño A
//Postcondici—n: estructura cargada en fichero
void Guardar_Alumnos(r_alum **alum, int *A)
{
int cont;
FILE *f;
f=fopen("alumnos.txt","w");
if (f==NULL) //Comprobación de si el fichero se ha abierto.
{
    printf("Alumnos.txt no pudo abrirse.\n");
    exit(-1);
}
for (cont=0;cont<*A;cont++)
{
    fprintf(f,"%s-%s-%s-%s-%d-%d\n ",alum[a].Id_alum, alum[a].Nombre_alum, alum[a].Direc_alum, alum[a].Local_alum, alum[a].Curso, alum[a].Grupo);
}

fclose(f); //Cierre del fichero.
}

//Cabecera:void baja(int alumno)
//Precondición: Recibe la estructura con un alumno.
//Postcondición: Da de alta al alumno seleccionado.

void alta(r_alum *alum){
    int nuevoid,nuevonombre,nuevodirec,nuevolocal,nuevocurso,nuevogrupo, res;
    printf("Introduzca los datos siguientes del alumno que quiere añadir:")
    printf("Id: ");
    scanf("%c",&nuevoid);
    printf("Nombre: ");
    scanf("%c",&nuevonombre);
    printf("Dirección: ");
    scanf("%c",&nuevodirec);
    printf("Localidad: ");
    scanf("%c",&nuevolocal);
    printf("Curso: ");
    scanf("%c",&nuevocurso);
    printf("Grupo:");
    scanf("%c",&nuevogrupo);
    alum=realloc(alum,N+1);
    alum[N+1].Id_alum=nuevoid;
    alum[N+1].Nombre_alum=nuevonombre;
    alum[N+1].Direc_alum=nuevodirec;
    alum[N+1].Local_alum=nuevolocal;
    alum[N+1].Curso=nuevocurso;
    alum[N+1].Grupo=nuevogrupo;
    printf("Alumno añadido");

        do{
        printf("¿Quiere dar de baja a otro alumno? Si / No");
        scanf("%c", &res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));
        if(strcmp(res,"Si")==0)
            alta(alum); //Si escribe "Si" vuelve a empezar
        else{
                break;
                return;     //Si escribe "No" sale de la función
            }

}


//Cabecera:void baja(int alumno)
//Precondición: Recibe la estructura inicializada
//Postcondición: Da de baja al alumno seleccionado.
void baja(r_alum *alum){
    int i,j,res,alumno,res2;
    printf("Introduzca el ID del alumno que quiera dar de baja:");
    scanf("%c",&alumno);
    for(i=0; i<N;i++){
        if(strcmp(alum[i].Id_alum,alumno)==0){
            printf("El alumno %s se llama %s",alum[i].Id_alum,alum[i].Nombre_alum);

                printf("¿Desea dar de baja al alumno? Introduzca Si / No");
                scanf("%c",&res);
            }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));
            if((strcmp(res,Si)==0)){
                for(j=i;j<(N-1);j++){
                    alum[j]=alum[j+1];
                }
            printf("Alumno dado de baja");
            }
            alumno=realloc(alumno,N-1);
            else{
                break;
                return;
        }
       else
           printf("Error. Id no encontrado")
    }
    do{
    printf("¿Quiere dar de baja a otro alumno? Si / No");
    scanf("%c", &res2);
    }while((strcmp(res2,"Si")!=0) && (strcmp(res2,"No")!=0));
    if(strcmp(res2,"Si")==0)
        baja(alum); //Si escribe "Si" vuelve a empezar
    else{
            break;
            return;     //Si escribe "No" sale de la función
        }
}


//Cabecera:void modalum(r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum){
    int nuevoid,mod,i,j, nuevonombre,nuevodirec,nuevolocal,nuevogrupo,nuevocurso,res;

    printf("Introduzca el ID del alumno que quiere modificar: ");
    scanf("%c",&nuevoid);
    for(j=0;j<N;j++){
        if(strcmp(alum[j].Id_alum,nuevoid)==0){
            printf("¿Qué quiere modificar del alumno seleccionado?");

        do{
        printf("Introduzca 1 para modificar el nombre\n Introduzca 2 para modificar la dirección\n Introduzca 3 para modificar la localidad\n Introduzca 4 para modificar el curso\n Introduzca 5 para modificar el grupo");
        scanf("%d",&mod);
        }while(mod>5 || mod<1);

        //for(i=0;i<N;i++){
           // if(strcmp(alum[i].Id_alum,nuevoid)==0)){
                switch (mod) {
                    case 1:
                        printf("Introduzca el nuevo nombre");
                        scanf("%c",&nuevonombre);
                        alum[i].Nombre_alum=nuevonombre;
                        break;
                    case 2:
                        printf("Introduzca la nueva dirección");
                        scanf("%c",&nuevodirec);
                        alum[i].Direc_alum=nuevodirec;
                        break;
                    case 3:
                        printf("Introduzca la nueva localidad");
                        scanf("%c",&nuevolocal);
                        alum[i].Local_alum=nuevolocal;
                        break;
                    case 4:
                        printf("Introduzca la nueva localidad");
                        scanf("%c",&nuevocurso);
                        alum[i].Curso=nuevocurso;
                        break;
                    default
                        printf("Introduzca la nueva localidad");
                        scanf("%c",&nuevogrupo);
                        alum[i].Grupo=nuevogrupo;
                        break;
                        }
                }
           }
        do{
        printf("¿Quiere modificar otro alumno? Si/No");
        scanf("%c",&res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));

        if(strcmp(res,"Si")==0)
            modalum(alum); //Si escribe "Si" vuelve a empezar
        else{
                break;
                return;     //Si escribe "No" sale de la función
            }
    }
    else
        printf("Error. Id no encontrado");


    }
}

//Cabecera:void listaalumprof (r_alum*alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos

void listaalumprof (r_alum *alum){
    int i,res;
    for(i=0;i<N;i++){
        printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
        }
    do{
     printf("¿Quiere modificar algún dato?");
     scanf("%d",&res);
    }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));
    if(strcmp(res,"Si")==0)
        modalum(alum);
    else{
        break;
        return;
    }
}

//Cabecera:void listaalumadm (r_alum*alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos
void listaalumadm (r_alum *alum){
    int i,res;
    do{
     printf("Introduzca 1 si quiere dar de alta\n Introduzca 2 si quiere dar de baja\n Introduzca 3 si quiere modificar\n Introduzca 4 si quiere listar todos los alumnos");
     scanf("%d",&res);
    }while(res<1 || res>4);
    switch (res) {
        case 1:
            alta(alum);
            break;
        case 2:
            baja(alum);
            break;
        case 3:
            modalum(alum);
            break;
        default //Caso 4
            //Listar
            for(i=0;i<N;i++){
                printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
                }
            break;
            }
}


