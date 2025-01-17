#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam];
    int vetB[tam];

    for(int i = 0; i <  tam; i++){
        printf("Digite o %dª número: ",i+1);
            scanf("%d",&vetA[i]);
            vetB[i] = vetA[i] * 3;
    }
    int i = 0;
    while (i < tam) {
        printf("VetB[%d] = %d\n", i + 1, vetB[i]);
        i++;
    }
    return 0;
}
