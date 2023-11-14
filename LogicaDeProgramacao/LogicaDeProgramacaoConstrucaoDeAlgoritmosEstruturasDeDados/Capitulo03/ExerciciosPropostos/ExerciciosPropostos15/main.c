#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int n1,n2,contador;
    float resto;

   printf("\nDigite dois númeors para acahar o quociente inteiro da divisão entre eles: ");
        scanf("%d%d",&n1,&n2);

    do{

        n1 -= n2;
        contador++;

    }while(n1>0 && n1>=n2);

    printf("\nQuociente da divisão = %d\n",contador);
    return 0;
}
