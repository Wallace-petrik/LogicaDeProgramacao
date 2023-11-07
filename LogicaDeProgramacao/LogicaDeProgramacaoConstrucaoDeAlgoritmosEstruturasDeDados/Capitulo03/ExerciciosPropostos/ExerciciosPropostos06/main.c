#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float valorApagar,prejuizo;

    printf("\nEntre com o valor em atraso: ");
        scanf("%f",&valorApagar);

    prejuizo = valorApagar;
    valorApagar =  valorApagar*1.1;
    valorApagar -=  valorApagar*0.1;
    prejuizo -= valorApagar;

    printf("\nValor final a ser pago %.2f",valorApagar);
    printf("\nPrejuizo de %.2f\n",prejuizo);

    return 0;
}
