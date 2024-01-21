#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int numeroDaPassagem;
    char nomeDoPassageiro[40];
    int sexo;
}Poltronas;

typedef struct{
    char origem[40];
    char destino[40];
    char data[11];
    char horario[6];
    int distancia;
    Poltronas passageiros[44];
}Linha;

int main(){
    setlocale(LC_ALL,"");

    Linha onibus[10] = {"Campinas","Rio de Janeiro","20/03/2024","10:30",400,01,"Wallace",1};

    int opcao = 0, linhasDoOnibus = 0, controle = 0,contador = 0;

    do{
        system("cls");
        printf("1 Para buscar ônibus.\n");
        printf("2 Para linha de ônibus que estão lotadas.\n");
        printf("10 Para sair\n");
            scanf("%d",&opcao);
        switch(opcao){

            case 1:
                system("cls");
                printf("Entre com o numero do ônibus:");
                    scanf("%d",&linhasDoOnibus);
                for(int i = 0; i < 10; i++){
                    if(i==linhasDoOnibus){
                        printf("Horário de Saída : %s\n",onibus[i].horario);
                        printf("Distância = %d\n",onibus[i].distancia);
                        controle = 1;
                        break;
                    }
                }
                if(controle==0){
                    printf("Linha de ônibus não encontrada\n");
                }
                controle = 0;
                system("pause");
                system("cls");
            break;
            case 2:



            break;
            case 10:
                system("cls");
                printf("Até logo.\n");
            break;
            default:
                system("cls");
                printf("Opção invalida\n");
                system("pause");
        }
    }while(opcao!=10);

    return 0;
}
