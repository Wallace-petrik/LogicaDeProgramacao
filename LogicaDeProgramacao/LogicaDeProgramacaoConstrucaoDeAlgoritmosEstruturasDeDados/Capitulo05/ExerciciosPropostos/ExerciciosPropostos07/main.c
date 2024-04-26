#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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

    Produtos produtos, produtoAux;
    Movimentacao movimentacao, movimentacaoAux,movimentacaoAuxx;

    int opcao, total = 0, controle = 0,qtdV = 0, qtdC = 0, saldoEstoque = 0;
    float precoMedioV = 0, precoMedioC = 0, ultimoCusto = 0, custo = 0, custoTotal = 0;

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
        printf("4 para dados de um poduto\n");
        printf("5 para relatório por tipo de produo\n");

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
                    fwrite(&produtos,sizeof(produtos),1,arqProdutos);
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
            case 4:

                if((arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL || (arqMovimentacao = fopen("arqMovimentacao.dat","r+b"))==NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{

                    system("cls");
                    printf("Digite o código do produto que deseja encontrar: ");
                        scanf("%d",&produtos.codigo);

                    fseek(arqProdutos,(produtos.codigo-1)*sizeof(produtos),SEEK_SET);
                    fread(&produtos,sizeof(produtos),1,arqProdutos);

                    printf("\nNome: %s",produtos.nome);
                    printf("\nTipo: %s",produtos.tipo);

                    movimentacaoAux.quantidade = 0;
                    precoMedioV = 0, precoMedioC = 0;
                    qtdV = 0, qtdC = 0;

                    while(fread(&movimentacao,sizeof(movimentacao),1,arqMovimentacao)){
                        if(movimentacao.codigo==produtos.codigo){
                            if(movimentacao.tipo>=1 && movimentacao.tipo<=2){
                                movimentacaoAux.quantidade += movimentacao.quantidade;
                                if(movimentacao.tipo==1){
                                    precoMedioC += movimentacao.valor/movimentacao.quantidade;
                                    qtdC++;
                                    movimentacaoAuxx.dia = movimentacao.dia;
                                    movimentacaoAuxx.mes = movimentacao.mes;
                                    movimentacaoAuxx.ano = movimentacao.ano;
                                }
                            } else if(movimentacao.tipo>=3 && movimentacao.tipo<=4){
                                movimentacaoAux.quantidade -= movimentacao.quantidade;
                                if(movimentacao.tipo==3){
                                    precoMedioV += movimentacao.valor/movimentacao.quantidade;
                                    qtdV++;
                                    movimentacaoAux.dia = movimentacao.dia;
                                    movimentacaoAux.mes = movimentacao.mes;
                                    movimentacaoAux.ano = movimentacao.ano;
                                }
                            }
                        }
                    }
                    printf("\nEstoque atual: %d",movimentacaoAux.quantidade);
                    printf("\nPreço médio de venda: %.1f",precoMedioV/qtdV);
                    printf("\nData da ultima venda: %d/%d/%d",movimentacaoAux.dia,movimentacaoAux.mes,movimentacaoAux.ano);
                    printf("\nPreço médio de compra: %.1f",precoMedioC/qtdC);
                    printf("\nData da ultima compra: %d/%d/%d",movimentacaoAuxx.dia,movimentacaoAuxx.mes,movimentacaoAuxx.ano);
                }
                if(fclose(arqProdutos)==0 & fclose(arqMovimentacao)==0){
                    printf("Sucesso ao fechar o arquivo!!!");
                    system("pause");
                }

            break;
            case 5:

                if((arqProdutos = fopen("arqProdutos.dat","r+b"))==NULL || (arqMovimentacao = fopen("arqMovimentacao.dat","r+b"))==NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{

                    system("cls");
                    printf("Digite o tipo do produto: ");
                        fflush(stdin);
                        scanf("%[^\n]",&produtos.tipo);

                    while(fread(&produtoAux,sizeof(produtoAux),1,arqProdutos)){
                        if((strcmp(produtos.tipo,produtoAux.tipo)==0)){
                            saldoEstoque = 0;
                            custoTotal = 0;
                            custo = 0;
                            qtdC = 0;
                            qtdV = 0;
                            ultimoCusto = 0;
                            while(fread(&movimentacao,sizeof(movimentacao),1,arqMovimentacao)){
                                if(produtoAux.codigo==movimentacao.codigo){

                                    if(movimentacao.tipo==1 || movimentacao.tipo==2){

                                        saldoEstoque += movimentacao.quantidade;
                                        ultimoCusto = movimentacao.valor;
                                        qtdC += movimentacao.quantidade;
                                        if(movimentacao.tipo==1){
                                            custo = movimentacao.valor;
                                        }
                                    }else{
                                        qtdV += movimentacao.quantidade;
                                    }

                                }
                            }
                            custoTotal = (qtdC > 0) ? ((custo/qtdC)*(qtdC-qtdV)) : 0;
                            printf("Nome do produto: %s Qtd em estoque %d Último custo %.2f Custo dotal do estoque %.2f\n",
                                produtoAux.nome,saldoEstoque,ultimoCusto,custoTotal);
                            fseek(arqMovimentacao,0,SEEK_SET);
                        }
                    }

                }
                if(fclose(arqProdutos)==0 && fclose(arqMovimentacao)==0){
                    printf("Arquivo fechado com sucesso!!!");
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
