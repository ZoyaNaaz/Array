#include<iostream>
#include<algorithm>
using namespace std;
// Reverse array element
// array -> {5,10,15,-2,24,78}
// reverse -> {78,24,-2,15,10,5}

//1. approach
//  using two pointer approach
void reverseArray(int arr[], int size){
    int start = 0; //start from 0th position
    int end = size - 1; // start from end'th position
    while(start < end){
        swap(arr[start], arr[end]); //swap
        start++;
        end--;
    }
}
// 2. approach
// void reverseArray(int arr[], int size){
//     for(int i = 0; i < size/2; i++){
//          swap(arr[i], arr[size - (i+1)]);
//         }
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
    reverseArray(arr, n);
    //print array
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}