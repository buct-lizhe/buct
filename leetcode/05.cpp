#include<iostream>
using namespace std;

string replaceSpace(string s) {

    string s1 = "";
    for( int i = 0; i < s.length(); i++ ){
        if( s[i] == ' ' ){
            s1 +="%20";
        }
        else{
            s1 += s[i];
        }
    }
    cout<<s1<<endl;
    return s1;
}

int main()
{
    replaceSpace("We are happy.");
    system("pause");
}