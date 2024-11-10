#include<iostream>
#include<vector>
using namespace std;
// Search in rotated array
// input -> {3, 4, 5, 6, 7, 0, 1, 2}, target = 0
// output-> index of 0 is 5

// 1.approach - O(log n)
// iterative
int searchInRotatedArray(vector<int> arr,int target){
    int n = arr.size();
    int start = 0, end = n-1;
    while(start <= end){
        //its a optimatization - to protect from overflow
        int mid = start + (end - start)/2; //same as (start+end)/2
        if(arr[mid] == target)
            return mid; //target found

        if(arr[start] <= arr[mid]){ //left half is sorted
            if(arr[start] <= target && target <= arr[mid]) //apply binary search on left half
                end = mid-1; 
            else
                start = mid+1; //go to right half if target is not in left half
        }
        else{ // right half is sorted -> binary search on right half
            if(arr[mid] <= target && target<= arr[end])
                start = mid+1;
            else
                end = mid-1;
        }
    } 
    return -1;// not found
}

int main(){
    vector<int>v = {3, 4, 5, 6, 7, 0, 1, 2};
    int target = 2;
    int n = v.size();

    int index = searchInRotatedArray(v, target); //iterative call
    cout<<"Index of target element "<<target<<" is "<<index<<endl;

    return 0;
}