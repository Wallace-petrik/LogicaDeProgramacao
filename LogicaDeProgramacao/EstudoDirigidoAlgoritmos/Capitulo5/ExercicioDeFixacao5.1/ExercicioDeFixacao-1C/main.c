#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;
    int i;

    printf("\nEntre com um número qualquer: ");
        scanf("%d",&numero);

    while(i++ <10){
        printf("\n%2.d X %2.d = %2.d",numero,i,numero*i);
    }
    return 0;
}
