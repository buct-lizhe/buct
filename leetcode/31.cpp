#include<iostream>
#include<vector>
#include<map>
#include<stack>
using namespace std;

stack<int> st;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int index = 0;
    for( int i = 0 ; i < pushed.size(); i++ ){
        st.push( pushed[i] );
        while ( !st.empty() && st.top() == popped[ index ] )
        {
            st.pop();
            index++;
        }
    }
    if( st.empty() ){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,2,1 };
    cout<<validateStackSequences( pushed , popped )<<endl;
    system("pause");
}