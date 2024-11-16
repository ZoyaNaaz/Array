#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// array -> {1, 2, 3, 6, 5, 4}
// output -> {1 2 4 3 5 6}

// 1. approach -> TC - O(n) || SC - O(1)
void nextPermutation(vector<int>& A){
    int n = A.size();
    // 1st step : find pivot
    int pivot = -1;
    for(int i = n-2; i > 0; i--){
        if(A[i] < A[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(A.begin(), A.end());
    }
    // 2nd step : next larger element 
    for(int i = n-1; i > pivot; i--){
        if(A[i] > A[pivot]){
            swap(A[i], A[pivot]);
            break;
        }
    }
    // 3rd step : reverse (pivot+1 to n-1)
    // reverse(A.begin() + pivot + 1, A.end());
    int i = pivot+1, j = n-1;
    while( i <= j){
        swap(A[i++], A[j--]);
    }
    
}

int main(){
    vector<int>v1 = {1, 2, 3, 6, 5, 4};
   
    nextPermutation(v1);
     
   for(auto val : v1)
          cout<<val<<" ";
   
    return 0;
}