#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Materias.h"
#include "alumnos.h"
#include"horarios.h"
#include "usuarios.h"

/* Cabecera: int busca_hora(int hora,int dia, int ID_pro,int *B,horari *horarios)
   Precondicion: le debe llegar la hora, el dia y la ID de un profesor valido
   Postcondicion: busca si el profesor tiene clase en la hora y el dia indicados */
int busca_hora(int hora,int dia, int ID_pro,int B,horari *horarios){
    int i;
    for(i=0;i<B;i++){
        if(ID_pro==horarios[i].ID_prof && hora==horarios[i].hora_clase && horarios[i].dia_clase==dia){
            return i;
            }
        }
    return -1;
}

/*
cabecera: void modi_hora(int i,int *Y,materia *mater)
Precondicion: Le debe llegar una posicion del vector
Postcondicion: Modifica la materia a la que va a dar clase un profesor
*/
/*ARREGLAR*/
void modi_hora(int i,materia *mater){
    int Y=tam_materia(); //Tama–o materia.txt
    char nuevamater[5];
     int o=0,l=0;
    do{
    printf("Introduzca el ID de la nueva materia o pulse 0 \n");
    scanf("%s",nuevamater);
    }while(strtol(nuevamater,NULL,10)<0 || strtol(nuevamater,NULL,10)>9999);
    if(strtol(nuevamater,NULL,10)==0){
        return;
        }
    else{
        do{
            if(strcmp(mater[l].id,nuevamater)==0){
                    o=1;}
            l++;
            }while((o=0) && (l!=Y));
            if(o==0){
                printf("El ID introducido no se ha encontrado o no existe \n");
                modi_hora(i,Y, mater);
                }
            else{
                strcpy(horarios[i].ID_materia,nuevamater);
            }
        }
}
/* Cabecera: void grupo_hora(int i, int *A,r_alum *alum)
   Precondicion: Le debe llegar la posicion del vector
   Postcondicion: Cambia el grupo al que dara clase el profesor */
void grupo_hora(int i,r_alum *alum){
    int A=tam_alumnos("alumnos.txt"); //Tama–o alumnos
    int o,l,u;
    char nuevaclase[10];
    printf("Introduzca la clase a donde quiere mover la clase \n");
    scanf("%s", nuevaclase);
        do{
            if(strcmp(nuevaclase,alum[l].Grupo)==0){
                o=1;}
            l++;
        }while((o=0)&& (l!=A));
        if(o==0){
            printf("La clase introducida no se ha encontrado o no existe \n");
            do{
            printf("ÀQuiere salir? Pulse 1 para si y 0 para no \n");
            scanf("%i",&u);
            }while(u<0 || u>1);
            if(u==1){
                return;
            }
            else{
                grupo_hora(i,alum);
            }
        }
        else{
            strcpy(horarios[i].grupo,nuevaclase);
            printf("Se ha completado el cambio con exito \n");
            return;
        }
}
/* Cabecera: void cambia_hora(int i, int *B,horari *horarios)
   Precondicion:Le debe llegar la posicion del vector
   Postcondicion: Cambia una clase de hora a otra que hora que este libre */
void cambia_hora(int i, int B,horari *horarios){
    int o,dia,hora,salir;
    do{
            do{
            printf("Indique el dia al que quiere cambiar la clase \n");
            scanf("%i",&dia);
            }while(dia<1 || dia>5);
        
            do{
            printf("Indique la hora del dia a la que quiere cambiar la clase \n");
            scanf("%i",&hora);
            }while(hora<1 || hora>6);
        if(busca_hora(hora,dia,horarios[i].ID_prof, B,horarios)==-1)
                o++;
        
        else{
            printf("La hora escogida ya tiene una clase \n");
            do{
            printf("ÀDesea salir de este menu? Marque 1 para si y 0 para no \n");
            scanf("%i",&salir);
            }while(salir!=1 || salir!=0);

            if(salir==1)
                return;
        }
    }while(o==0);
    horarios[i].dia_clase=dia;
    horarios[i].hora_clase=hora;
}

/* Cabecera: void modificar_hora(int ID_pro, int *M, int B,horari *horarios,r_alum *alum,usuario *usuar,materia *mater)
   Precondicion:Le debe llegar el ID del profesor
   Postcondicion: Abre un menu para seleccionar que quiere hacer con la hora seleccionada */
