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

    FILE *arqClientes, *arqFilmes,*arqLocacao, *arqLocacaoAux, *arqHistorico, *arqHistoricoCliente;

    Cliente cliente,clienteAux;
    Filme filme,filmeAux;
    Locacao aluguel,aluguelAux;

    do{

        system("cls");
        printf("1 para Cadastrar clientes \n");
        printf("2 para Cadastrar filmes \n");
        printf("3 para aluguel de filmes \n");
        printf("4 para devolução de filme\n");
        printf("5 para buscar histórico de filmes alugados\n");
        printf("6 para buscar qual cliente  locaram determinado filme\n");
        printf("\nOpção: ");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

        case 0:

            system("cls");
            printf("Até logo\n");

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
                printf("Digite o endereço: ");
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
                printf("Gênero: ");
                    scanf("%[^\n]",&filme.assunto);
                    fflush(stdin);
                printf("Ganhador de Oscar S/sim N/não: ");
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

            if((arqLocacao = fopen("aluguel.dat","a+b"))==NULL || (arqClientes = fopen("clientes.dat","a+b"))== NULL || (arqFilmes = fopen("filmes.dat","a+b")) == NULL ||(arqHistorico = fopen("historico.dat","a+b"))== NULL){
                printf("Erro ao abrir o arquivo\n");

                exit(1);
            }else{

                system("cls");
                printf("Digite o código do filme que deseja alugar: ");
                    scanf("%d",&filmeAux.codigo);
                    controle = 0;

                while(fread(&aluguel,sizeof(aluguel),1,arqLocacao)){
                    if(aluguel.codigoFita==filmeAux.codigo){
                        controle = 1;
                    }
                }

                if(controle==1){
                    printf("Filme encontra-se alugado!!!\n");
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
                        printf("Filme não encontrado!!\n");
                        system("pause");
                    }else{
                        printf("Digite o código do cliente: ");
                            scanf("%d",&clienteAux.codigo);
                        while(fread(&cliente,sizeof(cliente),1,arqClientes)){
                            if(clienteAux.codigo==cliente.codigo){
                                controle = 0;
                                break;
                            }else{
                                controle = 1;
                            }
                        }

                        if(controle==1){
                            printf("Cliente não cadastrado!!!");
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
                            fwrite(&aluguel,sizeof(aluguel),1,arqHistorico);
                        }

                    }

                }

            }

            if(fclose(arqLocacao)==0 && fclose(arqClientes)==0 && fclose(arqFilmes)==0 && fclose(arqHistorico)==0){
                printf("Operação realizada com sucesso!!\n");
                system("pause");
            }

        break;
        case 4:

            if((arqLocacao = fopen("aluguel.dat","r+b"))==NULL){
                printf("Erro ao abrir o arquivo");
                system("pause");
                exit(1);
            }else{

                printf("Digite o código do filme que foi devolvido: ");
                    scanf("%d",&aluguelAux.codigoFita);

                while(fread(&aluguel,sizeof(aluguel),1,arqLocacao)){
                    if(aluguelAux.codigoFita==aluguel.codigoFita){

                        if((arqLocacaoAux = fopen("aluguelAux.dat","a+b"))==NULL){
                            printf("Erro ao abrir o arquivo!!!\n");
                        }else{
                            fseek(arqLocacao,0,SEEK_SET);
                            while(fread(&aluguel,sizeof(aluguel),1,arqLocacao)){

                                if(aluguel.codigoFita!=aluguelAux.codigoFita){
                                    fwrite(&aluguel,sizeof(aluguel),1,arqLocacaoAux);
                                }

                            }
                        }

                        controle = 0;
                        break;
                    }else{
                        controle = 1;
                    }
                }

                if(controle == 1){
                    printf("Filme não encontrado!\n");
                }else{
                    printf("Filme devolvido com sucesso!!!\n");
                }
            }

            if(fclose(arqLocacao)==0 && fclose(arqLocacaoAux)==0){
                printf("Fim da operação!!!\n");

            }

            remove("aluguel.dat");
            rename("aluguelAux.dat","aluguel.dat");
            system("pause");

        break;
        case 5:

            if((arqHistorico = fopen("historico.dat","a+b"))==NULL || (arqFilmes = fopen("filmes.dat","a+b")) == NULL){
                printf("Erro ao abrir o arquivo!!!!\n");
                exit(1);
            }else{
                printf("Entre com o códido do cliente: ");
                    scanf("%d",&cliente.codigo);

                while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){
                    if(aluguel.codigoCliente==cliente.codigo){
                        controle = 0;

                        if((arqHistoricoCliente = fopen("historicocliente.dat","a+b"))==NULL){
                            printf("Erro ao abrir o arquivo!!!!\n");
                            exit(1);
                        }else{
                            while(fread(&aluguelAux,sizeof(aluguelAux),1,arqHistoricoCliente)){
                                if(aluguelAux.codigoFita==aluguel.codigoFita){
                                    controle = 1;
                                    break;
                                }
                            }
                        }

                        if(controle==0){
                            fwrite(&aluguel,sizeof(aluguel),1,arqHistoricoCliente);
                            fclose(arqHistoricoCliente);
                        }
                    }
                }

                if((arqHistoricoCliente = fopen("historicocliente.dat","rb"))==NULL){
                    printf("Esse cliente não possui historico!!!!\n");
                    system("pause");
                }else{
                    while(fread(&aluguelAux,sizeof(aluguelAux),1,arqHistoricoCliente)){
                        fseek(arqFilmes,(aluguelAux.codigoFita-1)*(sizeof(filmeAux)),SEEK_SET);
                        fread(&filmeAux,sizeof(filmeAux),1,arqFilmes);
                        printf("Nome do filme: %s\n",filmeAux.titulo);
                        printf("Assunto: %s\n",filmeAux.assunto);
                    }
                }
            }

            if(fclose(arqHistorico)==0 && fclose(arqFilmes)==0 && fclose(arqHistoricoCliente)==0){
                printf("Sucesso!\n");
                remove("historicocliente.dat");
                system("pause");
            }

        break;
        case 6:

            if((arqHistorico = fopen("historico.dat","a+b"))==NULL || (arqClientes = fopen("clientes.dat","a+b"))== NULL){
                printf("Erro ao abrir o arquivo!\n");
                exit(1);
            }else{

                printf("Entre com o código do filme: ");
                    scanf("%d",&filme.codigo);

                while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){
                    controle = 0;
                    if(aluguel.codigoFita==filme.codigo){

                       if((arqHistoricoCliente = fopen("historicocliente.dat","a+b"))==NULL){
                            printf("Erro ao abrir o arquivo!!!!\n");
                            exit(1);
                        }else{
                            while(fread(&aluguelAux,sizeof(aluguelAux),1,arqHistoricoCliente)){
                                if(aluguelAux.codigoCliente==aluguel.codigoCliente){
                                    controle = 1;
                                    break;
                                }
                            }
                        }

                        if(controle==0){
                            fwrite(&aluguel,sizeof(aluguel),1,arqHistoricoCliente);
                            fclose(arqHistoricoCliente);
                        }

                    }
                }

                if((arqHistoricoCliente = fopen("historicocliente.dat","rb"))==NULL){
                    printf("Esse cliente não possui historico!!!!\n");
                    system("pause");
                }else{
                    while(fread(&aluguelAux,sizeof(aluguelAux),1,arqHistoricoCliente)){
                        fseek(arqClientes,(aluguelAux.codigoCliente-1)*(sizeof(cliente)),SEEK_SET);
                        fread(&clienteAux,sizeof(clienteAux),1,arqClientes);
                        printf("Nome do cliente: %s\n",clienteAux.nome);
                        printf("Tel: %d\n",clienteAux.telefone);
                    }
                }

            }

            if(fclose(arqHistorico)==0 && fclose(arqClientes)==0 && fclose(arqHistoricoCliente)==0){
                printf("Sucesso!\n");
                remove("historicocliente.dat");
                system("pause");
            }

        break;
        default:

            system("cls");
            printf("Opção invalida");
            system("pause");

        }
    }while(opcao != 0);

    return 0;
}
