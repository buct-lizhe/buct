#include<iostream>
#include<math.h>
using namespace std;
#define LL long long 


// mode = (a*b) % M 等价于 ( a%M )  * ( b % M ) % M

//快速幂求模
long long quickmode( int a , int b , int M ){   // a^b%M
    long long ans = 1;
    long long base = a % M;
    while( b ){
        if( b & 1 == 1 ){
            ans = ( ( ans % M ) * ( base % M ) ) % M;
        }
        base = (base*base) % M;
        b >>= 1;
    }
    return ans;
}


//循环求余
long long mode( int a , int b , int M ){
    long long  rem = 1;
    for( int i = 0; i < b; i++ ){
        rem = ( rem * a ) % M;
    }
    return rem;
}

int main(){
    system("pause");
}