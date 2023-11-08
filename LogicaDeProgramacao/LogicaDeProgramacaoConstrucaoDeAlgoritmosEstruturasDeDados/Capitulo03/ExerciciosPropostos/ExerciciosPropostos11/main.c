#include <stdio.h>
#include <locale.h>

typedef struct {
    char nome[30];
    int Ouro,prata,bronze,ranking;
}paises;

int main(){
    setlocale(LC_ALL,"");

    paises pais1,pais2,pais3;

    printf("\nEntre com o nome do país: ");
        scanf(" %s",&pais1.nome);
    printf("\nMedalhas de OURO: ");
        scanf("%d",&pais1.Ouro);
    printf("\nMedalhas de PRATA: ");
        scanf("%d",&pais1.prata);
    printf("\nMedalhas de BRONZE: ");
        scanf("%d",&pais1.bronze);

        printf("\nEntre com o nome do país: ");
        scanf(" %s",&pais2.nome);
    printf("\nMedalhas de OURO: ");
        scanf("%d",&pais2.Ouro);
    printf("\nMedalhas de PRATA: ");
        scanf("%d",&pais2.prata);
    printf("\nMedalhas de BRONZE: ");
        scanf("%d",&pais2.bronze);

        printf("\nEntre com o nome do país: ");
        scanf(" %s",&pais3.nome);
    printf("\nMedalhas de OURO: ");
        scanf("%d",&pais3.Ouro);
    printf("\nMedalhas de PRATA: ");
        scanf("%d",&pais3.prata);
    printf("\nMedalhas de BRONZE: ");
        scanf("%d",&pais3.bronze);

        pais1.ranking = (pais1.Ouro*3)+(pais1.prata*2)+(pais1.bronze);
        pais2.ranking = (pais2.Ouro*3)+(pais2.prata*2)+(pais2.bronze);
        pais3.ranking = (pais3.Ouro*3)+(pais3.prata*2)+(pais3.bronze);

        if((pais1.ranking>=pais2.ranking)&&(pais1.ranking>=pais3.ranking)){
            if(pais2.ranking>=pais3.ranking){
                printf("\n1º %s\n2º %s\n3º %s",pais1.nome,pais2.nome,pais3.nome);
            }else{
                printf("\n1º %s\n2º %s\n3º %s",pais1.nome,pais3.nome,pais2.nome);
            }
        }else if((pais2.ranking>=pais1.ranking)&&(pais2.ranking>=pais3.ranking)){
            if(pais1.ranking>=pais3.ranking){
                printf("\n1º %s\n2º %s\n3º %s",pais2.nome,pais1.nome,pais3.nome);
            }else{
                printf("\n1º %s\n2º %s\n3º %s",pais2.nome,pais3.nome,pais1.nome);
            }
        }else if((pais3.ranking>=pais1.ranking)&&(pais3.ranking>=pais2.ranking)){
            if(pais2.ranking>=pais1.ranking){
                printf("\n1º %s\n2º %s\n3º %s",pais3.nome,pais2.nome,pais1.nome);
            }else{
                printf("\n1º %s\n2º %s\n3º %s",pais3.nome,pais1.nome,pais2.nome);
            }
        }

    return 0;
}
