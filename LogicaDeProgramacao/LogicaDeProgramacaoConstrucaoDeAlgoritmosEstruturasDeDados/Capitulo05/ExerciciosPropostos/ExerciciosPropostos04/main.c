#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

typedef struct{
    int codigo; // Chave
    int telefone;
    int RG;
    int CPF;
    char nome[40];
    char endereco[40];
}Cliente;

typedef struct{
    int codigo; //Chave
    float preco;
    int dataDeCompra[3];
    char oscar;
    char titulo[40];
    char assunto[40];
}Filme;

typedef struct{
    int codigoFita;
    int codigoCliente;
    int qtdDiasFora;
    float preco;
}Locacao;

int main(){
    setlocale(LC_ALL,"");

    int opcao = 0, contador = 0,controle = 0;

    FILE *arqClientes, *arqFilmes,*arqLocacao;

    Cliente cliente,clienteAux;
    Filme filme,filmeAux;
    Locacao aluguel;

    do{

        system("cls");
        printf("1 para Cadastrar clientes \n");
        printf("2 para Cadastrar filmes \n");
        printf("3 para aluguel de filmes \n");
        printf("4 para devolu��o de filme\n");
        printf("\nOp��o: ");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

        case 0:

            system("cls");
            printf("At� logo\n");

        break;
        case 1:

            if((arqClientes = fopen("clientes.dat","a+b"))==NULL){
                printf("Erro ao abrir o arquivo!!!\n");
                system("pause");
                exit(1);
            }else{

                system("cls");

                contador = 0;
                while(fread(&cliente,sizeof(cliente),1,arqClientes)){contador++;}

                memset(&cliente,0,sizeof(cliente));

                printf("Digite o nome do cliente: ");
                    scanf("%[^\n]",&cliente.nome);
                printf("Digite o telefone: ");
                    scanf("%d",&cliente.telefone);
                printf("Digite o RG: ");
                    scanf("%d",&cliente.RG);
                printf("Digite o CPF: ");
                    scanf("%d",&cliente.CPF);
                    fflush(stdin);
                printf("Digite o endere�o: ");
                    scanf("%[^\n]",&cliente.endereco);

                cliente.codigo = ++contador;

                fwrite(&cliente,sizeof(cliente),1,arqClientes);

            }

            if(fclose(arqClientes) == 0){

                system("cls");
                printf("Cliente cadastrado com sucesso!\n");
                system("pause");

            }

        break;
        case 2:

            if((arqFilmes = fopen("filmes.dat","a+b")) == NULL){
                printf("Erro ao abrir o arquivo!!!\n");
                system("pause");
                exit(1);
            }else{

                system("cls");
                contador = 0;
                while(fread(&filme,sizeof(filme),1,arqFilmes)){contador++;}

                memset(&filme,0,sizeof(filme));
                filme.codigo = ++contador;
                fflush(stdin);

                printf("Nome do filme: ");
                    scanf("%[^\n]",&filme.titulo);
                    fflush(stdin);
                printf("G�nero: ");
                    scanf("%[^\n]",&filme.assunto);
                    fflush(stdin);
                printf("Ganhador de Oscar S/sim N/n�o: ");
                    scanf("%c",&filme.oscar);
                    fflush(stdin);
                printf("Valor da fita: ");
                    scanf("%f",&filme.preco);
                printf("Digite a data da compra: ");
                scanf("%d%d%d",&filme.dataDeCompra[0],&filme.dataDeCompra[1],&filme.dataDeCompra[2]);

                fwrite(&filme,sizeof(filme),1,arqFilmes);
            }

            if(fclose(arqFilmes)==0){
                printf("Sucesso ao cadastrar filme!!!\n");
            }

        break;
        case 3:

            if((arqLocacao = fopen("aluguel.dat","a+b"))==NULL || (arqClientes = fopen("clientes.dat","a+b"))== NULL || (arqFilmes = fopen("filmes.dat","a+b")) == NULL){
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }else{

                system("cls");
                printf("Digite o c�digo do filme que deseja alugar: ");
                    scanf("%d",&filmeAux.codigo);
                    contador = 0;

                while(fread(&aluguel,sizeof(aluguel),1,arqLocacao)){
                    if(aluguel.codigoFita==filmeAux.codigo){
                        controle = 1;
                    }
                }

                if(contador==1){
                    printf("Filme encontra-se alugado!!!");
                    system("pause");
                }else{

                    while(fread(&filme,sizeof(filme),1,arqFilmes)){
                        if(filmeAux.codigo==filme.codigo){
                            controle = 0;
                            break;
                        }else{
                            controle = 1;
                        }
                    }

                    if(controle==1){
                        printf("Filme n�o encontrado!!\n");
                        system("pause");
                    }else{
                        printf("Digite o c�digo do cliente: ");
                            scanf("%d",&clienteAux.codigo);
                        while(fread(&cliente,sizeof(cliente),1,arqClientes)){
                            if(clienteAux.codigo==cliente.codigo){
                                controle = 0;
                                break;
                            }else{
                                controle = 1;
                            }
                        }

                        if(contador==1){
                            printf("Cliente n�o cadastrado!!!");
                            system("pause");
                        }else{

                            printf("Digite quantos dias alugados: ");
                                scanf("%d",&aluguel.qtdDiasFora);
                            printf("Digite o valor: ");
                                scanf("%f",&aluguel.preco);
                                aluguel.preco *= aluguel.qtdDiasFora;
                                aluguel.codigoCliente=cliente.codigo;
                                aluguel.codigoFita=filme.codigo;

                            fwrite(&aluguel,sizeof(aluguel),1,arqLocacao);

                        }

                    }

                }

            }

            if(fclose(arqLocacao)==0 && fclose(arqClientes)==0 && fclose(arqLocacao)==0){
                printf("Opera��o realizada com sucesso!!\n");
                system("pause");
            }

        break;
        case 4:

            if((arqLocacao = fopen("aluguel.dat","r+b"))==NULL){
                printf("Erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }else{

                printf("Digite o c�digo do filme que foi devolvido: ");
                    scanf("%d",&filmeAux.codigo);

                while(fread(&filme,sizeof(filme),1,arqLocacao)){
                    if(filmeAux.codigo==filme.codigo){
                        fseek(arqLocacao,0,SEEK_SET);

                        //Criar um novo arquivo e apagar o antigo, em seguida renomear o novo.


                        break;
                    }else{
                        controle = 1;
                    }
                }

                if(controle == 1){
                    printf("Filme n�o encontrado!\n");
                }else{
                    printf("Filme devolvido com sucesso!!!\n");
                }
            }

            if(fclose(arqLocacao)==0){
                printf("Fim da opera��o!!!\n");
                system("pause");
            }

        break;
        default:

            system("cls");
            printf("Op��o invalida");
            system("pause");

        }

    }while(opcao != 0);

    return 0;
}