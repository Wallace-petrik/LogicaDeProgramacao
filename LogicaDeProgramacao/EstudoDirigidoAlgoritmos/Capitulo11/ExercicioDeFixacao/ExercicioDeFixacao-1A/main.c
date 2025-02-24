#include <stdio.h>
#include <locale.h>

#define qtd 3

struct{
    char nome[50];
    char endereco[50];
    int telefone;
}typedef Agenda;

Agenda contato[qtd], auxContato;
int indice = 0;

void cadastrarContato();
void classificar();

int main(){

    setlocale(LC_ALL,"");

    int opcao;

    do{
        system("cls");
        printf(" ======================\n");
        printf(" |1 para cadastramento |\n");
        printf(" ======================\n");
        printf(" |2 para pesquisa      |\n");
        printf(" ======================\n");
        printf(" |3 para correção      |\n");
        printf(" ======================\n");
        printf(" |4 para remoção       |\n");
        printf(" ======================\n");
        printf(" |5 para sair          |\n");
        printf(" ======================\n : ");
            scanf("%d",&opcao);

        switch(opcao){

            case 1:{
                cadastrarContato();
                classificar();
            break;}

            case 2:{
                pesquisa();
            break;}

            case 3:{

            break;}

            case 4:{

            break;}

            case 5:{
                fflush(stdin);
                printf("\n Até logo !!! ");

            break;}

            default:{
                fflush(stdin);
                printf(" Opção invalida !!!\n");
                getchar();
            }

        }

    }while(opcao != 5);

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


void classificar(){

    int continuar;
    int fim = indice;
    if(indice >= 2){

        do{
            continuar = 0;

                for(int i = 0; i < fim-1; i++){

                    if(strcmp(contato[i].nome,contato[i+1].nome)>0){
                        auxContato = contato[i];
                        contato[i] = contato[i+1];
                        contato[i+1] = auxContato;
                        continuar = i;
                    }

                }

            fim--;
        }while(continuar != 0);

    }

}

void pesquisa(){

    system("cls");
    classificar();
    int achou = 0;
    printf("Digite o nome de deseja pesquisar: ");
        fflush(stdin);
        gets(auxContato.nome);

    for(int i = 0; i < indice; i++){
        if(strcmp(auxContato.nome,contato[i].nome)== 0){
            printf("\nNome: %s\nEndereço: %s\nTelefone: %d",contato[i].nome,contato[i].endereco,contato[i].telefone);
            achou = 1;
        }
    }
    if(achou == 0){
        printf("\nContato não encontrado !!!");
    }
    getchar();
}
