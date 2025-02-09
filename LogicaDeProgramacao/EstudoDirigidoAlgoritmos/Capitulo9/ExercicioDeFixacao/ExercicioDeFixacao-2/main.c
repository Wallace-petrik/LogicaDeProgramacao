#include <stdio.h>
#include <locale.h>
#define tam 3;

struct{
    char nome[30];
    int notas[4];
};

int main(){

    setlocale(LC_ALL,"");

    int opc = 4;

    do{
        system("cls");
        printf("1 para cadastrar alunos.\n");
        printf("2 para buscar aluno.\n");
        printf("3 para listar alunos\n");
        printf("4 para sair.\n:");
            scanf("%d",&opc);

        switch(opc){

            case 1:{

            break;}

            case 2:{

            break;}

            case 3:{

            break;}

            case 4:{
                printf("\nAté logo !!!\n");
                fflush(stdin);
            break;}

            default:{
                printf("\nOpção invalida!!!\nPressione ENTER para continuar...\n");
                fflush(stdin);
                getchar();

            }

        }
    }while(opc != 4);

    return 0;
}
