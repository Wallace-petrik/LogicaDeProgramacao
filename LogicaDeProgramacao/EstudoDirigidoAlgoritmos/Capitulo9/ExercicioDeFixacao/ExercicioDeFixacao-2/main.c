#include <stdio.h>
#include <locale.h>
#define tam 3

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
