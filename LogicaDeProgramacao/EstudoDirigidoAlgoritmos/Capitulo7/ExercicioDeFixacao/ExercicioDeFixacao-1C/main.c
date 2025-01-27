#include <stdio.h>
#include <locale.h>
#define tam 5
int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam];
    int fat = 1;
    int continua, fim = tam;

    for(int i = 0; i < tam; i++){
        printf("Digite um o %dª número do vetor: ",i+1);
            scanf("%d",&vetA[i]);
        vetB[i] = 1;
        for(int j = vetA[i]; j > 1; j--){
            fat *= j;
        }
        vetB[i] = fat;
        fat = 1;
    }

    do{
        continua = 0;
        for(int i = 0; i < fim-1; i++){
            if(vetB[i]>vetB[i+1]){
                vetB[i] = vetB[i]+vetB[i+1];
                vetB[i+1] = vetB[i]-vetB[i+1];
                vetB[i] = vetB[i]-vetB[i+1];
                continua = 1;
            }
        }
        fim--;
    }while(continua != 0);

    for(int i = 0; i < tam; i++){
        printf("Vet[%d] = %d\n",i+1,vetB[i]);
    }
    return 0;
}
