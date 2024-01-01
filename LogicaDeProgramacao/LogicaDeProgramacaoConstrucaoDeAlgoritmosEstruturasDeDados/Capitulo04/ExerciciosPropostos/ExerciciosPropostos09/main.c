#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define max 5

int main(){
    setlocale(LC_ALL,"");

    float alturas[max],somatoria = 0;
    float media, mediana = 0, desvioPadrao;
    int moda = 0, fim, maior = 0, contador = 0;

    for (int i = 0; i < max; i++){
        printf("\nEntre com os dados da %dº altura: ",i+1);
            scanf("%f",&alturas[i]);

            somatoria += alturas[i];
    }

    bubblesort(alturas,max);

    media = somatoria/max;
    desvioPadrao = ((somatoria*somatoria)/max) - media*media;

    fim = max;

    for(int i = 0; i < fim; i++){
        for(int j = 0; j < fim; j++){
            if(alturas[i]==alturas[j]){
                contador++;
            }
        }
        if(contador > maior){
            moda = i;
            maior = contador;
        }
    }

    if(max%2==1){
        mediana = alturas[(max/2)+1];
    }else{
        mediana = (alturas[(max/2)+1]+alturas[(max/2)]);
    }

    printf("\nMédia = %.1f",media);
    printf("\nDesvio Padrão = %.1f",desvioPadrao);
    printf("\nModa = %.1f",alturas[moda]);
    printf("\nMediana = %.1f",mediana);

    return 0;
}
void bubblesort(float *vet,int tam){
    int controlador = 0;
    do{
        controlador = 0;
        for(int i = 0; i < tam - 1; i++){
            if(vet[i]>vet[i+1]){

                vet[i+1] =  vet[i+1] + vet[i];
                vet[i] = vet[i+1] - vet[i];
                vet[i+1] = vet[i+1] - vet[i];

                controlador = 1;
            }
            tam--;
        }
    }while(controlador != 0);

}
