#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//brute
//1. approach=> TC -> O(n*n*n * log(uniqueTriplets)) || SC->O(uniqueTriplets)

vector<vector<int>> threeSum(vector<int>& A){ 
    int n = A.size();
    vector<vector<int>>ans;
    set<vector<int>>s; //set<uniqueTriplets>
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(A[i]+A[j]+A[k] == 0){
                    vector<int>trip = {A[i], A[j], A[k]};
                    sort(trip.begin(), trip.end());//sort=> so that only unique pairs will be stored in set
                    if(s.find(trip) == s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

//better
//2.approach=> TC -> O(n*n * log(uniqueTriplets)) || SC->O(uniqueTriplets + n)

vector<vector<int>> threeSum1(vector<int>& A){ 
    int n = A.size();
    set<vector<int>>uniqueTriplets;

    for(int i = 0; i < n; i++){
        set<int>s; //for storing j values
        for(int j = i+1; j < n; j++){
            // a+b+c = 0 || c = -a-b
            int third = -A[i]-A[j];
            if(s.find(third) != s.end()){
                vector<int>trip = {A[i], A[j], third};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(A[j]);
        }
    }
    vector<vector<int>>ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

// optimal
//3. approach=> TC-> O(n*n) || SC=> O(uniqueTriplets)
//2 pointer approach
vector<vector<int>> threeSum2(vector<int>& A){
    int n = A.size();
    sort(A.begin(), A.end()); //O(nlogn)
    vector<vector<int>>ans;
    for(int i = 0; i < n; i++){ //O(n*n)
        if(i > 0 && A[i] == A[i-1])
            continue; //Move to next iteration if 'i' is same.
        int j = i+1, k = n-1;
        while(j < k){
            int sum = A[i] + A[j] + A[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{ // sum == 0
                ans.push_back({A[i], A[j], A[k]});
                j++; k--;
                while(j < k && A[j] == A[j-1]){
                    j++; // jabtak 'j' ki unique value na mil jaye
                }
            }
        }
    }
    return ans;
}

int main(){
    vector<int>v = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>>res = threeSum2(v);
    for(auto i : res){
        for(auto j : i)
             cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}