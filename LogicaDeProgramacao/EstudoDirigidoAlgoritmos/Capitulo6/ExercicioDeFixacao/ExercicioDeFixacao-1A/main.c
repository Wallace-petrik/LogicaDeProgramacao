#include <stdio.h>
#include <locale.h>
#define tam 3
int main(){

    setlocale(LC_ALL,"");

    int vet[tam];

    for(int i = 0; i < tam; i++){
        printf("Digite o %dª número: ",i+1);
            scanf("%d",&vet[i]);
    }

    for(int i = 0; i < tam; i++){
        printf("Vet[%d] = %d\n",i+1,vet[i]);
    }

    return 0;
}
