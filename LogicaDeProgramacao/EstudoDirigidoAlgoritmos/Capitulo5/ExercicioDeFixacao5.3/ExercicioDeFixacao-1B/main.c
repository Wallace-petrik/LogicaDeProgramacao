#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int n = 0;
    int soma = 0;

    printf("Entre com um número qualquer: ");
        scanf("%d",&n);

    for(int i = 1; i <= n; i++){
        soma += i;
    }

    //soma = (n*(1+n))/2;

    printf("Resposta: %d",soma);
    return 0;
}
