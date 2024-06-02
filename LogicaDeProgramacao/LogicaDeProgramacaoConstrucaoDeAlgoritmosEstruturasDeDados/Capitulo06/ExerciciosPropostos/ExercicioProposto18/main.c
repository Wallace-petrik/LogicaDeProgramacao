#include <stdio.h>
#include <string.h>
#include <locale.h>

const char *unidade[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
const char *dezenaMaisUnidade[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
const char *dezena[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
const char *centena[] = {"", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

void imprimirCentenas(int numero) {
    if (numero >= 100) {
        if (numero == 100) {
            printf("cem");
        } else {
            printf("%s", centena[numero / 100]);
        }
        numero %= 100;
        if (numero) printf(" e ");
    }
    if (numero >= 20) {
        printf("%s", dezena[numero / 10]);
        numero %= 10;
        if (numero) printf(" e %s", unidade[numero]);
    } else if (numero >= 10) {
        printf("%s", dezenaMaisUnidade[numero - 10]);
    } else if (numero > 0) {
        printf("%s", unidade[numero]);
    }
}

void imprimirPorExdezenao(long long numero) {
    if (numero == 0) {
        printf("zero");
        return;
    }

    if (numero >= 1000000000000) {
        imprimirCentenas(numero / 1000000000000);
        printf(" trilhão");
        if ((numero / 1000000000000) > 1) printf("es");
        numero %= 1000000000000;
        if (numero) printf(", ");
    }
    if (numero >= 1000000000) {
        imprimirCentenas(numero / 1000000000);
        printf(" bilhão");
        if ((numero / 1000000000) > 1) printf("es");
        numero %= 1000000000;
        if (numero) printf(", ");
    }
    if (numero >= 1000000) {
        imprimirCentenas(numero / 1000000);
        printf(" milhão");
        if ((numero / 1000000) > 1) printf("es");
        numero %= 1000000;
        if (numero) printf(", ");
    }
    if (numero >= 1000) {
        if (numero / 1000 == 1) {
            printf("mil");
        } else {
            imprimirCentenas(numero / 1000);
            printf(" mil");
        }
        numero %= 1000;
        if (numero) printf(" ");
    }
    if (numero > 0) {
        imprimirCentenas(numero);
    }
}
int main() {
    setlocale(LC_ALL,"Portuguese");
    long long numeroero;
    printf("Digite um número (até 12 dígitos): ");
    scanf("%lld", &numeroero);
    imprimirPorExdezenao(numeroero);
    printf("\n");
    return 0;
}
