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

    int cidadeDeOrigem,cidadeDeDestino,cidadeP1,cidadeP2;
    int soma1 = 0,soma2 = 0;

    do{
        printf("\n0/p Rio de Janeiro\n1/p São Gonçalo\n2/p Duque de Caxias\n3/p Nova Iguaçu\n4/p Belford Roxo\n5/p Niterói\n6/p Petrópolis\n\nPara sair digite -1 em qualquer opção");

        printf("\nEntre com as cidades de origem e destino: ");
            scanf("%d%d",&cidadeDeOrigem,&cidadeDeDestino);
        printf("\nEntre com duas cidades como opção de descanso: ");
            scanf("%d%d",&cidadeP1,&cidadeP2);

        if(cidadeDeDestino<-1 || cidadeDeDestino>6 || cidadeDeOrigem<-1 || cidadeDeOrigem>6 || cidadeP1<-1 || cidadeP1>6 || cidadeP2<-1 || cidadeP2>6){
            system("cls");
            printf("\nDados inválidos tente novamente!");
            getch();
            system("cls");
            continue;
        }else{

            soma1 = matriz[cidadeDeOrigem][cidadeP1]+matriz[cidadeP1][cidadeDeDestino];
            soma2 = matriz[cidadeDeOrigem][cidadeP2]+matriz[cidadeP2][cidadeDeDestino];

            if(soma1>soma2){
                printf("\nMelhor opção = %d, %d, %d",cidadeDeOrigem,cidadeP1,cidadeDeDestino);
            }else{
                if(soma1<soma2){
                    printf("\nMelhor opção = %d, %d, %d",cidadeDeOrigem,cidadeP2,cidadeDeDestino);
                }else{
                    printf("\nAs duas opções consomem o mesmo tempo!");
                }
            }
            cidadeDeDestino=-1;
        }

    }while(cidadeDeDestino!=-1 && cidadeDeOrigem!=-1 && cidadeP1!=-1 && cidadeP2!=-1);


    return 0;
}
