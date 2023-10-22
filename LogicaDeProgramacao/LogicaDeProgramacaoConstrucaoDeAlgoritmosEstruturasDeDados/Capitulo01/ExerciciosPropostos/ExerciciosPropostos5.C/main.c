#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int resp = 10;
    int cont = 0;
    for(;;){

        resp -= 2;
        cont++;

        if(resp==0){
            printf("\n10 / 2 = %d\n",cont);
            break;
        }
    }



    return 0;
}

