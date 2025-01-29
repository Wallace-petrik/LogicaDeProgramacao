#include <stdio.h>
#include <locale.h>
#define tam 2
int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam+1], vetC[2 * tam + 1];
    int continuar, fimDeC = sizeof(vetC)/sizeof(vetC[0]);

    for(int i = 0; i < sizeof(vetA)/sizeof(vetA[0]); i++){
        printf("Digiteo %dº do vetor A: ",i+1);
            scanf("%d",&vetA[i]);
    }

    printf("\n\n");

    for(int i = 0; i < sizeof(vetB)/sizeof(vetB[0]); i++){
        printf("Digiteo %dº do vetor B: ",i+1);
            scanf("%d",&vetB[i]);
    }

    for(int i = 0; i < sizeof(vetB)/sizeof(vetB[0]); i++){
        if( i < sizeof(vetA)/sizeof(vetA[0])){
            vetC[i] = vetA[i];
            vetC[i+sizeof(vetB)/sizeof(vetB[0])-1] = vetB[i];
        }else{
            vetC[i+sizeof(vetB)/sizeof(vetB[0])-1] = vetB[i];
        }
    }

    do{
        continuar = 0;
        for(int i = 0; i < fimDeC-1; i++){
            if(vetC[i]>vetC[i+1]){
                vetC[i] = vetC[i] + vetC[i+1];
                vetC[i+1] = vetC[i] - vetC[i+1];
                vetC[i] = vetC[i] - vetC[i+1];
                continuar = i;
            }
        }
        fimDeC--;
    }while(continuar != 0);

    printf("\n\n");

    for(int i = 0; i < sizeof(vetC)/sizeof(vetC[0]); i++){
        printf("VetC[%d] = %d\n",i+1,vetC[i]);
    }

    return 0;
}
