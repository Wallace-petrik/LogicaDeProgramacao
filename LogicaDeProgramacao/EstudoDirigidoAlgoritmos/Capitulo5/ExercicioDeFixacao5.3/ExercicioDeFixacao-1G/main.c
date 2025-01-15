#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int base = 0;
    int expoente = 0;
    int potencia = 1;

    printf("Entre com o valor de uma base qualquer: ");
        scanf("%d",&base);
    printf("Entre com o valor de um expoente qualquer: ");
        scanf("%d",&expoente);


    for(int i = 0; i < expoente; i++){
        potencia *= base;
    }

    if(expoente==0){
        printf("\nResposta = 1\n");
    }else{
        printf("\nResposta = %d",potencia);
    }
    return 0;
}
