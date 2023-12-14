#include <stdio.h>
#include <locale.h>
#define tam 5
int main(){
    setlocale(LC_ALL,"");

    int vetA[tam],vetB[tam];

    for(int i = 0; i < tam; i++){
        printf("\nEntre com o %dº elemento do array: ",i+1);
            scanf("%d",&vetA[i]);

        if(i%2 == 0 ){
            vetB[i] = vetA[i] * 2;
        }else{
            vetB[i] = vetA[i] * 3;
        }

    }
    printf("\n");
    for(int i = 0; i < tam; i++){
        printf("[%2.d] ",vetA[i]);

    }
    printf("\n");
    for(int i = 0; i < tam; i++){

        printf("[%2.d] ",vetB[i]);
    }
    return 0;
}
