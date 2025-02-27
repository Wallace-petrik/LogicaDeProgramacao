#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define tam 100

typedef struct{

    int dia;
    int mes;
    int ano;

}Data;

typedef struct{

    int cnpj;
    char razaoSocial[tam];
    int telefone;
    char email[tam];

}Cliente;

typedef struct{

    int cnpj;
    Data data;
     int origem;
    int contato;
    char problema[tam];
    char solucao[tam];

}Atendimento;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqCliente, *arqAtendimento;

    Cliente cliente, clienteAux;
    Atendimento atendimento, atendimentoAnt;

    int opcao = 0, controle = 0, contador = 0;

    if((arqAtendimento = fopen("arqAtendimento.dat","a+b")) == NULL || (arqCliente = fopen("arqCliente.dat","a+b")) ==  NULL){
        printf("Erro ao criar os arquivos!!!\n");
        system("pause");
        exit(1);
    }else{

        fclose(arqAtendimento);
        fclose(arqCliente);

    }

    do{
         system("cls");
        printf("1 para cadastrar cliente\n");
        printf("2 para cadastrar atendimento\n");
        printf("3 para mostrar os últimos 5 atendimentos originados pelo cliente\n");
        printf("4 para mostrar os últimos 5 atendimentos originados na empresa\n");
        printf("5 para apresentar relatório do mes\n");
        printf("6 para média de tendimento de por cliente por mês\n");

        printf("\n0 para sair\n");

        printf("\nDigite uma opçao: ");
            scanf("%d",&opcao);

        switch(opcao){

            case 0:

                system("cls");
                printf("\nAté logo\n");

            break;
            case 1:

                if((arqCliente = fopen("arqCliente.dat","r+b")) == NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{
                    system("cls");
                    printf("Entre com o CNPJ: ");
                        scanf("%d",&cliente.cnpj);
                        fflush(stdin);
                    printf("Entre com a Razão Social: ");
                        scanf("%[^\n]",&cliente.razaoSocial);
                        fflush(stdin);
                    printf("Entre com o email: ");
                        scanf("%[^\n]",&cliente.email);
                        fflush(stdin);
                    printf("Entre com o número de telefone: ");
                        scanf("%d",&cliente.telefone);
                        fflush(stdin);
                    fseek(arqCliente,(cliente.cnpj-1)*sizeof(cliente),SEEK_SET);
                    fwrite(&cliente,sizeof(cliente),1,arqCliente);

                }
                if(fclose(arqCliente) == 0){
                    printf("Operação realizada com sucesso!!!\n");
                    system("pause");;
                }

            break;
            case 2:

                if((arqAtendimento = fopen("arqAtendimento.dat","a+b")) == NULL){
                    printf("Erro ao abrir o arquivo!!!");
                    system("pause");
                }else{

                    system("cls");
                    printf("Digite o CNPJ: ");
                        scanf("%d",&atendimento.cnpj);
                    printf("Digite a data: ");
                        scanf("%d%d%d",&atendimento.data.dia,&atendimento.data.mes,&atendimento.data.ano);
                    printf("1 para empresa\n2 para cliente\nDigite a origem: ");
                        scanf("%d",&atendimento.origem);
                    printf("Digite o contato: ");
                        scanf("%d",&atendimento.contato);
                        fflush(stdin);
                    printf("Digite o problema: ");
                        scanf("%[^\n]",&atendimento.problema);
                        fflush(stdin);
                    printf("Digite a soluçao: ");
                        scanf("%[^\n]",&atendimento.solucao);

                    fwrite(&atendimento,sizeof(atendimento),1,arqAtendimento);

                }
                if(fclose(arqAtendimento) == 0){
                    printf("Operação realizada com sucesso!!!");
                    system("pause");
                }

            break;
            case 3:

                if((arqCliente = fopen("arqCliente.dat","r+b")) == NULL || (arqAtendimento = fopen("arqAtendimento.dat","r+b")) == NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{
                    struct tm data1 = {0};
                    struct tm data2 = {0};

                    time_t segundos1;
                    time_t segundos2;

                    printf("Digite o CNPJ: ");
                        scanf("%d",&cliente.cnpj);

                    fseek(arqCliente,(cliente.cnpj-1)*sizeof(cliente),SEEK_SET);
                    fread(&clienteAux,sizeof(clienteAux),1,arqCliente);

                    if(cliente.cnpj!=clienteAux.cnpj){
                        printf("Cliente não está cadastradp\n");
                        system("pause");
                    }else{

                        printf("\n\nNome = %s\n",clienteAux.razaoSocial);

                        fseek(arqAtendimento,0,SEEK_END);
                        long fileSize = ftell(arqAtendimento);
                        long qtdRegistros = fileSize / sizeof(atendimento);

                        for(int i = qtdRegistros - 1, contador = 0; i >= 0 && contador<5 ; i--,++contador){

                            fseek(arqAtendimento,(i * sizeof(atendimento)),SEEK_SET);
                            fread(&atendimento,sizeof(atendimento),1,arqAtendimento);

                            if(cliente.cnpj == atendimento.cnpj && atendimento.origem == 2){
                                int dias = 0;
                                printf("Data %d/%d/%d\t",atendimento.data.dia,atendimento.data.mes,atendimento.data.ano);
                                printf("Problema: %s\t",atendimento.problema);

                                controle = (i == 0) ? i : i - 1;

                                while(controle>=0){

                                    fseek(arqAtendimento,(controle * sizeof(atendimentoAnt)),SEEK_SET);
                                    fread(&atendimentoAnt,sizeof(atendimentoAnt),1,arqAtendimento);

                                    if(cliente.cnpj == atendimentoAnt.cnpj && atendimentoAnt.origem == 2){
                                        break;
                                    }else{
                                        controle--;
                                    }
                                }

                                if(atendimentoAnt.cnpj==atendimento.cnpj){

                                    data1.tm_year = atendimento.data.ano - 1900;
                                    data1.tm_mon = atendimento.data.mes;
                                    data1.tm_mday = atendimento.data.dia;
                                    data2.tm_year = atendimentoAnt.data.ano - 1900;
                                    data2.tm_mon = atendimentoAnt.data.mes;
                                    data2.tm_mday = atendimentoAnt.data.dia;

                                }else{

                                    atendimentoAnt = atendimento;

                                }
                                    segundos1 = mktime(&data1);
                                    segundos2 = mktime(&data2);

                                    double diferenca = difftime(segundos2, segundos1);

                                    dias = diferenca / 86400;

                                    atendimentoAnt = atendimento;

                                printf("O tempo desde o chamado anterior é de %d dias\n",abs(dias));

                            }else{
                                contador--;
                            }
                        }
                        system("pause");
                    }
                }
                if(fclose(arqCliente) != 0 && fclose(arqAtendimento) != 0){
                    printf("Erro ao finalizar operação!!!");
                    system("pause");
                }

            break;
            case 4:

                if((arqCliente = fopen("arqCliente.dat","r+b")) == NULL || (arqAtendimento = fopen("arqAtendimento.dat","r+b")) == NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{
                    struct tm data1 = {0};
                    struct tm data2 = {0};

                    time_t segundos1;
                    time_t segundos2;

                    printf("Digite o CNPJ: ");
                        scanf("%d",&cliente.cnpj);

                    fseek(arqCliente,(cliente.cnpj-1)*sizeof(cliente),SEEK_SET);
                    fread(&clienteAux,sizeof(clienteAux),1,arqCliente);

                    if(cliente.cnpj!=clienteAux.cnpj){
                        printf("Cliente não está cadastradp\n");
                        system("pause");
                    }else{

                        printf("\n\nNome = %s\n",clienteAux.razaoSocial);

                        fseek(arqAtendimento,0,SEEK_END);
                        long fileSize = ftell(arqAtendimento);
                        long qtdRegistros = fileSize / sizeof(atendimento);

                        for(int i = qtdRegistros - 1, contador = 0; i >= 0 && contador<5 ; i--,++contador){

                            fseek(arqAtendimento,(i * sizeof(atendimento)),SEEK_SET);
                            fread(&atendimento,sizeof(atendimento),1,arqAtendimento);

                            if(cliente.cnpj == atendimento.cnpj && atendimento.origem == 1){
                                int dias = 0;
                                printf("Data %d/%d/%d\t",atendimento.data.dia,atendimento.data.mes,atendimento.data.ano);
                                printf("Problema: %s\t",atendimento.problema);

                                controle = (i == 0) ? i : i - 1;

                                while(controle>=0){

                                    fseek(arqAtendimento,(controle * sizeof(atendimentoAnt)),SEEK_SET);
                                    fread(&atendimentoAnt,sizeof(atendimentoAnt),1,arqAtendimento);

                                    if(cliente.cnpj == atendimentoAnt.cnpj && atendimentoAnt.origem == 1){
                                        break;
                                    }else{
                                        controle--;
                                    }
                                }

                                if(atendimentoAnt.cnpj==atendimento.cnpj){

                                    data1.tm_year = atendimento.data.ano - 1900;
                                    data1.tm_mon = atendimento.data.mes;
                                    data1.tm_mday = atendimento.data.dia;
                                    data2.tm_year = atendimentoAnt.data.ano - 1900;
                                    data2.tm_mon = atendimentoAnt.data.mes;
                                    data2.tm_mday = atendimentoAnt.data.dia;

                                }else{

                                    atendimentoAnt = atendimento;

                                }
                                    segundos1 = mktime(&data1);
                                    segundos2 = mktime(&data2);

                                    double diferenca = difftime(segundos2, segundos1);

                                    dias = diferenca / 86400;

                                    atendimentoAnt = atendimento;

                                printf("O tempo desde o chamado anterior é de %d dias\n",abs(dias));

                            }else{
                                contador--;
                            }
                        }
                        system("pause");
                    }
                }
                if(fclose(arqCliente) != 0 && fclose(arqAtendimento) != 0){
                    printf("Erro ao finalizar operação!!!");
                    system("pause");
                }

            break;
            case 5:

                if((arqCliente = fopen("arqCliente.dat","r+b"))==NULL || (arqAtendimento = fopen("arqAtendimento.dat","r+b"))==NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{

                    time_t tempo;
                    tempo = time(NULL);
                    struct tm tm = *localtime(&tempo);

                     while(fread(&atendimento,sizeof(atendimento),1,arqAtendimento)){
                        fseek(arqCliente,(atendimento.cnpj-1)*sizeof(cliente),SEEK_SET);
                        fread(&cliente,sizeof(cliente),1,arqCliente);

                        if(atendimento.data.mes=tm.tm_mon){
                            printf("Nome: %s\t CNPJ: %d\t Data: %2.d/%2.d/%d\t Problema: %s\n",cliente.razaoSocial,cliente.cnpj,atendimento.data.dia,atendimento.data.mes,atendimento.data.ano,atendimento.problema);
                        }

                     }

                    system("pause");
                }
                if(fclose(arqCliente)!= 0 && fclose(arqAtendimento)!= 0){
                    printf("Erro ao fechar os arquivos!!!");
                    system("pause");
                }
            break;
            case 6:

                if((arqCliente = fopen("arqCliente.dat","r+b"))==NULL || (arqAtendimento = fopen("arqAtendimento.dat","r+b"))==NULL){
                    printf("Erro ao abrir os arquivos!!!");
                    system("pause");
                }else{

                    system("cls");
                    printf("Entre com o CNPJ do cliente: ");
                        scanf("%d",&cliente.cnpj);

                    fseek(arqCliente,(cliente.cnpj-1)*sizeof(cliente),SEEK_SET);
                    fread(&clienteAux,sizeof(clienteAux),1,arqCliente);

                    if(cliente.cnpj != clienteAux.cnpj){
                        printf("Cliente não encontrado!!!");
                        system("pause");
                    }else{

                        contador = 0;

                        while(fread(&atendimento,sizeof(atendimento),1,arqAtendimento)){
                            if(cliente.cnpj == atendimento.cnpj){
                                contador++;
                            }
                        }

                        printf("O cliente %s tem uma média de atendimento por mês de %.2f\n",clienteAux.razaoSocial,contador/12.0);
                        system("pause");
                    }

                }
                if(fclose(arqCliente)!= 0 && fclose(arqAtendimento)!= 0){
                    printf("Erro ao fechar os arquivos!!!");
                    system("pause");
                }
            break;
            default:
                printf("Opção invalida!!!\n");
                system("pause");
        }

    }while(opcao != 0);

    return 0;
}
