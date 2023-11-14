#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

     double grao = 1;

    for(int i  = 1; i <204; i++){

        grao += grao;

    }
    printf("Pagamento %.1Lf\n",grao);
    return 0;
}
