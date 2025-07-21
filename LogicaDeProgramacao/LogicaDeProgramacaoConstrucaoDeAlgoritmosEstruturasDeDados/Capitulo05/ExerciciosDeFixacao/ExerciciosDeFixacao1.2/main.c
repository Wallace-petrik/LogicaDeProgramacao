#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        printf("SISTEMA DE GERENCIAMENTO DE LIVROS\n");
        printf("1 /p Cadastrar\n");
        printf("2 /p Listar \n");
        printf("3 /p Alterar\n");
        printf("4 /p Buscar\n");
        printf("5 /p Excluir\n");
        printf("6 /p Sair\n:");
        scanf("%d",&opcao);
        fflush(stdin);

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
                printf("Até logo!!!\n");
            break;}
            default:{
                printf("Opção invalida\nTente novamente !!!\n\nPressione qualquer tecla para continuar");
                system("pause");
            }
        }

    }while(opcao!=6);

    return 0;
}
