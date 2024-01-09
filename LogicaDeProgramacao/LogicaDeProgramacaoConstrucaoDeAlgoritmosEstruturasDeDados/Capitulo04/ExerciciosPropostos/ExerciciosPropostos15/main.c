#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM_MAX 3



typedef struct{
    int codigoDeCatalogacao;
    int numeroDePaginas;
    char nomeDaObra[40];
    char nomeDoAutor[40];
    char editora[40];
    char doado[40];
}Obras;


void bubblesort(Obras livros[TMP_MAX]);
void buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca);
int main(){
    setlocale(LC_ALL,"");

    int codigo,opcao,area;

    Obras cienciasExatas[TAM_MAX] = {75,155,"Banana Rei","Calor Machado","Book","Reis",8,50,"ABC","Machado","Book","Leandra",22,300,"C++","wallace","Alura","Berenice"};
    Obras cienciasHumanas[TAM_MAX] = {80,290,"Rei macaco","Maria Clara","Darkside","CLara",15,70,"Design Patterns","Wallace","Saraiva","Rita",46,255,"Java","IGor","Alura","Ana"};
    Obras cienciasBiomedicas[TAM_MAX] = {55,120,"Rei Leão","Gabriel Reis","Rocco","Lucas",06,180,"Amigos","Gustavo","Saraiva","Fenanda",11,75,"C++","Thiago","Alura","Ellen"};

    bubblesort(cienciasBiomedicas);
    bubblesort(cienciasExatas);
    bubblesort(cienciasHumanas);

    do{
        printf("\nESCOLHA UMA OPÇÂO\n");
        printf("\n0/P voltar para o menu anterior");
        printf("\n1/P buscar um livro: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 0:
                printf("\nAté logo.");
            break;
            case 1:
                do{
                    printf("\nEntre com o código do livro: ");
                        scanf("%d",&codigo);
                    printf("\nESCOLHA A ÀREA DO LIVRO\n");
                    printf("\n1/P Ciências Exatas");
                    printf("\n2/P Ciências Humanas");
                    printf("\n3/P Ciências Biomedicas\n0/P Voltar para o menu anteriso: ");
                        scanf("%d",&area);
                    switch(area){
                        case 0:
                            printf("\nAté mais");
                        break;
                        case 1:
                            buscarLivros(cienciasExatas,codigo);
                        break;
                        case 2:
                            buscarLivros(cienciasHumanas,codigo);
                        break;
                        case 3:
                            buscarLivros(cienciasBiomedicas,codigo);
                        break;
                        default:
                            printf("\nDados de área invalidos.");
                            printf("\nDigite novamente.");
                    }
                }while(area!=0);
            break;
            default :
                printf("\nEntrada invalida!");
        }
    }while(opcao!=0);


    return 0;
}

void buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca){
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if(livros[i].codigoDeCatalogacao==codigoDeBusca){
            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s",livros[i].nomeDoAutor);
            controle = 1;
        }
    }
    if(controle==0){
        printf("\nLivro não encontrado.");
    }

}

void bubblesort(Obras livros[TAM_MAX]){
    int controle = 0, fim = TAM_MAX;
    Obras livroAux;
    do{
        controle = 0;
        for(int i = 0; i < fim - 1; i++){
            if(livros[i].codigoDeCatalogacao>livros[i+1].codigoDeCatalogacao){
                livroAux = livros[i];
                livros[i] = livros[i+1];
                livros[i+1] = livroAux;
                controle = i;
            }
        }
        fim --;
    }while(controle!=0);
}
