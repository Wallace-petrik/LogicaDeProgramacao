#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 40

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int numeroSocio;
    char nome[tam];
    char endereco[tam];
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int dependentes;
    Data dataDeAssociacao;
}Associados;

typedef struct{
    int numeroSocio;
    Data dataDeVencimento;
    float valor;
    Data dataDePagamento;
}Mensalidade;

int main(){

    setlocale(LC_ALL,"");

    int opcao,contador;

    FILE *arquivoAssociados, *arquivoMensalidade, *novoarquivo;

    Associados socio,socioAux;
    Mensalidade boleto;
    do{

        system("cls");
        printf("1 para associados\n");
        printf("2 para apresentar número de pessoas que pode frequentar o clube\n");
        printf("3 para listar aniversariantes do mês\n");
        printf("4 para listar mensaldades dos socios\n");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){

            case 0:

                system("cls");
                printf("Até logo!\n");

            break;
            case 1:

                system("cls");
                if((arquivoAssociados = fopen("arquivoS.dat","rb+"))==NULL){

                    printf("Erro ao abrir o arquivo!\n");
                    system("pause");
                    exit(1);

                }else{

                    printf("1 para inclusões\n2 para alterações\n3 para exclusões\n");
                        scanf("%d",&opcao);

                        if(opcao==1){
                            printf("Número de sócio: ");
                                scanf("%d",&socio.numeroSocio);
                                fflush(stdin);
                            printf("Nome: ");
                                fgets(socio.nome,tam,stdin);
                                fflush(stdin);
                            printf("Endereço: ");
                                fgets(socio.endereco,tam,stdin);
                                fflush(stdin);
                            printf("Bairro: ");
                                fgets(socio.bairro,tam,stdin);
                                fflush(stdin);
                            printf("Cidade: ");
                                fgets(socio.cidade,tam,stdin);
                                fflush(stdin);
                            printf("Estado: ");
                                fgets(socio.estado,tam,stdin);
                                fflush(stdin);
                            printf("Número de dependentes: ");
                                scanf("%d",&socio.dependentes);
                                fflush(stdin);
                            printf("Data de associação: ");
                                scanf("%d%d%d",&socio.dataDeAssociacao.dia,&socio.dataDeAssociacao.mes,&socio.dataDeAssociacao.ano);
                                fflush(stdin);

                            fwrite(&socio,sizeof(socio),1,arquivoAssociados);
                        }else if(opcao == 2){

                            printf("\nDigite o código do associado: ");
                                scanf("%d",&socioAux.numeroSocio);

                            printf("Número de sócio: ");
                                scanf("%d",&socio.numeroSocio);
                                fflush(stdin);
                            printf("Nome: ");
                                fgets(socio.nome,tam,stdin);
                                fflush(stdin);
                            printf("Endereço: ");
                                fgets(socio.endereco,tam,stdin);
                                fflush(stdin);
                            printf("Bairro: ");
                                fgets(socio.bairro,tam,stdin);
                                fflush(stdin);
                            printf("Cidade: ");
                                fgets(socio.cidade,tam,stdin);
                                fflush(stdin);
                            printf("Estado: ");
                                fgets(socio.estado,tam,stdin);
                                fflush(stdin);
                            printf("Número de dependentes: ");
                                scanf("%d",&socio.dependentes);
                                fflush(stdin);
                            printf("Data de associação: ");
                                scanf("%d%d%d",&socio.dataDeAssociacao.dia,&socio.dataDeAssociacao.mes,&socio.dataDeAssociacao.ano);
                                fflush(stdin);

                            fseek(arquivoAssociados,sizeof(socio)*(socioAux.numeroSocio-1),SEEK_SET);
                            fwrite(&socio,sizeof(socio),1,arquivoAssociados);

                        }else if(opcao==3){

                            if((novoarquivo = fopen("novoarq.dat","a+b"))==NULL){

                                    printf("Erro ao abrir o arquivo\n");

                            }else{

                                printf("Digite o número do socio: ");
                                    scanf("%d",&socioAux.numeroSocio);

                                while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                                    if(socioAux.numeroSocio!=socio.numeroSocio){
                                        fwrite(&socio,sizeof(socio),1,novoarquivo);
                                    }

                                }

                            }

                        }else{
                            printf("Opção invalida\n");
                        }

                }

                if((fclose(arquivoAssociados))==0){

                    printf("Êxito\n");
                    system("pause");

                }
                if((fclose(novoarquivo))==0){

                    printf("Êxito\n");
                    system("pause");

                }

                remove("arquivoS.dat");
                rename("novoarq.dat","arquivoS.dat");

            break;
            case 2:

                if((arquivoAssociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    contador = 0;

                    while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                        contador+= socio.dependentes+1;

                    }
                    if(contador>0){
                        printf("\nO total depssoas: %d\n\n",contador);
                    }
                }

                if((fclose(arquivoAssociados))==0){

                    printf("Êxito na busca!\n");
                    system("pause");

                }

            break;
            case 3:

                if((arquivoAssociados = fopen("arquivoS.dat","ab+"))==NULL){

                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);

                }else{

                    printf("\nDigite o mês: ");
                        scanf("%d",&socioAux.dataDeAssociacao.mes);
                    printf("\n");
                    while(fread(&socio,sizeof(socio),1,arquivoAssociados)){

                        if(socioAux.dataDeAssociacao.mes==socio.dataDeAssociacao.mes){

                            printf("Nome: %s",socio.nome);

                        }

                    }

                }

                if((fclose(arquivoAssociados))==0){

                    printf("\nÊxito na busca!\n");
                    system("pause");

                }

            break;
            case 4:

                system("cls");
                if((arquivoAssociados = fopen("arquivoS.dat","rb"))==NULL || (arquivoMensalidade = fopen("arquivosM.dat","w+b"))==NULL){

                    system("cls");
                    printf("Erro ao abrir os arquivos!\n");
                    exit(1);
                }else{



                }

                if((fclose(arquivoAssociados))==0 && (fclose(arquivoMensalidade))){

                    printf("Busca realizada com sucesso!\n");
                    system("pause");

                }

            break;
            default:

                system("cls");
                printf("Opção invalida!\n");
                system("pause");
        }

    }while(opcao!=0);

    return 0;
}
