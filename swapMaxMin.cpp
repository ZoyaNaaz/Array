#include<iostream>
#include<limits.h>
using namespace std;
// array ->  {5 10 15 2 29 20}
// output -> {5 10 15 29 2 20}
void swapMaxMin(int arr[], int size){
    int Max = INT_MIN, maxIndex;
    int Min = INT_MAX, minIndex;
    for(int i = 0; i < size; i++){ //finding min max element
        Max = max(Max, arr[i]); 
        Min = min(Min, arr[i]); 
    }
    for(int i = 0; i < size; i++){ //finding index of min max
        if(arr[i] == Max)
            maxIndex = i;
        if(arr[i] == Min)
            minIndex = i;
    }
    swap(arr[maxIndex], arr[minIndex]); // swapping min max
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
    swapMaxMin(arr, n);
    //print array
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}