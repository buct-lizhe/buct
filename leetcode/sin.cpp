#include <stdio.h> 
#include <math.h> 
#define PAI 3.1415926 
int main(void) { 
    double x,y; 
    for(y=-1;y <= 1;y=y+0.1) { 
        for(x=-PAI;x <=PAI;x=x+0.1) 
        { 
            if(fabs(y-sin(x)) <=0.046) 
            printf("#"); 
            else 
            printf(" "); 
        } 
        printf("\n"); 
    } 
    getchar(); 
    return 0; 
}