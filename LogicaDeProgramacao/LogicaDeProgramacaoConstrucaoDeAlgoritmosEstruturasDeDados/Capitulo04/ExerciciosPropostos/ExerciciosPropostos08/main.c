#include <stdio.h>
#include <string.h>
#include <locale.h>

#define max 3

int main(){
    setlocale(LC_ALL,"");

    int contalador,fim;
    float provas[max];
    char nome[max][15],nomeAux[15];

    for(int i = 0; i < max; i++){
        printf("\nEntre com o nome do %dº participante: ",i+1);
                scanf("%s",&nome[i]);
        printf("\nEntre com a nota do %dº participante: ",i+1);
            scanf("%f",&provas[i]);
    }

    fim = max;

    do{
        contalador = 0;
        for(int i = 0; i < fim-1; i++){
            if(provas[i]<provas[i+1]){
                provas[i+1] = provas[i+1]+provas[i];
                provas[i]= provas[i+1]-provas[i];
                provas[i+1] = provas[i+1]-provas[i];

                strcpy(nomeAux,nome[i]);
                strcpy(nome[i],nome[i+1]);
                strcpy(nome[i+1],nomeAux);
                contalador = i;
            }
        }
        fim--;
    }while(contalador!=0);

    while(provas[contalador]>=7){
        printf("\n%dº lugar %s com %.1f pontos.",contalador+1,nome[contalador],provas[contalador]);
        contalador++;
    }

    return 0;
}
