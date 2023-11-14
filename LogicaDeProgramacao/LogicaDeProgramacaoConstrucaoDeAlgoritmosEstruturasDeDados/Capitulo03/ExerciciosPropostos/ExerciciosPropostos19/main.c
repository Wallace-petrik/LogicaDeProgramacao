#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
    printf("\n|-------------------------| ");
    printf("\n|Fahrenheit || Centígrados| ");
    printf("\n|-------------------------| ");
    for(int i = 50; i <=150 ; i++){

    printf("\n|%11d||%12.2f|",i,((5.0/9.0)*(i-32)));
    printf("\n|-------------------------| ");
    }

    return 0;
}
