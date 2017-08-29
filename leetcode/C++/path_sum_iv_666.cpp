#include "common.hpp"

// idea: iterate elements backwards, store all the leaf nodes into a
// map ({depth-position : value}), for each node, count the number of
// leaves it can reach to.

class Solution {
public:
  int pathSum(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) return 0;
    if (len == 1) return nums[0] - 110;

    int sum = 0;
    unordered_map<int, int> leaves;
    int max_depth = nums[len-1] / 100;

    int depth, pos, val;
    for (int i = len - 1; i > 0; --i) {
      depth = nums[i] / 100;
      pos = (nums[i] - depth * 100) / 10;
      val = nums[i] - depth * 100 - pos * 10;

      if (depth == max_depth) {
        leaves[depth * 10 + pos] = 1;
        sum += val; // every leaf node will be counted only once
        //cout << "found a leaf: " << nums[i] << endl;
      } else {
        int leaf_count = 0;
        for (int d = max_depth; d > depth; --d) {
          int pos_start = pow(2, d - depth) * pos - (pow(2, d - depth) - 1);
          int pos_end = pos_start +  pow(2, d - depth) - 1;
          for (int p = pos_start; p <= pos_end; ++p) {
            int key = d * 10 + p;
            //if (nums[i] == 215) cout << "scanning key: " << key << endl;
            if (leaves.count(key)) ++leaf_count;
          }
        }

        if (leaf_count) {
          sum += val * leaf_count;
        } else { // this is a leaf node
          cout << "found a leaf: " << nums[i] << endl;
          leaves[depth * 10 + pos] = 1;
          sum += val; // every leaf node will be counted only once
        }
      }
      //cout << "current num: " << nums[i] << ", current sum: " << sum << endl;
    }

    sum += (nums[0] - 110) * leaves.size();

    //for (const auto& kv : leaves) cout << "key: " << kv.first << endl;

    return sum;
  }
};

int main()
{
  Solution sol;
  // vector<int> nums {115,215,224,325,336,446,458};
  vector<int> nums {113, 215, 221};
  cout << sol.pathSum(nums) << endl;
}
