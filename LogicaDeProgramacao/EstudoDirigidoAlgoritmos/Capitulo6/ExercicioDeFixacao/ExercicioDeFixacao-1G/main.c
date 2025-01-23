#include <stdio.h>
#include <locale.h>
#include <math.h>

#define tam 3
int main(){

    setlocale(LC_ALL,"");

    int vetA[tam];
    int vetB[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite o valor da %dª posição: ",i+1);
            scanf("%d",&vetA[i]);
        vetB[i] = pow(vetA[i],2);
    }

    for(int i = 0; i < tam; i++){
        printf("%d² = %d\n",vetA[i],vetB[i]);
    }
    return 0;
}
