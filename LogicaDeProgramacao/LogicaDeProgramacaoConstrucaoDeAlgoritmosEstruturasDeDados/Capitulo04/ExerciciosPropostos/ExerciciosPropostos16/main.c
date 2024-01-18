#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define Tam_Max 5

typedef struct{
    char proprietario[40];
    char modelo[40];
    char placa[8];
    char cor[40];
    int combustivel;
    int chassi;
    int anor;
}Veiculo;

int main(){
    setlocale(LC_ALL,"");

    Veiculo carros[Tam_Max] = {"Wallace","Astra","WPS-0805","Branco",3,123321,2014};

    int controle = 0, contador = 0,opcao;

    do{
        printf("Escolha uma opção\n");
        printf("\n1/p Listar proprietários de carros com anos posterios 1980 movidos a diesel.");
        printf("\nDigite uma opção: ");
            scanf("%d",&opcao);
        switch(opcao){
            controle = 0;
            contador = 0;
            case 1:
                system("cls");
                for(int i = 0; i < Tam_Max; i++){ // 1 para álcool, 2 para gasolina e 3 para diesel.
                    if(carros[i].anor>=1980 && carros[i].combustivel==3){
                        contador++;
                        printf("%dº Proprietário  = %s\n",contador,carros[i].proprietario);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhum proprietário encontrado\n");
                }
                system("pause");
                system("cls");
            break;
            default:
                system("cls");
                printf("Opção invalida!\nTente novamente.\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=10);
    return 0;
}
