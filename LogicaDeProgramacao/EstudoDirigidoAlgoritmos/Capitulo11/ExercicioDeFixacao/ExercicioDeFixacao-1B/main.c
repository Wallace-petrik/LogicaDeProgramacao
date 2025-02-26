#include <stdio.h>
#include <locale.h>

#define  elem 3

void classificar();
void cadastrar();

struct{
    char nome[50];
    float notas[4];
    float media;
}typedef Alunos;

Alunos aluno[elem];
Alunos auxAluno;

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        fflush(stdin);
        printf("\n1 para cadastrar");
        printf("\n2 para corrigir");
        printf("\n3 para pesquisar");
        printf("\n4 para listar Ap");
        printf("\n5 para listar Rp");
        printf("\n6 para sair\n:");
            scanf("%d%*c",&opcao);
            fflush(stdin);

        switch(opcao){
            case 1:{
                cadastrar();
            break;}

            case 2:{

            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{

            break;}

            case 6:{
                printf("\nAté logo !!!");
                getchar();
            break;}

            default:{
                printf("\n Opção invalida !!!");
                getchar();
            break;}
        }

    }while(opcao != 6);

    return 0;
}

void cadastrar(){

    fflush(stdin);
    system("cls");
    int soma = 0;
    for(int i = 0; i < elem; i++){
        printf("Digite o nome do aluno: ");
            gets(aluno[i].nome);
        printf("Digite as notas do aluno !\n");
        for(int j = 0; j < 4; j++){
            printf("Nota %d: ",j+1);
            scanf("%f",&aluno[i].notas[j]);
            soma += aluno[i].notas[j];
        }
        aluno[i].media =  soma / 4;
        fflush(stdin);
    }
    classificar();
    printf("Alunos cadastrardos com sucesso !!!");
    getchar();
}

void classificar(){

    int fim = elem;
    int continua;

    do{
        continua = 0;
        for(int i = 0; i < fim-1; i++){
            if(strcmp(aluno[i].nome,aluno[i+1].nome)>0){
                auxAluno = aluno[i];
                aluno[i] = aluno[i+1];
                aluno[i+1] = auxAluno;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);

}
