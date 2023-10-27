#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL,"");

    int x1,x2,y1,y2;
    float d;
    printf("\nDistância entre dois pontos\n\nEntre com as coordenadas do ponto X");
    printf("\nx':");
        scanf("%d",&x1);
    printf("x\":");
        scanf("%d:",&x2);
    printf("\nEntre com as coordenadas do ponto Y");
    printf("\ny':");
        scanf("%d",&y1);
    printf("y\":");
        scanf("%d",&y2);

    d = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    printf("\nA distância entre dois pontos é = %.1f",d);

    return 0;
}
