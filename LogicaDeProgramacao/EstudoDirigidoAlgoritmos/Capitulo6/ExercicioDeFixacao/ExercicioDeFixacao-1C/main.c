#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam];
    int vetB[tam];
    int fib;
    for(int i = 0; i < tam; i++){
        printf("Digite %dª número: ",i+1);
            scanf("%d",&vetA[i]);
    }

    for(int i = 0; i < tam; i++){
        fib = 1;
        for(int j  = 1; j <= vetA[i]; j++){
           fib *= j;
        }
        vetB[i] = fib;
    }

    printf("\n");
    for(int i = 0; i < tam; i++){

        printf("Fatorial de %d! = %d\n",vetA[i],vetB[i]);

    }
    return 0;
}
