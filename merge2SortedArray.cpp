#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// array1 -> {1, 2, 3, 0, 0, 0}
// array2 -> {4, 5, 6}
// output -> {1,2,3,4,5,6}

//1. approach - TC - O(m+n) || SC - O(m+n) 
// vector<int> mergeSortedArray(vector<int>& A, vector<int>& B, int sizeA, int sizeB){    
//       vector<int>res;
//       int i = 0, j = 0;
//       while(i < sizeA && j < sizeB){
//         if(A[i] <= B[j])
//           res.push_back(A[i++]);
//         else
//           res.push_back(B[j++]);
//       }
//       while(i < sizeA){
//         res.push_back(A[i++]);
//       }
//       while(j < sizeB){
//         res.push_back(B[j++]);
//       }
//       return res;
// }

// 2. approach -> TC - O(m+n) || SC - O(1)
void mergeSortedArray(vector<int>& A, vector<int>& B, int m, int n){
      int idx = m+n-1, i = m-1, j = n-1;
      while(i >= 0 && j >= 0){
        if(A[i] >= B[j]){
          A[idx--] = A[i--];
        }
        else{
          A[idx--] = B[j--];
        }
      }
      // i < 0
      while(j >= 0){
        A[idx--] = B[j--];
      }
}
int main(){
    vector<int>v1 = {1, 2, 3, 0, 0, 0};
    vector<int>v2 = {2, 5, 6};
    int m  = 3, n = 3;
    mergeSortedArray(v1, v2, m, n);
     
   for(auto val : v1)
          cout<<val<<" ";
   
    return 0;
}
