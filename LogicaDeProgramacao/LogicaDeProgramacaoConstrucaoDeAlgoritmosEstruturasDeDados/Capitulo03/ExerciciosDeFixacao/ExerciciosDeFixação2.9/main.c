#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a,b;
    char simbolo;

    printf("\n-----------------------------");
    printf("\nSímbolo | Operação aritmética");
    printf("\n-----------------------------");
    printf("\n+                      Adição");
    printf("\n-                   Subtração");
    printf("\n*               Multiplicação");
    printf("\n/                     Divisão");
    printf("\n-----------------------------");

    printf("\nEntre com dois números inteiros: ");
        scanf("%d%d",&a,&b);
    printf("\nEntre com o tipo da operação: ");
        scanf(" %c",&simbolo);

    switch(simbolo){
        case '+':
            printf("\n %d + %d = %d",a,b,a+b);
        break;
        case '-':
            printf("\n %d + %d = %d",a,b,a-b);
        break;
        case '*':
            printf("\n %d + %d = %d",a,b,a*b);
        break;
        case '/':
            printf("\n %d + %d = %.1f",a,b,(float)a/b);
        break;
        default:
            printf("\nOperação invalida.\nEntre com os simbolos da tabela.\n\n");
        break;
    }
    return 0;
}
