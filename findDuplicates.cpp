#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// find duplicates
// 1. approach => O(n*n)
int findDuplicates(vector<int>& A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        int f = A[i];
        for(int j = 0;j < n; j++){
            if(i == j) continue;
            if(f == A[j]){
                return j;
            }
        }
        return -1;
    }
}

// 2. approach => TC =>O(n) || SC => O(n)
int findDuplicates1(vector<int>& A){
    int n = A.size();
    unordered_set<int>s;

    for(int i = 0; i < n; i++){
        if(s.find(A[i]) != s.end()){
            return i;
        }
        else{
            s.insert(A[i]);
        }
    }
    return -1;
}

// 3. approach => slow-fast pointer -> TC => O(n) || SC=> O(1)
int findDuplicates3(vector<int>& A){
    int n = A.size();
    int slow = A[0], fast = A[0];
    do{
        slow = A[slow];
        fast = A[A[fast]];

    }while(slow != fast);

    slow = A[0];
    while(slow != fast){
        slow = A[slow];
        fast = A[fast];
    }
    return slow; // duplicate value
}
int main(){
    vector<int>v = {3, 1, 3, 4, 2};
    cout<<findDuplicates3(v);
    return 0;
}