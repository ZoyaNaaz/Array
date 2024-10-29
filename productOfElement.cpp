#include<iostream>
using namespace std;
// product of array elements
// array -> {5 1 15 2 2 20}
// output -> 6000

// 1. approach
// iterative
int productOfArrayElements(int arr[], int size){
    long int product = 1;
    for(int i = 0; i < size; i++){
        product *= arr[i];
    }
    return product;
}
// 2. approach
// recursive
// int productOfArrayElements(int arr[], int size){
//     if(size == 0) 
//         return 1;
//     return arr[0] * productOfArrayElements(arr + 1, size-1);
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
    cout<< productOfArrayElements(arr, n);
    return 0;
}