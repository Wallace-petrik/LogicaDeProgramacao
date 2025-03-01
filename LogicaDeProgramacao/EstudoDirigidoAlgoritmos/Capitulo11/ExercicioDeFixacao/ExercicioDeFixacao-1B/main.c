#include <stdio.h>
#include <locale.h>

#define  elem 2

void classificar();
void reprovados();
void cadastrar();
void aprovados();
void corrigir();
void pesquisa();


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
                corrigir();
            break;}

            case 3:{
                pesquisa();
            break;}

            case 4:{
                aprovados();
            break;}

            case 5:{
                reprovados();
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
        aluno[i].media =  soma / 4.0;
        soma = 0;
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

void corrigir(){

    fflush(stdin);
    system("cls");
    int soma = 0;
    int achor = 0;
    int indice = 0;
    printf("Digite o nome do aluno para corrigir: ");
        scanf("%[^\n]",&auxAluno.nome);
        fflush(stdin);
    for(int i = 0; i < elem; i++){
        if(strcmp(aluno[i].nome,auxAluno.nome)==0){
            indice = i;
            achor = 1;
            break;
        }
    }

    if(achor = 1){
        printf("Digite o nome corrigido: ");
            scanf("%[^\n]",aluno[indice].nome);
            fflush(stdin);
        for(int i = 0; i < 4; i++){
            printf("Digite a nota %d corrigida: ",i+1);
                scanf("%f",&aluno[indice].notas[i]);
                soma += aluno[indice].notas[i];
        }
        aluno[indice].media = soma/4.0;
        printf("Dados corrigidos !!!");
        getchar();
    }else{
        printf("\nAluno não encontrado !!! ");
        getchar();
    }

}

void pesquisa(){

    fflush(stdin);
    system("cls");
    int achou = 0;

    printf("Digite o nome que deseja buscar: ");
        scanf("%[^\n]",auxAluno.nome);
        fflush(stdin);

    for(int i = 0; i < 4; i++){
        if(strcmp(aluno[i].nome,auxAluno.nome)==0){
            achou = 1;
            auxAluno = aluno[i];
            break;
        }
    }
    if(achou == 0){
        printf("\n Aluno não encontrado !!!");
        getchar();
    }else{
        printf("\nNome: %s\n\n",auxAluno.nome);
        for(int i = 0; i < 4; i++){
            printf("Nota %d: %.2f\n",i+1,auxAluno.notas[i]);
        }
        printf("\nMédia: %.2f\n\n",auxAluno.media);
        getchar();
    }
}

void aprovados(){
    int achou = 0;
    for(int i = 0; i < elem; i++){
        if(aluno[i].media>=7){
            printf("Nome: %s\tAprovado\n",aluno[i].nome);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("Nenhum aluno aprovado !!!");
    }
    getchar();
}

void reprovados(){
    int achou = 0;
    for(int i = 0; i < elem; i++){
        if(aluno[i].media>=7){
            printf("Nome: %s\tReprovado\n",aluno[i].nome);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("Nenhum aluno reprovado !!!");
    }
    getchar();
}
