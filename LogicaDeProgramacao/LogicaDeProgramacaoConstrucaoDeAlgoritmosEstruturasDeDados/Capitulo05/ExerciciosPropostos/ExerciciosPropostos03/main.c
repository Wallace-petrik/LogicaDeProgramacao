#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct{

    int dia;
    int mes;
    int ano;

}Data;

typedef struct{

   int contaCorrente;
   int agencia;
   char correntista[40];
   Data dataAbertura;

}Correntistas;

typedef struct{

    int numeroAgencia;
    char nomeAgencia[40];

}Agencia;

typedef struct{

    int contaCorrente;
    Data datalancamento;
    float valor;
    int docto;
    int historico;

}Lancamento;

typedef struct{
    int ag;
    float saldoAg;
}Saldo;

int main(){

    setlocale(LC_ALL,"");

    int opcao,controle,contador, pint = 0;
    char pchar;
    FILE *arqCliente, *arqAgenciaBancaria, *arqTansacao, *arqRanking;

    Correntistas cliente;
    Agencia agenciaBancaria,agenciaBancariaAux;
    Lancamento transacao;
    Saldo saldoAgencia,saldoAgenciaAux1,saldoAgenciaAux2;

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    do{

        system("cls");
        printf("1 para abrir conta.\n");
        printf("2 para listar quantidade de correntistas de cada agência.\n");
        printf("3 para listar ranking das agências com maior saldo.\n");
        printf("0 para sair!\n");
            scanf("%d",&opcao);


        switch(opcao){

        case 0:

            system("cls");
            printf("Até logo!");

        break;
        case 1:

            if((arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","a+b"))==NULL || (arqCliente = fopen("arqCliente.dat","a+b"))==NULL || (arqTansacao = fopen("arqTansacao.dat","a+b"))==NULL){
                printf("\n\nErro ao abrir os arquivos!!!\n\n");
                exit(1);
            }else{

                system("cls");
            controle = 0;
            printf("Digite o número da agência: ");
                scanf("%d",&agenciaBancaria.numeroAgencia);
                fflush(stdin);

            printf("Digite o nome da agência: ");
                scanf("%[^\n]",&agenciaBancaria.nomeAgencia);
                fflush(stdin);

            printf("Digite o número da conta: ");
                scanf("%d",&cliente.contaCorrente);
                cliente.agencia = agenciaBancaria.numeroAgencia;
                fflush(stdin);

            printf("Digite o nome do cliente: ");
                scanf("%[^\n]",&cliente.correntista);

                cliente.dataAbertura.dia = tm.tm_mday;
                cliente.dataAbertura.mes = tm.tm_mon;
                cliente.dataAbertura.ano = tm.tm_year+1900;

                transacao.contaCorrente = cliente.contaCorrente;
                transacao.datalancamento = cliente.dataAbertura;
                transacao.docto = cliente.agencia+cliente.contaCorrente;
                transacao.historico = transacao.docto;
                fflush(stdin);

            printf("Digite o valor do primeiro deposito: ");
                scanf("%f",&transacao.valor);
                fflush(stdin);

                while(fread(&agenciaBancariaAux,sizeof(agenciaBancariaAux),1,arqAgenciaBancaria)){

                    if(agenciaBancariaAux.numeroAgencia==agenciaBancaria.numeroAgencia){

                        controle = 1;

                    }

                }

                if(controle!=1){
                    fwrite(&agenciaBancaria,sizeof(agenciaBancaria),1,arqAgenciaBancaria);
                }

                fwrite(&transacao,sizeof(transacao),1,arqTansacao);
                fwrite(&cliente,sizeof(cliente),1,arqCliente);

            }

            if(fclose(arqAgenciaBancaria)==0 && fclose(arqCliente)==0 && fclose(arqTansacao)==0){
                printf("\n\nConta criada com sucesso!!!\n\n");
                system("pause");
            }

        break;
        case 2:

            system("cls");
            if((arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","rb"))==NULL || (arqCliente = fopen("arqCliente.dat","rb"))==NULL || (arqTansacao = fopen("arqTansacao.dat","rb"))== NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                exit(1);
            }else{

                while(fread(&agenciaBancariaAux,sizeof(agenciaBancariaAux),1,arqAgenciaBancaria)){

                    printf("%s\n",agenciaBancariaAux.nomeAgencia);
                    contador = 0;

                    while(fread(&cliente,sizeof(cliente),1,arqCliente)){

                        if(agenciaBancariaAux.numeroAgencia==cliente.agencia){
                            contador++;
                        }

                    }

                    printf("Quantidade de correntistas: %d\n\n",contador);
                    fseek(arqCliente,0,SEEK_SET);
                }

            }

            if(fclose(arqAgenciaBancaria)==0 && fclose(arqCliente)==0 && fclose(arqTansacao)==0){
                printf("Sucesso na execução!!!\n");
                system("pause");
            }

        break;
        case 3:

            system("cls");
            if((arqRanking = fopen("arqRanking.dat","w+"))==NULL ||
              (arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","rb"))==NULL ||
              (arqCliente = fopen("arqCliente.dat","rb"))==NULL ||
              (arqTansacao = fopen("arqTansacao.dat","rb")) == NULL){

                printf("Erro ao abrir os arquivos!!!\n");

                exit(1);
            }else{

                contador = 0;
                while(fread(&agenciaBancariaAux,sizeof(agenciaBancariaAux),1,arqAgenciaBancaria)){

                    saldoAgencia.saldoAg = 0;

                    while(fread(&transacao,sizeof(transacao),1,arqTansacao)){

                        pint = transacao.contaCorrente;

                        while(pint>=10){
                            pint /= 10;
                        }

                        if(agenciaBancariaAux.numeroAgencia==pint){

                            saldoAgencia.saldoAg += transacao.valor;

                        }
                    }

                    saldoAgencia.ag = agenciaBancariaAux.numeroAgencia;
                    fwrite(&saldoAgencia,sizeof(saldoAgencia),1,arqRanking);
                    fseek(arqTansacao,0,SEEK_SET);
                    contador++;
                }

                do{
                    controle = 0;

                    for(int i = 0; i < contador - 1; i++){

                        fseek(arqRanking,i*sizeof(saldoAgenciaAux1),SEEK_SET);
                        fread(&saldoAgenciaAux1,sizeof(saldoAgenciaAux1),1,arqRanking);
                        fseek(arqRanking,(i+1)*sizeof(saldoAgenciaAux2),SEEK_SET);
                        fread(&saldoAgenciaAux2,sizeof(saldoAgenciaAux2),1,arqRanking);

                        if(saldoAgenciaAux1.saldoAg<saldoAgenciaAux2.saldoAg){

                            fseek(arqRanking,i*sizeof(saldoAgenciaAux1),SEEK_SET);
                            fwrite(&saldoAgenciaAux2,sizeof(saldoAgenciaAux1),1,arqRanking);
                            fseek(arqRanking,(i+1)*sizeof(saldoAgenciaAux2),SEEK_SET);
                            fwrite(&saldoAgenciaAux1,sizeof(saldoAgenciaAux2),1,arqRanking);

                            controle = i;
                        }
                        fseek(arqRanking,0,SEEK_SET);
                    }
                    contador--;
                }while(controle!=0);

                fseek(arqAgenciaBancaria,0,SEEK_SET);

                contador = 0;

                while(fread(&agenciaBancaria,sizeof(agenciaBancaria),1,arqAgenciaBancaria)){

                    printf("%dº Nome: %s\n",++contador,agenciaBancaria.nomeAgencia);
                    fseek(arqRanking,(agenciaBancaria.numeroAgencia-1)*(sizeof(saldoAgencia)),SEEK_SET);
                    fread(&saldoAgencia,sizeof(saldoAgencia),1,arqRanking);
                    printf("Saldo: %.2f\n\n",saldoAgencia.saldoAg);

                    if(contador>10){
                        break;
                    }
                }

            }

            if(fclose(arqAgenciaBancaria)==0 && fclose(arqCliente)==0 && fclose(arqTansacao)==0){
                printf("Sucesso na execução!!!\n");
                system("pause");
            }


        break;
        default:
            system("cls");
            printf("Opção invalda!\n");
        }

    }while(opcao!=0);

    return 0;
}
