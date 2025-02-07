#include <stdio.h>
#include <locale.h>
#define tam 2

struct {

    char nome[30];
    char endereco[50];
    int telefone;

} typedef Agenda;

int main(){

    setlocale(LC_ALL,"");

    Agenda minhaAgenda[tam];
    Agenda auxAgenda;
    int opcao = 0;
    int achou = 0, index;

    do{
        system("cls");
        printf("1 para Cadastrar contato~\n");
        printf("2 para Pesquisar contato\n");
        printf("3 para Ordenar por nome\n");
        printf("4 para listar contatos\n");
        printf("5 para sair\n:");
            scanf("%d",&opcao);

        switch(opcao){
            case 1:

                system("cls");
                for(int i = 0; i < tam; i++){
                    system("cls");
                    printf("Contato %d\n",i+1);
                    printf("Digite o nome: ");
                        fflush(stdin);
                        scanf("%[^\n]s",minhaAgenda[i].nome);
                    printf("Digite o Endereço: ");
                        fflush(stdin);
                        scanf("%[^\n]s",minhaAgenda[i].endereco);
                    printf("Digite o telefone: ");
                        fflush(stdin);
                        scanf("%d",&minhaAgenda[i].telefone);
                        system("pause");
                }

            break;
            case 2:

                system("cls");
                achou = 0;
                printf("Digite o nome que deseja buscar: \n");
                    fflush(stdin);
                    scanf("%[^\n]s",&auxAgenda.nome);

                for(int i = 0; i < tam; i++){
                    if(strcmp (auxAgenda.nome,minhaAgenda[i].nome)==0){
                       achou =  1;
                       index = i;
                       break;
                    }else{
                        achou =  0;
                    }
                }
                if(achou == 1){
                    printf("O nome %s foi localizado no index: %d\n",minhaAgenda[index].nome,index
                           );
                }else
                    printf("Nome não localizado\n");
                system("pause");

            break;
            case 3:

            break;
            case 4:

            break;
            case 5:
                printf("\n\tAté logo!!!");
            break;
            default:

                printf("\n\tOpição invalida!!!\n");
                system("pause");

        }

    }while(opcao != 5);

    return 0;
}
