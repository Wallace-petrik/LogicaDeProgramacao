#include <stdio.h>
#include <locale.h>
#define tam 5

int main(){

    setlocale(LC_ALL,"");

    int vet[tam];
    int continua = 0;
    int fim;

    for(int i = 0; i < tam; i++){
        printf("Digite o %dª do vetor: ",i+1);
        scanf("%d",&vet[i]);
    }

    //Início do Bubble Sort
    fim  = tam;
    do{
        continua = 0 ;
         for(int i = 0; i < fim-1; i++){
            if(vet[i]>vet[i+1]){
                vet[i]=vet[i]+vet[i+1];
                vet[i+1]=vet[i]-vet[i+1];
                vet[i]=vet[i]-vet[i+1];
                continua = i;
            }
         }
         fim--;
    }while(continua != 0);
    //Fim do Bubble Sort

    for(int i = 0; i < tam; i++){
        printf("vet[%d] = %d\n",i+1,vet[i]);
    }

    return 0;
}
