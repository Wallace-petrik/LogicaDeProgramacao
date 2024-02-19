#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[30];
    char rua[30];
    char bairro[30];
    char estadoCivil[30];
    char cargo[30];
    int numeroDeDependentes;
    int cep;
    int anoDeAdmissao;
    int anoDeDemisap;
    int cpf;
    int tel;
    int setor;
    float salario;

}regFunc;

typedef struct{
    int posicao;
    int codigo;
}regCod;

int main(){

    setlocale(LC_ALL,"");

    int opcao, contador;

    FILE *funcionarios, *codigos;

    regFunc colaborador;
    regCod cod;
    do{

        system("cls");
        printf("1 para cadastrar funcionario.\n");
        printf("2 para listar todos os colaboradores.");
            scanf("%d",&opcao);
            fflush(stdin);

            if(((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL)||((codigos = fopen("indices.dat","wb"))==NULL)){
                printf("Erro ao gerar índices");
                exit(1);
            }else{
                contador = 0;
                while(fread(&colaborador,sizeof(colaborador),1,funcionarios)){

                    cod.codigo = colaborador.anoDeAdmissao+colaborador.setor+contador;
                    cod.posicao = cod.codigo - (colaborador.anoDeAdmissao+colaborador.setor);
                    contador++;
                    fwrite(&cod,sizeof(cod),1,codigos);
                }

                fclose(funcionarios);
                fclose(codigos);

            }

        switch(opcao){

            case 0:

                system("cls");
                printf("Até logo!\n");
                system("pause");

            break;
            case 1:

                system("cls");
                if((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo");
                    exit(1);
                }else{

                    printf("Nome: ");
                        fgets(colaborador.nome,30,stdin);
                    printf("\nRua: ");
                        fgets(colaborador.rua,30,stdin);
                        fflush(stdin);
                    printf("\nBairro: ");
                        fgets(colaborador.bairro,30,stdin);
                        fflush(stdin);
                    printf("\nCEP: ");
                        scanf("%d",&colaborador.cep);
                        fflush(stdin);
                    printf("\nCPF: ");
                        scanf("%d",&colaborador.cpf);
                        fflush(stdin);
                    printf("\nTelefone: ");
                        scanf("%d",&colaborador.tel);
                        fflush(stdin);
                    printf("\nAno de admissão: ");
                        scanf("%d",&colaborador.anoDeAdmissao);
                        fflush(stdin);
                    printf("\nAno de demissão: ");
                        scanf("%d",&colaborador.anoDeDemisap);
                        fflush(stdin);
                    printf("\nEstado civil: ");
                        fgets(colaborador.estadoCivil,30,stdin);
                        fflush(stdin);
                    printf("\nNº de dependentes: ");
                        scanf("%d",&colaborador.numeroDeDependentes);
                        fflush(stdin);
                    printf("\nSalário: ");
                        scanf("%f",&colaborador.salario);
                        fflush(stdin);
                    printf("\nSetor: ");
                        scanf("%d",&colaborador.setor);
                        fflush(stdin);
                    printf("\nCargo: ");
                        fgets(colaborador.cargo,30,stdin);
                        fflush(stdin);

                    fwrite(&colaborador,sizeof(colaborador),1,funcionarios);

                    if(fclose(funcionarios)==0){
                        system("cls");
                        printf("Dados salvos com sucesso!\n");
                        system("pause");
                    }

                }

            break;
            case 2:

                system("cls");
                if((funcionarios = fopen("registrodefuncionarios.dat","ab+"))==NULL ||((codigos = fopen("indices.dat","ab+"))==NULL)){

                    printf("Erro ao abrir o arquivo!\n");
                    exit(1);
                }else{

                    while(fread(&colaborador,sizeof(colaborador),1,funcionarios)){
                        fread(&cod,sizeof(cod),1,codigos);
                        printf("Matricula: %d\n",cod.codigo);
                        printf("Posi: %d\n",cod.posicao);
                        printf("Nome: %sCargo: %s\n",colaborador.nome,colaborador.cargo);
                    }

                    if(fclose(funcionarios)==0 && fclose(codigos)==0){
                        printf("\n\nOperação realizada com sucesso!\n");
                        system("pause");
                    }
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
