#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int,int> m;

int singleNumber(vector<int>& nums) {
    
    for( int i = 0; i < nums.size(); i++ ){
        m[ nums[i] ]++;
    }
    int value = 0;
    for( int i = 0; i < nums.size(); i++ ){
        if( m[nums[i] ] == 1 ){
            value = nums[i];
            break;
        }
    }
    return value;
}

int main()
{

}