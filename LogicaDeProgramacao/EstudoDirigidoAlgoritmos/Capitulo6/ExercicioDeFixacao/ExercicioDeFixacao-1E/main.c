#include <stdio.h>
#include <locale.h>
#define tam 3

int main(){

    setlocale(LC_ALL,"");

    int vetA[tam], vetB[tam], vetC[tam*2];

    for(int i = 0; i < tam*2; i++){
        printf("Digite o %dª número: ",i+1);
        if(i<tam){
            scanf("%d",&vetA[i]);
        }else{
                scanf("%d",&vetB[i-tam]);
        }
    }

    for(int i = 0; i < tam; i++){
        vetC[i]=vetA[i];
        vetC[i+tam]=vetB[i];
    }
    for(int i = 0; i < tam*2; i++){
        printf("VetC[%d] = %d\n",i+1,vetC[i]);
    }
    return 0;
}
