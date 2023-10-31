#include <stdio.h>
#include <locale.h>
#define anoAtual 2023

int main(){
    setlocale(LC_ALL,"");

    int anoNasc,idade;

    printf("\nEntre com o ano de nascimento: ");
        scanf("%d",&anoNasc);

    idade = anoAtual - anoNasc;

    if(idade<16){
        printf("\nSua idade é  = %d anos",idade);
    }else if(idade>=16 && idade<18){
                printf("\nSua idade é %d anos",idade);
                printf("\nVocê ja tem idade para votar.");
    }else if(idade>=18){
                printf("\nSua idade é %d anos",idade);
                printf("\nVocê ja tem idade para votar.");
                printf("\nVocê ja tem idade para tirar a CNH.");
    }

    return 0;
}
