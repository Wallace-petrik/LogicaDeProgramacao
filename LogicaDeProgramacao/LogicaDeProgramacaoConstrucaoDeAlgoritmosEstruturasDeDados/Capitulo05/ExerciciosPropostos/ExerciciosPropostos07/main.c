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
    int tipo;
    float valor;

}Movimentacao;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqProdutos, *arqMovimentacao;

    Produtos produtos;
    Movimentacao movimentacao, movimentacaoAux;

    int opcao, total = 0, controle = 0;

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
        printf("3 para saída de estoque\n");

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

                if((arqMovimentacao = fopen("arqMovimentacao.dat","a+b"))==NULL || (arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!");
                    system("pause");
                }else{

                    printf("Digite o código do produto: ");
                        scanf("%d",&movimentacao.codigo);

                        fseek(arqProdutos,(movimentacao.codigo-1)*sizeof(produtos),SEEK_SET);
                        fread(&produtos,sizeof(produtos),1,arqProdutos);

                        if(produtos.codigo == movimentacao.codigo){

                            printf("Digite a data da compro: ");
                                scanf("%d%d%d",&movimentacao.dia,&movimentacao.mes,&movimentacao.ano);
                            printf("Digite a quantidade do produto: ");
                                scanf("%d",&movimentacao.quantidade);
                            printf("\n1 para compra\n2 para devolução\nDigite o tipo de entrada: ");
                                scanf("%d",&movimentacao.tipo);
                            if(movimentacao.tipo==1){
                                printf("Digite o preço da compra: ");
                                    scanf("%f",&movimentacao.valor);
                            }else if(movimentacao.tipo==2){
                                 movimentacao.valor = 0;
                            }else{
                                printf("Opção invalida!!!");
                            }
                            fwrite(&movimentacao,sizeof(movimentacao),1,arqMovimentacao);
                        }else{
                            printf("Produto não encontrado!!!");
                        }
                }
                if(fclose(arqMovimentacao)==0 && fclose(arqProdutos)==0){
                    printf("Operação realizada com sucesso!!!");
                    system("pause");
                }

            break;
            case 3:

                if((arqMovimentacao = fopen("arqMovimentacao.dat","a+b"))==NULL || (arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{
                    controle = 0;
                    printf("Digite o código do produto para venda: ");
                        scanf("%d",&movimentacaoAux.codigo);

                    fseek(arqProdutos,(movimentacaoAux.codigo-1)*sizeof(produtos),SEEK_SET);
                    fread(&produtos,sizeof(produtos),1,arqProdutos);

                    if(produtos.codigo==movimentacaoAux.codigo){
                        total = 0;
                        while(fread(&movimentacao,sizeof(movimentacao),1,arqMovimentacao)){
                            if(movimentacao.tipo==1 || movimentacao.tipo==2){
                                total +=  movimentacao.quantidade;
                            }else{
                                total -= movimentacao.quantidade;
                            }
                        }

                        printf("Digite a quantidade do produto vendido: ");
                            scanf("%d",&movimentacaoAux.quantidade);

                        if(total>=movimentacaoAux.quantidade){
                            printf("Digite a data da venda: ");
                                scanf("%d%d%d",&movimentacaoAux.dia,&movimentacaoAux.mes,&movimentacaoAux.ano);
                            printf("\n3 para venda\n4 para tranferencia\nDigite uma opção: ");
                                scanf("%d",&movimentacaoAux.tipo);

                            if(movimentacaoAux.tipo==3){
                                printf("Digite o valor da venda: ");
                                    scanf("%f",&movimentacaoAux.valor);
                            }else if(movimentacaoAux.tipo==4){
                                movimentacaoAux.valor=0;
                            }else{
                                printf("Opção invalida!!!");
                            }
                            fwrite(&movimentacaoAux,sizeof(movimentacaoAux),1,arqMovimentacao);
                        }else{
                            printf("Quantidade de produto no estoque insuficiente!!!\n");
                             printf("Quantidade em estoque %d\n",total);
                        }

                    }else{
                        printf("Produto não encontrado!!!");
                    }

                }
                if(fclose(arqMovimentacao)==0  && fclose(arqProdutos)==0){
                    printf("Operação realizada com sucesso!!!");

                    system("pause");
                }

            break;
            default:
                printf("Opcção invalida!!!\n");
                system("pause");

        }

    }while(opcao!=0);

    return 0;
}
