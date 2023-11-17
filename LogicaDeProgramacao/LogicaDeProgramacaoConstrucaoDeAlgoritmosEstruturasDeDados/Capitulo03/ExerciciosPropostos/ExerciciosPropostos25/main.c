#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    double h = 0;
    int i = -1, j = 0;

    while((i+=2)<=99 && j++<=50){

        h+=((float)i/j);

    }

    printf("\n%.2f",h);

    return 0;
}
