#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = 99;

    do{
        contador +=2;
        printf("%d\n",contador);
    }while(contador<199);

    return 0;
}
