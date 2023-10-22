#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int resp = 0;

    for(int i = 0 ; i < 4 ; i++){

        resp += 12;

    }

    printf("\n12 X 4 = %d\n",resp);

    return 0;
}