void modificar_hora(int ID_pro, int B,horari *horarios,r_alum *alum,materia *mater){
    int i,dia,hora,x;
    do{
        do{
            printf("Elija dia, entre el 1 y el 5, o 0 si desea volver \n");
            scanf("%i",&dia);
            if(dia==0)
                    return;
            
        }while(dia<1 || dia>5);
        
        do{
            printf("Introduzca la hora en un rango de 1 a 6 \n");
            scanf("%i",&hora);
        }while(hora<1 || hora>6);
        
        x=busca_hora(hora,dia,ID_pro,B, horarios);
        
        if(x<1 || x> num_usuarios){
            printf("Lo siento, no se ha encontrado o no existe clase en la hora a la que quiere acceder. Intentelo de nuevo :) \n");
            }
    }while(x<1 || x> num_usuarios);
    
    printf("Se ha encontrado clase en la hora accedida\n");
    do{
    printf("ÀQue desea modificar de esta clase?\n");
    printf(" 1.La materia a la que dara clase el profesor \n 2.El grupo al que dara clase el profesor \n");
    printf(" 3.Tambien puede cambiar el dia y la hora de esta clase\n");
    printf(" Advertencia: Tenga en cuenta, que solo se podra cambiar esta clase a una hora que no tenga una clase previa asignada \n");
    printf(" 4.Salir al anterior menu");
    scanf("%i",&i);
    }while(i<1 || i>4);
    switch(i){
        case 1: modi_hora(i,mater);
                break;

        case 2: grupo_hora(i,alum);
                break;

        case 3: cambia_hora(i,B, horarios);
                break;

        case 4: return;
                break;
        }
}

/* Cabecera: int elige_grupo(char *ID, int *B,horari *horarios)
   Precondicion: Le debe llegar la ID del profesor
   Postcondicion: Le dice que clases tiene ese dia y devuelve la posicion del vector de la clase elegida sino devuelve -1 */
int elige_grupo(char *ID, int B,horari *horarios){
    int i, j, k,p,dia_clas, ID_pro;
    long ID_p;
    ID_p=strtol(ID,NULL,10);
    ID_pro=(int)ID_p;

    do{
        printf("Introduzca el dia al que quiere acceder \n Introduzca un numero del 1-5 siendo el 1 el lunes, el 2 martes, el 3 miercoles, el 4 jueves y el 5 viernes \n");
        scanf("%i", &dia_clas);

    }while(dia_clas>5 || dia_clas<1);


    printf("Estas son las clases que tiene en este día:\n");
    do{
        printf("A la hora %i tiene ",k);
        j=0;
        for(i=0;i>B;i++){
            if(ID_pro==horarios[i].ID_prof && dia_clas==horarios[i].dia_clase && k==horarios[i].hora_clase){
                printf("con la clase %s para dar la asignatura %i\n", horarios[i].grupo, horarios[i].ID_materia);
                k++;
                j=1;
                do{
                    printf("ÀDesea elegir este grupo?\n Elige 1 para si y 0 para no \n");
                    scanf("%i",&p);
                    }while(p!=0 && p!=1);
                if(p==1){
                        printf("%s", horarios[i].grupo);
                        return i;}
                }
        }
        if(j==0)
            printf("hora libre\n");
            
        k++;
    }while(k<=5);
return -1;
}
/* Cabecera: void aniadir_hora(int ID_pro, int B,horari *horarios,r_alum *alum,usuario *usuar,materia *mater)
   Precondicion: Le debe llegar la ID de un profesor
   Postcondicion: Le deja aniadir a un admin una clase a un profesor siempre que el hueco elegido este libre */
