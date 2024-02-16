#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    int matricula;
    int rg;
    char nome[40];
    char nascimento[11];
    char sexo;
    int curso;
}Aluno;

int main(){
    setlocale(LC_ALL,"");

    FILE *arq;
    Aluno aluno;
    int opcao;

    do{
        printf("1 para cadastrar aluno\n");
            scanf("%d",&opcao);
        switch(opcao){
            case 0:

                system("cls");
                printf("Até logo!");

            break;
            case 1:

                system("cls");
                if((arq = fopen("arquivo.dat","ab+"))==NULL){
                    printf("Erro ao criar o arquivo!\n");
                }else{

                    printf("Digite os dados do aluno!\n");
                    printf("Matrícula: ");
                        scanf("%d",&aluno.matricula);
                    printf("RG: ");
                        scanf("%d",&aluno.rg);
                        fflush(stdin);
                    printf("Nome: ");
                        fgets(aluno.nome,40,stdin);
                        fflush(stdin);
                    printf("Data de nascimento: ");
                        fgets(aluno.nascimento,11,stdin);
                        fflush(stdin);
                    printf("Sexo: ");
                        scanf("%c",&aluno.sexo);
                        fflush(stdin);
                    printf("Curso: ");
                        scanf("%d",&aluno.curso);
                        fflush(stdin);

                    fwrite(&aluno,sizeof(aluno),1,arq);

                    if(fclose(arq)==0){
                        printf("Dados salvos com sucesso!\n");
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
