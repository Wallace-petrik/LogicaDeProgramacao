#include <stdio.h>
#include <locale.h>
#define elem 2

struct{

    int mat;
    float sal;
    char nome[30];

}typedef Empregado;

int main(){

    setlocale(LC_ALL,"");

    Empregado empregado[elem];
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
                for(int i = 0; i < elem; i++){
                     system("cls");
                    printf("Digite a matrícula do empregado: ");
                        scanf("%d%*c",&empregado[i].mat);
                    printf("Entre com o nome do empregado: ");
                    fgets(empregado[i].nome,50,stdin);
                    empregado[i].nome[strcspn(empregado[i].nome,"\n")] = '\0';
                    printf("Entre com o salário: ");
                        scanf("%f%*c",&empregado[i].sal);
                }
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
