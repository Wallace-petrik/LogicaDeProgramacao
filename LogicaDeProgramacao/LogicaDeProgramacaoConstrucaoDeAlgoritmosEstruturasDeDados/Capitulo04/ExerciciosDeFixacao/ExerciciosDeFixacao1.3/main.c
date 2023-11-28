#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    const int controle = 20;
    int j=controle-1,k = (controle/2)-1;

    float vetA[controle], vetB[controle], vetR[controle];

    for (int i = 0 ; i < controle ; i++){
        printf("\nEntre com o %dº elemento do Vet A: ",i+1);
            scanf("%f",&vetA[i]);
    }

    for (int i = 0 ; i < controle ; i++){
        printf("\nEntre com o %dº elemento do Vet B: ",i+1);
            scanf("%f",&vetB[i]);
        vetR[i] = 0.0;
    }

    for(int i = 0;i<controle;i++){
        vetR[k] = vetA[i] * vetB[j];
        if(i%2!=0){
            k = k - (i+1);
        }else{
            k = k + (i+1);
        }
        j = j - 1;
    }

    for(int i = 0 ; i < controle ; i++){
        printf("\n VetR[%d]=%.2f",i,vetR[i]);
    }

    return 0;
}
