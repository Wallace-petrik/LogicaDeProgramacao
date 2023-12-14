#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5



int main(){
    setlocale(LC_ALL,"");

    int vetA[tam],vetB[tam],vetC[tam];

    printf("\nEntre com o dados o primeiro vetor:");
    for(int i = 0; i < tam; i++){
        scanf("%d",&vetA[i]);
    }
    /*printf("\nEntre com o dados o segundo vetor:");
    for(int i = 0; i < tam; i++){
        scanf("%d",vetB[i]);
    }*/

    bubbleSort(vetA,tam);
    return 0;
}

void bubbleSort (int *vet, int tam){
		int continua;
		do{
				continua = 0;
				for(int i = 0; i < tam-1; i++){
						if(vet[i] > vet[i+1]){
								vet[i] = vet[i] + vet[i+1];
								vet[i+1] = vet[i] - vet[i+1];
								vet[i] = vet[i] - vet[i+1];
								continua = i;
						}
				}
				tam--;
		}while(continua != 0);
}
