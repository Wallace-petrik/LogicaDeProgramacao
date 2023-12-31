#include <stdio.h>
#include <math.h>
#include <locale.h>

#define max 5

int main(){
    setlocale(LC_ALL,"");

    float alturas[max],somatoria = 0,variancia = 0;
    float media, mediana = 0, desvioPadrao;
    int moda = 0, fim, maior = 0, contador = 0;

    for (int i = 0; i < max; i++){
        printf("\nEntre com os dados da %d� altura: ",i+1);
            scanf("%f",&alturas[i]);

            somatoria += alturas[i];
    }

    bubblesort(alturas,max);
    media = somatoria/max;

    for(int i = 0; i < max; i++){

        variancia += pow(alturas[i]-media,2);

    }
    variancia = variancia/max;

    desvioPadrao = sqrt(variancia);

    fim = max;

    for(int i = 0; i < fim; i++){
        for(int j = 0; j < fim; j++){
            if((alturas[i]==alturas[j])&& i!=j){
                contador++;
            }
        }
        if(contador > maior){
            moda = i;
            maior = contador;
        }
    }

    if(max%2==0){
        mediana = (alturas[(max/2)-1]+alturas[(max/2)])/2;
    }else{
        mediana = (alturas[max/2]);
    }

    printf("\nM�dia = %.1f",media);
    printf("\nDesvio Padr�o = %.1f",desvioPadrao);
    contador==0 ? printf("\nModa = ***") : printf("\nModa = %.1f",alturas[moda]);
    printf("\nMediana = %.1f\n",mediana);

    return 0;
}
void bubblesort(float *vet,int tam){
    int controlador = 0;
    do{
        controlador = 0;
        for(int i = 0; i < tam - 1; i++){
            if(vet[i]>vet[i+1]){

                vet[i+1] =  vet[i+1] + vet[i];
                vet[i] = vet[i+1] - vet[i];
                vet[i+1] = vet[i+1] - vet[i];

                controlador = 1;
            }
        }
        tam--;
    }while(controlador != 0);

}
