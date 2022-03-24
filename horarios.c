#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int A=5,Y=5,MAX=5,M=5,N=5;

typedef struct{
int ID_prof;
int dia_clase;
int hora_clase;
int ID_materia;
char grupo[10];
}horari;
horari horarios[N];

typedef struct{
	char Id_alum[6]; //Identificador escolar
	char Nombre_alum[20]; //Nombre alumno
	char Direc_alum[30]; //Direccion alumno
	char Local_alum[30]; //Localidad del alumno
	char Curso[30]; // Curso al que pertenece
	char Grupo[10];
} r_alum;

r_alum alum[A];

typedef struct{
    int Id_usuario;
    char Nomb_usuario[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];
}usuario;
usuario usuar[M];

typedef struct{
int id;
char nombre[50];
char siglas[3];
}materia;
materia mater[Y];

int busca_hora(int hora,int dia, int ID_pro){
int i;
for(i=0;i<M;i++){
    if(ID_pro==horarios[i].ID_prof && hora==horarios[i].hora_clase && horarios[i].dia_clase==dia){
        return i;
        }
    }
return -1;}

void modi_hora(int i){
int m=0,o=0,l=0;
do{
printf("Introduzca el ID de la nueva materia o pulse 0 \n");
scanf("%i",m);
}while(m<0 || m>9999);
if(m==0){
    return;
    }
else{
    do{
        if(mater[l].id==m){
                o=1;}
        l++;
        }while(o=0 && l!=Y);
        if(o=0){
            printf("El ID introducido no se ha encontrado o no existe \n");
            modi_hora(i);
            }
        else{
            horarios[i].ID_materia=m;
        }
    }
}

void grupo_hora(int i){
int o=0,l=0,u=0;
char c[10];
printf("Introduzca la clase a donde quiere mover la clase \n");
getchar(c);
    do{
    if(strcmp(c,alum[l].Grupo)==0){
        o=1;}
        l++;
    }while(o=0 && l!=A);
    if(o=0){
        printf("La clase introducida no se ha encontrado o no existe \n");
        do{
        printf("¿Quiere salir? Pulse 1 para si y 0 para no \n");
        scanf("%i",u);
        }while(u!=0 || u!=1);
        if(u==1){
            return;
        }
        else{
            grupo_hora(i);
        }
    }
    else{
        cpystr(horarios[i].grupo,c);
        printf("Se ha completado el cambio con exito \n");
        return;
    }
}

void cambia_hora(int i){
int o=0,d=0,h=0,y=0;
do{
do{
printf("Indique el dia al que quiere cambiar la clase \n");
scanf("%i",d);
}while(d<1 || d>5);
do{
printf("Indique la hora del dia a la que quiere cambiar la clase \n");
scanf("%i",h);
}while(h<1 || h>6);
if(busca_hora(h,d,horarios[i].ID_prof)==-1){
    o++;
}
else{
    printf("La hora escogida ya tiene una clase \n");
    do{
    printf("¿Desea salir de este menu? Marque 1 para si y 0 para no \n");
    scanf("%i",y);
    }while(y==1 || y==0);
    if(y==1){
        return;
        }
}
}while(o=0);
horarios[i].dia_clase=d;
horarios[i].hora_clase=h;
}

void modificar_hora(int ID_pro){
int i,d=0,h=0,x=0;
do{
do{
printf("Elija dia, entre el 1 y el 5, o 0 si desea volver \n");
scanf("%i",d);
if(d==0){
        return;
    }
}while(d<1 || d>5);
do{
    printf("Introduzca la hora en un rango de 1 a 6 \n");
    scanf("%i",h);
}while(h<1 || h>6);
x=busca_hora(d,h,ID_pro);
if(x<1 || x>M){
    printf("Lo siento, no se ha encontrado o no existe clase en la hora a la que quiere acceder. Intentelo de nuevo :) \n");
    }
}while(x<1 || x>M);
printf("Se ha encontrado clase en la hora accedida\n");
do{
printf("¿Que desea modificar de esta clase?\n");
printf(" 1.La materia a la que dara clase el profesor \n 2.El grupo al que dara clase el profesor \n");
printf(" 3.Tambien puede cambiar el dia y la hora de esta clase\n");
printf(" Advertencia: Tenga en cuenta, que solo se podra cambiar esta clase a una hora que no tenga una clase previa asignada \n");
printf(" 4.Salir al anterior menu");
scanf("%i",i);
}while(i<1 || i>4);
switch(i){
    case 1: modi_hora(i);
            break;

    case 2: grupo_hora(i);
            break;

    case 3: cambia_hora(i);
            break;

    case 4: return;
            break;
    }
}

