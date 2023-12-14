#include <stdio.h>
#include <locale.h>
#define tam 500



typedef struct {
    int cod;
    char nome[40];
    float preco;
    int baixo[4][6];
}regProduto;


int main(){
    setlocale(LC_ALL,"");

    regProduto produto[tam];
    int baixaMensal = 0, maiorBaixa, indice = 0;

    for(int i = 0; i < tam; i++){
        baixaMensal = 0;
        produto[i].cod = i;
        for(int l = 0; i < 4; i++){
            for(int c = 0; c < 6; c++){
                baixaMensal = baixaMensal + produto[i].baixo[l][c];
            }
        }

        if(baixaMensal>maiorBaixa){
            maiorBaixa = baixaMensal;
            indice = i;
        }

    }

    if(indice>0){
        printf("\nProduto mais vendido %s: ", produto[indice].nome);
        printf("\nTotal de baixas: %d", maiorBaixa);
    }else{
        printf("Nunhuma baiza registrada");
    }

    return 0;
}
