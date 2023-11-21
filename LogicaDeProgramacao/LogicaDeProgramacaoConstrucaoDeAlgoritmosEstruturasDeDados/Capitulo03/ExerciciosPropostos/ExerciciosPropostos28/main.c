#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float h = 0;
    int x = 0;

    for(int i = 1; i <= 20; i+=2){
        x++;

        if(x%2==1){
            h += 1.0/pow(i,3);
        }else{
            h -= 1.0/pow(i,3);
        }

    }

    printf("\nDez primeiros termos da série H = %.2f\n",h);

    return 0;
}
