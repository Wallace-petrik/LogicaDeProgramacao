#include <stdio.h>
#include <locale.h>
#define tam 40
typedef struct {

        int numPas;
        int idade;
        char nome[40];
        char dada[10];
        char origem[40];
        char destino[40];
        char hot[10];

    }reEmbarque;

int main(){
    setlocale(LC_ALL,"");

    reEmbarque onibus;

    int somaIdade;
    float mediaIdade;

    for(int i = 0; i < tam; i++){

        somaIdade+=onibus[i].idade;

    }

    mediaIdade = (float)somaIdade/tam;

    printf("%.1f".mediaIdade);

    for(int i = 0; i < tam; i++){
        if(onibus[i].idade>mediaIdade){
            printf("\n%.1f",onibus[i].nome);
        }

    }

    return 0;
}
