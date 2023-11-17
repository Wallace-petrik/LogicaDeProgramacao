#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int candidato1 = 0, candidato2 = 0, candidato3 = 0, candidato4 = 0;
    int voto = 1, votoBranco = 0, votoNulo = 0, totalDeVotos = 0;

    while(voto!=0){
        printf("Vote no seu candidato.\n\n1/p Carlos\n2/p Thiago\n3/p Rita\n4/p João\n5/p Voto Nulo\n5/p Voto em Branco\n\nVote: ");
            scanf("%d",&voto);

            if(voto>=1 && voto <=6){totalDeVotos++;}

        switch(voto){
            case 0: printf("\nAgradeço a participação.");
            break;
            case 1: candidato1++;
            break;
            case 2: candidato2++;
            break;
            case 3: candidato3++;
            break;
            case 4: candidato4++;
            break;
            case 5: votoNulo++;
            break;
            case 6: votoBranco++;
            break;
            default: printf("\nInvalido");
            break;
        }

    }

    printf("\nCarlor teve %d vatos com um percentual de %.2f%% do total. ",candidato1,(float)(candidato1*100)/totalDeVotos);
    printf("\nThiago teve %d vatos com um percentual de %.2f%% do total. ",candidato2,(float)(candidato2*100)/totalDeVotos);
    printf("\nRita teve %d vatos com um percentual de %.2f%% do total. ",candidato3,(float)(candidato3*100)/totalDeVotos);
    printf("\nJoão teve %d vatos com um percentual de %.2f%% do total. ",candidato4,(float)(candidato4*100)/totalDeVotos);
    printf("\nVotos Nulos teve %d vatos com um percentual de %.2f%% do total. ",votoNulo,(float)(votoNulo*100)/totalDeVotos);
    printf("\nVotos em Branco teve %d vatos com um percentual de %.2f%% do total. \n",votoBranco,(float)(votoBranco*100)/totalDeVotos);
    return 0;
}
