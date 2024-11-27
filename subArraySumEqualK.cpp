#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// count subarray sum equals k
// array -> {9, 4, 20, 3, 10, 5}, k = 33
// sum -> 2

//1.approach
//brute force - O(n^2)
int countSubarraySum(vector<int>& A, int target){
    int n = A.size();
    int count = 0;
    for(int i = 0; i < n; i++){ //starting point of subarray
        int sum = 0;
        for(int j = i; j < n; j++){ //ending point of subarray
            sum += A[j];
            if(sum == target){
                count++;
            }
        }
    }
    return count;
}

//2.approach
//optimal - TC=>O(n) || SC=>O(n)
int countSubarraySum1(vector<int>& A, int target){
    int n = A.size(), count = 0;
    vector<int>ps(n); // array prifix sum
    ps[0] = A[0];
    for(int i = 1; i < n; i++){
        ps[i] = ps[i-1] + A[i];
    }
    unordered_map<int, int>m; //ps, freq
    for(int j = 0; j < n; j++){
        if(ps[j] == target) count++;

        int val = ps[j] - target; //val->right boundry
        if(m.find(val) != m.end()){
            count += m[val];
        }
        if(m.find(ps[j]) == m.end()){
            m[ps[j]] = 0;
        }
        m[ps[j]]++;
    }
    return count;
}



int main(){
   vector<int>v = {9, 4, 0, 20, 3, 10, 5};
    //print sum
    cout<<countSubarraySum(v, 33);
  
    return 0;
}