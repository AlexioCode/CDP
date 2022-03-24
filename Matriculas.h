#ifndef MATRICULAS_H_INCLUDED
#define MATRICULAS_H_INCLUDED

typedef struct{
    char matid[5];
    char alumid[7];
}matricula;


int cargar_matriculas();
void guardar_matriculas(matricula *p, int cant);

void cambiar_id_matriculas(matricula *p, char *id, char *nuevo_id);

void cambiar_alumid_matriculas(matricula *p, char *alumid, char *nuevo_alumid);

// cant debe de ser un valor devuelto por cargar_materias() o alta()
void ver_matriculas(matricula *p, int cant);


void baja(matricula *p, char *id);

// cant debe de ser un valor devuelto por cargar_materias o alta()
void alta(matricula *p, char *id, char *alumid, int cant);

#endif // MATRICULAS_H_INCLUDED
