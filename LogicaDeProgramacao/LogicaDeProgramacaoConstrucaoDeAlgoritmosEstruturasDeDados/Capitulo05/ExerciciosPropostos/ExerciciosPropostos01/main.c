#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tam 30

typedef struct{
    char nome[tam];
    char endereco[tam];
    int telefone;
}RegistroTelefone;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
}RegistroEndereco;

typedef struct{
    char nome[tam];
    char rua[tam];
    char bairro[tam];
    char cidade[tam];
    char dt_nasc[tam];
    int CEP;
    int telefone;
}RegistroGeral;

int main(){

    setlocale(LC_ALL,"");

    int opcao_01 = 0,opcao_02 = 0;

    FILE *arquivoTelefone, *arquivoEndereco, *arquivoGeral;

    RegistroTelefone telefone;
    RegistroEndereco endereco;
    RegistroGeral geral;

    do{

        system("cls");
        printf("1 para cadastrar dados\n2 para gerar arquivo único para usuários que estão nos dois arquivos\n");
            scanf("%d",&opcao_01);
            fflush(stdin);

        switch(opcao_01){

            case 0:

                system("cls");
                printf("Até logo!\n");
                system("pause");

            break;
            case 1:

                system("cls");
                printf("1 para cadastrar telefone\n2 para cadastrar endereço");
                    scanf("%d",&opcao_02);
                    fflush(stdin);
                if(((arquivoTelefone = fopen("telefone.dat","ab+"))==NULL) || ((arquivoEndereco = fopen("endereco.dat","ab+"))==NULL)){
                    system("cls");
                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);
                }else{
                    if(opcao_02==1){
                        system("cls");
                        printf("Nome: ");
                            fgets(telefone.nome,tam,stdin);
                            fflush(stdin);
                        printf("Endereço: ");
                            fgets(telefone.endereco,tam,stdin);
                            fflush(stdin);
                        printf("Telefone: ");
                            scanf("%d",&telefone.telefone);
                            fflush(stdin);
                        fwrite(&telefone,sizeof(telefone),1,arquivoTelefone);
                    }else if(opcao_02==2){
                        system("cls");
                        printf("Nome: ");
                            fgets(endereco.nome,tam,stdin);
                            fflush(stdin);
                        printf("Cidade: ");
                            fgets(endereco.cidade,tam,stdin);
                            fflush(stdin);
                        printf("Bairro: ");
                            fgets(endereco.bairro,tam,stdin);
                            fflush(stdin);
                        printf("Rua: ");
                            fgets(endereco.rua,tam,stdin);
                            fflush(stdin);
                        printf("CEP: ");
                            scanf("%d",&endereco.CEP);
                            fflush(stdin);
                        printf("Data de nascimento: ");
                            fgets(endereco.dt_nasc,tam,stdin);
                            fflush(stdin);

                            fwrite(&endereco,sizeof(endereco),1,arquivoEndereco);
                    }else{
                        system("cls");
                        printf("Opção invalida!\n");
                        system("pause");
                    }
                }

                if((fclose(arquivoTelefone))==0 && (fclose(arquivoEndereco))==0){
                    system("cls");
                    printf("Dados salvos com sucesso!\n");
                    system("pause");
                }

            break;
            case 2:

                system("cls");
                if(((arquivoTelefone = fopen("telefone.dat","ab+"))==NULL) ||
                  ((arquivoEndereco = fopen("endereco.dat","ab+"))==NULL) ||
                  ((arquivoGeral = fopen("telefonemaisendereco.dat","wb"))==NULL)){
                        system("cls");
                        printf("Erro ao abrir o arquivo!\n");
                        exit(1);
                  }else{

                    system("cls");
                    while(fread(&telefone,sizeof(telefone),1,arquivoTelefone)){
                        while(fread(&endereco,sizeof(endereco),1,arquivoEndereco)){
                            if((strcmp(telefone.nome,endereco.nome))==0){

                                strcpy(geral.nome,endereco.nome);
                                strcpy(geral.cidade,endereco.cidade);
                                strcpy(geral.bairro,endereco.bairro);
                                strcpy(geral.rua,endereco.rua);
                                geral.CEP=endereco.CEP;
                                strcpy(geral.dt_nasc,endereco.dt_nasc);
                                geral.telefone=telefone.telefone;

                                fwrite(&geral,sizeof(geral),1,arquivoGeral);
                            }
                        }
                        fseek(arquivoEndereco,0,SEEK_SET);
                    }

                  }

                if((fclose(arquivoTelefone))==0 && (fclose(arquivoEndereco))==0 && (fclose(arquivoGeral))==0){

                    printf("Dados salvos com sucesso!\n");
                    system("pause");
                }

            break;
            default :

                system("cls");
                printf("Opção invalida!\n");
                system("pause");

        }

    }while(opcao_01!=0);

    return 0;
}
