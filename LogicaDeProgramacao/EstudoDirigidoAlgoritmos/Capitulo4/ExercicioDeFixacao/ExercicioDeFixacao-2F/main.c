#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){

    setlocale(LC_ALL,"");

    int valor;

    printf("Entre com número qualquer: ");
        scanf("%d",&valor);

    /*
    if(valor<0){
        printf("O valor módulo dele é = %d",valor*-1);
    }else{
        printf("O valor módulo dele é = %d",valor);
    }*/

    printf("O valor módulo dele é = %d",abs(valor));
    return 0;
}
