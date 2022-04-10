#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "alumnos.h"
#include "Materias.h"


r_alum *alum;//Estructura

//Cabecera: int tam_alumnos(char *fichero)
//Precondici—n: Puntero a fichero
//Postcondici—n: Tamaño del fichero alumnos.txt
int tam_alumnos(r_alum ** v_alumno){
    int n = 0;
    char c;
    FILE *fich;
    if((fich = fopen("alumnos.txt", "r")) == NULL){ //Si no encontramos fichero, salimos
        printf("No se ha podido abrir el fichero %s",fichero);
        exit(1);
    }//Fin if
    else{ //Recorremos ficheros y contamos
        c = getc(fich);
        while(c != EOF){
            c = getc(fich);
        if(c == '\n')   //una linea por cada caracter '\n'
            n++;
        }//Fin while
        fclose(fich);
    }//Fin else
    return n;
}//Fin tam_alumnos

//Cabecera: void cargar_estructura (char *fichero)
//Precondici—n: Puntero a fichero
//Postcondici—n: Estructura cargada en fichero
void cargar_estructura (r_alum ** v_alumno){
    int A= tam_alumnos("alumnos.txt");
    char cadena[150];
    unsigned i=0;
    int a;
    FILE *f;
    f=fopen("alumnos.txt", "r");//Abrimos fichero
    alum=(r_alum*)malloc(sizeof(r_alum)*A);
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

    for(a=0;a<9;a++){ //Recorrer el vector de alumnos
        printf("Linea: %s-%s-%s-%s-%s-%s\n ",alum[a].Id_alum, alum[a].Nombre_alum, alum[a].Direc_alum, alum[a].Local_alum, alum[a].Curso, alum[a].Grupo);
    }//Fin for
}//Fin cargar_estructura

//Cabecera: void Guardar_Alumnos(r_alum *alum)
// Precondición: estructura realizada
//Postcondición: estructura cargada en fichero
void Guardar_Alumnos(r_alum **v_alumno){
int A= tam_alumnos("alumnos.txt");
int cont;
FILE *f;
f=fopen("alumnos.txt","w");
    if (f==NULL){ //Comprobación de si el fichero se ha abierto.
        printf("Alumnos.txt no pudo abrirse.\n");
        exit(-1);
    } //Fin if
    for (cont=0;cont<A;cont++){
        fprintf(f,"%s-%s-%s-%s-%s-%s\n ",alum[cont].Id_alum, alum[cont].Nombre_alum, alum[cont].Direc_alum, alum[cont].Local_alum, alum[cont].Curso, alum[cont].Grupo);
    }//Fin for
fclose(f); //Cierre del fichero.
}//Fin Guardar_alumnos

//Cabecera:void alta(r_alum* alum)
//Precondición: Recibe la estructura inicializada.
//Postcondición: Da de alta al alumno seleccionado.
void alta(r_alum* alum){
    int A= tam_alumnos("alumnos.txt");
    char res[3];
    alum= (r_alum*) malloc(sizeof(alum)*(A+1));//Aumentamos la reserva +1
    printf("Introduzca los datos siguientes del alumno que quiere añadir:");
    printf("Id: ");
    scanf("%s",alum[A+1].Id_alum);
    printf("Nombre: ");
    scanf("%s",alum[A+1].Nombre_alum);
    printf("Dirección: ");
    scanf("%c",alum[A+1].Direc_alum);
    printf("Localidad: ");
    scanf("%c",alum[A+1].Local_alum);
    printf("Curso: ");
    scanf("%c",alum[A+1].Curso);
    printf("Grupo:");
    scanf("%c",alum[A+1].Grupo);
    printf("Alumno añadido");

    do{
        printf("¿Quiere dar de alta a otro alumno? Si / No");
        scanf("%c",res);
    }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que solo se introduzca un Si o No
    if(strcmp(res,"Si")==0)
            alta(alum); //Si escribe "Si" vuelve a empezar
        else{
                return;     //Si escribe "No" sale de la función
            }

}


