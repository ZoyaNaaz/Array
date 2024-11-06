#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// majority elemrnt
// vector -> {1,2,2,1,1,1},
// output -> 1

// 1. approach
//   brute force - O(n2)
//  int majorityElement(vector<int> &nums){
//      int n = nums.size();
//      for(int i = 0; i < n; i++){
//          int frequency = 0;
//          for (int j = 0; j < n; j++){
//              if(nums[i] == nums[j])
//                  frequency++;
//          }
//          if(frequency > n/2)
//              return nums[i];
//          }
//      return -1;
//  }

// 2. approach
// better - approach O(nlogn)
// int majorityElement(vector<int> nums){
//     int n = nums.size();
//     sort(nums.begin(), nums.end()); //O(nlogn)
//     int frequency = 1,answer = nums[0];
//     for(int i = 1; i < n; i++){ //O(n)
//         if(nums[i] == nums[i-1])
//             frequency++;
//         else{
//             frequency = 1;
//             answer = nums[i];
//         }
//         if(frequency > n/2)
//             return answer;
//      }
//      return -1; //if majority element is not found
// }

// 3. approach
// optimal - approach O(n)
int majorityElement(vector<int> nums)
{
    int n = nums.size();
    int frequency = 0, answer = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (frequency == 0)
            answer = nums[i];
        if (answer == nums[i])
            frequency++;
        else
            frequency--;
    }
    return answer;
}

int main()
{
    vector<int> v = {1, 2, 2, 1, 1, 1};

    int element = majorityElement(v);
    // print
    cout << element;

    return 0;
}