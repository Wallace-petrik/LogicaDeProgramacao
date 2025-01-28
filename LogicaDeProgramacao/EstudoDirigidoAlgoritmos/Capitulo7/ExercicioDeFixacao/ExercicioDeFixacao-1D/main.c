#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam], vetC[tam];
    int continua, fim = tam;

    for(int i = 0; i < tam; i++){
        printf("Digite o %dº número do vetor A:  ",i+1);
            scanf("%d",&vetA[i]);
    }

    do{
        continua = 0;
        for(int i = 0; i < fim-1; i++){
            if(vetA[i]>vetA[i+1]){
                vetA[i]=vetA[i]+vetA[i+1];
                vetA[i+1] =vetA[i]-vetA[i+1];
                vetA[i]=vetA[i]-vetA[i+1];
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);

    for(int i = 0; i < tam; i++){
        printf("Digite o %dº número do vetor B:  ",i+1);
            scanf("%d",&vetB[i]);
    }

    do{
        continua = 0;
        for(int i = 0; i < fim-1; i++){
            if(vetB[i]>vetB[i+1]){
                vetB[i]=vetB[i]+vetB[i+1];
                vetB[i+1] =vetB[i]-vetB[i+1];
                vetB[i]=vetB[i]-vetB[i+1];
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);

    for(int i = 0; i < tam; i++){
        vetC[i] = vetA[i] + vetB[i];
    }

    do{
        continua = 0;
        for(int i = 0; i < fim-1; i++){
            if(vetC[i]>vetC[i+1]){
                vetC[i]=vetC[i]+vetC[i+1];
                vetC[i+1] =vetC[i]-vetC[i+1];
                vetC[i]=vetC[i]-vetC[i+1];
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);


    for(int i = 0; i < tam; i++){
        printf("Vet C [%d] = %d\n",i+1,vetC[i]);
    }

    return 0;
}
