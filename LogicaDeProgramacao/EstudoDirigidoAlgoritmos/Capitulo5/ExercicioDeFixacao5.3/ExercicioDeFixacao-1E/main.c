#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    for(int i = 1; i <= 50; i++){
        if(i%5==0){
            printf("%d\n",i);
        }
    }
    return 0;
}
