#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_MAX 5

typedef struct{
    int codigoDeCatalogacao;
    int numeroDePaginas;
    char nomeDaObra[40];
    char nomeDoAutor[40];
    char editora[40];
    char doado[40];
}Obras;

int main(){
    setlocale(LC_ALL,"");

    Obras cienciasExatas[TAM_MAX],cienciasHumanas[TAM_MAX],cienciasBiomedicas[TAM_MAX];

    return 0;
}
