#include <stdio.h>
#include <math.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"");

    int number,aux=0;
    float resp;

    printf("\n\tEntre com um número interiro: ");
        scanf("%d",&number);

    resp = sqrt(number);

    while(aux<resp){
        aux++;
    }

    if(aux-0.5>=resp){
        printf("\n\tO número inteiro que mais se proxima da raiz do número fornecido é = %d.\n",(int)--aux);
    }else printf("\n\tO número inteiro que mais se proxima da raiz do número fornecido é = %d.\n",(int)aux);



    return 0;
}
