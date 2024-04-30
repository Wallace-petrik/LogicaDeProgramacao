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
     int origem;
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
         system("cls");
        printf("1 para cadastrar cliente\n");
        printf("2 para cadastrar atendimento\n");

        printf("\n0 para sair\n");

        printf("\nDigite uma opçao: ");
            scanf("%d",&opcao);



        switch(opcao){

            case 0:

                system("cls");
                printf("\nAté logo\n");

            break;
            case 1:

                if((arqCliente = fopen("arqCliente.dat","r+b")) == NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{
                    system("cls");
                    printf("Entre com o CNPJ: ");
                        scanf("%d",&cliente.cnpj);
                        fflush(stdin);
                    printf("Entre com a Razão Social: ");
                        scanf("%[^\n]",&cliente.razaoSocial);
                        fflush(stdin);
                    printf("Entre com o email: ");
                        scanf("%[^\n]",&cliente.email);
                        fflush(stdin);
                    printf("Entre com o número de telefone: ");
                        scanf("%d",&cliente.telefone);
                        fflush(stdin);
                    fseek(arqCliente,(cliente.cnpj-1)*sizeof(cliente),SEEK_SET);
                    fwrite(&cliente,sizeof(cliente),1,arqCliente);

                }
                if(fclose(arqCliente) == 0){
                    printf("Operação realizada com sucesso!!!\n");
                    system("pause");;
                }

            break;
            case 2:

                if((arqAtendimento = fopen("arqAtendimento.dat","a+b")) == NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{

                    system("cls");
                    printf("Digite o CNPJ: ");
                        scanf("%d",&atendimento.cnpj);
                    printf("Digite a data: ");
                        scanf("%d%d%d",&atendimento.data.dia,&atendimento.data.mes,&atendimento.data.ano);
                    printf("1 para empresa\n2 para cliente\nDigite a origem: ");
                        scanf("%d",&atendimento.origem);
                    printf("Digite o contato: ");
                        scanf("%d",&atendimento.contato);
                        fflush(stdin);
                    printf("Digite o problema: ");
                        scanf("%[^\n]",&atendimento.problema);
                        fflush(stdin);
                    printf("Digite a soluçao: ");
                        scanf("%[^\n]",&atendimento.solucao);

                    fwrite(&atendimento,sizeof(atendimento),1,arqAtendimento);

                }
                if(fclose(arqAtendimento) == 0){
                    printf("Operação realizada com sucesso!!!");
                    system("pause");
                }

            break;
            default:
                printf("Opção invalida!!!\n");
                system("pause");
        }

    }while(opcao != 0);

    return 0;
}
