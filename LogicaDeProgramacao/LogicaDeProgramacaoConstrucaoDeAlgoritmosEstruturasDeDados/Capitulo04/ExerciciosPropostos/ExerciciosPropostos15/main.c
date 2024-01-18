#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_MAX 3

typedef struct{
    int codigoDeCatalogacao;
    int numeroDePaginas;
    char nomeDaObra[40];
    char nomeDoAutor[40];
    char editora[40];
    char doado[40];
}Obras;

int tamAreaB = TAM_MAX, tamAreaE = TAM_MAX, tamAreaH = TAM_MAX;
void bubblesort(Obras livros[TMP_MAX]);
void excluirLivro(Obras area[TAM_MAX], int cod,int op);
int buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca);
int buscarLivrosPorNome(Obras livros[TAM_MAX], char nomeDoLivrosDeBusca[40]);
int impremi(Obras livros[TAM_MAX],int number, int max);
int alterarLivro(Obras livros[TAM_MAX], int cod);

int main(){
    setlocale(LC_ALL,"");

    int codigo,opcao,area,totaDeLivrosDoados = 0;
    char nome[40];

    Obras cienciasExatas[TAM_MAX] = {75,155,"Banana Rei","Calor Machado","Book","Sim",8,50,"ABC","Machado","Book","Não",22,300,"C++","wallace","Alura","Sim"};
    Obras cienciasHumanas[TAM_MAX] = {80,290,"Rei macaco","Maria Clara","Darkside","Sim",15,70,"Design Patterns","Wallace","Rita","Sim",46,255,"Kotlin","IGor","Alura","Não"};
    Obras cienciasBiomedicas[TAM_MAX] = {55,120,"Rei Leão","Gabriel Reis","Rocco","Sim",06,180,"Amigos","Gustavo","Saraiva","Não",11,75,"Como fazer amigos","Thiago","Alura","Não"};

    bubblesort(cienciasBiomedicas);
    bubblesort(cienciasExatas);
    bubblesort(cienciasHumanas);

        do{
        system("cls");
        printf("\nESCOLHA UMA OPÇÂO\n");
        printf("\n1/Para buscar um livro código");
        printf("\n2/Para buscar um livro nome");
        printf("\n3/Para listar todos os livros doados.");
        printf("\n4/Para listar todos os livros comprados.");
        printf("\n5/Para alterar dados do livro.");
        printf("\n6/Para excluir livro.");
        printf("\n10/Para Sair: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:
                    do{
                         system("cls");
                        printf("\nESCOLHA UMA OPÇÂO\n");
                        printf("\n1/Para buscar um livro");
                        printf("\n2/Para voltar: ");
                            scanf("%d",&opcao);
                            fflush(stdin);
                        switch(opcao){

                            case 1:
                                do{
                                    system("cls");
                                    printf("\nEntre com o código do livro: ");
                                        scanf("%d",&codigo);
                                        fflush(stdin);
                                        system("cls");
                                    printf("\nESCOLHA A ÀREA DO LIVRO\n");
                                    printf("\n1/Para Ciências Exatas");
                                    printf("\n2/Para Ciências Humanas");
                                    printf("\n3/Para Ciências Biomedicas\n4/Para Voltar para o menu anterior: ");
                                        scanf("%d",&area);
                                        fflush(stdin);
                                    switch(area){
                                        case 1:
                                            area=buscarLivros(cienciasExatas,codigo);
                                        break;
                                        case 2:
                                            area=buscarLivros(cienciasHumanas,codigo);
                                        break;
                                        case 3:
                                            area=buscarLivros(cienciasBiomedicas,codigo);
                                        break;
                                        case 4:
                                            printf("Ok!!!");
                                        break;
                                        default:
                                            printf("\nDados de área invalidos.");
                                            printf("\nDigite novamente.");
                                    }
                                }while(area!=4);
                            break;
                            case 2:
                                printf("Ok!!!");
                            break;
                            default :
                                printf("\nEntrada invalida!");
                        }
                    }while(opcao!=2);

            break;
            case 2:
                    do{
                        system("cls");
                        printf("\nESCOLHA UMA OPÇÂO\n");
                        printf("\n1/Para buscar um livro");
                        printf("\n2/Para voltar para o menu anterior: ");
                            scanf("%d",&opcao);
                            fflush(stdin);
                        switch(opcao){

                            case 1:
                                do{
                                    system("cls");
                                    printf("\nEntre com o nome do livro: ");
                                        scanf("%[^\n]",&nome);
                                        fflush(stdin);
                                        system("cls");
                                    printf("\nESCOLHA A ÀREA DO LIVRO\n");
                                    printf("\n1/Para Ciências Exatas");
                                    printf("\n2/Para Ciências Humanas");
                                    printf("\n3/Para Ciências Biomedicas\n4/Para Voltar para o menu anterior: ");
                                        scanf("%d",&area);
                                        fflush(stdin);
                                    switch(area){
                                        case 1:
                                            area=buscarLivrosPorNome(cienciasExatas,nome);
                                        break;
                                        case 2:
                                            area=buscarLivrosPorNome(cienciasHumanas,nome);
                                        break;
                                        case 3:
                                            area=buscarLivrosPorNome(cienciasBiomedicas,nome);
                                        break;
                                        case 4:
                                            printf("Ok!!!");
                                        break;
                                        default:
                                            printf("\nDados de área invalidos.");
                                            printf("\nDigite novamente.");
                                    }
                                }while(area!=4);
                            break;
                            case 2:
                                printf("Ok!!!");
                            break;
                            default :
                                printf("\nEntrada invalida!");
                        }
                    }while(opcao!=2);

            break;
            case 3:
                system("cls");
                printf("\nLivros doados\n");
                totaDeLivrosDoados=impremi(cienciasHumanas,opcao,tamAreaH);
                totaDeLivrosDoados+=impremi(cienciasExatas,opcao,tamAreaE);
                totaDeLivrosDoados+=impremi(cienciasBiomedicas,opcao,tamAreaB);
                printf("\n\nTotal de livros doados = %d\n\n",totaDeLivrosDoados);
                system("pause");
            break;
            case 4:
                system("cls");
                totaDeLivrosDoados = 0;
                printf("\nLivros comprados\n");
                totaDeLivrosDoados=impremi(cienciasHumanas,opcao,tamAreaH);
                totaDeLivrosDoados+=impremi(cienciasExatas,opcao,tamAreaE);
                totaDeLivrosDoados+=impremi(cienciasBiomedicas,opcao,tamAreaB);
                printf("\n\nTotal de livros comprados = %d\n\n",totaDeLivrosDoados);
                system("pause");
            break;
            case 5:
                system("cls");
                do{
                    printf("\nEntre com o código do livro que deseja alterar: ");
                        scanf("%d",&codigo);
                        system("cls");
                    printf("\nESCOLHA A ÀREA DO LIVRO\n");
                    printf("\n1/Para Ciências Exatas");
                    printf("\n2/Para Ciências Humanas");
                    printf("\n3/Para Ciências Biomedicas\n4/Para Voltar para o menu anterior: ");
                        scanf("%d",&area);
                    switch(area){
                        case 1:
                            area =  alterarLivro(cienciasExatas,codigo);
                        break;
                        case 2:
                            area =  alterarLivro(cienciasHumanas,codigo);
                        break;
                        case 3:
                            area =  alterarLivro(cienciasBiomedicas,codigo);
                        break;
                        case 4:
                            printf("Ok!!!");
                        break;
                        default:
                            printf("\nDados de área invalidos.");
                            printf("\nDigite novamente.");
                    }
                }while(area!=4);

            break;
            case 6:
                //Excluir livro
                do{
                    system("cls");
                    printf("\nDigite o código que deseja excluir:");
                        scanf("%d",&codigo);
                    printf("\n1/Para Ciências Exatas");
                    printf("\n2/Para Ciências Humanas");
                    printf("\n3/Para Ciências Biomedicas\n4/Para Voltar para o menu anterior: ");
                    printf("\nDigite a áre do livro:");
                        scanf("%d",&area);

                    switch(area){
                        case 1:

                        break;
                        case 2:

                        break;
                        case 3:
                            excluirLivro(cienciasBiomedicas,codigo,area);
                        break;
                        case 4:
                            system("cls");
                            printf("\nOk!!!\n\n");
                            system("pause");
                        break;
                        default:
                            system("cls");
                            printf("\nDados invalidos.\n");
                            system("pause");
                    }
                }while(area<1 && area>4);
            break;
            case 10:
                printf("\nAté logo");
            break;
            default :
                printf("\nEntrada invalida!");
        }
    }while(opcao!=10);

    return 0;
}
int buscarLivrosPorNome(Obras livros[TAM_MAX], char nomeDoLivrosDeBusca[40]){
    system("cls");
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if((strcmp(livros[i].nomeDaObra, nomeDoLivrosDeBusca))==0){

            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s\n\n",livros[i].nomeDoAutor);
            controle = 1;
            system("pause");
            return 4;
        }
    }
    if(controle==0){
        printf("\nLivro não encontrado.\n\n");
        system("pause");
        return 4;
    }
}

