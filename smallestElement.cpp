#include<iostream>
#include<limits.h> // for using INT_MAX
using namespace std;
// finding smallest element in array
// {5,10,15,-2,24,78}
int findSmallest(int a[], int size){
    int smallest = INT_MAX;
    for(int i = 0; i < size; i++){
        smallest = min(a[i], smallest);
        }
    return smallest; // return final value of smallest
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
    //find smallest
    int small = findSmallest(arr,n);
    //print smallest element of array
    cout<<small;
    return 0;
}