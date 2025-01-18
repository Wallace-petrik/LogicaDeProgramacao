#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam];
    int vetB[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite %dª número: ",i+1);
            scanf("%d",&vetA[i]);
    }



    printf("\n");
    for(int i = 0; i < tam; i++){

        printf("Fatorial de %d = %d\n",vetA[i],vetB[i]);

    }
    return 0;
}
