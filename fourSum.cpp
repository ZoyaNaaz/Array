#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//4 sum problem -> using two pointer
vector<vector<int>> fourSum(vector<int>& A, int target){
    int n = A.size();
    sort(A.begin(), A.end());
    vector<vector<int>>ans;

    for(int i = 0; i < n; i++){
        if(i > 0 && A[i] == A[i-1]){ //To ignore same values of 'i'
            continue;
        }
        for(int j = i+1; j < n; ){ //move j++ at the end of loop
            int p = j+1, q = n-1;
            while(p < q){
                int sum = A[i]+A[j]+A[p]+A[q];
                if(sum < target){
                    p++;
                }
                else if(sum > target){
                    q--;
                }
                else{
                    ans.push_back({A[i],A[j],A[p],A[q]});
                    p++; q--;
                    while(p < q && A[p] == A[p-1]){ //To ignore same value of 'k'
                        p++;
                    }
                }
            }
        j++;
        while(j < n && A[j] == A[j-1]){
            j++;
        }
        }
        return ans;
    }
}
int main(){
    vector<int>v = {-2, -1, -1, 1, 1, 2};
    int target = 2;
    vector<vector<int>>result = fourSum(v, target);
    for(auto i : result){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Complexity
// TC => O(nlogn + n*n*n)
// SC => O(uniqueGroups)