#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int number, maior= 0,menor = 0;
    printf("\nDigite -1 para sair.\nEntre com um número inteiro e positivo: ");
            scanf("%d",&number);
            menor = number;
    do{
       if(number>=0){
            if(number>=maior){
                maior = number;
            }else{
                if(number<=menor){
                    menor = number;
                }
            }
       }else{
            if(number==-1){
                printf("Até mais!");
                break;
            }else{
                printf("Número invalido!");
            }
       }
    printf("\nDigite -1 para sair.\nEntre com um número inteiro e positivo: ");
            scanf("%d",&number);

    }while(number!= -1);

    menor==-1 ? : printf("Maior número: %d\nMenor número: %d",maior,menor);

    return 0;
}
