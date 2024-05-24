#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calcularExponenciacao(int base, int expoente);

int main(){
    setlocale(LC_ALL,"POrtuguese");

    int base, expoente;

    printf("Calcular Exponenciação\nDigite a base:");
        scanf("%d",&base);
    printf("Digite o expoente: ");
        scanf("%d",&expoente);

    printf("\n%d^%d = %d",base,expoente,calcularExponenciacao(base,expoente));

    return 0;
}

int calcularExponenciacao(int base, int expoente){
    int exponenciacao = base;
    for( int i = 1; i < expoente; i++){

        exponenciacao *= base;

    }
    return exponenciacao;
}
