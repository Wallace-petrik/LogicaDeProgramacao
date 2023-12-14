#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tam 2

int main(){
    setlocale(LC_ALL,"");

    char nomeProduto[tam][20];
    float curtoProduto[tam], precoProduto[tam];

    for(int i = 0; i < tam; i++){
        printf("\nEntre com a nome do %dº produto: ",i+1);
            scanf("%[^\n]",&nomeProduto[i]);
        printf("\nEntre com o custo do %dº produto: ",i+1);
            scanf("%f",&curtoProduto[i]);
        printf("\nEntre com o preço do %dº produto: ",i+1);
            scanf("%f",&precoProduto[i]);
            getchar();
    }

    for(int i = 0; i < tam; i++){
        if(precoProduto[i]-curtoProduto[i]<curtoProduto[i]*0.1){
            printf("O produto %s tem um lucro menor que 10%%\n",nomeProduto[i]);
        }
    }
    for(int i = 0; i < tam; i++){
        if(precoProduto[i]-curtoProduto[i]>curtoProduto[i]*0.1 && precoProduto[i]-curtoProduto[i]<curtoProduto[i]*0.3){
            printf("O produto %s tem um lucro entre 10%% e 30%%\n",nomeProduto[i]);
        }
    }
    for(int i = 0; i < tam; i++){
        if(precoProduto[i]-curtoProduto[i]>curtoProduto[i]*0.3){
            printf("O produto %s tem um lucro entre 10%% e 30%%\n",nomeProduto[i]);
        }
    }
    return 0;
}
