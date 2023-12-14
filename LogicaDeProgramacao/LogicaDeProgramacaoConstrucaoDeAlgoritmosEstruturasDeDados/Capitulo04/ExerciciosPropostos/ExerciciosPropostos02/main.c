#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 5

int main(){
    setlocale(LC_ALL,"");

    int vetA[tam],vetB[tam];

    for(int i = 0; i < tam; i++){
        printf("\nEntre com o %dº número: ",i+1);
            scanf("%d",&vetA[i]);
    }

    for(int i = 0, j = tam-1; i < tam; i++,j--){

        vetB[j] = vetA[i];

    }

    printf("\n[A] [B]\n");
    for(int i = 0; i < tam; i++){
        printf("\n[%d] [%d]",vetA[i],vetB[i]);
    }
    return 0;
}
