#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a = 1, b = 3, c = (-4);
    float delta,x1,x2;

    if(a == 0){
        printf("\nNão é uma equação do 2º grau");
        printf("\n\n");
    }else{
        delta = pow(b,2)-4*a*c;
        if(delta<0){
            printf("\nA equação não possui solução real");

            printf("\n\n");
        }else if(delta==0){
            printf("\nA equanção possui uma solução real");
            x1 = (- b + sqrt(delta))/2*a;
            printf("\n x¹ = %.1f",x1);
            printf("\n\n");
        }else{
            printf("\nA equanção possui duas solução reais");
            x1 = (- b + sqrt(delta))/2*a;
            x2 = (- b - sqrt(delta))/2*a;
            printf("\nx¹ = %.1f",x1);
            printf("\nx² = %.1f",x2);
            printf("\n\n");
        }
    }

    return 0;
}

