#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution_naive {
public:
  int hammingDistance(int x, int y) {
    int dist = 0;
    int z = x ^ y;
    while (z) {
      ++dist;
      z &= z - 1;
    }

    return dist;
  }

  int totalHammingDistance(vector<int>& nums) {
    int len = nums.size();
    int total = 0;
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        total += hammingDistance(nums[i], nums[j]);
      }
    }

    return total;
  }
};

// the idea is that we loop through 1st bit to 32nd bit and count the
// total # of 1's across all numbers in each iteration. The key insight is
// that for the ith bits of each pair of numbers, they only contribute to the
// total hamming distance if their ith bits are different. So if there are k 1's
// bits at the ith bit position for all numbers, then each of them will contribute to the total distance
// by pairing up with the remaining (n-k) numbers with 0 at ith position, so it's total k * (n-k) distance
// at one iteration.
//
// time: O(n)
// space: O(1)
class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int i, mask = 1;
    int len = nums.size(), one_count = 0;
    int total = 0;
    for (i = 0; i < 32; ++i) {
      mask = 1 << i;
      one_count = 0; // reset
      // count the # of 1-bit of all numbers at bit i
      for (const int num : nums) {
        //cout << std::hex << num << ", " << std::hex << mask << endl;
        if (num & mask) ++one_count;
      }
      total += one_count * (len - one_count);
      //cout << "Bit " << i << ", total = " << total << endl;
    }

    return total;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {4, 14, 2};
  cout << sol.totalHammingDistance(nums) << endl;
}
