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



    return 0;
}
