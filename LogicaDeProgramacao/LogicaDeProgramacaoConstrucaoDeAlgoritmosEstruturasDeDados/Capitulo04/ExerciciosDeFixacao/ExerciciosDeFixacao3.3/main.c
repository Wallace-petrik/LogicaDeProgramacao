#include <stdio.h>
#include <locale.h>
#define tan 500



typedef struct {
    int cod;
    char nome[40];
    float preco;
    int baixo[4][6];
}regProduto;


int main(){
    setlocale(LC_ALL,"");

    regProduto produto[tan];

    for(int i = 0; i < tan; i++){

        produto[i].cod = i;
        for(int l = 0; i < 4; i++){
            for(int c = 0; c < 6; c++){
                produto[i].baixo[l][c] = 0;
            }
        }

    }

    return 0;
}
