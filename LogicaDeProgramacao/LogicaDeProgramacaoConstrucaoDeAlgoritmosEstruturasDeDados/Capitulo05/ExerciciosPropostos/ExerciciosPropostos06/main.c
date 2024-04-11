#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 30

typedef struct{
    char nome[tam];
    char cargo [tam];
    char ender[tam];
    char bairro[tam];
    char dtAdmissao[tam];
    char dtDemissao[tam];
    char estCivil[tam];

    int cpf;
    int tel;
    int cep;
    int nDep;
    int setor;

    float sal;
}RegistroFuncionario;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqFuncionario;

    RegistroFuncionario funcionario, funcionarioAUx;

    int opcao = 0;

    do{

        system("cls");
        printf("1 para cadastrar funcionário\n");
        printf("2 para buscar funcionário\n");
        printf("0 para sair\n");
            scanf("%d",&opcao);
            fflush(stdin);
        fflush(stdin);

        switch(opcao){

            case 0:

                system("cls");
                printf("Até logo\n");
                system("pause");

            break;
            case 1:

                arqFuncionario = fopen("arqFuncionarios.dat","a+b");
                fclose(arqFuncionario);

                if((arqFuncionario = fopen("arqFuncionarios.dat","r+b"))==NULL){
                     printf(" Erro ao abrir o arquivo!\n");
                      exit(1);
                }else{

                    printf("Entre com o nome do funcionario: ");
                        scanf("%s",&funcionario.nome);
                        fflush(stdin);
                    printf("Entre com o endereço: ");
                        scanf("%s",&funcionario.ender);
                        fflush(stdin);
                    printf("Entre com o bairro: ");
                        scanf("%s",&funcionario.bairro);
                        fflush(stdin);
                    printf("Entre com o CEP: ");
                        scanf("%d",&funcionario.cep);
                        fflush(stdin);
                    printf("Entre com o CPF: ");
                        scanf("%d",&funcionario.cpf);
                        fflush(stdin);
                    printf("Entre com o telefone: ");
                        scanf("%d",&funcionario.tel);
                        fflush(stdin);
                    printf("Entre com ano de admissão: ");
                        scanf("%s",&funcionario.dtAdmissao);
                        fflush(stdin);
                    printf("Entre com o ano de demissão: ");
                        scanf("%s",& funcionario.dtDemissao);
                        fflush(stdin);
                    printf("Entre com o estado civil: ");
                        scanf("%s",&funcionario.estCivil);
                        fflush(stdin);
                    printf("Entre com o número de dependentes: ");
                        scanf("%d",&funcionario.nDep);
                        fflush(stdin);
                    printf("Entre com o salário: ");
                        scanf("%f",&funcionario.sal);
                        fflush(stdin);
                        fflush(stdin);
                    printf("Entre com o cargo: ");
                        scanf("%s",&funcionario.cargo);
                        fflush(stdin);
                    printf("Entre com o setor: ");
                        scanf("%d",&funcionario.setor);
                        fflush(stdin);

                    fseek(arqFuncionario,funcionario.cpf*sizeof(funcionario),SEEK_SET);
                    fwrite(&funcionario,sizeof(funcionario),1,arqFuncionario);

                }

                if(fclose(arqFuncionario)==0){
                    printf("\nCadastro realizado com sucesso");
                    system("pause");
                }

            break;
            case 2:

                if((arqFuncionario = fopen("arqFuncionarios.dat","r+b"))==NULL){
                     printf(" Erro ao abrir o arquivo!\n");
                      exit(1);
                }else{
                    printf("Digite o CPF no funcionario que deseja buscar:");
                        scanf("%d",&funcionarioAUx.cpf);
                    fseek(arqFuncionario,funcionarioAUx.cpf*sizeof(funcionario),SEEK_SET);
                    fread(&funcionario,sizeof(funcionario),1,arqFuncionario);

                    if(funcionario.cpf==funcionarioAUx.cpf){
                        printf("Nome do funcionario: %s",funcionario.nome);
                    }else{
                        printf("Funcionario não encontrado!!!\n");
                    }
                }

                if(fclose(arqFuncionario)==0){
                    printf("\nFuncionario encontrado com sucesso\n");
                    system("pause");
                }

            break;
            default:

                system("cls");
                printf("Opção invalidade\n");
                system("pause");

        }

    }while(opcao != 0);
    return 0;
}
