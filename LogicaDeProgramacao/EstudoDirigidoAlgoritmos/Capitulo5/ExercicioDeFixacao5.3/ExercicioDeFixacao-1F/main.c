#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL,"");

    for(int i = 0; i <= 10; i++){
        printf("2 ^ %2.1d = %4.0f\n",i,pow(2,i));

    }

    return 0;
}
