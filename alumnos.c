#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "alumnos.h"
#include "Materias.h"
#include "calificaciones.h"


r_alum *alum;//Estructura

//cabecera: int n_lineas(char * fichero)
//precondicion: fichero es el nombre del fichero cuyo numero de lineas quieres contar
//postcondicon: devuelve el numero de lineas que tiene fichero
int n_lineas(char * fichero)
{
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("alumnos.txt", "r")) == NULL)
    {
        printf("No se ha podido abrir el fichero %s", fichero);
        exit(1);
    }
    else
    {
        c = getc(fich);
        while(c != EOF)
        {
            c = getc(fich);
            if(c == '\n')   //una linea por cada caracter '\n'
                n++;
        }
        fclose(fich);
    }
    return n;
}

//Cabecera: void cargar_estructura ()
//Precondici—n: Puntero a fichero
//Postcondici—n: Estructura cargada en fichero
void cargar_estructura (r_alum ** v_alumno){
    tam_alum = n_lineas("alumnos.txt");//variable global que guarda el numero de usuarios que hay en el vector de usuarios

    char cadena[150];
    unsigned i=0;
    FILE *f;
    f=fopen("alumnos.txt", "r");//Abrimos fichero
    v_alumno=(r_alum*)malloc(sizeof(r_alum)*tam_alum);
    r_alum aux;

    if(f){  //Controla si se ha podido abrir el fichero
        while(!feof(f)){
            fgets(cadena, 150, f);
            sscanf(cadena,"%[^-]/%[^-]/%[^-]/%[^-]/%s[^-]/%s[^-]/",aux.Id_alum, aux.Nombre_alum, aux.Direc_alum, aux.Local_alum, aux.Curso, aux.Grupo);
            alum[i]=aux;
            i++;
                        }
            fclose(f);
        }//Fin while
    else
    printf("Error al abrir el fichero alumnos.txt\n");
    }//Fin cargar_estructura

//Cabecera: void Guardar_Alumnos(r_alum *alum)
// Precondición: estructura realizada
//Postcondición: estructura cargada en fichero
void Guardar_Alumnos(r_alum **v_alumno){
int cont;
FILE *f;
f=fopen("alumnos.txt","w");
    if (f==NULL){ //Comprobación de si el fichero se ha abierto.
        printf("Alumnos.txt no pudo abrirse.\n");
        exit(-1);
    } //Fin if
    for (cont=0;cont<tam_alum;cont++){
        fprintf(f,"%s-%s-%s-%s-%s-%s\n ",alum[cont].Id_alum, alum[cont].Nombre_alum, alum[cont].Direc_alum, alum[cont].Local_alum, alum[cont].Curso, alum[cont].Grupo);
    }//Fin for
fclose(f); //Cierre del fichero.
}//Fin Guardar_alumnos

//Cabecera:void alta(r_alum* alum)
//Precondición: Recibe la estructura inicializada.
//Postcondición: Da de alta al alumno seleccionado.
void alta(r_alum* alum){
    char res[3];
    tam_alum=tam_alum+1;
    alum= (r_alum*) malloc(sizeof(r_alum)*(tam_alum+1));//Aumentamos la reserva +1
    printf("Introduzca los datos siguientes del alumno que quiere añadir:");
    printf("Id: ");
    scanf("%s",alum[tam_alum+1].Id_alum);
    printf("Nombre: ");
    scanf("%s",alum[tam_alum+1].Nombre_alum);
    printf("Dirección: ");
    scanf("%c",alum[tam_alum+1].Direc_alum);
    printf("Localidad: ");
    scanf("%c",alum[tam_alum+1].Local_alum);
    printf("Curso: ");
    scanf("%c",alum[tam_alum+1].Curso);
    printf("Grupo:");
    scanf("%c",alum[tam_alum+1].Grupo);
    printf("Alumno añadido");

    do{
        printf("¿Quiere dar de alta a otro alumno? Si / No");
        scanf("%s",res);
    }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que solo se introduzca un Si o No
    if(strcmp(res,"Si")==0)
            alta(alum); //Si escribe "Si" vuelve a empezar
        else{
                Guardar_Alumnos(alum);
                return;     //Si escribe "No" sale de la función
            }
}


