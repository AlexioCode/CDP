#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
int main()
{
    int n = n_usuarios();
    usuario usuarios[n];
    cargar_usuarios(&usuarios);
    return 0;
}
