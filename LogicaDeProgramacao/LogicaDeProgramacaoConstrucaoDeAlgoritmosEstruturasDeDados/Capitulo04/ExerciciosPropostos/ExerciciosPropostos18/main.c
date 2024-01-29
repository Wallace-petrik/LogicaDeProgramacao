#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

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

    Alunos aluno[tam] = {112233,"Wallace",1,1001,'F',8.9,'S',1994,"RJ",
                         445566,"Reis",1,1001,'M',7.5,'S',1995,"RJ",
                         778899,"Ellen",1,1001,'M',4.5,'N',2001,"RJ",
                         112233,"Wallace",1,1002,'M',8.9,'S',1994,"NI",
                         445566,"Reis",1,1002,'F',7.5,'S',1995,"RJ",
                         778899,"Ellen",1,1002,'F',4.5,'N',2001,"RJ"};

    int opcao, contador = 0, contTurma = 0, soma =0, estrangeiros = 0;
    float AP = 0, RP = 0, aprovados = 0, reprovados = 0 , sexoM = 0, sexoF = 0 ,masculino = 0, feminino = 0;

    do{
        system("cls");
        printf(" 1 Para porcentagem de aprovados e reprovados.\n");
        printf(" 2 Para porcentagem de alunos do sexo masculino e feminino.\n");
        printf(" 3 Para média de cada série.\n");
        printf(" 4 Para o percentual de alunos de outra cidade.\n");
        printf(" 5 Para o percentual de alunos repetentes.\n");
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
                            printf(" Reprovados por série = %.2f\n ",(float)reprovados/contTurma);
                            contTurma = 0;
                        }

                        AP = 0;
                        RP = 0;
                        contador = 0;
                    }

                }
                aprovados = 0;
                reprovados = 0;
                system("pause");

            break;
            case 2:

                system("cls");
                for(int i = 0; i < tam; i++){
                    if(aluno[i].turma==aluno[i+1].turma){
                        if(aluno[i].sexo=='M'){
                            sexoM++;
                        }else{
                            sexoF++;
                        }
                        contador++;
                    }else{
                        if(aluno[i].sexo=='M'){
                            sexoM++;
                        }else{
                            sexoF++;
                        }
                        contador++;

                        masculino += (sexoM/contador)*100.0;
                        feminino += (sexoF/contador)*100.0;

                        printf(" Turma %d\n %.2f%% alunos do sexo masculino\n %.2f%% alunos do sexo feminino\n\n",aluno[i].turma,(sexoM/contador)*100.0,(sexoF/contador)*100.0);

                        contTurma++;

                        if(aluno[i].serie!=aluno[i+1].serie){
                            printf("\n Sexo masculino por série = %.2f\n",(float)masculino/contTurma);
                            printf(" Sexo feminino por série = %.2f\n ",(float)feminino/contTurma);
                            contTurma = 0;
                        }

                        sexoM = 0;
                        sexoF = 0;
                        contador = 0;
                    }

                }
                masculino = 0;
                feminino = 0;
                system("pause");

            break;
            case 3:

                system("cls");
                for(int i = 0; i < tam; i++){
                    if(aluno[i].serie==aluno[i+1].serie){
                        soma += 2024 - aluno[i].anoDeNascimento;
                        contador++;
                    }else{

                        soma += 2024 - aluno[i].anoDeNascimento;
                        contador++;
                        printf(" A média da série de idade da %d é = %d anos\n ",aluno[i].serie,soma/contador);
                        soma = 0;
                        contador = 0;
                    }
                }
                system("pause");

            break;
            case 4:

                system("cls");
                for(int i = 0; i < tam; i++){

                    if(strcmp(aluno[i].naturalidade,"RJ")!=0){
                        estrangeiros++;
                    }
                }
                printf(" A porcentagem de alunos estrangeiros é de %.2f%%\n ",(float)(estrangeiros*100)/tam);
                system("pause");

            break;
            case 5:
                system("cls");
                contador = 0;
                for(int i = 0; i < tam; i++){
                    contTurma++;
                    if(aluno[i].turma==aluno[i+1].turma){

                        if(aluno[i].media<6){
                            contador++;

                        }

                    }else{

                        if(aluno[i].media<6){
                            contador++;

                        }

                        if(aluno[i].turma!=aluno[i+1].turma){

                            printf("A porcentagem de alunos reprovados da tuma %d é de  %.2f%%\n",aluno[i].turma,(contador*100.0)/contTurma);
                            contTurma = 0;
                        }

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
