#include <stdio.h>
#include <locale.h>
#include <math.h>
int main(){

    setlocale(LC_ALL,"");

    int i = 2;

    do{
        printf("%2.d ^ 2 = %7.2f\n",i,pow(i,2));
        i++;
    }while(i<=50);

    return 0;
}
