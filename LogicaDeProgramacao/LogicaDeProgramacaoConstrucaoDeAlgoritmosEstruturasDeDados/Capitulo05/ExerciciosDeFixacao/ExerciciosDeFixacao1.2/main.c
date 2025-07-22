#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct{
    int codigo;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}typedef Livro;

FILE *abrirArquivo(char *nomeDoArquivo,char *modoDeAbertura);

int main(){
    setlocale(LC_ALL,"");

    int opcao;

    Livro livro;
    FILE *arquivo;


    do{
        system("cls");
        printf("SISTEMA DE GERENCIAMENTO DE LIVROS\n");
        printf("1 /p Cadastrar\n");
        printf("2 /p Listar \n");
        printf("3 /p Alterar\n");
        printf("4 /p Buscar\n");
        printf("5 /p Excluir\n");
        printf("6 /p Sair\n:");
        scanf("%d",&opcao);
        fflush(stdin);

        switch(opcao){
            case 1:{
                system("cls");
                arquivo = abrirArquivo("livros.dat","ab");
                printf("\tEntre com os dados do livro !!!\n\n");
                printf("Código: ");
                    scanf("%d%*c",&livro.codigo);
                printf("Titulo: ");
                    scanf("%[^\n]%*c",&livro.titulo);
                printf("Autor: ");
                    scanf("%[^\n]%*c",&livro.autor);
                printf("Assunto: ");
                    scanf("%[^\n]%*c",&livro.assunto);
                printf("Editora: ");
                    scanf("%[^\n]%*c",&livro.editora);
                printf("Ano");
                    scanf("%d%*c",&livro.ano);
                printf("Edição: ");
                    scanf("%d%*c",&livro.edicao);
                fwrite(&livro,sizeof(livro),1,arquivo);

                if(!ferror(arquivo)){
                    if(!fclose(arquivo)){
                        printf("\nSucesso ao salvar os dados !!!");
                    }else printf("Erro ao fechar o arquivo !!! ");

                }else printf("\n\nErro ao salvar os dados.");
                getchar();
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
                printf("Até logo!!!\n");
            break;}
            default:{
                printf("Opção invalida\nTente novamente !!!\n\nPressione qualquer tecla para continuar");
                system("pause");
            }
        }

    }while(opcao!=6);

    return 0;
}

FILE *abrirArquivo(char *nomeDoArquivo,char *modoDeAbertura){
    FILE *arquivo = fopen(nomeDoArquivo,modoDeAbertura);
    if(arquivo ==NULL){
        printf("Falha ao abrir o arquivo %s!!!",nomeDoArquivo);
        system("pause");
        exit(1);
    }
    return arquivo;
}
