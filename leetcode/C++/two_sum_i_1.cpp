#include "common.hpp"

// idea: build a hashtable that maps (target - number) to number's index
// for each number in the input array. then scan through every number, look up
// the hashtable to see if there is a match. The hashtable should be defined as
// map<int, vector<int>> instead of map<int, int> to handle cases like [4,4],
// target = 8. Two passes are required, one pass for building the map, the other
// one for finding the match.

// time: O(n)
// space: O(n)
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> indices;
    unordered_map<int, vector<int>> diff2index;

    int len = numbers.size();
    int diff;
    for (int i = 0; i < len; ++i) {
      diff = target - numbers[i];
      diff2index[diff].emplace_back(i);
    }

    // for (const auto& keyval : diff2index) {
    //   cout << "key: " << keyval.first << ", value: ";
    //   for (const int index : keyval.second) {
    //     cout << index << ',';
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < len; ++i) {
      if (diff2index.find(numbers[i]) != diff2index.end()) {
        for (const int index : diff2index[numbers[i]]) {
          if (index != i) {
            indices.emplace_back(i);
            indices.emplace_back(index);
            return indices;
          }
        }
      }
    }

    return indices;
  }
};

// one pass solution
class Solution2 {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> indices;
    unordered_map<int, vector<int>> diff2index;

    int len = numbers.size();
    int diff;
    for (int i = 0; i < len; ++i) {
      diff = target - numbers[i];
      diff2index[numbers[i]].emplace_back(i);
      if (diff2index.find(diff) != diff2index.end()) {
        for (const int index : diff2index[diff]) {
          if (index != i) {
            indices.emplace_back(i);
            indices.emplace_back(index);
            return indices;
          }
        }
      }
    }

    return indices;
  }
};


// improved one pass solution, no need to store a list of indexes for repeated elements

class Solution3 {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> indices;
    unordered_map<int, int> diff2index;

    int len = numbers.size();
    int diff;
    for (int i = 0; i < len; ++i) {
      diff = target - numbers[i];
      if (diff2index.find(diff) != diff2index.end()) {
        indices.push_back(diff2index[diff]);
        indices.push_back(i);
        break;
      }
      diff2index[numbers[i]] = i;
    }

    return indices;
  }
};


int main()
{
  Solution2 sol;
  vector<int> nums {2, 7, 11, 15};
  vector<int> res = sol.twoSum(nums, 9);
  cout << res[0] << ", " << res[1] << endl;

  vector<int> nums2 {4, 3, 6, 4};
  vector<int> res2 = sol.twoSum(nums2, 8);
  cout << res2[0] << ", " << res2[1] << endl;

  vector<int> nums3 {3, 2, 4};
  vector<int> res3 = sol.twoSum(nums3, 6);
  cout << res3[0] << ", " << res3[1] << endl;
}
