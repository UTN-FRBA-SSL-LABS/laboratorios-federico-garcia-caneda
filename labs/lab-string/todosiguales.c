#include <stdio.h>
#include "String.h"

/*
 * todosiguales — imprime 1 si todos los argumentos son iguales, 0 si no.
 *
 * Uso: ./todosiguales hola hola hola  →  1
 *      ./todosiguales hola mundo      →  0
 *
 * Pista: compara cada argumento contra argv[1] usando AreEqual.
 *        Iterá con puntero (char **arg), no con indice entero.
 */

int main(int argc, char *argv[]) {
    (void)argc;
    if (argc < 2) {
        printf("0\n");
        return 0;
    }
    char *primer = argv[1];
    char **arg = argv + 2;
    while (*arg != NULL){
        if (AreEqual(*arg, primer)){
            arg++;
        } else {
            printf("0\n");
            return 0;
        }
    }
        printf("1\n");
    return 1;
}