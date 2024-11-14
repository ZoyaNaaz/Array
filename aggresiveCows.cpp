#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// array ->  {1, 2, 8, 4, 9}
// output -> 3

bool isPossible(vector<int>& arr, int n, int c, int maxAllowedDist){//O(n)
    int cows = 1, lastStallPosition = arr[0];
    
    for(int i = 1; i < n; i++){

        if(arr[i] - lastStallPosition >= maxAllowedDist){
            cows++;
            lastStallPosition = arr[i];
        }
    }
    if(cows == c) return true;
    else return false;
}

// max possible min distance
int aggresiveCows(vector<int>& arr, int n, int c){ 
    sort(arr.begin(), arr.end()); //O(nlogn)

    int ans = -1;
    int st = 1, end = arr[n-1] - arr[0]; // range of possible ans

    while(st <= end){ //O(log(range) * n)

        int mid = st + (end - st)/2;

        if(isPossible(arr, n, c, mid)){ // O(n)
            ans = mid; //right
            st = mid+1;
        }
        else{ //left
            end = mid-1;
        }
    }

    return ans; 
}
int main(){
    vector<int>v = {1, 2, 8, 4, 9};
    int n = 5, c = 3; //n -> no of stalls || c -> no of cows
    
    int result = aggresiveCows(v, n, c);
    cout<<"max possible min distance: "<<result<<" ";
    

    return 0;
}


// tc o(nlogn + O(logN * n)), 
// sc o(1)