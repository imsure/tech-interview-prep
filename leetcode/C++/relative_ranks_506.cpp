#include "common.hpp"

// time:
// space:
class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    int len = nums.size();
    vector<string> ranks;

    for (const int num : nums) {
      ranks.push_back(std::to_string(num));
    }

    sort(nums.begin(), nums.end());

    int score, index, rel_rank;
    for (int i = 0; i < len; ++i) {
      score = std::stoi(ranks[i]);
      auto it = std::lower_bound(nums.begin(), nums.end(), score);
      index = std::distance(nums.begin(), it);
      rel_rank = len - index;
      if (rel_rank == 1) {
        ranks[i] = "Gold Medal";
      } else if (rel_rank == 2) {
        ranks[i] = "Silver Medal";
      } else if (rel_rank == 3) {
        ranks[i] = "Bronze Medal";
      } else {
        ranks[i] = std::to_string(rel_rank);
      }
    }

    return ranks;
  }
};

int main()
{
  Solution sol;
  vector<int> nums {5, 4, 3, 2, 1};
  vector<string> ranks = sol.findRelativeRanks(nums);
  for (const string rank : ranks) {
    cout << rank << endl;
  }
}
