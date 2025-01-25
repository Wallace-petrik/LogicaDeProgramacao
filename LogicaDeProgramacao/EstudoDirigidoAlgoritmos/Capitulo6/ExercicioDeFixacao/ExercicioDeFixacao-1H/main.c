#include <stdio.h>
#include <locale.h>
#define tam 5
int main(){

    setlocale(LC_ALL,"");

    /*int vetA[tam];
    int vetB[tam];

    for(int i  = 0; i < tam; i++){
        printf("Entre com o %dª elemento do vetor: ",i);
            scanf("%d",&vetA[i]);
    }
    for(int i = 0; i < tam; i++){
        vetB[tam-i-1] = vetA[i];
    }
    for(int i = 0; i < tam; i++){
        printf("VetA[%d] = %d\tVetB[%d] = %d\n",i,vetA[i],i,vetB[i]);
    }*/

    int a = 5;
    int b = 2;

    printf(" Resto da divisão = %d",a - b * (a/b));

    return 0;
}
