#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int nums[ arr.size() ];
    for( int i = 0; i < arr.size(); i++ ){
        nums[i] = arr[i];
    }
    vector<int> arr1;
    sort( nums , nums+arr.size() );
    for( int i = 0; i < k; i++ ){
        arr1.push_back( nums[i] );
    }
    return arr1;
}

int main()
{
    vector<int> vc = { 0, 1, 2, 1 };
    getLeastNumbers( vc , 1 );
}