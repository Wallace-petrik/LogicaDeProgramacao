#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"");

    int resp,elevadorA=0,elevadorB=0,elevadorC=0,elevadorM=0;
    int matA=0,vespA=0,notA=0;
    int matB=0,vespB=0,notB=0;
    int matC=0,vespC=0,notC=0;

    int maiorPeriodoA = 0,maiorPeriodoB = 0,maiorPeriodoC = 0,maiorAux = 0,periodoMenosUsado=0,periodoMaisUsado=0,total=0;

    int maiorG=0;
    char elevador,periodo,elevadorMaisFrequentado;


    int maiorPeriodo(int a,int b,int c){

    if(a>b){
        if(b>c){
            maiorG='M';
            return a;
        }else{
            if(a>c){
                maiorG='M';
                return a;
            }else{
                maiorG='N';
                return c;
            }
        }
    }else{
        if(b>c){
            if(a>c){
                maiorG='V';
                return b;
            }else{
                maiorG='V';
                return b;
            }
        }else{
            maiorG='N';
            return c;
        }
    }

}

    int menorPeriodo(int a,int b,int c){

    if(a<b){
        if(b<c){
            return a;
        }else{
            if(a<c){
                return a;
            }else{
                return c;
            }
        }
    }else{
        if(b<c){
            if(a<c){
                return b;
            }else{
                return b;
            }
        }else{
            return c;
        }
    }

}

    do{

        do{
            printf("\nQual elevador utiliza com mais frequencia a,b ou c? ");
                scanf(" %c",&elevador);
            printf("\nO periodo que utiliza o elevador: ");
            printf("\nm = matutino\nv = vespertino\nn = noturno\n");
                scanf(" %c",&periodo);

            if((elevador != 'a' && elevador != 'b' && elevador != 'c')||(periodo != 'm' && periodo != 'v' && periodo != 'n')){
                printf("\nDados invalidos.");
            }

            total++;

        }while((elevador != 'a' && elevador != 'b' && elevador != 'c')||(periodo != 'm' && periodo != 'v' && periodo != 'n'));

            switch(elevador){

                case 'a':
                    elevadorA++;

                    switch (periodo){
                        case 'm':
                            matA++;
                        break;
                        case 'v':
                            vespA++;
                        break;
                        case 'n':
                            notA++;
                        break;

                    }
                break;
                case 'b':
                    elevadorB++;

                    switch (periodo){
                        case 'm':
                            matB++;
                        break;
                        case 'v':
                            vespB++;
                        break;
                        case 'n':
                            notB++;
                        break;

                    }
                break;
                case 'c':
                    elevadorC++;

                    switch (periodo){
                        case 'm':
                            matC++;
                        break;
                        case 'v':
                            vespC++;
                        break;
                        case 'n':
                            notC++;
                        break;
                    }

                break;
                default :
                    printf("\nDados invalidos.");
                continue;

            }

        do{

        printf("\nDeseja continuar (1/Sim e 2/Não): ");
            scanf(" %d",&resp);

            if(resp<1 || resp>2){
                printf("\nDados invalidos.");
                getchar();
            }
        }while(resp<1 || resp>2);

    }while(resp!=2);

    if(elevadorA>elevadorB){
        if(elevadorB>elevadorC){
            elevadorMaisFrequentado='A';
            maiorPeriodo(matA,vespA,notA);
            elevadorM=elevadorB;
        }else{
            if(elevadorA>elevadorC){
                elevadorMaisFrequentado='A';
                elevadorM=elevadorC;
            }else{
                elevadorMaisFrequentado='C';
                elevadorM=elevadorA;
            }
        }
    }else{
        if(elevadorB>elevadorC){
            if(elevadorA>elevadorC){
                elevadorMaisFrequentado='B';
                elevadorM=elevadorA;
            }else{
                elevadorMaisFrequentado='B';
                elevadorM=elevadorC;
            }
        }else{
            elevadorMaisFrequentado='C';
            elevadorM=elevadorB;
        }
    }

    if(elevadorA>elevadorB && elevadorA>elevadorC){
        printf("\nO elevador %c é o mais utilizado.",elevadorMaisFrequentado);
        maiorPeriodo(matA,vespA,notA);
        printf(" O périodo com maior fluxo é %c.",maiorG);
    }else if(elevadorB>elevadorA && elevadorB>elevadorC){
        printf("\nO elevador %c é o mais utilizado.",elevadorMaisFrequentado);
        maiorPeriodo(matB,vespB,notB);
        printf(" O périodo com maior fluxo é %c.",maiorG);
    }else if(elevadorC>elevadorA && elevadorC>elevadorB){
        printf("\nO elevador %c é o mais utilizado.",elevadorMaisFrequentado);
        maiorPeriodo(matC,vespC,notC);
        printf(" O périodo com maior fluxo é %c.",maiorG);
    }else if(elevadorA == elevadorB && elevadorB == elevadorC){
        printf("\nTodos os elevadores são usados igualmente.");
    }else if(elevadorA==elevadorB){
        printf("\nOs elevadores A e B são usados igualmente.");
    }else if(elevadorA==elevadorC){
        printf("\nOs elevadores A e C são usados igualmente.");
    }else if(elevadorB==elevadorC){
        printf("\nOs elevadores B e C são usados igualmente.");
    }

    maiorPeriodoA=maiorPeriodo(matA,vespA,notA);
    maiorPeriodoB=maiorPeriodo(matB,vespB,notB);
    maiorPeriodoC=maiorPeriodo(matC,vespC,notC);

    maiorAux=maiorPeriodo(maiorPeriodoA,maiorPeriodoB,maiorPeriodoC);

    if(maiorAux==maiorPeriodoA){
        maiorPeriodo(matA,vespA,notA);
        printf("\nPeríodo mais usado é %c do elevador A",maiorG);
    }else if(maiorAux==maiorPeriodoB){
        maiorPeriodo(matB,vespB,notB);
        printf("\nPeríodo mais usado é %c do elevador B",maiorG);
    }else{
        maiorPeriodo(matC,vespC,notC);
        printf("\nPeríodo mais usado é %c do elevador C",maiorG);
    }

    periodoMaisUsado = maiorPeriodo(maiorPeriodo(matA,vespA,notA),maiorPeriodo(matB,vespB,notB),maiorPeriodo(matC,vespC,notC));
    periodoMenosUsado = menorPeriodo(menorPeriodo(matA,vespA,notA),menorPeriodo(matB,vespB,notB),menorPeriodo(matC,vespC,notC));

    printf("\nA diferença porcentual entre o mais usado dos horários e o menos usado é %.2f%% ",(float)100-((100*periodoMenosUsado)/periodoMaisUsado));

    printf("\nPorcentagem sobre o total de serviço prestados do elevador de média atulização e %f%% ",((float)elevadorM/total)*100);


    return 0;
}
