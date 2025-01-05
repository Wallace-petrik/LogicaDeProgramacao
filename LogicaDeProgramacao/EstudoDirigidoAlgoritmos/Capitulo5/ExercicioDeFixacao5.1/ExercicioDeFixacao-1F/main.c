#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = 14;

    while(++contador<=200){

        printf(" %d^2 = %d\n",contador,contador*contador);

    }

    return 0;
}
