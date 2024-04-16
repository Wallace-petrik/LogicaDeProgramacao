#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 20

typedef struct{

    int codigo;
    char nome[tam];
    char tipo[tam];
    int estoqueMinimo;

}Produtos;

typedef struct{

    int codigo;
    int dia;
    int mes;
    int ano;
    int quantidade;
    char tipo[tam];
    float valor;

}Movimentacao;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqProdutos, *arqMovimentacao;

    Produtos produtos;
    Movimentacao movimentacao;

    int opcao;

    if((arqProdutos = fopen("arqProdutos.dat","a+b"))==NULL){
        system("cls");
        printf("Erro ao abrir os arquivos");
    }else{
        fclose(arqProdutos);
    }

    do{
        system("cls");
        printf("1 para cadastrar produto\n");
        printf("2 para entrada no estoque\n");

        printf("\nDigite uma oção: ");
            scanf("%d",&opcao);
        switch(opcao){

            case 0:

                system("cls");
                printf("Até logo!!!");

            break;
            case 1:

                if((arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{

                    printf("Digite o código do produto: ");
                        scanf("%d",&produtos.codigo);
                        fflush(stdin);
                    printf("Digite o tipo do produto: ");
                        scanf("%[^\n]",&produtos.tipo);
                        fflush(stdin);
                    printf("Digite o nome do produto: ");
                        scanf("%[^\n]",&produtos.nome);
                        fflush(stdin);
                    printf("Digite a quantidade de mínima de produtos: ");
                        scanf("%d",&produtos.estoqueMinimo);

                    fseek(arqProdutos,(produtos.codigo-1)*sizeof(produtos),SEEK_SET);
                    fwrite (&produtos,sizeof(produtos),1,arqProdutos);
                }
                if((fclose(arqProdutos))==0){
                    printf("Produto cadastrado com sucesso!!!!\n");
                    system("pause");
                }

            break;
            case 2:



            break;
            default:
                printf("Opcção invalida!!!\n");
                system("pause");

        }

    }while(opcao!=0);

    return 0;
}
