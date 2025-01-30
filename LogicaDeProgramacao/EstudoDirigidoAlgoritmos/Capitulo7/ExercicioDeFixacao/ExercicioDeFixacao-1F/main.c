#include <stdio.h>
#include <locale.h>
#include <math.h>

#define tam 5

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite o %dº do vetor: ",i+1);
            scanf("%d",&vetA[i]);
        vetB[i] = pow(vetA[i],3);
    }



    return 0;
}
