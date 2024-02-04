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

    int opcao,controle,contador = 0;

    do{
        printf("Escolha uma opção\n\n");
        printf("1 Para adicionar um livros\n");
        printf("2 Para listar todos os arquivos.\n");
        printf("3 Para buscar livros por assunto\n");
        printf("4 Para alterar dados de um livro\n");
        printf("5 Para excluir um livros\n");
        printf("6 Para sair\n");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:

                system("cls");
                arquivo = fopen("arquivo.dat","a+b");
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

                    if(ferror(arquivo)){ //ferror retorna ZERO se nunhum erro ocorreu.
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
                contador = 0;
                arquivo = fopen("arquivo.dat","a+b");
                if(arquivo == NULL){
                   printf("Erro na abertura do arquivo!!!\n");
                }else{
                    while(!feof(arquivo)){
                        controle = fread(&livro,sizeof(livro),1,arquivo);
                        if(controle!=0){
                            printf("Livro  = [%d]\nCódigo = %d\nTítulo = %s\nAutor  = %s\n\n",(contador++)+1,livro.codLivro,livro.titulo,livro.autor);
                        }
                    }
                    if(fclose(arquivo)){
                    printf("Erro no fechamentob do arquivo!!!\n");
                    }
                    system("pause");
                    system("cls");
                }

            break;
            case 3:

                system("cls");
                printf("Sobre qual assunto está buscando?");
                    scanf("%s",&aux.assunto);
                arquivo = fopen("arquivo.dat","a+b");

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
            case 4:

                system("cls");
                arquivo = fopen("arquivo.dat","rb+");
                if(arquivo == NULL){
                    printf("Erro na abertura do arquivo!!!\n");
                }else{
                    do{
                        printf("Escolha uma opção\n\n");
                        printf("1 Para alterar título do livro\n");
                        printf("2 Para alterar autor do livro\n");
                        printf("3 Para voltar para o menu anterior\n");
                            scanf("%d",&opcao);
                            contador = 0;
                            controle = 0;
                        switch(opcao){
                            case 1:
                                system("cls");
                                printf("Digite o código do livro que deseja alterar: ");
                                    scanf("%d",&aux.codLivro);
                                    fflush(stdin);
                                while(fread(&livro,sizeof(livro),1,arquivo)){
                                    if(aux.codLivro==livro.codLivro){
                                        contador++;
                                        printf("\nTítulo atual: %s\n",livro.titulo);
                                         printf("Digite o novo título do livro: ");
                                            fgets(livro.titulo,30,stdin);
                                            livro.titulo[strcspn(livro.titulo,"\n")] = '\0';
                                            fseek(arquivo,-1*sizeof(livro),SEEK_CUR);
                                            fwrite(&livro,sizeof(livro),1,arquivo);
                                            controle++;
                                            break;
                                    }

                                }
                                if(contador==0){
                                    printf("Livro não encontrado!!!\n");
                                }else{
                                    printf("Dados atualizados con sucesso!!!\n");
                                    system("pause");
                                    system("cls");
                                }
                                if(fclose(arquivo)!= 0){
                                    printf("Erro no fechamentob do arquivo!!!\n");
                                }

                            break;
                            case 2:
                                system("cls");
                                printf("Digite o código do livro que deseja alterar: ");
                                    scanf("%d",&aux.codLivro);
                                    fflush(stdin);
                                while(fread(&livro,sizeof(livro),1,arquivo)){
                                    if(aux.codLivro==livro.codLivro){
                                        contador++;
                                        printf("\nAutor atual: %s\n",livro.autor);
                                         printf("Digite o novo autor do livro: ");
                                            fgets(livro.autor,30,stdin);
                                            livro.autor[strcspn(livro.autor,"\n")] = '\0';
                                            fseek(arquivo,-1*sizeof(livro),SEEK_CUR);
                                            fwrite(&livro,sizeof(livro),1,arquivo);
                                            controle++;
                                            break;
                                    }

                                }

                                if(contador==0){
                                    printf("Livro não encontrado!!!\n");
                                }else{
                                    printf("Dados atualizados con sucesso!!!\n");
                                    system("pause");
                                    system("cls");
                                }
                                if(fclose(arquivo)!= 0){
                                    printf("Erro no fechamentob do arquivo!!!\n");
                                }

                            break;
                            case 3:
                                system("cls");
                            break;
                            default:
                                system("cls");
                                printf("Opção invalida!!!\n");
                                system("pause");
                                system("cls");
                        }

                    }while(opcao!=3);
                }

            break;
            case 5:



            break;
            case 6:
                system("cls");
                printf("Até logo!!!");
            break;
            default:
                system("cls");
                printf("Opção invalida!!!\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=6);

    fclose(arquivo);
    return 0;
}
