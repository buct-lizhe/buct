/**
 * 求逆序对在归并排序中的应用
 * 暴力求解逆序对采用双层for循环肯定会超时
 * 利用归并排序以nlogn的时间复杂度求解
 * 在归并排序代码的基础上添加count计数逆序对即可完成要求
 * */

/**
 *                  归并排序java代码模板
 *     void merge(int[] arr, int start, int end) {
        if (start == end) return;
        int mid = (start + end) / 2;
        merge(arr, start, mid);
        merge(arr, mid + 1, end);

        int[] temp = new int[end - start + 1];
        int i = start, j = mid + 1, k = 0;
        while(i <= mid && j <= end)
            temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        while(i <= mid)
            temp[k++] = arr[i++];
        while(j <= end)
            temp[k++] = arr[j++];
        System.arraycopy(temp, 0, arr, start, end);
    }
 * */

#include<iostream>
#include<vector>
using namespace std;
int count = 0;

void merge(int arr[], int start, int end ){

    // cout<<start<<"  "<<end<<endl;
    if( start >= end ) return;
    int mid = ( start + end ) / 2;
    // cout<<start<<"  "<<mid<<"  "<<end<<endl;
    merge( arr, start, mid );
    merge( arr, mid+1, end );
    
    int temp[ end - start + 1 ];
    int i = start , j = mid + 1 , k = 0;
    while( i <= mid && j <= end ){
       while (i <= mid && j <= end) {
            count += arr[i] > arr[j] ? mid - i + 1 : 0;      //   count += mid - i + 1 即后一个数组的某一数据在前一个数据形成了多少个逆序对
            temp[k++] = arr[i] > arr[j] ? arr[j++] : arr[i++];
        }
        while (i <= mid) {
            // count += j - (mid + 1);
            temp[k++] = arr[i++];
        }
        while (j <= end)
            temp[k++] = arr[j++];
    }   
    for( int k = 0 , m = start; k < end - start + 1 ; k++ , m++ ){
        arr[m] = temp[k];
        // cout<<temp[i]<<"  "<<nums[i]<<endl;
    }
}

int reversePairs(vector<int>& nums) {
    int arr[nums.size()];
    for( int i = 0; i < nums.size(); i++ ){   //将vector转换为数组可以降低时间复杂度
        arr[i] = nums[i];
    }
    merge ( arr , 0 , nums.size()-1 );
    return count;
}

int main()
{

    vector<int> vc;
    vc.push_back( 7 );
    vc.push_back( 5 );
    vc.push_back( 6 );
    vc.push_back( 4 );
    cout<<reversePairs( vc )<<endl;
    system("pause");

}