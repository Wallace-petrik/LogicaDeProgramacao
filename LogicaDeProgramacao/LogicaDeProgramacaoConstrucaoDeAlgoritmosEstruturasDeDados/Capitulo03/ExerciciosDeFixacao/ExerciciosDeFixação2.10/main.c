#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float altura,peso,IMC;

    printf("\nEntre com sua altura: ");
        scanf("%f",&altura);
    printf("\nEntre com seu peso: ");
        scanf("%f",&peso);

    IMC = peso/(altura*altura);

    if(IMC<18.5){
        printf("\nAbaixo do peso");
    }else if(IMC>=18.5 && IMC<25){
        printf("\nPeso normal");
    }else if(IMC>=25 && IMC<30){
        printf("\nAcima do peso");
    }else
        printf("\nObeso\n");
    return 0;
}
