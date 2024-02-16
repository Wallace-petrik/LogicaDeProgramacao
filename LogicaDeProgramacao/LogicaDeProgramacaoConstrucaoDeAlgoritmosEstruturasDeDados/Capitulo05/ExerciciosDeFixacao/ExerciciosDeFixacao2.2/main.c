#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[40];
    int n;
    float n1, n2, n3, n4;
}Aluno;

int calculateOffset(int recordNumber) {
    return recordNumber * sizeof(Aluno);
}

int main(){
    setlocale(LC_ALL,"");

    int opcao,contador,controle;
    int numeroAluno , equipes[8][5];
    float media = 0,mediaE = 0;
    FILE *arq;
    Aluno aluno;

    do{
        system("cls");
        printf("1 Para cadastrar aluno\n");
        printf("2 Para listar todos os alunos\n");
        printf("3 Para buscar aluno\n");
        printf("4 Para listar a média das equipes\n");
        printf(": ");
            scanf("%d",&opcao);
            fflush(stdin);
        switch(opcao){
            case 0:

                system("cls");
                printf("Até logo\n");

            break;
            case 1:

                system("cls");
                if((arq = fopen("Arquivo.dat","ab+"))==NULL){
                    printf("Erro ao criar o arquivo!\n");
                }else{

                    printf("Digite o nome do aluno: ");
                        fgets(aluno.nome,40,stdin);
                        fflush(stdin);

                    printf("Digite as 4 notas do aluno: ");
                        scanf("%f %f %f %f", &aluno.n1, &aluno.n2, &aluno.n3, &aluno.n4);
                        fflush(stdin);
                    fwrite(&aluno,sizeof(aluno),1,arq);

                    if(fclose(arq)==0){
                        printf("Dados salvos!\n");
                        system("pause");
                    }
                }

            break;
            case 2:

                system("cls");
                if((arq = fopen("Arquivo.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo!\n");
                }else{
                    contador = 0;
                    while((fread(&aluno,sizeof(aluno),1,arq)!=0)){
                        contador++;
                        printf("\nAluno[%d]\n",contador);
                        printf("Nome: %s\n",aluno.nome);
                        printf("B1: %.2f\n",aluno.n1);
                        printf("B2: %.2f\n",aluno.n2);
                        printf("B3: %.2f\n",aluno.n3);
                        printf("B4: %.2f\n",aluno.n4);
                    }
                    if(fclose(arq)==0){
                        printf("Dados salvos!\n");
                        system("pause");
                    }
                }

            break;
            case 3:

                system("cls");
                if((arq = fopen("Arquivo.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo!\n");
                }else{
                    contador = 0;

                    while(fread(&aluno,sizeof(Aluno),1,arq)){
                        contador++;
                    }

                    printf("Digite o número do aluno: ");
                        scanf("%d",&numeroAluno);
                    fseek(arq,calculateOffset(numeroAluno-1),SEEK_SET);
                    fread(&aluno,sizeof(Aluno),1,arq);

                    if(numeroAluno>=1 && numeroAluno<= contador){
                        printf("Nome: %s",aluno.nome);
                        media = (aluno.n1+aluno.n2+aluno.n3+aluno.n4)/4.0;

                        if(media>=7){
                            printf("Aluno aprovado com média = %.2f.\n",media);
                        }else if (media<7 && media>=5){
                            printf("Aluno de recuperação!\n");
                        }else printf("Aluno reprovado\n");

                    }else{
                        printf("Aluno não encontrado!\n");
                    }
                    if(fclose(arq)==0){
                        printf("Dados salvos!\n");
                        system("pause");
                    }
                }

            break;
            case 4:

                if((arq = fopen("Arquivo.dat","ab+"))==NULL){
                    printf("Erro ao abrir o arquivo!\n");
                }else{
                    contador = 0;

                    while(fread(&aluno,sizeof(Aluno),1,arq)){
                        contador++;
                    }

                    controle = contador;
                    contador = 0;

                    for(int i  = 0; i < 8; i++){
                        for(int j = 0; j < 5; j++){
                            equipes[i][j] = contador++;
                        }

                        media = 0;

                        for(int k = 0; k < 5; k++){

                           fseek(arq,calculateOffset(equipes[i][k]),SEEK_SET);
                           fread(&aluno,sizeof(Aluno),1,arq);
                           media += (aluno.n1+aluno.n2+aluno.n3+aluno.n4)/4;
                        }
                        mediaE += media;
                        printf("Média da equipe [%d] = %.2f\n",i+1,mediaE/5.0);
                        mediaE = 0;
                    }

                    if(fclose(arq)==0){
                        printf("Fim da execução!\n");
                        system("pause");
                    }
                }

            break;
            default:
                system("cls");
                printf("Opção invalida\n");
                system("pause");
        }
    }while(opcao!=0);
    return 0;
}
