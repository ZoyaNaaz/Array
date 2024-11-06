#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Reverse vector element
// vector -> {5,10,15,-2,24,78}, target -> 25
// output -> index of 10,15 -> 1,2

//1. approach
//  brute force - O(n2)
// vector<int> pairSum(vector<int> nums,int target){
//    vector<int>index; //for index return
//    for(int i = 0; i < nums.size(); i++){
//     for(int j = i+1; j < nums.size();j++ ){
//         if(nums[i] + nums[j] == target){
//             index.push_back(i);
//             index.push_back(j);
//             return index;
//         }
//     }
//    }
//    return index;

//}

// 2. approach
// optimal - approach O(n)
vector<int> pairSum(vector<int> nums,int target){
   vector<int>index; //for index return
   int n  = nums.size();
   int i = 0;
   int j = n - 1;
   while(i < j){
    int pairSum = nums[i] + nums[j];
    if(pairSum > target)
        j--;
    else if(pairSum < target)
        i++;
    else{
        index.push_back(nums[i]);
        index.push_back(nums[j]);
        return index;
    }
   }
    return index;
}

int main(){
    vector<int>v = {1,2,3,4,5};
    int target = 9;
    
    vector<int>index; //to store result
    index =  pairSum(v,target);
    //print 
    for(auto val : index){
        cout<<val<<" ";
    }

    return 0;
}