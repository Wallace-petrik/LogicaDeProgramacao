#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tan 5

int main(){
    setlocale(LC_ALL,"");

    int vetA[tan],vetB[tan];

    for(int i = 0; i < tan; i++){
        printf("\nEntre com o %dº número: ",i+1);
            scanf("%d",&vetA[i]);
    }

    for(int i = 0, j = tan-1; i < tan; i++,j--){

        vetB[j] = vetA[i];

    }

    printf("\n[A] [B]\n");
    for(int i = 0; i < tan; i++){
        printf("\n[%d] [%d]",vetA[i],vetB[i]);
    }
    return 0;
}
