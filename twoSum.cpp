#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Two Sum
// vector -> {5,10,15,-2,24,78}, target -> 25
// output -> index of 10,15 -> 1,2

// 1. approach -> brute => O(n*n)
// vector<int> twoSum1(vector<int> nums, int target){
//     int n = nums.size();
//     vector<int>ans;
//     for(int i = 0; i < n; i++){
//         for(int j = i+1; j<n; j++){
//             if(nums[i]+nums[j] == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//             }
//         }
//     }
//     return ans;
// }

// 2. approach -> better=> O(nlogn)
// vector<int> twoSum2(vector<int> nums, int target){
//     sort(nums.begin(), nums.end());
//     // after sorting index will be changed.
//     int n = nums.size();
//     vector<int>ans;
//     int i = 0, j = n-1;
//     while(i < j){
//         int sum = nums[i]+nums[j];
//         if(sum > target){
//             j--;
//         }
//         else if(sum < target){
//             i++;
//         }
//         else{
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }
//     }
//     return ans;
// }

// 3. approach -> optimal => O(n)
vector<int> twoSum(vector<int>& nums, int target){
    int n = nums.size();
    unordered_map<int, int>m;
    vector<int>ans;
    for(int i = 0; i < n; i++){
        int first = nums[i]; //first + second = target 
        int second = target - first;
        if(m.find(second) != m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
        }
        m[first] = i;
    }
    return ans;
}
int main(){
    vector<int>v = {5, 2, 11, 7, 15};
    int target = 9;
    
    vector<int>index;
    index =  twoSum(v,target);
    // //print 
    if(index.size() == 0){
        cout<<"Not found";
    }
    for(auto val : index){
        cout<<val<<" ";
    }

    return 0;
}