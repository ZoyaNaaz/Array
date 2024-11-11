#include<iostream>
#include<vector>
using namespace std;
// Search peak element in array
// input -> {0, 3, 8, 9, 5, 2}
// output-> index of 9 is 3

// 1.approach - O(log n)
// binary search
int searchPeakElement(vector<int> arr){
    int n = arr.size();
    int start = 1, end = n-2; // index -> 0 and n-1 can never be peak element
    while(start <= end){

        int mid = start + (end - start)/2; 
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
            return mid; //peak found

        if(arr[mid-1] < arr[mid]) //left -> inc || search in right half
                start = mid+1; 
        else
                end = mid-1; //right -> dec || search in left half
       
       } 
       return -1;// not found
}

int main(){
    vector<int>v = {0, 3, 8, 9, 5, 2};

    int index = searchPeakElement(v);
    cout<<"Index of peak element "<<v[index]<<" is "<<index<<endl;

    return 0;
}