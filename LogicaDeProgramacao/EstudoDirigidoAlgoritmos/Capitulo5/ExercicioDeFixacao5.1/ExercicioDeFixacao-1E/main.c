#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int contador = 0;

    while(++contador<=200){
        if(contador%4==0){
            printf("\n %3.d e divisivel por 4",contador);
        }
    }

    return 0;
}
