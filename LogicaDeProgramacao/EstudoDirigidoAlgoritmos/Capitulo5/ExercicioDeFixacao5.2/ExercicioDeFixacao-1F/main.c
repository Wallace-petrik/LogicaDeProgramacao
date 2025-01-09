#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int i = 0;

    do{
        printf("2 ^ %2.1d = %.f\n",i,pow(2,i));
        i++;
    }while(i<=10);

    return 0;
}
