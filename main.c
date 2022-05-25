#include <stdio.h>
#include <math.h>

float LaPlace(int lin, int col, int matriz[lin][col]){
    if(lin == 2) return (* * matriz * *( * matriz+3)) - ( * (*matriz+1)  * * ( * matriz+2));
    int i = 0, j, n;
    float determinante = 0;
    while(i < col){
        int submatriz[lin-1][col-1], k = 1;
        for(j = col, n = 0; j<(lin*col); j++, n++){
            if(i == (j - (k*col))){
                if(((j+1)%col) == 0) k++;
                n--;
                continue;
            }
            *(*submatriz+n) = *(*matriz+j);
            if(((j+1)%col) == 0) k++;
        }
        determinante += *(*matriz+i)*pow((-1),(i+1)+1)*LaPlace(lin-1, col-1, submatriz);
        i++;
    }
    return determinante;
}

int main(){

  
int mat[4][4] = {2 , 3 , -1 , 2 , 0 , 4 , -3 , 5 , 1 , 2, 1, 3 ,0 , 4 , 1 , 0};

printf("%f" , LaPlace(4 , 4,  mat));








  return 0;
}