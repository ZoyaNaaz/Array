#include<iostream>
#include<limits.h>
using namespace std;
// max subarray sum
// array -> {5,10,15,-2,24,78}
// sum -> 130

//1. approach
//  brute force - O(n2)
// int maxSubarraySum(int arr[], int size){
//     int maxSum = INT_MIN;
//     for(int start = 0; start < size; start++){
//     int currentSum = 0;
//     for(int end = start; end < size; end++){
//         currentSum += arr[end]; //calc sum of current subarray
//         // cout<<"c "<<currentSum<<" ";
//         maxSum = max(currentSum, maxSum);
//         // cout<<"m "<<maxSum<<" ";

//     }
//    }
//    return maxSum;
// }
// 2. approach
// O(n) - kadane's algorithm
int maxSubarraySum(int arr[] , int size){
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i = 0; i < size; i++){
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0)
            currentSum = 0; // reset if currSum is -ve
    }
    return maxSum;
}


int main(){
    int n;
    cout<<"enter size of array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter array elements:"<<endl;
    //array input
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    //print sum
    cout<<maxSubarraySum(arr, n);
  
    return 0;
}