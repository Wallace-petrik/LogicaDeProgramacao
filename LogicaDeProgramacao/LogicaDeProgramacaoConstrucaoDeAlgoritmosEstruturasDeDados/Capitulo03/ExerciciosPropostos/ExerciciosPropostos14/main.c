#include <stdio.h>
#include <locale.h>
//Algoritmo de Euclides
int main(){
    setlocale(LC_ALL,"");

    int n1,n2,a,b;
    int resto;;

   printf("\nDigite dois númeors para calcular o MDC entre eles: ");
        scanf("%d%d",&n1,&n2);

    a=n1; b=n2;

    do{
         resto=a%b;
         a=b;
         b=resto;

    }while(resto!=0);//MDC

    printf("\nO MDC = %d",a);
    return 0;
}
