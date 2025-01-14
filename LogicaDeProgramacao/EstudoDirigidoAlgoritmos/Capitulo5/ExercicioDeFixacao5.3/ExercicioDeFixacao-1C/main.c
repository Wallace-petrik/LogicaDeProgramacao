#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int numero = 0;
    int fat = 1;
    printf("Entre com um número para calauclar o fatorial: ");
        scanf("%d",&numero);

    for(int i = numero; i >= 1; i--){
        fat *= i;
    }
    printf("Fatorial de %d é %d\n",numero,fat);
    return 0;
}