//Cabecera:void baja(r_alum *alum)
//Precondición: Recibe la estructura inicializada
//Postcondición: Da de baja al alumno seleccionado.
void baja(r_alum *alum){
    int i,j;
    char alumno[7],res[3],res2[3];
    printf("Introduzca el ID del alumno que quiera dar de baja:");
    scanf("%s",alumno); //Introducir alumno que se requiera dar de baja
    for(i=0; i<tam_alum;i++){ //Recorremos desde i hasta A(tamaño del fichero)
        if(strcmp(alum[i].Id_alum,alumno)==0){ //Si coincide el id de la estructura con el introducido:
            printf("El alumno %s se llama %s",alum[i].Id_alum,alum[i].Nombre_alum); //Escribir su id y nombre:

            do{printf("¿Desea dar de baja al alumno? Introduzca Si / No"); //Aseguramos que se quiera dar de baja
                scanf("%s",res);
            }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));

            if((strcmp(res,"Si")==0)){ //Si introduce 'Si' damos de baja
                tam_alum = tam_alum-1;
                alum= (r_alum*) malloc(sizeof(r_alum)*(tam_alum-1));//Reservamos nuevo espacio de memoria
                tam_calif--;
                for(j=i;j<tam_alum;j++){
                    alum[j]=alum[j+1]; //Sustituyo posicion del alumo por la siguiente
                }
                printf("Alumno dado de baja");
                }//Fin if
            else
                return; //Si el alumno inserta "No", volver
        } //Fin if
    }//Fin for
//VOLVER A PREGUNTAR POR SI QUIERE DAR DE BAJA A ALGUIEN MAS
    do{
        printf("¿Quiere dar de baja a otro alumno? Si / No");
        scanf("%s", res2);
    }while((strcmp(res2,"Si")!=0) && (strcmp(res2,"No")!=0));
    if(strcmp(res2,"Si")==0)//Si dice "Si", llamamos de nuevo a la función
        baja(alum); //Vuelve a empezar
    else{
        Guardar_Alumnos(alum);
        return;     //Si escribe "No" sale de la función
        }
}//Fin función


//Cabecera:void modalum(r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum){
    int mod,j;
    char nuevoid[6],res[3];
    printf("Introduzca el ID del alumno que quiere modificar: ");
    scanf("%s",nuevoid);
    for(j=0;j<tam_alum;j++){ //Recorremos
        if(strcmp(alum[j].Id_alum,nuevoid)==0){ //Si coincide, hemos encontrado al alumno
            printf("¿Qué quiere modificar del alumno seleccionado?"); //Preguntamos:

            do{
            printf("Introduzca 1 para modificar el nombre\n Introduzca 2 para modificar la dirección\n Introduzca 3 para modificar la localidad\n Introduzca 4 para modificar el curso\n Introduzca 5 para modificar el grupo");
            scanf("%d",&mod); //Guardamos valor el mod
            }while(mod>5 || mod<1);//Aseguramos que entre un valor del 1 al 5

                switch (mod) { //Para las distintas opciones
                    case 1: //Si mod=1
                        printf("Introduzca el nuevo nombre");
                        scanf("%s",alum[j].Nombre_alum);
                        break;
                    case 2: //Si mod=2
                        printf("Introduzca la nueva dirección");
                        scanf("%s",alum[j].Direc_alum);
                        break;
                    case 3: //Si mod=3
                        printf("Introduzca la nueva localidad");
                        scanf("%s",alum[j].Local_alum);
                        break;
                    case 4: //Si mod=4
                        printf("Introduzca la nueva localidad");
                        scanf("%s",alum[j].Curso);
                        break;
                        default://Si mod =5
                        printf("Introduzca la nueva localidad");
                        scanf("%s",alum[j].Grupo);
                        break;
                }//Fin switch
            } //Fin if
        }//Fin for
    //VOLVER A PREGUNTAR POR SI QUIERE DAR DE BAJA A ALGUIEN MAS
        do{
            printf("¿Quiere modificar otro alumno? Si/No"); //Preguntamos si quiere modificcar otro alumno
            scanf("%s",res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que solo entre Si o No
        if(strcmp(res,"Si")==0) //Si res= "Si"
                    modalum(alum); //Llamamos de nuevo a la función, vuelve a empezar
        else
                Guardar_Alumnos(alum);
                return;     //Si escribe "No" sale de la función

    }


//Cabecera:void listaalumprof (r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos

void listaalumprof (r_alum *alum){
    int i;
    char res[3];
    for(i=0;i<tam_alum;i++){ //Recorremos el fichero y listamos los alumnos
        printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
        }//Fin for
    do{
        printf("¿Quiere modificar algún dato?"); //damos la opción de modificar algún dato de la lista
        scanf("%s",res);
    }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0)); //Aseguramos que solo se introduce Si o No
    if(strcmp(res,"Si")==0) //Si pone "Si"
        modalum(alum); //Llamamos a la función modificar alumnos
    else{
        Guardar_Alumnos(alum);
        return;//Si pone "No", salimos
    }
}

