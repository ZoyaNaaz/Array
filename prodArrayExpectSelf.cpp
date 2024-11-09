#include<iostream>
#include <vector>
using namespace std;
// product of array elements except self
// array -> {1, 2, 3, 4}
// output -> {24, 12, 8, 6}

// 1. approach
// iterative - O(n^2)
// vector<int> prodArrayExceptSelf(vector<int>& arr){
//     int n = arr.size();
//     vector<int>ans;
//     for(int i = 0; i < n; i++){
//         long int product = 1;
//         for(int j = 0; j < n; j++){
//             if(i != j)
//                 product *= arr[j];
//         }
//         ans.push_back(product);
//     }
//     return ans;
// }

// 2. approach
// TC -> O(n) || SC -> O(n)
// vector<int> prodArrayExceptSelf(vector<int>& arr){
//     int n = arr.size();
//     vector<int>ans(n,1);
//     vector<int>prefix(n,1);
//     vector<int>suffix(n,1);
//     // prefix
//     for(int i = 1; i < n; i++){
//        prefix[i] = prefix[i-1] * arr[i-1];
//     }
//     // suffix
//     for(int i = n-2; i >= 0; i--){
//        suffix[i] = suffix[i+1] * arr[i+1];
//     }
//     // answer
//     for(int i = 0; i < n; i++){
//        ans[i] = prefix[i] * suffix[i];
//     }
//     return ans;
// }

// 3.approach - optimized
// TC -> O(n) || SC -> O(1)
vector<int> prodArrayExceptSelf(vector<int>& arr){
    int n = arr.size();
    vector<int>ans(n,1);
    // prefix -> left product of ith index || suffix -> right product of ith index
    // prefix -> store in answer
    for(int i = 1; i < n; i++){
       ans[i] = ans[i-1] * arr[i-1];
    }
    // suffix
    int suffix = 1;
    for(int i = n-2; i >= 0; i--){
       suffix = suffix * arr[i+1];
       ans[i] = ans[i] * suffix; // answer -> prefix * suffix
    }
    return ans;
}




int main(){
    vector<int>v = {1, 2, 3, 4};
    //print product array
    vector<int>result;
    result = prodArrayExceptSelf(v);
    for(int val : result)
        cout<<val<<" ";
    return 0;
}