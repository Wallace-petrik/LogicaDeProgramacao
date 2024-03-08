#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct{
    int codigo; // Chave
    int telefone;
    int RG;
    int CPF;
    char nome[40];
    char endereco[40];
}Cliente;

typedef struct{
    int codigo; //Chave
    float preco;
    int dataDeCompra[3];
    char oscar;
    char titulo[40];
    char assunto[40];
}Fita;

typedef struct{
    int codigoFita;
    int codigoCliente;
    int qtdDiasFora;
    float preco;
}Locacao;

int main(){
    setlocale(LC_ALL,"");

    int opcao = 0, contador = 0;

    FILE *arqClientes;

    Cliente cliente;


    do{

        system("cls");
        printf("1 para Cadastrar clientes: \n");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

        case 0:

            system("cls");
            printf("Até logo\n");

        break;
        case 1:

            if((arqClientes = fopen("clientes.dat","a+b"))==NULL){
                printf("Erro ao abrir o arquivo!!!\n");
                system("pause");
                exit(1);
            }else{

                system("cls");

                contador = 0;
                while(fread(&cliente,sizeof(cliente),1,arqClientes)){contador++;}

                printf("Digite o nome do cliente: ");
                    scanf("%[^\n]",&cliente.nome);
                printf("Digite o telefone: ");
                    scanf("%d",&cliente.telefone);
                printf("Digite o RG: ");
                    scanf("%d",&cliente.RG);
                printf("Digite o CPF: ");
                    scanf("%d",&cliente.CPF);
                    fflush(stdin);
                printf("Digite o endereço: ");
                    scanf("%[^\n]",&cliente.endereco);

                cliente.codigo = ++contador;

                fwrite(&cliente,sizeof(cliente),1,arqClientes);

            }
            if(fclose(arqClientes) == 0){

                system("cls");
                printf("Cliente cadastrado com sucesso!\n");
                system("pause");

            }
        break;
        default:

            system("cls");
            printf("Opção invalida");
            system("pause");

        }

    }while(opcao != 0);

    return 0;
}
