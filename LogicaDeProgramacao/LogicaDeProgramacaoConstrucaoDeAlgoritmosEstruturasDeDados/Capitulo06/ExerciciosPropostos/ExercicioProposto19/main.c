#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int numeroDoCheque;
    int agencia;
    int conta;
    int dv;
    char nome[10];
    float valor;
}Cheque;

FILE *arqCheque;
Cheque cheque;

void leituraDosCheques();
void menu();

int main(){
    setlocale(LC_ALL,"Portuguese");

    menu();

    return 0;
}

void menu(){

    int opcao = 0;

    do{
        printf("1 /p leitua do cheque\n");
        printf("0 /p sai\n\n");

        printf("Digite uma opção: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 0:
                system("cls");
                printf("Até logo !!!\n\n");
            break;
            case 1:
                system("cls");
                leituraDosCheques();
            break;
            default:
                printf("Opção invalida!!!\n");
                system("pause");
                system("cls");

        }

    }while(opcao!=0);

}

void leituraDosCheques(){
    if((arqCheque = fopen("arquivo.dat","a+b"))==NULL){
       printf("Erro ao abrir o arquivo!!!\n");
       system("pause");
       exit(1);
    }else{
        printf("Entre com os dados do cheque\n");
        printf("Número do cheque: ");
            scanf("%d",&cheque.numeroDoCheque);
        printf("Agência: ");
            scanf("%d",&cheque.agencia);
        printf("Conta: ");
            scanf("%d",&cheque.conta);
            cheque.dv = digitoVerificador(cheque.conta);
        printf("Nome: ");
            fflush(stdin);
            scanf("%[^\n]",&cheque.nome);
        printf("Valor: ");
            scanf("%f",&cheque.valor);

        fwrite(&cheque,1,sizeof(cheque),arqCheque);
    }
    if(fclose(arqCheque)!= 0){
        printf("Erro ao fechar o arquivo!!!");
        exit(1);
    }
}

int inversorNumero(int numeroParaInverter){
    int rev = 0;

    while (numeroParaInverter != 0) {
        int digit = numeroParaInverter % 10;
        rev = rev * 10 + digit;
        numeroParaInverter /= 10;
    }
    return rev;
}

void digitoVerificador(int numeroConta){

    int numeroInvertido = inversorNumero(numeroConta);

}


