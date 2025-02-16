#include <stdio.h>
#include <locale.h>
#define elem 3

struct{
    int mat;
    float sal;
    char nome[30];
};
int main(){

    setlocale(LC_ALL,"");

    int opcao = 0;

    do{
        printf("1 para cadastra empregados\n");
        printf("2 para casificar por matrícula\n");
        printf("3 para pesquisar empregado\n");
        printf("4 para listar empregados com salário > 1000\n");
        printf("5 para listar empregados com salário < 1000\n");
        printf("6 para listar empregados com salário = 1000\n");
        printf("0 para sair\n:");
            scanf("%d%*c",&opcao);

        switch(opcao){

            case 0:{
                printf("\n Até logo\n");
                getchar();

            break;}

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
                printf("\nOpção invalida !!!\n");
                getchar();
                system("cls");
            break;}

        }
    }while(opcao!=0);

    return 0;
}
