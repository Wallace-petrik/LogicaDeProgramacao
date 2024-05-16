#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somarNumeroDeContaComSeuInverso(int numeroDeContaCorrente);

int main(){
    setlocale(LC_ALL,"");

    int numeroDeContaCorrente = 0;
    int digitoVerificador = 0;

    printf("\nDigite o número da sua conta corrente com cinco dígitos: ");
        scanf("%d",&numeroDeContaCorrente);

    //digitoVerificador = calcularDigitoVerificador(numeroDeContaCorrente);

    printf("\nDígito verificador: %d",somarNumeroDeContaComSeuInverso(numeroDeContaCorrente));
    return 0;
}


int calcularDivisor(int numeroDeContaCorrente){

     int divisor = 1;

    while(numeroDeContaCorrente>0){

        numeroDeContaCorrente*= 0.1;
        divisor *=10;
    }
    return divisor/10;
}

int inverterNumero(int numeroDeContaCorrente){

    int quociente = 0;
    int resto = 0;
    int numeroInvertido = 0;

    for(int i=calcularDivisor(numeroDeContaCorrente), j = 1; i>0; i/=10, j*=10){

        quociente = numeroDeContaCorrente/i;
        resto = numeroDeContaCorrente%i;

        numeroInvertido += quociente*j;

        numeroDeContaCorrente = resto;

    }
    return numeroInvertido;
}

int somarNumeroDeContaComSeuInverso(int numeroDeContaCorrente){

    int soma = 0;

    return numeroDeContaCorrente + inverterNumero(numeroDeContaCorrente);

}
