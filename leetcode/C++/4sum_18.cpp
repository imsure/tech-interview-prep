#include "common.hpp"

// same idea with 3sum, just one more added loop

// time: O(n^3)
// space:
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> results {};
    int len = nums.size();

    if (len < 4) return results;

    sort(nums.begin(), nums.end());

    int front1 = 0, front2, front3, back3, sum;
    while (front1 < len) {
      front2 = front1 + 1;
      while (front2 < len) {
        front3 = front2 + 1;
        back3 = len - 1;
        while (front3 < back3) {
          sum = nums[front1] + nums[front2] + nums[front3] + nums[back3];
          if (sum < target) ++front3;
          else if (sum > target) --back3;
          else {
            vector<int> quadruplet (4, 0);
            quadruplet[0] = nums[front1];
            quadruplet[1] = nums[front2];
            quadruplet[2] = nums[front3];
            quadruplet[3] = nums[back3];
            results.emplace_back(quadruplet);

            // skip duplicates
            while (front3 < back3 && nums[++front3] == quadruplet[2]) ;
            while (front3 < back3 && nums[--back3] == quadruplet[3]) ;
          }
        }

        // skip duplicates
        while (front2+1 < len && nums[front2+1] == nums[front2]) ++front2;
        ++front2;
      }

      // skip duplicates
      while (front1+1 < len && nums[front1+1] == nums[front1]) ++front1;
      ++front1;
    }

    return results;
  }
};

int main()
{
  Solution sol;
  // vector<int> nums {1, 0, -1, 0, -2, 2};
  vector<int> nums {-3,-2,-1,0,0,1,2,3};
  vector<vector<int>> results = sol.fourSum(nums, 0);
  for (const auto& quadruplet : results) {
    for (const int n : quadruplet) {
      cout << n << ", ";
    }
    cout << endl;
  }
}
