#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    for(int i = 1; i <=6; i++){
        for(int j = 1; j <= 6; j++){
            if(i+j==7){
                printf("\n%d + %d = %d",i,j,i+j);
            }
        }
    }
    return 0;
}
