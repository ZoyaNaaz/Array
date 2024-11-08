#include <iostream>
#include <vector>
using namespace std;
// 11. container with most water
// vector -> {1, 8, 6, 2, 5, 4, 8, 3, 7},
// output -> 49

// 1.approach
// brute-force - O(n^2)
// int ContainerMostWater(vector<int>& height) {
//       int n = height.size();
//       int maxArea = 0;
//       for(int i = 0; i < n; i++){
//         int minHeight = height[i];
//         int width = 0;
//         for(int j = i+1; j < n; j++){
//             minHeight = min(height[i], height[j]);
//             width++;
//         }
//         maxArea = max(maxArea, minHeight * width);
//       }
//       return maxArea;
// }

// 2.approach - 2 pointer approach
// optimal - O(n)
int ContainerMostWater(vector<int>& height) {
      int n = height.size();
      // 2 pointer
      int lp = 0, rp = n-1;
      int maxArea = 0,currArea = 0;
      while(lp < rp){
        int width = rp-lp;
        int ht = min(height[lp],height[rp]);
        currArea = width * ht;
        maxArea = max(maxArea, currArea);
        height[lp] < height[rp] ? lp++ : rp--; //updating pointers
      }
      return maxArea;
}

int main()
{
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int area = ContainerMostWater(v);
    // print
    cout << area;

    return 0;
}