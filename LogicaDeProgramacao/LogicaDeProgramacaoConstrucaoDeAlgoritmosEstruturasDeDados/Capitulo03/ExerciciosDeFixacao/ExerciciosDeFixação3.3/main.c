#include <stdio.h>
#include <stdlib.h>

int main(){

    int number,div;

    printf("\n Entre com um numero inteiro: ");
        scanf("%d",&number);

    for(int i = 1; i<=number; i++){
        if(number%i==0){
            div++;
        }
    }

    if(div==2){
        printf("\n O numero %d e primo.",number);
    }else printf("\n O numero %d nao e primo.",number);

    return 0;
}
