#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL,"");

    int matriz[7][7] = {{0,02,11,06,15,11,01},
                        {02,0,07,12,04,02,15},
                        {11,07,0,11,8,03,12},
                        {06,12,11,0,10,02,01},
                        {15,04,8,10,0,05,13},
                        {11,02,03,05,05,0,14},
                        {01,15,13,01,13,14,0}};

    int cidade,cidadeDePartida,tempoTotal = 0;
    int controle = 0;
    do{
        printf("\n0/p Rio de Janeiro\n1/p São Gonçalo\n2/p Duque de Caxias\n3/p Nova Iguaçu\n4/p Belford Roxo\n5/p Niterói\n6/p Petrópolis\n\nPara sair digite -1");

        if(controle==0){
            printf("\nEntre as cidades acima, escola uma para o ponto de partida: ");
                scanf("%d",&cidade);
        }else{
            printf("\nEscola a próxima cidade: ");
                scanf("%d",&cidade);
        }

        if(cidade==-1){

            printf("\nAté logo!\n");
        }else{
             if(cidade>=0 && cidade<=6){

                if(controle==0){
                    controle=1;
                    cidadeDePartida = cidade;
                }else{
                    tempoTotal += matriz[cidadeDePartida][cidade];
                    cidadeDePartida = cidade;
                }

             }else{
                system("cls");
                printf("\nCidades invalidas.\nTente novamente.\n");
                printf("\nPressione qualquer tecla para continuar");
                getch();
                system("cls");
             }
        }
    }while(cidade!=-1);

    printf("\nO tempo total é = %d",tempoTotal);

    return 0;
}
