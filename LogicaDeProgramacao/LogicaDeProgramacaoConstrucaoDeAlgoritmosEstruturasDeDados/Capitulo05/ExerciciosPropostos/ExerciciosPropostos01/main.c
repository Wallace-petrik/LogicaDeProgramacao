#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 30

typedef struct{
    char nome[tam];
    char endereco[tam];
    int telefone;
}RegistroTelefone;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
}RegistroEndereco;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
    int telefone;
}RegistroGeral;

int main(){

    setlocale(LC_ALL,"");

    int opcao_01 = 0,opcao_02 = 0;

    FILE *arquivoTelefone = 0, *arquivoEndereco = 0;

    RegistroTelefone telefone;
    RegistroEndereco endereco;
    RegistroGeral geral;

    do{

        system("cls");
        printf("1 para cadastrar dados\n");
            scanf("%d",&opcao_01);
            fflush(stdin);

        switch(opcao_01){

            case 0:

                system("cls");
                printf("Até logo!\n");
                system("pause");

            break;
            case 1:

                system("cls");
                printf("1 para cadastrar telefone\n2 para cadastrar endereço\n");
                    scanf("%d",&opcao_02);

                if(((arquivoTelefone = fopen("telefone.dat","ab+"))==NULL) || ((arquivoEndereco = fopen("endereco.dat","ab+"))==NULL)){
                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);
                }else{
                    if(opcao_02==1){

                    }else if(opcao_02==2){

                    }else{
                        system("cls");
                        printf("Opção invalida!\n");
                        system("pause");
                    }
                }
                if((fclose(arquivoTelefone))==0 && (fclose(arquivoEndereco))==0){
                    system("cls");
                    printf("Dados salvos com sucesso!\n");
                    system("pause");
                }
            break;
            default :

                system("cls");
                printf("Opção invalida!\n");
                system("pause");

        }

    }while(opcao_01!=0);

    return 0;
}
