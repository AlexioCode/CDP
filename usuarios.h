#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#define MAX 25
#define hey {puts("\n\nHEY!!!\n\n");}
typedef struct
{
    char Id_usuario[4];
    char Nomb_usuario[21];
    char Perfil_usuario[14];
    char Usuario[6];
    char Contrasena[9];
}usuario;
//cabecera: void cargar_usuarios(usuario * usuarios)
//precondicion: recibe un vector de usuarios
//postcondicion: carga los usuarios del fichero usuarios.txt y lo vuelca a sus registros
void cargar_usuarios(usuario * usuarios);
//cabecera: n_usuarios(usuario * usuarios)
//precondicion: recibe un vector del tipo de estructura usuario
//postcondicon: devuelve el numero de usuarios que residen en usuarios.txt
int n_usuarios();
//cabecera: void guardar_usuarios(usuario * usuarios)
//precondicion: recibe un vector de usuarios
//postcondicion: vuelca usuarios de su estructura al fichero
void guardar_usuarios(usuario * usuarios);
#endif // USUARIOS_H_INCLUDED
