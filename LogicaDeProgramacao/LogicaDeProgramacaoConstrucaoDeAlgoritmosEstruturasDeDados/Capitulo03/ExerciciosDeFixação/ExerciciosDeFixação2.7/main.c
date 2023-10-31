#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int idade;

    printf("\n------------------------------");
    printf("\nidade                Categoria");
    printf("\n------------------------------");
    printf("\n5 até 7 anos        Infantil A");
    printf("\n8 até 10 anos       Infantil B");
    printf("\n11 até 13 anos       Juvenil A");
    printf("\n14 até 17 anos       Juvenil B");
    printf("\nMaior de 18 anos     Juvenil A");
    printf("\n------------------------------");

    printf("\n\nEntre com a idade: ");
        scanf("%d",&idade);

    if(idade>=5 && idade<=7){
        printf("\nInfantil A");
    }else if(idade>=8 && idade<=10){
        printf("\nInfantil B");
    }else if(idade>=11 && idade<=13){
        printf("\nJuvenil A");
    }else if(idade>=14 && idade<=17){
        printf("\nJuvenil B");
    }else if(idade>=18){
        printf("\nAdulto");
    }else
        printf("\nBebê");

    return 0;
}
