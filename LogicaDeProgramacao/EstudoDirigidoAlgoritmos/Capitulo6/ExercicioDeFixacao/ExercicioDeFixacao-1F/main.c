#include <stdio.h>
#include <locale.h>
#define tam 2

int main(){

    setlocale(LC_ALL,"");

    int vetA[2], vetB[3], vetC[5];

    for(int i = 0; i < tam; i++){
        printf("Digite o valor %dª posição do vetor 1: ",i);
            scanf("%d",&vetA[i]);
    }
    for(int i = 0; i <= tam; i++){
        printf("Digite o valor %dª posição do vetor 2: ",i);
            scanf("%d",&vetB[i]);
    }

    for(int i = 0; i < 5; i++ ){
        if(i<tam){
            vetC[i] = vetA[i];
        }else{
            vetC[i] = vetB[i-2];
        }
    }
    for(int i = 0; i < 5; i++){
        printf("Vet[%d] = %d\n",i,vetC[i]);
    }
    return 0;
}