void aniadir_hora(int ID_pro, int B,horari *horarios,r_alum *alum,materia *mater){
    int a, b,i,l,c;
    do{
        printf("Introduzca el dia de la semana en que quiere aniadir la clase \n El numero debera ser del 1-5 donde sera lunes, martes, miercoles, jueves y viernes, respectivamente");
        scanf("%i",&a);
    }while(a<1 || a>5);
    
    do{
        printf("Introduzca la hora del dia en que quiere aniadir la clase \n El numero debera ser del 1-6 donde sera primera, segunda, tercera, cuarta, quinta y sexta hora respectivamente");
        scanf("%i",&b);
    }while(b<1 || b>6);
    
    for(i=0;i<B;i++){
        if(horarios[i].ID_prof==ID_pro && horarios[i].dia_clase==a && horarios[i].hora_clase==b)
            l=0;
        }
    
    if(l==0){
        printf("El profesor %i ya tiene clase el dia %i en la hora numero %i \n", ID_pro, a, b);
        do{
            printf("ÀDesea modificarla, introducir otros parametros o desea salir?. Introduce 1 para lo primero, 2 para lo segundo o 3 para lo tercero\n");
            scanf("%i",&c);
        }while(c<1 || c>3);
        switch(c){
            case 1: modificar_hora(ID_pro,B,horarios,alum,mater);
                    break;
            case 2: aniadir_hora(ID_pro,B,horarios,alum,mater);
                    break;
            case 3: return;
                    break;
            }
    }
    else{
        horarios=(horari*)realloc(horarios,sizeof(horari)*(B+1));           //Preguntar sobre el realloc
        horarios[B-1].dia_clase=a;
        horarios[B-1].hora_clase=b;
        horarios[B-1].ID_prof=ID_pro;
        }
}

/* Cabecera: void eliminar_hora(int ID_pro, int B,horari *horarios)
   Precondicion: Le debe llegar la ID de un profesor
   Postcondicion: Le permite al admin eliminar una clase a un profesor */

void eliminar_hora(int ID_pro, int B,horari *horarios){
    int dia,hora,i,j,p;
    do{
        printf("Introduzca la hora \n");
        scanf("%i",&hora);
    }while(hora<1 || hora>6);
    
    do{
        printf("Introduzca el dia \n");
        scanf("%i",&dia);
    }while(dia<1 || dia>5);
    
    i=busca_hora(hora,dia,ID_pro,B,horarios);
    
    if(i==-1){
        do{
            printf("La hora seleccionada no existe\n ÀDesea introducir otra o volver al anterior menu? Pulse 1 para lo primero o 0 para lo segundo\n");
            scanf("%i",&j);
        }while(j!=0 && j!=1);//Pendiente de revision !!!!!!!!!!!!!!!!!!!!!!
        
        if(j==0)
            return;
            
        else
            eliminar_hora(ID_pro,B,horarios);
            
        }
    else{
        int x=B;
        for(p=i;p<(x-1);p++){
            horarios[p]=horarios[p+1];
        }
        horarios=realloc(horarios,sizeof(horari)*(B-1));
        printf("Eliminado con exito \n");
        printf("Volveras al anterior menu \n");
    }
}

/* Cabecera: int busca(int ID_pro, int *M,usuario *usuar)
   Precondicion: Le debe llegar la ID de un profesor
   Postcondicion: Devuelve 1 si encuentra la ID del profesor y 5 si no lo ha hecho. */
int busca(char *ID_pro,usuario *usuar){//Devuelve 1 si existe la ID pasada y ademas es un profesor
    int i;
    for(i=0;i<num_usuarios;i++){
        if(strcmp("profesor",usuar[i].Perfil_usuario)==0 && strcmp(ID_pro,usuar[i].Id_usuario)==0){
            return 1;
            }
        }
    return 5;
}
/* Cabecera: void admin_hora(int B,horari *horarios,r_alum *alum,usuario *usuar,materia *mater)
 Postcondicion: Le abre el menu de horarios al admin y le manda a las respectivas funciones
*/
void admin_hora(int B,horari *horarios,r_alum *alum,usuario *usuar,materia *mater){
    printf("######################################################################################");
    int a,id;
    printf("Bienvenido a la opcion de horarios \n");
    do{
        printf("En esta opcion, usted puede:\n  1.Modificar un horario ya existente. \n");
        printf("2.Eliminar un horario ya existente. \n 3.Crear un horario desde cero \n");
        printf("Introduzca una opcion del 1-3 o 4 para salir\n");
        scanf("%i",&a);
    }while(a>4 || a<1);
    
    printf("Introduzca el ID de un profesor \n");
    scanf("%i",&id);

    switch(a){
        case 1: modificar_hora(id,B,horarios,alum, mater);
                break;
        case 2: eliminar_hora(id,B,horarios);
                break;
        case 3: aniadir_hora(id,B,horarios,alum,mater);
                break;
        case 4: return;
                break;
        }
}
