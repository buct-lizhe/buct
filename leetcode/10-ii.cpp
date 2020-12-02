#include<iostream>
using namespace std;

int num[ 100+5 ];
int numWays(int n) {
    if( num[n] != 0 ){
        return num[n] % 1000000007 ;
    }
    if( n == 0 || n == 1 ){
        return num[n] = 1;
    }
    else if( n == 2 ){
        return num[n] = 2;
    }
    else{
        return num[n] = ( numWays( n-1 ) + numWays( n -2 ) ) % 1000000007;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<numWays( n )<<endl;
    system("pause");
}