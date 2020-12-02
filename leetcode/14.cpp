#include<iostream>
#include<math.h>
using namespace std;
#define LL long long 


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

int cuttingRope(int n) {
    if( n < 4 ){
        return n-1;
    }
    if( n == 4 ){
        return n;
    }
    if( n > 4 ){
        int m = n / 3;
        int mm = n % 3;
        if( mm == 0 ){
            return quickmode( 3 , m , 1000000007 );
        }
        if( mm == 1 ){
            return ( quickmode( 3 , m-1 , 1000000007 ) * 4 ) % 1000000007;
        }
        if( mm ==2 ){
            return ( quickmode( 3 , m , 1000000007 ) * 2 ) % 1000000007;
        }
    }
}

int main(){
    int n;
    cin>>n;
    cout<<cuttingRope( n )<<endl;
    // long long s = 1;
    // for( int i = 0; i < 12; i++ ){
    //     s = ( ( s%1000000007 ) * 10 ) % 1000000007;
    //     cout<<s<<endl;
    // }
    // cout<<9999999370%1000000007<<endl;
    system("pause");
}