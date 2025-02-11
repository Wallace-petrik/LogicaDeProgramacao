#include <stdio.h>
#include <locale.h>
#define tam 1

struct{
    char nome[30];
    float notas[4];
}typedef Aluno;

int main(){

    setlocale(LC_ALL,"");

    int opc = 4;
    Aluno aluno[tam];

    do{
        system("cls");
        printf("1 para cadastrar alunos.\n");
        printf("2 para buscar aluno.\n");
        printf("3 para listar alunos\n");
        printf("4 para sair.\n:");
            scanf("%d",&opc);

        switch(opc){

            case 1:{

                int fim = tam;
                int continua = 0;
                Aluno auxAluno;
                system("cls");
                for(int i = 0; i < tam; i++){

                    fflush(stdin);
                    printf("Digite o nome do aluno: ");
                        scanf("%[^\n]",aluno[i].nome);

                    printf("Digite as notas do aluno: ");
                    for(int j = 0; j < 4; j++){
                        scanf("%f",&aluno[i].notas[j]);
                    }

                }

                do{
                    continua = 0;

                    for(int i = 0; i < tam-1; i++){
                        if(strcmp(aluno[i].nome,aluno[i+1].nome)>0){
                            auxAluno = aluno[i];
                            aluno[i] = aluno[i+1];
                            aluno[i+1] = auxAluno;
                            continua = i;
                        }
                    }

                    fim--;
                }while(continua != 0);

            break;}

            case 2:{
                system("cls");
                Aluno auxAluno;
                float media = 0;
                char situacao[10];
                int achou = 0;
                fflush(stdin);
                printf("Digite o nome do aluno: ");
                    scanf("%[^\n]",auxAluno.nome);

                for(int i = 0; i < tam; i++){
                    if(strcmp(auxAluno.nome,aluno[i].nome)==0){
                        printf("Aluno encontrado!!!\n");
                        for(int j = 0; j < 4; j++){
                            media+= aluno[i].notas[j];
                        }
                        media /= 4;
                        if(media > 5){
                            strcpy(situacao,"Aprovado");
                        }else{
                           strcpy(situacao,"Reprovado");
                        }
                        printf("Nome: %s\nNota: %.2f\nSituação: %s\n",aluno[i].nome,media,situacao);
                        achou = 1;
                        break;
                    }
                }
                if(achou = 0){
                    printf("Aluno não encontrado\n");
                }
                system("pause");
            break;}

            case 3:{

            break;}

            case 4:{
                printf("\nAté logo !!!\ngit sta");
                fflush(stdin);
            break;}

            default:{
                printf("\nOpção invalida!!!\nPressione ENTER para continuar...\n");
                fflush(stdin);
                getchar();
            }

        }
    }while(opc != 4);

    return 0;
}
