#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 40

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int numeroSocio;
    char nome[tam];
    char endereco[tam];
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int dependentes;
    Data dataDeAssociacao;
}Associados;

typedef struct{
    int numeroSocio;
    Data dataDeVencimento;
    float valor;
    Data dataDePagamento;
}Mensalidade;

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    FILE *arquivoSociados, *arquivoMensalidade;

    Associados socio;
    Mensalidade boleto;
    do{

        system("cls");
        printf("1 para cadastrar associados\n");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

            case 0:

                system("cls");
                printf("Até logo!\n");

            break;
            case 1:

                system("cls");
                if((arquivoSociados = fopen("arquivoS.dat","ab+"))==NULL){

                    printf("Erro ao abrir o arquivo!\n");
                    system("pause");
                    exit(1);

                }else{

                    printf("Número de sócio: ");
                        scanf("%d",&socio.numeroSocio);
                        fflush(stdin);
                    printf("Nome: ");
                        fgets(socio.nome,tam,stdin);
                        fflush(stdin);
                    printf("Endereço: ");
                        fgets(socio.endereco,tam,stdin);
                        fflush(stdin);
                    printf("Bairro: ");
                        fgets(socio.bairro,tam,stdin);
                        fflush(stdin);
                    printf("Cidade: ");
                        fgets(socio.cidade,tam,stdin);
                        fflush(stdin);
                    printf("Estado: ");
                        fgets(socio.estado,tam,stdin);
                        fflush(stdin);
                    printf("Número de dependentes: ");
                        scanf("%d",&socio.numeroSocio);
                        fflush(stdin);
                    printf("Data de associação: ");
                        scanf("%d%d%d",&socio.dataDeAssociacao.dia,&socio.dataDeAssociacao.mes,&socio.dataDeAssociacao.ano);
                        fflush(stdin);

                        fwrite(&socio,sizeof(socio),1,arquivoSociados);

                }

                if((fclose(arquivoSociados))==0){

                    printf("Asóciado cadastrado com sucesso!\n");
                    system("pause");

                }

            break;
            default:

                system("cls");
                printf("Opção invalida!\n");
                system("pause");
        }

    }while(opcao!=0);

    return 0;
}
