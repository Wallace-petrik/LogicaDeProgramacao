#include <stdio.h>
#include <locale.h>

typedef struct{
    int codigoDoLivro;
    char titulo[30];
    char autor[30];
    char assunto[30];
    char editora[30];
    int ano;
    int edicao;
}Livro;

FILE *arqLivros;
Livro livro;

int main(){

    setlocale(LC_ALL,"");

    menu();

return 0;}

void menu(){
    int opcao;
    do{
        printf("1/p Cadastrar livro\n");
        printf("2/p Buscar livros por assunto\n");
        printf("3/p sair\n");
            scanf("%d",&opcao);
            fflush(stdin);
        switch(opcao){
            case 1:{
                if((arqLivros = fopen("Livros.dat","a+b"))==NULL){
                    printf("Erro ao abrir o arquivo !!!");
                    getchar();
                    exit(1);
                }

                printf("Entre com os dados do livro !!!\n");
                printf("Código\; ");
                    scanf("%d",&livro.codigoDoLivro);
                    fflush(stdin);
                printf("Titulo: ");
                    scanf("%[^\n]",&livro.titulo);
                    fflush(stdin);
                printf("Autor: ");
                    scanf("%[^\n]",&livro.autor);
                    fflush(stdin);
                printf("Assunto: ");
                    scanf("%[^\n]",&livro.assunto);
                    fflush(stdin);
                printf("Editora: ");
                    scanf("%[^\n]",&livro.editora);
                    fflush(stdin);
                printf("Ano: ");
                    scanf("%d",&livro.ano);
                    fflush(stdin);
                printf("Edição: ");
                    scanf("%d",&livro.edicao);
                    fflush(stdin);

                if((fwrite(&livro,sizeof(livro),1,arqLivros)!=1)){
                    printf("Erro ao gravar  os arquivos\n");
                }else if(!fclose(arqLivros)){
                    printf("Arquivo fechado com sucesso !!!");
                }else{
                    printf("Erro ao fechar o arquivo !!!");
                }
                getchar();
                system("cls");

            break;}
            case 2:{

            break;}
            case 3:{
                printf("Até logo !!!");
                getchar();
            break;}
            default:{
                printf("Opção invalida !!!");
                getchar();
                system("cls");}
        }
    }while(opcao!=3);
}

