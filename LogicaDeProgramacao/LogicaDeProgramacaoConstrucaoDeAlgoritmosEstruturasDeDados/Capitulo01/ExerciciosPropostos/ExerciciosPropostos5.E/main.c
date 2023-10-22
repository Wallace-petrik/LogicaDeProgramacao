#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL,"");

    int base = 2, exp = 8, resultado = 1, aux = 0;

    for(int i = 0; i < exp; i++){
        aux = 0;
        for(int j = 0; j < base; j++){
            aux += resultado;
        }
        resultado = aux;
    }

    printf("%d elevado a %d é igual a %d\n", base, exp, resultado);

    return 0;
}
