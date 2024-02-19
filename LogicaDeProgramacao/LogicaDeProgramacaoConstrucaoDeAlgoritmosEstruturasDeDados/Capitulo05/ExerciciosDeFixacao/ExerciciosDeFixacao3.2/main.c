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

typedef struct{
    int codigo;
    char nomeDoCurso[30];
}Curso;

int calculateOffset(int recordNumber) {
    return recordNumber * sizeof(Aluno);
}

int main(){
    setlocale(LC_ALL,"");

    FILE *arq,*arqCursos;
    Aluno aluno;
    Curso curso;
    int opcao,controle,contador;

    do{
        system("cls");
        printf("1 para cadastrar aluno\n");
        printf("2 para cadastrar cursos\n");
        printf("3 para listar alunos por curso\n");
        printf("4 para listar alunos do sexo masculino\n");
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
            case 2:

                system("cls");
                if((arqCursos = fopen("cursos.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo!\n");
                }else{

                    printf("Digite um código para o curso: ");
                        scanf("%d",&curso.codigo);
                        fflush(stdin);
                    printf("\nDigite o nome do curso: ");
                        fgets(curso.nomeDoCurso,30,stdin);
                        fflush(stdin);

                    fwrite(&curso,sizeof(Curso),1,arqCursos);

                    if(fclose(arqCursos)==0){
                        printf("Curso cadastrado com sucesso!\n");
                        system("pause");
                    }
                }

            break;
            case 3:

                system("cls");
                if((arq = fopen("arquivo.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo!\n");
                }else{
                    for(int i = 1; i <= 3; i++){
                        fseek(arq,0,SEEK_SET);

                        if(i==3){
                            printf("\nMatemática\n\n");
                        }else if(i==2){
                            printf("\nDireíto\n\n");
                        }else{
                            printf("\nPedagogía\n\n");
                        }

                        while((fread(&aluno,sizeof(aluno),1,arq)!=0)){
                            if(aluno.curso==i){
                                printf("Nome: %s",aluno.nome);
                            }
                        }
                    }
                    if(fclose(arq)==0){
                        printf("\n\nDados salvos!\n");
                        system("pause");
                    }
                }

            break;
            case 4:

                system("cls");
                if((arq = fopen("arquivo.dat","ab+"))==NULL || (arqCursos = fopen("cursos.dat","ab+"))==NULL){
                    printf("Erro ao abrir os arquivos\n");
                }else{

                    while(fread(&aluno,sizeof(Aluno),1,arq)){

                        if(aluno.sexo=='M'||aluno.sexo=='m'){

                            printf("Aluno: %s",aluno.nome);

                            fseek(arqCursos,(aluno.curso-1)*sizeof(curso),SEEK_SET);
                            fread(&curso,sizeof(Curso),1,arqCursos);
                            printf("Cuso: %s\n",curso.nomeDoCurso);

                        }

                    }

                    if((fclose(arq)==0)&&(fclose(arqCursos)==0)){
                        printf("Operação realizada com sucesso!\n");
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
