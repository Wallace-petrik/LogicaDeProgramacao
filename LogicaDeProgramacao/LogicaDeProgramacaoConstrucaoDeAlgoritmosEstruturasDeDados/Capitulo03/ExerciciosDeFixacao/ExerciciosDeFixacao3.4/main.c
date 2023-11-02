#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int number;
    float resp = 0;

    printf("\nEntre com um numero: ");
        scanf("%d",&number);

    for(int i = 1; i<=number; i++){

        resp += 1.0/i;

    }

    printf("\n Resposta = %.1f",resp);

    return 0;
}
