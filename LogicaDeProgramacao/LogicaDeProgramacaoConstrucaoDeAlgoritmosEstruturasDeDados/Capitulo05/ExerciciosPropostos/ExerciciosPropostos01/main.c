#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 30

typedef struct{
    char nome[tam];
    char endereco[tam];
    int telefone;
}Registro_01;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
}Registro_02;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
    int telefone;
}Registro_03;

int main(){

    setlocale(LC_ALL,"");

    int opcao_01 = 0,opcao_02 = 0;

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
                if(opcao_02==1){

                }else if(opcao_02==2){

                }else{
                    system("cls");
                    printf("Opção invalida!\n");
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
