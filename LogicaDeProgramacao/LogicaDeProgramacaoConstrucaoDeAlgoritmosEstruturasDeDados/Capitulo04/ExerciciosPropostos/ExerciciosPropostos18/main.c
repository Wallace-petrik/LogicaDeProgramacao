#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

typedef struct{
    int numeroDeMatricula;
    char nome[40];
    int serie;
    int turma;
    int sexo;
    float media;
    char aprovado;
    int anoDeNascimento;
    char naturalidade[40];
}Alunos;

int main(){
    setlocale(LC_ALL,"");

    Alunos aluno[tam] = {112233,"Wallace",7,20241,"M",8.9,"S",1994,"SP"};

    int opcao;

    do{
        system("cls");
        printf(" 1 Para porcentagem de aprovados e reprovados.\n");
        printf(" 9 Para sair.\n");
        printf(" Escolha uma opção: ");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:



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

void ordenarDados (Alunos alunoParaOrdenar, )
