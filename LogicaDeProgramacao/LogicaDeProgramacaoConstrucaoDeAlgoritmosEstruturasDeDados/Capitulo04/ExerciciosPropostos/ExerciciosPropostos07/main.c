#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5



int main(){
    setlocale(LC_ALL,"");

    int vetA[tam],vetB[tam],vetC[tam*2],contador = 0;
    int fim;

    printf("\nEntre com o dados do primeiro vetor:");
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
        vetC[i]=vetA[i];
        vetC[i+tam]=vetB[i];
    }

    fim = tam *2;

    for(int i = 0; i < fim-1; i++){
        for(int j = i+1; j < fim; j++){
            if(vetC[i]==vetC[j]){
                for(int k = j; k < fim - 1; k++){
                    vetC[k]=vetC[k+1];
                }
                fim--;
                j--;
            }
        }
    }

    imprimeVet(vetC,fim);
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
    printf("AUB = ");
    for(int i = 0; i < tamanho; i++){
        printf("[%d] ",vet[i]);
    }
    printf("\n\n");
}
