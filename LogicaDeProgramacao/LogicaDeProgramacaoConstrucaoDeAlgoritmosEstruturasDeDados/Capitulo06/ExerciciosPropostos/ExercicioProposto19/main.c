#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
int digitoVerificador(int numeroConta);
int qualcularQuantidadeDeDigitos(int numero);
int inversorNumero(int numeroParaInverter);


int main(){
    setlocale(LC_ALL,"Portuguese");

    menu();

    return 0;
}

void menu(){

    int opcao = 0;
    int contaAux = 0;
    do{
        printf("1 /p leitua do cheque\n");
        printf("2 /p saldo\n");
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
            case 2:
                system("cls");
                printf("Digite o número da conta: ");
                    scanf("%d",&contaAux);
                    somaTotalCheques(contaAux);
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
        system("cls");
    }
    if(fclose(arqCheque)!= 0){
        printf("Erro ao fechar o arquivo!!!");
        exit(1);
    }
}

int inversorNumero(int numeroParaInverter){
    int rev = 0;
    int num = numeroParaInverter;
    while (num != 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }
    return rev + numeroParaInverter;
}

int qualcularQuantidadeDeDigitos(int numero){

    int quantidadeDeDigitos = 0;

    while(numero>0){

        numero = numero/10;
        quantidadeDeDigitos++;
    }

    return quantidadeDeDigitos;
}

int digitoVerificador(int numeroConta){


    int digito = 0, soma = 0;

    int numeroInvertido = inversorNumero(numeroConta);
    int quantidadeDeDigitos = qualcularQuantidadeDeDigitos(numeroInvertido);

    for(int i = quantidadeDeDigitos; i >= 1; i--){

        digito = numeroInvertido % 10;
        soma += digito * i;
        numeroInvertido /= 10;

    }
    return soma;
}

void somaTotalCheques(int numeroConta){
    Cheque dados;

    float saldo = 0;
    int controle = 0;
    int controleAux = 0;

    char nomeAux[10];

    if((arqCheque = fopen("arquivo.dat","r+b"))==NULL){

        printf("Erro ao abrir o arquivo!!!");
        system("pause");
        exit(1);

    }else{
        fseek(arqCheque, 0, SEEK_END);
        int tam = (ftell(arqCheque))/(sizeof(cheque));

        while(controle< tam){

            fseek(arqCheque,controle*sizeof(cheque),SEEK_SET);
            fread(&dados,sizeof(cheque),1,arqCheque);

            if(dados.conta==numeroConta){
                strcpy(nomeAux, dados.nome);
                saldo+= dados.valor;
                controleAux++;
            }
            controle++;
        }
        if(controle!=0){
            printf("Cliente : %s\n",nomeAux);
            printf("R$ %f\n",saldo);
            system("pause");
            system("cls");
        }else{
            printf("Cliente não encontrado!!!");
            system("pause");
            system("cls");
        }

    }
    if(fclose(arqCheque)!=0){
        printf("Erro ao fechar o arquivo");
        system("pause");
        exit(1);
    }
}
