#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    for(int i = 3; i < 21; i++){
        if (i%2==0){
            printf("%d\n",i);
        }
    }

    return 0;
}
