#include<iostream>
#include<limits.h>
using namespace std;
// finding largest element in array
// {5,10,15,-2,24,78}
int findLargest(int a[], int size){
    int largest = INT_MIN;
    for(int i = 0; i < size; i++){
         largest = max(a[i], largest);
        }
    return largest; // return final value of largest
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
    //find largest
    int large = findLargest(arr,n);
    //print smallest element of array
    cout<<large;
    return 0;
}