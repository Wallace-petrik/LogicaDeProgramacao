#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int resp = 175;
    int cont = 0;
    for(;;){

        resp -= 7;
        cont++;

        if(resp==0){
            printf("\n175 / 7 = %d\n",cont);
            break;
        }
    }



    return 0;
}
