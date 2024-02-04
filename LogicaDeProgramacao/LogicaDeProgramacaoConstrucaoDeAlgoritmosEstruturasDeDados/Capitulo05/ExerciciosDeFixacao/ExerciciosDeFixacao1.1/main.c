#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    int codLivro;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}Livro;

int main(){
    setlocale(LC_ALL,"Portuguese");

    FILE *arquivo;

    Livro livro,aux;

    int opcao,controle;

    do{
        printf("Escolha uma opção\n\n");
        printf("1 Para adicionar um livros\n");
        printf("2 Para buscar livros por assunto\n");
        printf("3 Para sair\n");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:
                system("cls");
                arquivo = fopen("arquivo","a+b");
                if((arquivo == NULL)){
                    printf("Erro na abertura do arquivo!!!\n");
                }else{
                    printf("\nEntre com os dados do livro!\n\n");
                    printf("Código: ");
                        scanf("%d%*c",&livro.codLivro);
                    printf("Título: ");
                        fgets(livro.titulo,30,stdin);
                        livro.titulo[strcspn(livro.titulo,"\n")] = '\0';
                    printf("Autor: ");
                        fgets(livro.autor,30,stdin);
                        livro.autor[strcspn(livro.autor,"\n")] = '\0';
                    printf("Assunto: ");
                        fgets(livro.assunto,30,stdin);
                        livro.assunto[strcspn(livro.assunto,"\n")] = '\0';
                    printf("Editora: ");
                        fgets(livro.editora,30,stdin);
                        livro.editora[strcspn(livro.editora,"\n")] = '\0';
                    printf("Ano: ");
                        scanf("%d%*c",&livro.ano);
                    printf("Edição: ");
                        scanf("%d%*c",&livro.editora);

                    fwrite(&livro,sizeof(livro),1,arquivo);

                    if(ferror(arquivo)){ //ferrir retorna ZERO se nunhum erro ocorreu.
                        printf("Erro na gravação!\n");
                    }else{
                        printf("Dados gravados com sucesso!\n");
                    }

                    if(!fclose(arquivo)){
                        printf("Arquivo fechado com sucesso!\n");
                    }else{
                        printf("Erro no fechamento do arquivo!\n");
                    }
                }
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                printf("Sobre qual assunto está buscando?");
                    scanf("%s",&aux.assunto);

                arquivo = fopen("arquivo","a+b");

                if(arquivo == NULL){
                    printf("Erro na abertura do arquivo!!!\n");
                }else{

                    while(!feof(arquivo)){
                        controle = fread(&livro,sizeof(Livro),1,arquivo);
                        if(ferror(arquivo)){
                            printf("Erro na leitura do arquivo");
                        }else{
                            if((strcmp(aux.assunto,livro.assunto) == 0) && controle != 0){
                                printf("Nome do livro: %s\n",livro.titulo);
                                printf("Nome do autor: %s\n",livro.autor);
                            }
                        }
                    }
                }
                if(fclose(arquivo)){
                    printf("Erro no fechamentob do arquivo!!!\n");
                }
                system("pause");
                system("cls");
            break;
            case 3:
                system("cls");
                printf("Até logo!!!");
            break;
            default:
                system("cls");
                printf("Opção invalida!!!\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=3);

    fclose(arquivo);
    return 0;
}
