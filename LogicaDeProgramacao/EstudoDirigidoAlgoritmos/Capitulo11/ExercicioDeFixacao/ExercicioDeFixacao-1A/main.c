#include <stdio.h>
#include <locale.h>

struct{
    char endereco[50];
    char nome[50];
    int telefone;
}typedef Agenda;

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        printf("======================\n");
        printf("|1 para cadastramento |\n");
        printf("======================\n");
        printf("|2 para classificação |\n");
        printf("======================\n");
        printf("|3 para pesquisa      |\n");
        printf("======================\n");
        printf("|4 para correção      |\n");
        printf("======================\n");
        printf("|5 para remoção       |\n");
        printf("======================\n");
        printf("|6 para sair          |\n");
        printf("======================\n:");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:{

            break;}

            case 2:{

            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{

            break;}

            case 6:{

            break;}

            default:{
                fflush(stdin);
                printf("Opção invalida !!!\n");
                getchar();
            }

        }

    }while(opcao != 6);

    return 0;
}