//Cabecera:void baja(r_alum *alum)
//Precondición: Recibe la estructura inicializada
//Postcondición: Da de baja al alumno seleccionado.
void baja(r_alum *alum){
    int A= tam_alumnos("alumnos.txt"); //Tamaño del fichero en A
    int i,j;
    char alumno[7],res[3],res2[3];
    printf("Introduzca el ID del alumno que quiera dar de baja:");
    scanf("%c",alumno); //Introducir alumno que se requiera dar de baja
    for(i=0; i<A;i++){ //Recorremos desde i hasta A(tamaño del fichero)
        if(strcmp(alum[i].Id_alum,alumno)==0){ //Si coincide el id de la estructura con el introducido:
            printf("El alumno %s se llama %s",alum[i].Id_alum,alum[i].Nombre_alum); //Escribir su id y nombre:
            
            do{printf("¿Desea dar de baja al alumno? Introduzca Si / No"); //Aseguramos que se quiera dar de baja
                scanf("%c",res);
            }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));
            
            if((strcmp(res,"Si")==0)){ //Si introduce 'Si' damos de baja
                alum= (r_alum*) malloc(sizeof(alum)*(A-1));//Reservamos nuevo espacio de memoria
                for(j=i;j<(A-1);j++){
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
        scanf("%c", res2);
    }while((strcmp(res2,"Si")!=0) && (strcmp(res2,"No")!=0));
    if(strcmp(res2,"Si")==0)//Si dice "Si", llamamos de nuevo a la función
        baja(alum); //Vuelve a empezar
    else{
        return;     //Si escribe "No" sale de la función
        }
}//Fin función


//Cabecera:void modalum(r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Alumno que ha seleccionado el usuario modificado
void modalum(r_alum *alum){
    int A= tam_alumnos("alumnos.txt"); //Tamaño del fichero
    int mod,j;
    char nuevoid[6],res[3];
    printf("Introduzca el ID del alumno que quiere modificar: ");
    scanf("%s",nuevoid);
    for(j=0;j<A;j++){ //Recorremos
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
            scanf("%c",res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que solo entre Si o No
        if(strcmp(res,"Si")==0) //Si res= "Si"
                    modalum(alum); //Llamamos de nuevo a la función, vuelve a empezar
        else
                return;     //Si escribe "No" sale de la función
                    
    }
       

//Cabecera:void listaalumprof (r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos

void listaalumprof (r_alum *alum){
    int A= tam_alumnos("alumnos.txt"); //Tamaño fichero
    int i;
    char res[3];
    for(i=0;i<A;i++){ //Recorremos el fichero y listamos los alumnos
        printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
        }//Fin for
    do{
        printf("¿Quiere modificar algún dato?"); //damos la opción de modificar algún dato de la lista
        scanf("%c",res);
    }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0)); //Aseguramos que solo se introduce Si o No
    if(strcmp(res,"Si")==0) //Si pone "Si"
        modalum(alum); //Llamamos a la función modificar alumnos
    else{
        return;//Si pone "No", salimos
    }
}

//Cabecera:void listaalumadm (r_alum *alum)
//Precondición: Recibe estructura inicializada
//Postcondición: Devuelve lista de alumnos con opción a modificar alguno de ellos
void listaalumadm (r_alum *alum){
    int A= tam_alumnos("alumnos.txt"); //Tamaño del vector
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
            for(i=0;i<A;i++){
                printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo );
            } //Fin for
            //Fin caso 4
                break;
    }//Fin switch
//Preguntamos si quiere realizar algo más
    do{
        printf("¿Quiere modificar algún dato?");
        scanf("%c",mod);
    }while((strcmp(mod,"Si")!=0) && (strcmp(mod,"No")!=0));//Aseguramos que se introduzca Si o No
    if(strcmp(mod,"Si")==0) //Si pone "Si"
        modalum(alum); //volvemos a llamar a la función
    else{
        return;//Si pone "No", salimos
    }
}//Fin programa

//Cabecera:ficha_alumno(char* id_alumno,r_alum *alum )
//Precondición: Recibe estructura inicializada y el id de un alumno en concreto
//Postcondición: Devuelve lista de un alumno con opcion a modificar datos
void ficha_alumno(char* id_alumno,r_alum *alum ){
    int A= tam_alumnos("alumnos.txt"); //Tamaño del vector
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
        scanf("%c",mod);
    }while((strcmp(mod,"Si")!=0) && (strcmp(mod,"No")!=0));//Aseguramos que se introduzca Si o No
    if(strcmp(mod,"Si")==0) //Si pone "Si"modalum(r_alum *alum)
        modalum(alum); //volvemos a llamar a la función
    else{
        do{
            printf("¿Quiere buscar otro alumno?"); //Si no quiere modificar datos, preguntamos por otra búsqueda
            scanf("%c",res);
        }while((strcmp(res,"Si")!=0) && (strcmp(res,"No")!=0));//Aseguramos que se introduzca Si o No
        if(strcmp(res,"Si")==0){ //Si es que "Si", ingresamos otro id
            printf("Ingrese el id de otro alumno: ");
            scanf("%c",nuevo_id);
            ficha_alumno(nuevo_id,alum ); //Volvemos a llamar a la función
        }
        else
            return; //Si pone "No", salimos
    }
}
//Cabecera: void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat)
//Precondición: Recibe estructura inicializada, grupo de un alumno y materia
//Postcondición: Devuelve lista de alumnos del grupo determinado en la materia determinada
void mostrar_alumnos_grupo_materia(char *grupo, char *idmateria, r_alum *alum, materia *r_mat){
    int A= tam_alumnos("alumnos.txt"); //Tamaño del vector en alumnos
    int tam_max = tam_materia("materias.txt");//Tamaño del vector en materias
    int i,j;
    for(i=0;i<A;i++){//Recorremos alumnos
        for(j=0;j<tam_max;j++){ //Recorremos materias}
            if((strcmp(grupo,alum[i].Grupo)==0)&&(strcmp(idmateria, r_mat[j].id)==0)){
                printf("Alumno: %d | Id: %s | Nombre: %s | Direccion: %s | Localidad: %s | Curso: %s | Grupo: %s",i, alum[i].Id_alum, alum[i].Nombre_alum, alum[i].Direc_alum, alum[i].Local_alum, alum[i].Curso, alum[i].Grupo);
            }
        }
    }
}
