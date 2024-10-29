#include<iostream>
using namespace std;
// sum of array elements
// array -> {5 1 15 2 2 20}
// output -> 45

// 1. approach
// iterative
int sumOfArrayElements(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}
// 2. approach
// recursive
// int sumOfArrayElements(int arr[], int size){
//     if(size == 0) 
//         return 0;
//     return arr[0] + sumOfArrayElements(arr + 1, size-1);
// }


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
    cout<< sumOfArrayElements(arr, n);
    return 0;
}