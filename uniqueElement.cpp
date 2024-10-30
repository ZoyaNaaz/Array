#include<iostream>
using namespace std;
// array ->  {5 1 1 2 0 2}
// output -> 5, 0
int* uniqueElement(int arr[], int size, int &uniqueCount){
    int *unique = new int[size];
    int k = 0;
    for(int i = 0; i < size; i++){ //check for each element 
        int j;
        for(j = 0; j < size; j++){ // check for one element at a time
            if(i == j) // skip comparison for same element
                continue;
            if(arr[i] == arr[j]) //if any duplicate found -> break
                break;
        }
        if(j == size){ //unique element
            unique[k] = arr[i];
            k++; uniqueCount++;
        }
    }
    return unique; //returning array
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
    int uniqueCount = 0;
   int * unique = uniqueElement(arr, n, uniqueCount);
    // print
    for(int i = 0; i < uniqueCount; i++)
        cout<<unique[i]<<" ";

    delete[] unique;//deallocating
    return 0;
}