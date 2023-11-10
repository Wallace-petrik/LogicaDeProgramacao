#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    char resp;

    printf("\nEscolha um dos animais:\n");
    printf("\nL„o | Cavalo | Homem | Macaco | Morcego | Baleia | Avestruz |\nPinguim | Pato | ¡guia | Tartaruga | Crocodilo | Cobra | ");

    printf("\n\nResponda s/S para SIM e n/N para n„o.\n");

    printf("\n… mamÌfero? ");
        scanf(" %c",&resp);
    if(resp=='s' || resp=='S'){

        //mamÌferos

    }else{
        printf("\n… Aves? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){

            //aves

        }else{
            printf("\n… RÈpteis? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){

                printf("\nCom cosco? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal È uma TARTARUGA.");
                }else{
                    printf("\n» CarnÌvoros? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal È um CROCODILO.");
                    }else {
                        printf("\nSem patas? ");
                            scanf(" %c",&resp);
                        if(resp=='s' || resp=='S'){
                            printf("\nO animal È um COBRA.");
                        }
                    }
                }

            }else{
                printf("\nN„o foi possivel identificar o animal");
            }
        }
    }

    return 0;
}
