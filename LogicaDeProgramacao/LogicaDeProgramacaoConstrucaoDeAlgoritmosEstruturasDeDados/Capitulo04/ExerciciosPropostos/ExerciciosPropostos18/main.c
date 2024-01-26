#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 6

typedef struct{
    int numeroDeMatricula;
    char nome[40];
    int serie;
    int turma;
    char sexo;
    float media;
    char situacao;
    int anoDeNascimento;
    char naturalidade[40];
}Alunos;

void ordenarDados (Alunos alunoParaOrdenar[tam]);
Alunos alunoAux;

int main(){
    setlocale(LC_ALL,"");

    Alunos aluno[tam] = {112233,"Wallace",1,1001,"M",8.9,'S',1994,"SP",
                         445566,"Reis",1,1001,"M",7.5,'S',1995,"RJ",
                         778899,"Ellen",1,1001,"F",6.5,'N',2001,"RJ",
                         112233,"Wallace",1,1002,"M",8.9,'S',1994,"SP",
                         445566,"Reis",1,1002,"M",7.5,'S',1995,"RJ",
                         778899,"Ellen",1,1002,"F",6.5,'N',2001,"RJ"};

    int opcao, contador = 0, contTurma = 0;
    float AP = 0, RP = 0, aprovados = 0, reprovados = 0;

    do{
        system("cls");
        printf(" 1 Para porcentagem de aprovados e reprovados.\n");
        printf(" 9 Para sair.\n");
        printf(" Escolha uma opção: ");
            scanf("%d",&opcao);

        ordenarDados(aluno);

        switch(opcao){
            case 1:
                system("cls");

                for(int i = 0; i < tam; i++){
                    if(aluno[i].turma==aluno[i+1].turma){
                        if(aluno[i].situacao=='S'){
                            AP++;
                        }else{
                            RP++;
                        }
                        contador++;
                    }else{
                        if(aluno[i].situacao=='S'){
                            AP++;
                        }else{
                            RP++;
                        }
                        contador++;

                        aprovados += (AP/contador)*100.0;
                        reprovados += (RP/contador)*100.0;

                        printf(" Turma %d\n %.2f%% alunos aprovados\n %.2f%% alunos reprovados\n\n",aluno[i].turma,(AP/contador)*100.0,(RP/contador)*100.0);
                        contTurma++;

                        if(aluno[i].serie!=aluno[i+1].serie){
                            printf("\n Aprovados por série = %.2f\n",(float)aprovados/contTurma);
                            printf(" Reprovados por série = %.2f\n",(float)reprovados/contTurma);
                            contTurma = 0;
                        }

                        AP = 0;
                        RP = 0;
                        contador = 0;
                    }

                }
                system("pause");
            break;
            case 9:
                system("cls");
                printf("Até logo!\n");
            break;
            default :
                system("cls");
                printf("Opção inválida\n");
                system("pause");
        }

    }while(opcao!=9);

    return 0;
}

void ordenarDados (Alunos alunoParaOrdenar[tam]){
    int continua = 0, fim = tam;
    do{
        continua = 0;
        for(int i  = 0; i < tam-1; i++){
            if(alunoParaOrdenar[i].turma>alunoParaOrdenar[i+1].turma){

                alunoAux = alunoParaOrdenar[i];
                alunoParaOrdenar[i] = alunoParaOrdenar[i+1];
                alunoParaOrdenar[i+1] = alunoAux;
                continua = i;
            }
        }
        fim--;
    }while(continua !=0);
}