int impremi(Obras livros[TAM_MAX],int number, int max){
    int contador = 0;
    for(int i  = 0; i < max; i++){
        if((strcmp(livros[i].doado,"Sim"))==0 && number ==3){
            printf("\n%s",livros[i].nomeDaObra);
            contador++;
        }else{
            if((strcmp(livros[i].doado,"Não"))==0 && number ==4){
            printf("\n%s",livros[i].nomeDaObra);
            contador++;
            }
        }
    }
    return contador;
}

int buscarLivros(Obras livros[TAM_MAX], int codigoDeBusca){
    system("cls");
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if(livros[i].codigoDeCatalogacao==codigoDeBusca){
            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s\n\n",livros[i].nomeDoAutor);
            controle = 1;
            system("pause");
            return 4;

        }
    }
    if(controle==0){
        printf("\nLivro não encontrado.\n\n");
        system("pause");
        return 4;
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

int alterarLivro(Obras livros[TAM_MAX], int cod){
    system("cls");
    int controle = 0, op;
    for(int i = 0; i < TAM_MAX; i++){
        if(livros[i].codigoDeCatalogacao==cod){
            printf("\nNome do livros: %s",livros[i].nomeDaObra);
            printf("\nNome do autor: %s",livros[i].nomeDoAutor);
            printf("\nCódigo de catalogação: %d",livros[i].codigoDeCatalogacao);
            printf("\nEditora: %s",livros[i].editora);
            printf("\nDoado: %s",livros[i].doado);
            printf("\nNº de páginas: %d\n",livros[i].numeroDePaginas);

            printf("\n1/p alterar o nome do livro.");
            printf("\n2/p alterar o nome do autor.");
            printf("\n3/p alterar o código do livro.");
            printf("\n4/p alterar a editora do livro.");
            printf("\n5/p alterar doado ou não.");
            printf("\n6/p alterar número de página.");
            printf("\n7/p voltar.");
                scanf("%d",&op);
                fflush(stdin);
            switch(op){
                case 1:
                    printf("\nDigite o nome do livros: ");
                        scanf("%[^\n]",&livros[i].nomeDaObra);
                break;
                case 2:
                    printf("\nDigite o nome do autor: ");
                        scanf("%[^\n]",&livros[i].nomeDoAutor);
                break;
                case 3:
                    printf("\nDigite o código do livros: ");
                        scanf("%d",&livros[i].codigoDeCatalogacao);
                break;
                case 4:
                    printf("\nDigite o nome da editora: ");
                        scanf("%[^\n]",&livros[i].editora);
                break;
                case 5:
                    printf("\nDigite Sim ou Não para doado: ");
                        scanf("%[^\n]",&livros[i].doado);
                break;
                case 6:
                    printf("\nDigite o número de paginas: ");
                        scanf("%[^\n]",&livros[i].numeroDePaginas);
                break;
                case 7:
                    return 4;
                break;
                default:
                    printf("\nOpção invalida.");
            }

            controle = 1;
            return 4;
        }
    }
    if(controle==0){
        printf("\nLivro não encontrado.");
    }
}


void excluirLivro(Obras area[TAM_MAX], int cod,int op){
    int controle = 0;
    for(int i = 0; i < TAM_MAX; i++){
        if(area[i].codigoDeCatalogacao==cod){
            area[i].codigoDeCatalogacao = 1000;
            bubblesort(area);
            if(op==1){
                tamAreaB--;
            }else if(op==2){
                tamAreaH--;
            }else{
                tamAreaE--;
            }
            controle = 1;
        }
    }
    if(controle==1){
        printf("\nLivro excluido.");
    }else{
        printf("\nDados invalidos.");
    }
}
