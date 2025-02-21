#include <stdio.h>
#include <locale.h>

#define qtd 3

struct{
    char nome[50];
    char endereco[50];
    int telefone;
}typedef Agenda;

Agenda contato[qtd];
int indice = 0, fim = qtd;

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        printf(" ======================\n");
        printf(" |1 para cadastramento |\n");
        printf(" ======================\n");
        printf(" |2 para classificação |\n");
        printf(" ======================\n");
        printf(" |3 para pesquisa      |\n");
        printf(" ======================\n");
        printf(" |4 para correção      |\n");
        printf(" ======================\n");
        printf(" |5 para remoção       |\n");
        printf(" ======================\n");
        printf(" |6 para sair          |\n");
        printf(" ======================\n : ");
            scanf("%d",&opcao);

        switch(opcao){

            case 1:{
                cadastrarContato();
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
                fflush(stdin);
                printf("\n Até logo !!! ");

            break;}

            default:{
                fflush(stdin);
                printf(" Opção invalida !!!\n");
                getchar();
            }

        }

    }while(opcao != 6);

    return 0;
}

void cadastrarContato(){
    system("cls");
    fflush(stdin);
    if(indice == qtd){
        printf(" Agenda lotada !!!\n");
        getchar();
    }else{

        printf(" Digite o nome do contato: ");
            gets(contato[indice].nome);
        printf(" Digite o endereço: ");
            gets(contato[indice].endereco);
        printf(" Digite o telefone: ");
            scanf("%d",&contato[indice].telefone);

        printf(" Cadastro realizado com sucesso !!!");
        system("pause");
        indice++;

    }
}
