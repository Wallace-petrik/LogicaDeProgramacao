#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5



int main(){
    setlocale(LC_ALL,"");

    int vetA[tam],vetB[tam],vetC[tam],contador = 0;

    printf("\nEntre com o dados o primeiro vetor:");
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetA[i]);
    }
    printf("\nEntre com o dados o segundo vetor:");
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetB[i]);
    }

    bubbleSort(vetA,tam);
    bubbleSort(vetB,tam);

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(vetA[i]==vetB[j]){
                if(vetA[i]!=vetC[i] && vetC[contador-1]!=vetA[i]){
                    vetC[contador]=vetA[i];
                    contador++;
                }
            }
        }
    }
    if(contador>0){
        imprimeVet(vetC,contador);
    }else{
        printf("\nNão ha intersecção!");
    }
    return 0;
}

void bubbleSort (int *vet, int fim){
		int continua;
		do{
				continua = 0;
				for(int i = 0; i < fim-1; i++){
						if(vet[i] > vet[i+1]){
								vet[i] = vet[i] + vet[i+1];
								vet[i+1] = vet[i] - vet[i+1];
								vet[i] = vet[i] - vet[i+1];
								continua = i;
						}
				}
				fim--;
		}while(continua != 0);
}

void imprimeVet(int *vet, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("[%d] ",vet[i]);
    }
    printf("\n\n");
}


