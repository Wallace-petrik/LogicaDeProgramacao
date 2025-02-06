#include <stdio.h>
#include <locale.h>
#define tam 10

struct {

    char nome[30];
    char endereco[50];
    int telefone;

} typedef Agenda;

int main(){

    setlocale(LC_ALL,"");

    Agenda minhaAgenda[tam];

    int opcao = 0;

    do{
        system("cls");
        printf("1 para Cadastrar contato~\n");
        printf("2 para Pesquisar contato\n");
        printf("3 para Ordenar por nome\n");
        printf("4 para listar contatos\n");
        printf("5 para sair\n:");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:

            break;
            case 2:

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                printf("\n\tAté logo!!!");
            break;
            default:

                printf("\n\tOpição invalida!!!\n");
                system("pause");

        }

    }while(opcao != 5);

    return 0;
}