//Cabecera:void listaalumadm (r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos
void listaalumadm (r_alum *alum){
    int i,res;
    char mod[3];
    do{
     printf("Introduzca 1 si quiere dar de alta\n Introduzca 2 si quiere dar de baja\n Introduzca 3 si quiere modificar\n Introduzca 4 si quiere listar todos los alumnos");
     scanf("%d",&res);
    }while(res<1 || res>4); //Aseguramos que mete un número del 1 al 4
    switch (res) { //Damos opciones
        case 1:
            alta(alum); //Dar de alta
            break;
        case 2:
            baja(alum);//Dar de baja
            break;
        case 3:
            modalum(alum);//modificar
            break;
        default: //Caso 4
            //Listar
            for(i=0;i<tam_alum;i++){
                printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
            } //Fin for
            //Fin caso 4
                break;
    }//Fin switch
//Preguntamos si quiere realizar algo más
    do{
        printf("¿Quiere modificar algún dato?");
        scanf("%s",mod);
    }while((strcmp(mod,"Si")!=0) && (strcmp(mod,"No")!=0));//Aseguramos que se introduzca Si o No
    if(strcmp(mod,"Si")==0) //Si pone "Si"
        modalum(alum); //volvemos a llamar a la función
    else{
        Guardar_Alumnos(alum);
        return;//Si pone "No", salimos
    }
}//Fin programa

//Cabecera:ficha_alumno(char* id_alumno,r_alum *alum )
//Precondición: Recibe estructura inicializada y el id de un alumno en concreto
//Postcondición: Devuelve lista de un alumno con opcion a modificar datos
void ficha_alumno(char* id_alumno,r_alum *alum){
    int i;
    char mod[3],res[3], nuevo_id[7];
    for(i=0;i<A;i++){ //Recorremos estructura
        if(strcmp(id_alumno,alum[i].Id_alum)==0){
            printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo);
        }
    }
    //Preguntamos si quiere realizar algo más
    do{
        printf("¿Quiere modificar algún dato?");
        scanf("%s",mod);
    }while((strcmp(mod,"Si")!=0) && (strcmp(mod,"No")!=0));//Aseguramos que se introduzca Si o No
    if(strcmp(mod,"Si")==0) //Si pone "Si"modalum(r_alum *alum)
        modalum(alum); //volvemos a llamar a la función
    else{
        do{
            printf("¿Quiere buscar otro alumno?"); //Si no quiere modificar datos, preguntamos por otra búsqueda
            scanf("%s",res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que se introduzca Si o No
        if(strcmp(res,"Si")==0){ //Si es que "Si", ingresamos otro id
            printf("Ingrese el id de otro alumno: ");
            scanf("%s",nuevo_id);
            ficha_alumno(nuevo_id,alum); //Volvemos a llamar a la función
        }
        else{
            Guardar_Alumnos(alum);
            return; //Si pone "No", salimos
        }
    }
}
//Cabecera: void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat)
//Precondición: Recibe estructura inicializada, grupo de un alumno y materia
//Postcondición: Devuelve lista de alumnos del grupo determinado en la materia determinada
void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat){
    int i,j;
    for(i=0;i<tam_alum;i++){//Recorremos alumnos
        for(j=0;j<tam_mat;j++){ //Recorremos materias
            if((strcmp(grupo,alum[i].Grupo)==0)&&(strcmp(idmateria, r_mat[j].id)==0)){
                printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo);
            }
        }
    }
}
