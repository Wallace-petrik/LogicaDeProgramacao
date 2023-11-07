#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int anoNasc, mesNasc,diaNasc;
    int anoAtual, mesAtual, diaAtual;
    int idadeAnos,idadeMeses,idadeDias;

    printf("\nEntre com a data de nascimento com dia, mês e ano separadamente!");
    printf("\nEntre com o dia: ");
        scanf("%d",&diaNasc);
    printf("Entre com o mês: ");
        scanf("%d",&mesNasc);
    printf("Entre com o ano: ");
        scanf("%d",&anoNasc);

    getch();
    system("cls");

    printf("\nEntre com a data atual com dia, mês e ano separadamente!");
    printf("\nEntre com o dia: ");
        scanf("%d",&diaAtual);
    printf("Entre com o mês: ");
        scanf("%d",&mesAtual);
    printf("Entre com o ano: ");
        scanf("%d",&anoAtual);


    idadeAnos = anoAtual-anoNasc;
    idadeMeses = idadeAnos*12;
    idadeDias = idadeMeses*30;


    printf("\nIdade em anos = %d aproximadamente.",idadeAnos);
    printf("\nIdade em meses = %d aproximadamente.",idadeMeses);
    printf("\nIdade em dias = %d aproximadamente.\n",idadeDias);


    return 0;
}
