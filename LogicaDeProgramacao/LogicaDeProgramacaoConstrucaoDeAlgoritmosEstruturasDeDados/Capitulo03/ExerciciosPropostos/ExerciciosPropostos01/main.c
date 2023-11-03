#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float media;
    float n1,n2,n3,n4,n5;

    printf("\nEntre com 5 notas: ");
        scanf("%f%f%f%f%f",&n1,&n2,&n3,&n4,&n5);

    media = (n1+n2*2+n3*3+n4*4+n5*5)/15;

    printf("\nA média ponderada é = %.2f",media);
    return 0;
}
