#include<iostream>
#include<math.h>
using namespace std;

int cuttingRope(int n) {
    long long  m = 1;
    for( int i = 2; i <= n; i++ ){
        long long multiple = 1;
        long long v1 = n / i;
        long long v2 = n % i;
        for( int j = 0 , k = 0; j < i; j++,k++ ){
            if( k < v2 ){
                multiple %= 1000000007;
                multiple *= ( v1+1 );
            }
            else{
                multiple %= 1000000007;
                multiple *= v1;
            }
        }
        m = max( m , multiple );
    }
    return m % 1000000007 ;
}

int main(){
    int n;
    cin>>n;
    cout<<cuttingRope( n )<<endl;
    system("pause");
}