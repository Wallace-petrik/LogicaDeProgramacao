#include <stdio.h>
#include <locale.h>

#define elem 2

struct{
    char nome[30];
    float altura;
}typedef Pessoa;

int main(){

    setlocale(LC_ALL,"");

    Pessoa pessoa[elem];

    int opcao = 0;

    do{

        system("cls");
        fflush(stdin);

        printf("1 para registar pessoas\n");
        printf("2 para listar pessoas menors ou irguais a 1.5m\n");
        printf("3 para listar pessoas maiores que 1.5m\n");
        printf("4 para listar psssoas maiores que 1.5m e menores que 2.0m\n");
        printf("5 para listar todas as pessoas e média de altura\n");
        printf("0 para sair\n: ");
            scanf("%d%*c",&opcao);

        switch(opcao){

            case 0:{
                printf("\n\nAté logo !!!");
                getchar();
            break;}

            case 1:{

                system("cls");
                for(int i = 0; i < elem; i++){
                    printf("O nome e %dª pessoa: ",i+1);
                        scanf("%[^\n]%*c",pessoa[i].nome);
                    printf("Altura: ");
                        scanf("%f%*c",&pessoa[i].altura);
                    system("cls");
                }

            break;}

            case 2:{

                system("cls");
                int controle = 0;

                for(int i = 0; i < elem; i++){
                    if(pessoa[i].altura<=1.5){
                        printf("%s\t%.2f",pessoa[i].nome,pessoa[i].altura);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhuma pessoa encontrada !!!");
                }
                getchar();
            break;}

            case 3:{
                system("cls");
                int controle = 0;

                for(int i = 0; i < elem; i++){
                    if(pessoa[i].altura>1.5){
                        printf("%s\t%.2f",pessoa[i].nome,pessoa[i].altura);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhuma pessoa encontrada !!!");
                }
                getchar();
            break;}

            case 4:{

            break;}

            case 5:{

            break;}

            default:{
                printf("\n\nOpção invalida !!!");
                getchar();
                system("cls");
            break;}
        }

    }while(opcao != 0);

    return 0;
}
