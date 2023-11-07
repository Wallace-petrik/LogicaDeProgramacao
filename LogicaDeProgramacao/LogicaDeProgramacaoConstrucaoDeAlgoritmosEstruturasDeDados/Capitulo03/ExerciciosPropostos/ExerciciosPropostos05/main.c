#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int anoNasc, mesNasc,diaNasc;
    int anoAtual, mesAtual, diaAtual;
    int idadeAnos;

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

    if(mesAtual>=mesNasc){
        printf("\nIdade em anos = %d",anoAtual-anoNasc);
        printf("\nIdade em meses = %d",((anoAtual-anoNasc)*12)+(mesAtual-mesNasc));
    }else{
        printf("\nIdade em anos = %d",anoAtual-anoNasc-1);
        printf("\nIdade em meses = %d",((anoAtual-anoNasc-1)*12)+mesAtual);
    }


    return 0;
}
