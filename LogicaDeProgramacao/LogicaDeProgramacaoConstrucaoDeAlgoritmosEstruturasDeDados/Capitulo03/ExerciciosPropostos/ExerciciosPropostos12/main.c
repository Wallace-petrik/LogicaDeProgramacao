#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    char resp;

    printf("\nEscolha um dos animais:\n");
    printf("\nLão | Cavalo | Homem | Macaco | Morcego | Baleia | Avestruz |\nPinguim | Pato | Águia | Tartaruga | Crocodilo | Cobra | ");

    printf("\n\nResponda s/S para SIM e n/N para não.\n");

    printf("\nÉ mamífero? ");
        scanf(" %c",&resp);
    if(resp=='s' || resp=='S'){
        printf("\nQuadrúpedes? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){
            printf("\nCarnívoros? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nO animal é um LEÃO.");
            }else{
                printf("\nHerbíveros? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é um CAVALO.");
                }else{
                    printf("\nNão foi possivel identificar o animal");
                }
            }
        }else{
            printf("\nBípedes? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nOnívoros? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é um HOMEM.");
                }else{
                    printf("\nFrutívaros? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal é um MACACO.");
                    }else{
                        printf("\nNão foi possivel identificar o animal");
                    }
                }
            }else {
                printf("\nVoadores? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é um MORCEGO.");
                }else{
                    printf("\nAquáticos? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal é uma BALEIA.");
                    }else{
                        printf("\nNão foi possivel identificar o animal");
                    }
                }
            }
        }

    }else{
        printf("\nÉ Aves? ");
            scanf(" %c",&resp);
        if(resp=='s' || resp=='S'){
            printf("\nNão voadores? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){
                printf("\nTropicais? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é um AVESTRUZ.");
                }else{
                    printf("\nPolares? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal é um PINGUIM.");
                    }else{
                        printf("\nNão foi possivel identificar o animal");
                    }
                }
            }else{
                printf("\nNadadores? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é um PATO.");
                }else{
                    printf("\nDe rapina? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal é uma ÁGUIA.");
                    }else{
                        printf("\nNão foi possivel identificar o animal");
                    }
                }
            }

        }else{
            printf("\nÉ Répteis? ");
                scanf(" %c",&resp);
            if(resp=='s' || resp=='S'){

                printf("\nCom cosco? ");
                    scanf(" %c",&resp);
                if(resp=='s' || resp=='S'){
                    printf("\nO animal é uma TARTARUGA.");
                }else{
                    printf("\nÈ Carnívoros? ");
                        scanf(" %c",&resp);
                    if(resp=='s' || resp=='S'){
                        printf("\nO animal é um CROCODILO.");
                    }else {
                        printf("\nSem patas? ");
                            scanf(" %c",&resp);
                        if(resp=='s' || resp=='S'){
                            printf("\nO animal é um COBRA.");
                        }else{
                            printf("\nNão foi possivel identificar o animal");
                        }
                    }
                }

            }else{
                printf("\nNão foi possivel identificar o animal");
            }
        }
    }

    return 0;
}
