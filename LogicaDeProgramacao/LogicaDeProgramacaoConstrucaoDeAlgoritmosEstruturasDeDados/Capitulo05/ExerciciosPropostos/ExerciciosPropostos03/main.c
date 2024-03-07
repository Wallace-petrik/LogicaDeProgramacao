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
    float saldoCliente = 0;
    double diff1, diff2;
    FILE *arqCliente, *arqAgenciaBancaria, *arqTansacao, *arqRanking;

    Correntistas cliente,clienteAux;
    Agencia agenciaBancaria,agenciaBancariaAux;
    Lancamento transacao;
    Saldo saldoAgencia,saldoAgenciaAux1,saldoAgenciaAux2;

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    struct tm data1 ={0};
    struct tm data2 ={0};
    struct tm data3 ={0};

    time_t time1, time2, time3;

    do{

        system("cls");
        printf("1 para abrir conta.\n");
        printf("2 para listar quantidade de correntistas de cada agência.\n");
        printf("3 para listar ranking das agências com maior saldo.\n");
        printf("4 para saldo correntista em determinada data.\n");
        printf("5 para imprimi um estrato para um período\n");
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

            if((arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","rb"))==NULL || (arqCliente = fopen("arqCliente.dat","rb"))==NULL || (arqTansacao = fopen("arqTansacao.dat","rb"))== NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                exit(1);
            }else{
                system("cls");
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

            if((arqRanking = fopen("arqRanking.dat","w+"))==NULL ||
              (arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","rb"))==NULL ||
              (arqCliente = fopen("arqCliente.dat","rb"))==NULL ||
              (arqTansacao = fopen("arqTansacao.dat","rb")) == NULL){

                printf("Erro ao abrir os arquivos!!!\n");

                exit(1);
            }else{
                system("cls");
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
        case 4:

            if((arqCliente = fopen("arqCliente.dat","r+b"))==NULL || (arqTansacao = fopen("arqTansacao.dat","r+b"))==NULL){
                printf("Erro ao abrir os arquivos!!!\n");
                exit(1);
            }else{

                system("cls");
                printf("Digite sua agencia: ");
                    scanf("%d",&cliente.agencia);
                printf("Digite sua conta: ");
                    scanf("%d",&cliente.contaCorrente);

                printf("Digite a data: ");
                    scanf("%d%d%d",&cliente.dataAbertura.dia,&cliente.dataAbertura.mes,&cliente.dataAbertura.ano);

                data2.tm_mday = cliente.dataAbertura.dia;
                data2.tm_mon = cliente.dataAbertura.mes;
                data2.tm_year = cliente.dataAbertura.ano - 1900;

                saldoCliente = 0;

                while(fread(&clienteAux,sizeof(clienteAux),1,arqCliente)){

                    if(cliente.contaCorrente==clienteAux.contaCorrente){

                        while(fread(&transacao,sizeof(transacao),1,arqTansacao)){

                            data1.tm_mday = transacao.datalancamento.dia;
                            data1.tm_mon = transacao.datalancamento.mes;
                            data1.tm_year = transacao.datalancamento.ano - 1900;

                            time1 = mktime(&data1);
                            time2 = mktime(&data2);

                            diff1 = difftime(time1,time2);

                            if(transacao.contaCorrente==cliente.contaCorrente && diff1 < 0){

                                saldoCliente = transacao.valor;

                            }
                        }
                        break;
                    }
                }
                printf("Nome: %s\n",clienteAux.correntista);
                printf("Saldo = %.2f\n\n",saldoCliente);
            }

            if(fclose(arqCliente)==0 && fclose(arqTansacao)==0){
                printf("Buca realizada com sucesso!!!\n");
                system("pause");
            }

        break;
        case 5:

            if((arqAgenciaBancaria = fopen("arqAgenciaBancaria.dat","rb"))== NULL ||
               (arqCliente = fopen("arqCliente.dat","rb"))== NULL ||
               (arqTansacao = fopen("arqTansacao.dat","rb"))==NULL ||
               (arqRanking = fopen("arqRanking.dat","r+"))== NULL){
                printf("Erro ao abrir o arquivo!!!\n");
                    exit(1);
            }else{

                system("cls");
                printf("Entre com a data inicial: ");
                    scanf("%d%d%d",&data1.tm_mday,&data1.tm_mon,&data1.tm_year);
                    data1.tm_year -= 1900;
                printf("Entre com a data final: ");
                    scanf("%d%d%d",&data2.tm_mday,&data2.tm_mon,&data2.tm_year);
                    data2.tm_year -= 1900;
                printf("Digite a conta: ");
                    scanf("%d",&clienteAux.contaCorrente);

                time1 = mktime(&data1);
                time2 = mktime(&data2);
                saldoCliente = 0;

                while(fread(&transacao,sizeof(transacao),1,arqTansacao)){

                    data3.tm_mday = transacao.datalancamento.dia;
                    data3.tm_mon = transacao.datalancamento.mes;
                    data3.tm_year = transacao.datalancamento.ano - 1900;

                    time3 = mktime(&data3);

                    diff1 = difftime(time3,time1);

                    if(transacao.contaCorrente==clienteAux.contaCorrente && diff1 < 0){

                        saldoCliente += transacao.valor;

                    }

                }
                printf("\n\nSalto anterior: %.2f\n",saldoCliente);

                fseek(arqTansacao,0,SEEK_SET);

                while(fread(&transacao,sizeof(transacao),1,arqTansacao)){
                    if(transacao.contaCorrente==clienteAux.contaCorrente){

                        data3.tm_mday = transacao.datalancamento.dia;
                        data3.tm_mon = transacao.datalancamento.mes;
                        data3.tm_year = transacao.datalancamento.ano - 1900;

                        time3 = mktime(&data3);

                        diff1 = difftime(time3,time1);
                        diff2 = difftime(time3,time2);

                        if(diff1 >= 0 && diff2 <= 0){

                            printf("Ext -- %d/%d/%d -- Saldo = %.2f\n",transacao.datalancamento.dia,transacao.datalancamento.mes,transacao.datalancamento.ano,transacao.valor);

                        }

                    }
                }
                fseek(arqTansacao,0,SEEK_SET);
                saldoCliente = 0;

                while(fread(&transacao,sizeof(transacao),1,arqTansacao)){
                    if(transacao.contaCorrente==clienteAux.contaCorrente){
                        saldoCliente += transacao.valor;
                    }

                }
                printf("Salto atual: %.2f\n\n",saldoCliente);

            }

            if(fclose(arqAgenciaBancaria)== 0 && fclose(arqCliente)== 0 && fclose(arqRanking)== 0 && fclose(arqTansacao) == 0){

                printf("Sucesso na execução!!!\n");
                system("pause");

            }

        break;
        default:
            system("cls");
            printf("Opção invalda!\n");
            system("pause");
        }

    }while(opcao!=0);

    return 0;
}
