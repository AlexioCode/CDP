#include<stdio.h>
#include<stdlib.h>
int *N=5;
//N=calificaciones
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
calificaciones *nota;

int borrar(int alum, int materia,calificaciones *nota,int *N){
int i,j=0,k,u=0;
for(i=0;i<*N;i++){
    if(nota[i].alum==alum && nota[i].materia==materia){
        printf("El dia %i del mes %i en el anno %i saco un %i en el %c\n",nota[i].fecha.dia, nota[i].fecha.mes, nota[i].fecha.anno, nota[i].not, nota[i].descrip);
        do{
        printf("¿Desea eliminar la nota? Introduzca 1 para sí, 0 para no\n");
        scanf("%i",j);
        }while(j!=1 || j!=0);
        if(j==1){
                int x=*N;
            for(k=i;k<(x-1);k++){
                nota[i]=nota[i+1];
                }
            printf("Eliminado completado\n");
            u++;                            //Para disminuir el vector en u elementos
            }
        }
    }
return u;}

void ver_nota(int alum, int materia,calificaciones *nota,int *N){
int i,j=0;
for(i=0;i<*N;i++){
    if(nota[i].alum==alum && nota[i].materia==materia){
        printf("El dia %i del mes %i en el anno %i saco un %i en el %c\n",nota[i].fecha.dia, nota[i].fecha.mes, nota[i].fecha.anno, nota[i].not, nota[i].descrip);
        j++;
        }
    }
if(j==0){
    printf("El alumno buscado no tiene notas guardadas en esta materia\n");
    }
}

void mod_nota(int alum, int materia,calificaciones *nota,int *N){
int i,j=0,k=-1,p=0;
for(i=0;i<*N;i++){
    if(nota[i].alum==alum && nota[i].materia==materia){
        printf("El dia %i del mes %i en el anno %i saco un %i en el %c\n",nota[i].fecha.dia, nota[i].fecha.mes, nota[i].fecha.anno, nota[i].not, nota[i].descrip);
        p++;
        do{
        printf("¿Desea modificar la nota? Introduzca 1 para sí, 0 para no\n");
        scanf("%i",j);
        }while(j==1 || j==0);
        if(j==1){
            do{
            printf("Introduzca una nota valida entre 0-10\n");
            scanf("%i",k);
            }while(k>=0 && k<11);
            nota[i].not==k;
            }
        }
    }
if(p==0){
    printf("El alumno buscado no tiene notas guardadas en esta materia\n");
    }
}

void eliminar_nota(int alum, int materia,calificaciones *nota,int *N){
int i;
i=borrar(alum,materia,calificaciones *nota,int *N);
if(i>0){
    nota=realloc(nota,sizeof(calificaciones*)*(*N-1));
    }
}

void anadir_not(int alum, int materia,calificaciones *nota,int *N){
char descrip[30];
int a=1,b=1,c=2022;
printf("Indica el anno en el que quiere poner la nota\n");
scanf("%i",c);
nota[N-1].fecha.anno==c;
do{
printf("Indica el mes en el que quiere poner la nota\n");
scanf("%i",b);
}while(b<13 && b>0);
nota[N-1].fecha.mes==b;
do{
printf("Indica el dia en el que quiere poner la nota\n");
scanf("%i",a);
if(b==2 && a==29 && c%4!=0){
    a=32;
}
}while(a<1 || a>31);
nota[N-1].fecha.dia=a;
nota[N-1].alum=alum;
nota[N-1].materia=materia;
do{
    printf("Introduzca una nota entre 0 y 10 \n");
    scanf("%i",a);
}while(a<0 || a>10);
nota[N-1].not=a;
printf("Introduzca una descripcion del examen\n");
fgets(nota[N-1].descrip, N, stdin);}

void aniadir_not(int alu, int materia,calificaciones *nota,int *N){
nota=realloc(nota,sizeof(calificaciones*)*(*N+1));
anadir_not(alu,materia,calificaciones *nota,int *N);
}

void calif_profe(char *al, char *mat,calificaciones *nota,int *N){
int a=0,b=0, alum,materia;
long alu, mater;
alu=strtol(al, NULL ,10);
mater=strtol(mat,NULL,10);
alum=(int)alu;
materia=(int)mater;
do{
    printf("###################################################################################\n");
    printf("Bienvenido al menu de calificaciones \n");
    do{
        printf("¿Que desea hacer? \n Pulse el numero correspondiente a la accion que desee hacer \n");
        printf("1.Listar las notas \n");
        printf("2.Modificar las notas \n");
        printf("3.Eliminar una nota \n");
        printf("4.Aniadir una nota \n");
        printf("5.Salir de este menu \n");
        scanf("%i",a);
    }while(a<6 && a>0);
    switch(a){
        case 1: ver_nota(alum,materia,calificaciones *nota,int *N);
                break;
        case 2: mod_nota(alum, materia,calificaciones *nota,int *N);
                break;
        case 3: eliminar_nota(alum, materia,calificaciones *nota,int *N);
                break;
        case 4: aniadir_not(alum, materia,calificaciones *nota,int *N);
                break;
        case 5: return;
                break;
            }
    printf("¿Desea hacer algo mas en este menu? \n Pulse 1 para sí, y 0 para no \n");
    scanf("%i",b);
    }while(b==1);
printf("#####################################################################################################\n");
}
