#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int valor;

    printf("Digite um número qualquer: ");
        scanf("%d",&valor);

    printf("Sucessor: %d\n",valor+1);
    printf("Antecessor: %d\n",valor-1);

    return 0;
}
