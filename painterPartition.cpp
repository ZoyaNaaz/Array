#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// array ->  {2,1,3,4}
// output -> 6

bool isPossible(vector<int>& arr, int n, int m, int maxAllowedTime){//O(n)
    int painter = 1, time = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedTime) return false; 

        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }
        else{ //new painter
            painter++;
            time = arr[i];
        }
    }
     
    return painter > m ? false : true;
}
// 1. approach -> O(logN *k n) // N -> range
// Binary search
int painterPartition(vector<int>& arr, int n, int m){ 
    if(m > n) return -1;

    int sum = 0, maxVal = INT_MIN; //maxVal - sum -> range 
    for(int i = 0; i < n; i++){ //O(n)
        sum += arr[i];
        maxVal = max(maxVal, arr[i]); //max value of array
    }

    int ans = -1;
    int st = maxVal, end = sum; // range of possible ans'

    while(st <= end){ //O(logN * n)

        int mid = st + (end - st)/2;

        if(isPossible(arr, n, m, mid)){ //left
            ans = mid; 
            end = mid-1;
        }
        else{ //right
            st = mid+1;
        }
    }

    return ans;// not found
}
int main(){
    vector<int>v = {40, 30, 10, 20};
    int n = 4, m = 2; //n -> no of board || m -> no of painter
    
    int result = painterPartition(v, n, m);
    cout<<"Min Time to paint: "<<result<<" ";
    

    return 0;
}