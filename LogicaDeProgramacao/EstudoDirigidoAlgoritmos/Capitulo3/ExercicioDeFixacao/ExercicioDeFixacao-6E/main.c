#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a = 1;
    int b = 2;

    printf("\n %d e  %d",a,b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\n %d e  %d",a,b);

    return 0;
}
