#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 50

typedef struct{

    char nome[tam];
    int numero;
    float n1,n2,n3,n4;

}Alunos;

int main(){
    setlocale(LC_ALL,"");

    FILE *arqDiario;

    Alunos aluno, alunoAux;

    int opcao = 0, controle =0;

    do{
        system("cls");
        printf("1 para registrar aluno\n");
        printf("2 para buscar aluno\n");
        printf("\nDigite uma opção: ");
            scanf("%d",&opcao);
            fflush(stdin);

        switch(opcao){
            case 0:
                system("cls");
                printf("Até logo\n");
                system("pause");
            break;
            case 1:

                system("cls");
                printf("Entre com o nome do aluno: ");
                    scanf("%[^\n]",&aluno.nome);
                printf("Digite o número: ");
                    scanf("%d",&aluno.numero);
                printf("Digite nota 1: ");
                    scanf("%f",&aluno.n1);
                fflush(stdin);
                if(aluno.numero>0){
                    aluno.n2 = 0;
                    aluno.n3 = 0;
                    aluno.n4 = 0;
                }

                if((arqDiario = fopen("arqDiario.txt","a+b"))==NULL){
                    printf("Erro ao abrir o arquivo\n");
                    exit(1);
                }else{
                    fwrite(&aluno,1,sizeof(aluno),arqDiario);
                }

                if(fclose(arqDiario)==0){
                    printf("Aluno registrado com sucesso\n");
                    system("pause");
                }

            break;
            case 2:

                if((arqDiario = fopen("arqDiario.txt","r+b"))==NULL){
                    printf("Erro ao abrir o arquivo");
                    exit(1);
                }else{
                    printf("Digite o número do aluno que esta buscando: ");
                        scanf("%d",&alunoAux.numero);
                    while(fread(&aluno,sizeof(aluno),1,arqDiario)){
                        if(aluno.numero==alunoAux.numero){
                            controle = 1;
                            printf("\nNome: %s\nPossui nota: %.1f",aluno.nome,aluno.n1);
                            break;
                        }
                    }

                }

                if(fclose(arqDiario)==0){
                    if(controle = 1){
                        printf("\nAluno encontrado com sucesso\n");
                    }else{
                        printf("\nAluno não encontrado\n");
                    }
                    system("pause");
                }

            break;
            default:
                system("cls");
                printf("Opção invalida!!!\n");
                system("pause");

        }

    }while(opcao != 0);

    return 0;
}
