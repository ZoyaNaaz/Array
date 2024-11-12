#include<iostream>
#include<vector>
using namespace std;
// array ->  {2,1,3,4}
// output -> 6

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){//O(n)
    int students = 1, pages = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > maxAllowedPages) return false; 

        if(pages + arr[i] <= maxAllowedPages){
            pages += arr[i];
        }
        else{
            students++;
            pages = arr[i];
        }
    }
     
    return students > m ? false : true;
}
// 1. approach -> O(logN *k n) // N -> range
// Binary search
int bookAllocation(vector<int>& arr, int n, int m){ 
    if(m > n) return -1;

    int sum = 0;
    for(int i = 0; i < n; i++){ //O(n)
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum; // range of possible ans'

    while(st <= end){ //O(logN * n)

        int mid = st + (end - st)/2;

        if(isValid(arr, n, m, mid)){ //left
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
    vector<int>v = {15,17,20};
    int n = 3, m = 2;
    
    int result = bookAllocation(v, n, m);
    cout<<"min no of pages to be allocates to students: "<<result<<" ";
    

    return 0;
}