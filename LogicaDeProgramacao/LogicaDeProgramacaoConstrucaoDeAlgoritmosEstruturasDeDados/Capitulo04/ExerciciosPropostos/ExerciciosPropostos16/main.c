#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define Tam_Max 5

typedef struct{
    char proprietario[40];
    char modelo[40];
    char placa[9];
    char cor[40];
    int combustivel;
    int chassi;
    int anor;
}Veiculo;

int main(){
    setlocale(LC_ALL,"");

    Veiculo carros[Tam_Max] = {"Wallace","Astra","AES-1832","Prata",3,123321,2014};

    int controle = 0, contador = 0, opcao, soma, chassi;

    do{
        system("cls");
        printf("Escolha uma opção\n");
        printf("\n1/Para listar proprietários de carros com anos posterios 1980 movidos a diesel.");
        printf("\n2/Para listar todas as placas que comecem com a letra A e termina com 0, 2, 4 ou 7.");
        printf("\n3/Para listar modelo e cor de carros que aplaca tem como segunda letra uma goval.");
        printf("\n4/Para troca de propiretário com o fornecimento do número de chassi.");
        printf("\nDigite uma opção: ");
            scanf("%d",&opcao);
            controle = 0;
            contador = 0;
        switch(opcao){
            printf("\nPassei aqui");
            case 1:
                system("cls");
                for(int i = 0; i < Tam_Max; i++){ // 1 para álcool, 2 para gasolina e 3 para diesel.
                    if(carros[i].anor>=1980 && carros[i].combustivel==3){
                        contador++;
                        printf("%dº Proprietário  = %s\n",contador,carros[i].proprietario);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhum proprietário encontrado\n");
                }
                system("pause");
                system("cls");
            break;
            case 2:
                system("cls");
                for(int i = 0; i < Tam_Max; i++){
                    if((carros[i].placa[0]=='a'||carros[i].placa[0]=='A')&&
                       (carros[i].placa[7]=='0'||carros[i].placa[7]=='2'||
                        carros[i].placa[7]=='4'||carros[i].placa[7]=='7')){

                        printf("Proprietário = %s\n",carros[i].proprietario);
                        printf("Placa = %s \n",carros[i].placa);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhum placa encontrado\n");
                }
                system("pause");
                system("cls");
            break;
            case 3:
                system("cls");
                for(int i = 0; i < Tam_Max; i++){
                    for(int j = 4; j < 8; j ++){
                        soma+=carros[i].placa[j]-'0';
                    }
                    if((carros[i].placa[1]=='a'||carros[i].placa[1]=='e'||carros[i].placa[1]=='i'||carros[i].placa[1]=='o'||carros[i].placa[1]=='u'||
                        carros[i].placa[1]=='A'||carros[i].placa[1]=='E'||carros[i].placa[1]=='I'||carros[i].placa[1]=='O'||carros[i].placa[1]=='U')&&
                        soma%2==0){
                        printf("Modelo = %s\n",carros[i].modelo);
                        printf("Cor = %s \n\n",carros[i].cor);
                        controle = 1;
                    }
                }
                if(controle==0){
                    printf("Nenhum carro encontrado\n");
                }
                system("pause");
                system("cls");
            break;
            case 4:
                do{
                    system("cls");
                    printf("Entre com o numero do chassi: ");
                        scanf("%d",&chassi);
                        for(int i = 0; i < Tam_Max; i++){
                            if(carros[i].chassi==chassi && carros[i].placa[4]!='0'&&carros[i].placa[5]!='0'&&
                                carros[i].placa[6]!='0'&&carros[i].placa[7]!='0'){
                                system("cls");
                                printf("Entre com o novo nome do proprietário: ");
                                    scanf("%s",carros[i].proprietario);
                                printf("\nProprietário alterado com sucesso.");
                                printf("\nNome do novo proprietário = %s\n",carros[i].proprietario);
                                system("pause");
                                system("cls");
                                controle = 1;
                            }
                        }

                        if(controle==0){
                            printf("\nCarro não encontrado.\n");
                            printf("0/Para tentar novamente\n1/Para sair");
                                scanf("%d",&controle);
                        }

                }while(controle==0);
            break;
            default:
                system("cls");
                printf("Opção invalida!\nTente novamente.\n");
                system("pause");
                system("cls");
        }
    }while(opcao!=10);
    return 0;
}
