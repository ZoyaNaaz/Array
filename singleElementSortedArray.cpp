#include<iostream>
#include<vector>
using namespace std;
// array ->  {1 1 2 3 3 4 4 8 8}
// output -> 2

// 1. approach -> O(n)
// bit manipulation || Linear search
// important -> n^n = 0 || n^0 = n
// int singleElementInSortedArray(vector<int>& arr){
//     int answer = 0;
//     for(int val : arr){
//         answer ^= val; 
//     }
//     return answer;
// }

// 2. approach -> O(log n)
// Binary search
int singleElementInSortedArray(vector<int>& arr){
    int n = arr.size();
    int st = 0, end = n-1;
    // n == 1
    if(n == 1) return arr[0];
    // n == 2
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    while(st <= end){
        int mid = st + (end - st)/2;
        // handling edge cases
        // if(mid == 0 && arr[0] != arr[1]) return arr[0];
        // if(mid == n-1 || arr[n-1] != arr[n-2]) return arr[n-1];

        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1])
                return arr[mid]; //elem found
        if(mid % 2 == 0){ //even no. of elem in L&R
            if(arr[mid-1] == arr[mid])//search in left
                end = mid-1;
            else //search in right
                st = mid+1;
        } 
        else{ //odd no. of elem in L&R
            if(arr[mid-1] == arr[mid]) //search in right
                st = mid+1;
            else //search in left
                end = mid-1;
        }
    }
    return -1;// not found
}
int main(){
    vector<int>v = {2, 2, 3};

    
    int result = singleElementInSortedArray(v);
    cout<<"Single Number: "<<result<<" ";
    

    return 0;
}