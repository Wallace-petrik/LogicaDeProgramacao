#include <stdio.h>
#include <locale.h>

struct cheque{

    char valoreExtenso[40];
    char beneficiario[30];
    char data[10];

};


int main(){
    setlocale(LC_ALL,"");

    struct cheque p1;
    printf("Entre com o nome do beneficiário: ");
    scanf(" %[^\n]",&p1.beneficiario);

    printf("Entre com o valor por extenso: ");
    scanf(" %[^\n]",&p1.valoreExtenso);


    printf("Entre com o nome a data : ");
    scanf(" %[^\n]",&p1.data);


    printf("\nO nome do beneficiário é %s",p1.beneficiario);
    printf("\no valor é %s",p1.valoreExtenso);
    printf("\nData %s",p1.data);
    return 0;
}
