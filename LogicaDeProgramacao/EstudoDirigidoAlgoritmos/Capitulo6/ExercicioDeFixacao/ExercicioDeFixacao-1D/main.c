#include <stdio.h>
#include <locale.h>
#define tam 3
int main(){

    setlocale(LC_ALL,"");

    int vetA[tam];
    int vetB[tam];
    int vetC[tam];


    for(int i = 0; i < tam; i++){
        printf("Digite dois números para %dª operação: ",i+1);
            scanf("%d%d",&vetA[i],&vetB[i]);

        vetC[i] = vetA[i] - vetB[i];
    }

    for(int i = 0; i < tam; i++){

        printf("[%d]\t[%d]\t[%d]\n",vetA[i],vetB[i],vetC[i]);

    }
    return 0;
}
