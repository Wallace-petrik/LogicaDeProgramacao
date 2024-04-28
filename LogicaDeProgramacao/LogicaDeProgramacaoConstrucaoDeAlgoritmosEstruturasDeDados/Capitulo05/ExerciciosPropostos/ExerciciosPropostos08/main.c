#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 100

typedef struct{

    int dia;
    int mes;
    int ano;

}Data;

typedef struct{

    int cnpj;
    char razaoSocial[tam];
    int telefone;
    char email[tam];

}Cliente;

typedef struct{

    int cnpj;
    Data data;
    char origem[tam];
    int contato;
    char problema[tam];
    char solucao[tam];

}Atendimento;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqCliente, *arqAtendimento;

    Cliente cliente;
    Atendimento atendimento;

    int opcao = 0;

    if((arqAtendimento = fopen("arqAtendimento.dat","a+b")) == NULL || (arqCliente = fopen("arqCliente.dat","a+b")) ==  NULL){
        printf("Erro ao criar os arquivos!!!\n");
        system("pause");
        exit(1);
    }else{

        fclose(arqAtendimento);
        fclose(arqCliente);

    }

    do{

        printf("1 para cadastrar cliente\n");

        printf("\n0 para sair\n");

        printf("\nDigite uma opçao: ");
            scanf("%d",&opcao);



        switch(opcao){

            case 0:

                system("cls");
                printf("\nAté logo\n");

            break;
            case 1:



            break;
            default:
                printf("Opção invalida!!!\n");
                system("pause");
        }

    }while(opcao != 0);

    return 0;
}