int elige_grupo(int ID_pro, int dia_clas){
int i, j, k=1,p;
printf("Estas son las clases que tiene en este día:\n");
do{
j=0;
printf("A la hora %i tiene ",k);
    for(i=0;i>M;i++){
        if(ID_pro==horarios[M].ID_prof && dia_clas==horarios[M].dia_clase && k==horarios[M].hora_clase){
            printf("con la clase %i para dar la asignatura %i\n", horarios[M].grupo, horarios[M].ID_materia);
            k++;
            j=1;
            do{
                printf("¿Desea elegir este grupo?\n Elige 1 para si y 0 para no \n");
                scanf("%i",p);
                }while(p==0 || p==1);
            if(p==1){return i;}
            }
        }
    if(j=0){
        printf("hora libre\n");
        }
k++;
    }while(k<6);
return 0;}

void aniadir_hora(int ID_pro){
int a=0, b=0,i,l=1,c=3;
do{
    printf("Introduzca el dia de la semana en que quiere aniadir la clase \n El numero debera ser del 1-5 donde sera lunes, martes, miercoles, jueves y viernes, respectivamente");
    scanf("%i",a);
}while(a<1 || a>5);
do{
printf("Introduzca la hora del dia en que quiere aniadir la clase \n El numero debera ser del 1-6 donde sera primera, segunda, tercera, cuarta, quinta y sexta hora respectivamente");
scanf("%i",b);
}while(b<1 || b>6);
for(i=0;i<M;i++){
    if(horarios[i].ID_prof==ID_pro && horarios[i].dia_clase==a && horarios[i].hora_clase==b){
        l=0;
        }
    }
if(l==0){
    printf("El profesor %i ya tiene clase el dia %i en la hora numero %i \n", ID_pro, a, b);
    do{
        printf("¿Desea modificarla o introducir otros parametros o desea salir?. Introduce 1 para lo primero, 2 para lo segundo o 3 para lo tercero\n");
        scanf("%i",c);
    }while(c<1 || c>3);
    switch(c){
        case 1: modificar_hora(ID_pro);
                break;
        case 2: aniadir_hora(ID_pro);
                break;
        case 3: return;
                break;
        }
    }
else{
    horarios=realloc(horarios,M+1);           //Preguntar sobre el realloc
    M=M+1;                                  //Preguntar sobre punteros
    horarios[M-1].dia_clase=a;
    horarios[M-1].hora_clase=b;
    horarios[M-1].ID_prof=ID_pro;
                                            //Preguntar sobre materia y sobre el grupo
    }
}

void eliminar_hora(int ID_pro){
int d=0,h=0,i=0,j=0,p;
do{
printf("Introduzca la hora \n");
scanf("%i",h);
}while(h<1 || h>6);
do{
printf("Introduzca el dia \n");
scanf("%i",d);
}while(d<1 || d>5);
i=busca_hora(h,d,ID_pro);
if(i==-1){
    do{
    printf("La hora seleccionada no existe \n ¿Desea introducir otra o volver al anterior menu? Pulse 1 para lo primero o 0 para lo segundo\n");
    scanf("%i",j);
    }while(j!=0 && j!=1);               //Pendiente de revision !!!!!!!!!!!!!!!!!!!!!!
    if(j==0){
        return;
        }
    else{
        eliminar_hora(ID_pro);
        }
    }
else{
    for(p=i;p<(M-1);p++){
        horarios[p]=horarios[p+1];
        }
    horarios=realloc(horarios,M-1);
    M--;
    printf("Eliminado con exito \n");
    printf("Volveras al anterior menu \n");
    }
}

int busca(int ID_pro){              //Devuelve 1 si existe la ID pasada y ademas es un profesor
int i;
for(i=0;i<MAX;i++){
    if(strcmp("profesor",usuar[i].Perfil_usuario)==0 && ID_pro==usuar[i].Id_usuario){
        return 1;
        }
    }
return 5;}

void admin_hora(){
printf("######################################################################################");
int a=4,b=0;
printf("Bienvenido a la opcion de horarios \n");
do{
printf("En esta opcion, usted puede:\n  1.Modificar un horario ya existente. \n");
printf("2.Eliminar un horario ya existente. \n 3.Crear un horario desde cero \n");
printf("Introduzca una opcion del 1-3 o 4 para salir\n");
scanf("%i",a);
}while(a>4 || a<1);
do{
printf("Introduzca el ID de un profesor \n");
scanf("%i",b);
}while((b<1 || b>999) && busca(b)!=1);

switch(a){
    case 1: modificar_hora(b);
            break;
    case 2: eliminar_hora(b);
            break;
    case 3: aniadir_hora(b);
            break;
    case 4: return;
            break;
    }
}
