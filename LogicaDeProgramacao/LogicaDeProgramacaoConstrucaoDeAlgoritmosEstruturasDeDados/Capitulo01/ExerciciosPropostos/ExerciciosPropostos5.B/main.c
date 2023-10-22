#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int resp = 0;

    for(int i = 0 ; i < 11 ; i++){

        resp += 23;

    }

    printf("\n12 X 4 = %d\n",resp);

    return 0;
}
