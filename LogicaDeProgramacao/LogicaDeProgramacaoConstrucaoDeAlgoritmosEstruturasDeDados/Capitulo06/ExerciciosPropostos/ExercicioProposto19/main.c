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

int main(){
    setlocale(LC_ALL,"Portuguese");

    leituraDosCheques();

    return 0;
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
        printf("DV: ");
            scanf("%d",&cheque.dv);
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


