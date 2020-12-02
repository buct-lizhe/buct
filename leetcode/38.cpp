#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string , int > mmap;
vector<string> vt;
string ss = "";
int visit[ 10+5 ];

void solve( string s , string substr , int n ){
    if( n == s.length() ){
        if( mmap[ substr ] == 0 ){
            mmap[ substr ] = 1;
            vt.push_back( substr );
        }
        ss = "";
        return;
    }
    for( int i = 0; i < s.length(); i++ ){
        if( visit[i] == 0 ){
            visit[i] = 1;
            solve( s , substr+s[i] , n+1 );
            visit[i] = 0;
        }
    }
}

vector<string> permutation(string s) {
    for( int i = 0; i < s.length(); i++ ){
        visit[i] = 1;
        solve( s , ss+s[i] , 1 );
        visit[i] = 0;
    }
    return vt;
}

int main(){
    vector<string> v = permutation("abc");
    // cout<<v.size()<<endl;
    for( int i = 0; i < v.size(); i++ ){
        cout<<v[i]<<endl;
    }
    system("pause");
}