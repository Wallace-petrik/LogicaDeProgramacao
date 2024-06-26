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

    int opcao = 0,opcao2 = 0, contador = 0,controle = 0, fim = 0;
    float gastoDeCliente = 0;

    FILE *arqClientes, *arqFilmes, *arqFilmesAux, *arqLocacao, *arqLocacaoAux, *arqHistorico, *arqRanking, *arqHistoricoCliente;

    Cliente cliente,clienteAux;
    Filme filme,filmeAux;
    Locacao aluguel,aluguelAux;

    do{

        system("cls");
        printf("1 para Cadastrar clientes \n");
        printf("2 para Cadastrar filmes \n");
        printf("3 para aluguel de filmes \n");
        printf("4 para devolu��o de filme\n");
        printf("5 para buscar hist�rico de filmes alugados\n");
        printf("6 para buscar qual cliente  locaram determinado filme\n");
        printf("7 para imprimir relat�rios\n");
        printf("8 para consultar filmes premeados com oscar alugado por um cliente\n");
        printf("9 para relaca��o de filmes e total de tempo locada\n");
        printf("10 para imprimir relat�rio com os dez filmes mais locados\n");
        printf("11 para imprimir de rentabilidade\n");
        printf("12 para imprimir os filmes que j� se pagaram\n");
        printf("00 para sair ");
        printf("\nDigite uma op��o: ");
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

            if((arqLocacao = fopen("aluguel.dat","a+b"))==NULL || (arqClientes = fopen("clientes.dat","a+b"))== NULL || (arqFilmes = fopen("filmes.dat","a+b")) == NULL ||(arqHistorico = fopen("historico.dat","a+b"))== NULL){
                printf("Erro ao abrir o arquivo\n");

                exit(1);
            }else{

                system("cls");
                printf("Digite o c�digo do filme que deseja alugar: ");
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

                        if(controle==1){
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
                            fwrite(&aluguel,sizeof(aluguel),1,arqHistorico);
                        }

                    }

                }

            }

            if(fclose(arqLocacao)==0 && fclose(arqClientes)==0 && fclose(arqFilmes)==0 && fclose(arqHistorico)==0){
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

                system("cls");
                printf("Digite o c�digo do filme que foi devolvido: ");
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
                    printf("Filme n�o encontrado!\n");
                }else{
                    printf("Filme devolvido com sucesso!!!\n");
                }
            }

            if(fclose(arqLocacao)==0 && fclose(arqLocacaoAux)==0){
                printf("Fim da opera��o!!!\n");

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

                system("cls");
                printf("Entre com o c�dido do cliente: ");
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
                    printf("Esse cliente n�o possui historico!!!!\n");
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
                system("cls");
                printf("Entre com o c�digo do filme: ");
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
                    printf("Esse cliente n�o possui historico!!!!\n");
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
        case 7:

            do{

                system("cls");
                printf("1 para imprimir gastos de cada cliente\n");
                printf("2 para imprimir filmes ganhadores de Oscar\n");
                printf("3 para imprimir filme por assunto\n");
                printf("4 para imprimir fitas alugadas mais de uma vez\n");
                printf("0 para voltar ao menu anterior\n");

                printf("\nDigite uma op��o: ");
                    scanf("%d",&opcao2);
                fflush(stdin);

                switch(opcao2){
                    case 0:

                        printf("Ok voltando!!!");

                    break;
                    case 1:

                        if(((arqClientes = fopen("clientes.dat","a+b"))==NULL) || (arqHistorico = fopen("historico.dat","a+b"))==NULL){
                            printf("Erro ao abrir os arquivos!!\n");
                            exit(1);
                        }else{

                            system("cls");
                            while(fread(&cliente,sizeof(cliente),1,arqClientes)){

                                    gastoDeCliente = 0;

                                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){
                                        if(cliente.codigo==aluguel.codigoCliente){
                                            gastoDeCliente+=aluguel.preco;
                                        }
                                    }

                                printf("Nome: %s\nValor gasto: %.2f\n\n",cliente.nome,gastoDeCliente);
                                fseek(arqHistorico,0,SEEK_SET);
                            }

                        }

                        if(fclose(arqClientes)==0 && fclose(arqHistorico)==0){
                            printf("Sucesso!!!\n");
                            system("pause");
                        }

                    break;
                    case 2:

                        if((arqFilmes = fopen("filmes.dat","a+b")) == NULL){
                            printf("Erro ao abrir o arquivo\n");
                            exit(1);
                        }else{
                            system("cls");
                            printf("Filmes com Oscar\n\n");

                            while(fread(&filme,sizeof(filme),1,arqFilmes)){

                               if(filme.oscar == 's' || filme.oscar == 'S'){

                                 printf("Nome: %s Oscar: %c\n",filme.titulo,filme.oscar);

                               }

                            }

                        }

                        if(fclose(arqFilmes)==0){
                            printf("Fim da lista\n");
                            system("pause");
                        }

                    break;
                    case 3:
                        remove("filmesAux.dat");
                        if((arqFilmes = fopen("filmes.dat","a+b")) == NULL){
                            printf("Erro ao abrir os arquivos\n");
                            exit(1);
                        }else{

                            system("cls");
                            contador = 0;
                            while(fread(&filme,sizeof(filme),1,arqFilmes)){
                                contador++;
                                if((arqFilmesAux = fopen("filmesAux.dat","a+b")) == NULL){
                                    printf("Erro!!!\n");
                                    exit(1);
                                }else{

                                    fwrite(&filme,sizeof(filme),1,arqFilmesAux);

                                }

                                fclose(arqFilmesAux);

                            }

                            if((arqFilmesAux = fopen("filmesAux.dat","r+b")) == NULL){
                                    printf("Erro!!!\n");
                                    exit(1);
                            }else{

                                do{
                                    controle = 0;

                                    for(int i = 0; i < contador - 1; i++){

                                        fseek(arqFilmesAux,i*sizeof(filme),SEEK_SET);
                                        fread(&filme,sizeof(filme),1,arqFilmesAux);
                                        fseek(arqFilmesAux,(i+1)*sizeof(filmeAux),SEEK_SET);
                                        fread(&filmeAux,sizeof(filmeAux),1,arqFilmesAux);

                                        if(strcmp(filme.assunto,filmeAux.assunto)>0){

                                            fseek(arqFilmesAux,i*sizeof(filme),SEEK_SET);
                                            fwrite(&filmeAux,sizeof(filme),1,arqFilmesAux);
                                            fseek(arqFilmesAux,(i+1)*sizeof(filmeAux),SEEK_SET);
                                            fwrite(&filme,sizeof(filmeAux),1,arqFilmesAux);

                                            controle = i;
                                        }
                                        fseek(arqFilmesAux,0,SEEK_SET);
                                    }
                                    contador--;
                                }while(controle!=0);


                            }

                            fclose(arqFilmesAux);

                        }

                        if((arqFilmesAux = fopen("filmesAux.dat","a+b")) == NULL){
                            printf("Erro!!!\n");
                            exit(1);
                        }else{
                            controle = 0;
                            printf("\n");
                            while(fread(&filme,sizeof(filme),1,arqFilmesAux)){

                               printf("Nome: %-20s \t Assunto: %s\n",filme.titulo,filme.assunto);

                            }

                        }

                        fclose(arqFilmesAux);

                        if(fclose(arqFilmes)==0){
                            printf("\nFim da lista\n");
                            system("pause");
                        }

                    break;
                    case 4:

                        system("cls");

                        if((arqClientes = fopen("clientes.dat","r+b"))== NULL || (arqFilmes = fopen("filmes.dat","r+b")) == NULL || (arqHistorico = fopen("historico.dat","r+b"))==NULL){
                            printf("Erro ao abrir os arquivos\n");
                            exit(1);
                        }else{
                            system("cls");
                            while(fread(&cliente,sizeof(cliente),1,arqClientes)){
                                controle = 0;
                                while(fread(&filme,sizeof(filme),1,arqFilmes)){
                                contador = 0;
                                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){

                                        if(cliente.codigo==aluguel.codigoCliente && filme.codigo==aluguel.codigoFita){

                                            contador++;

                                        }

                                    }
                                    fseek(arqHistorico,0,SEEK_SET);
                                    if(contador>=2){
                                        printf("Filme %s alugados %d vezes\n",filme.titulo,contador);
                                        controle = 1;
                                    }

                                }
                                fseek(arqFilmes,0,SEEK_SET);
                                if(controle==1){
                                    printf("Cliente: %s\n\n",cliente.nome);
                                }

                            }

                        }

                        if(fclose(arqClientes) == 0 && fclose(arqFilmes) ==0 && fclose(arqHistorico) == 0){
                            printf("Fim da lista!!!\n");
                            system("pause");
                        }

                    break;
                    default:

                        printf("Op��o invalida!");
                        system("pause");

                }


            }while(opcao2!=0);

        break;
        case 8:

            if((arqClientes = fopen("clientes.dat","r+b"))==NULL || (arqFilmes = fopen("filmes.dat","r+b"))==NULL || (arqHistorico = fopen("historico.dat","r+b"))==NULL){
                printf("Erro ao abrir o arquivo!\n");
                exit(1);
            }else{

                system("cls");

                printf("Entre com o c�digo do cliente: ");
                    scanf("%d",&cliente.codigo);

                fseek(arqClientes,(cliente.codigo-1)*sizeof(cliente),SEEK_SET);
                fread(&cliente,sizeof(cliente),1,arqClientes);
                controle = 0;
                filmeAux.codigo = 0;

                printf("Cliente: %s\n",cliente.nome);

                while(fread(&filme,sizeof(filme),1,arqFilmes)){

                    if((filme.oscar == 's' || filme.oscar == 'S')){

                        while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){

                            if(cliente.codigo==aluguel.codigoCliente &&  filme.codigo!=filmeAux.codigo && filme.codigo==aluguel.codigoFita){
                                printf("Filme com Oscar: %s\n",filme.titulo);
                                filmeAux.codigo=filme.codigo;
                                controle = 1;
                            }

                        }
                        fseek(arqHistorico,0,SEEK_SET);
                    }

                }

                if(controle == 0){
                        printf("O cliente n�o alugou filmes vencedores de Oscar!\n");
                }
            }

            if(fclose(arqClientes)==0 && fclose(arqFilmes)==0 && fclose(arqHistorico)==0){
                printf("Fim da lista");
                system("pause");
            }

        break;
        case 9:

            if((arqFilmes = fopen("filmes.dat","r+b"))==NULL || (arqHistorico = fopen("historico.dat","r+b"))==NULL){
                printf("Erro ao abrir os arquivos!!\n");
                exit(1);
            }else{

                system("cls");

                while(fread(&filme,sizeof(filme),1,arqFilmes)){
                    contador = 0;
                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){

                        if(filme.codigo==aluguel.codigoFita){
                            contador+=aluguel.qtdDiasFora;
                        }

                    }
                    fseek(arqHistorico,0,SEEK_SET);
                    printf("Filme: %s TTL = %d\n",filme.titulo,contador);
                }

            }

            if(fclose(arqFilmes)==0 && fclose(arqHistorico)==0){
                printf("Fim da lista de filmes\n\n");
                system("pause");
            }

        break;
        case 10:

            if((arqHistorico = fopen("historico.dat","r+b"))==NULL || (arqFilmes = fopen("filmes.dat","r+b"))== NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                exit(1);
            }else{

                system("cls");
                remove("arqRanking.dat");
                fim = 0;
                while(fread(&filme,sizeof(filme),1,arqFilmes)){
                    contador = 0;
                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){
                        if(aluguel.codigoFita==filme.codigo){
                            contador +=aluguel.qtdDiasFora;
                        }
                    }
                    fseek(arqHistorico,0,SEEK_SET);
                    aluguel.qtdDiasFora = contador;
                    aluguel.codigoFita=filme.codigo;

                    if(contador>0){
                        if((arqRanking = fopen("arqRanking.dat","a+b"))==NULL){
                            printf("Erro ao abrir o arquivo!!!\n");
                            exit(1);
                        }else{
                            fwrite(&aluguel,sizeof(aluguel),1,arqRanking);
                            fim++;
                        }
                        fclose(arqRanking);
                    }
                }
                if((arqRanking = fopen("arqRanking.dat","r+b")) == NULL){
                        printf("Erro!!!\n");
                        exit(1);
                }else{

                    do{
                        controle = 0;

                        for(int i = 0; i < fim - 1; i++){

                            fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                            fread(&aluguel,sizeof(aluguel),1,arqRanking);
                            fseek(arqRanking,(i+1)*sizeof(aluguelAux),SEEK_SET);
                            fread(&aluguelAux,sizeof(aluguelAux),1,arqRanking);

                            if(aluguel.qtdDiasFora>aluguelAux.qtdDiasFora){

                                fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                                fwrite(&aluguelAux,sizeof(aluguel),1,arqRanking);
                                fseek(arqRanking,(i+1)*sizeof(aluguelAux),SEEK_SET);
                                fwrite(&aluguel,sizeof(aluguelAux),1,arqRanking);

                                controle = i;
                            }
                            fseek(arqRanking,0,SEEK_SET);
                        }
                        fim--;
                    }while(controle!=0);


                }

                fclose(arqRanking);
                if((arqRanking = fopen("arqRanking.dat","r+b")) == NULL){
                        printf("Erro!!!\n");
                        exit(1);
                }else{
                    controle = 0;
                    while((fread(&aluguel,sizeof(aluguel),1,arqRanking))&& controle<10){
                        fseek(arqFilmes,(aluguel.codigoFita-1)*sizeof(filme),SEEK_SET);
                        fread(&filme,sizeof(filme),1,arqFilmes);
                        printf("Ranking %d� Nome %s QTD: %d\n",++controle,filme.titulo,aluguel.qtdDiasFora);
                        fseek(arqFilmes,0,SEEK_SET);
                    }

                }
                fclose(arqRanking);
            }

            if(fclose(arqHistorico)==0 && fclose(arqFilmes)==0){
                printf("Fim da lista!!!\n");
                system("pause");
            }

        break;
        case 11:

            if((arqHistorico = fopen("historico.dat","r+b"))==NULL || (arqFilmes = fopen("filmes.dat","r+b"))== NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                exit(1);
            }else{

                system("cls");
                remove("arqRanking.dat");
                fim = 0;

                while(fread(&filme,sizeof(filme),1,arqFilmes)){
                    contador = 0;

                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){
                        if(aluguel.codigoFita==filme.codigo){
                            contador +=aluguel.preco*aluguel.qtdDiasFora;
                        }
                    }
                    fseek(arqHistorico,0,SEEK_SET);
                    aluguelAux.preco = contador;
                    aluguelAux.codigoFita=filme.codigo;


                    if((arqRanking = fopen("arqRanking.dat","a+b"))==NULL){
                        printf("Erro ao abrir o arquivo!!!\n");
                        exit(1);
                    }else{
                        fwrite(&aluguelAux,sizeof(aluguelAux),1,arqRanking);
                        fim++;
                    }
                    fclose(arqRanking);

                }
                if((arqRanking = fopen("arqRanking.dat","r+b")) == NULL){
                        printf("Erro!!!\n");
                        exit(1);
                }else{

                    do{
                        controle = 0;

                        for(int i = 0; i < fim - 1; i++){

                            fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                            fread(&aluguel,sizeof(aluguel),1,arqRanking);
                            fseek(arqRanking,(i+1)*sizeof(aluguelAux),SEEK_SET);
                            fread(&aluguelAux,sizeof(aluguelAux),1,arqRanking);

                            if(aluguel.qtdDiasFora>aluguelAux.qtdDiasFora){

                                fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                                fwrite(&aluguelAux,sizeof(aluguel),1,arqRanking);
                                fseek(arqRanking,(i+1)*sizeof(aluguelAux),SEEK_SET);
                                fwrite(&aluguel,sizeof(aluguelAux),1,arqRanking);

                                controle = i;
                            }
                            fseek(arqRanking,0,SEEK_SET);
                        }
                        fim--;
                    }while(controle!=0);
                }

                fclose(arqRanking);
                if((arqRanking = fopen("arqRanking.dat","r+b")) == NULL){
                        printf("Erro!!!\n");
                        exit(1);
                }else{
                    controle = 0;
                    contador = 0;
                    while(fread(&aluguel,sizeof(aluguel),1,arqRanking)){contador++;}
                    fseek(arqRanking,0,SEEK_SET);

                    for(int i = 0; i < 4; i++){
                        if(i<2){
                            fseek(arqFilmes,i*sizeof(filme),SEEK_SET);
                            fread(&filme,sizeof(filme),1,arqFilmes);

                            fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                            fread(&aluguel,sizeof(aluguel),1,arqRanking);

                            printf("%d� com maior rentabilidade Nome %s QTD: %.2f\n",i+1,filme.titulo,aluguel.preco);
                            fseek(arqFilmes,0,SEEK_SET);
                            fseek(arqRanking,0,SEEK_SET);
                        }
                        if(i>=2 && i<contador){
                            fseek(arqFilmes,i*sizeof(filme),SEEK_SET);
                            fread(&filme,sizeof(filme),1,arqFilmes);

                            fseek(arqRanking,i*sizeof(aluguel),SEEK_SET);
                            fread(&aluguel,sizeof(aluguel),1,arqRanking);

                            printf("%d� com menor rentabilidade Nome %s QTD: %.2f\n",++controle,filme.titulo,aluguel.preco);
                            fseek(arqFilmes,0,SEEK_SET);
                            fseek(arqRanking,0,SEEK_SET);
                        }
                    }

                }
                fclose(arqRanking);
            }

            if(fclose(arqHistorico)==0 && fclose(arqFilmes)==0){
                printf("Fim da lista!!!\n");
                system("pause");
            }

        break;
        case 12:

            if((arqFilmes = fopen("filmes.dat","r+b")) == NULL || (arqHistorico = fopen("historico.dat","r+b")) == NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                system("pause");
                exit(1);
            }else{

                controle = 0;

                while(fread(&filme,sizeof(filme),1,arqFilmes)){
                    while(fread(&aluguel,sizeof(aluguel),1,arqHistorico)){

                        if(filme.codigo==aluguel.codigoFita){

                            filmeAux.preco += aluguel.preco;

                        }

                    }
                    if(filmeAux.preco>=filme.preco){
                        printf("O filme %s j� se pagou e temos um lucro de %.2f\n",filme.titulo,filmeAux.preco-filme.preco);
                        controle = 1;
                    }

                    fseek(arqHistorico,0,SEEK_SET);
                    filmeAux.preco = 0;
                }

                if(controle==0){
                        printf("\nNenhum filme j� se pagou!!!\n");
                }

            }
            system("pause");
            if(fclose(arqFilmes) != 0 && fclose(arqHistorico) != 0){
                printf("Erro ao fechar os arquivos");
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
