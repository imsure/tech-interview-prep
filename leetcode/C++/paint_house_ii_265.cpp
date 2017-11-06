#include "common.hpp"

// same idea as for paint house i
// time: O(nk^2)

class Solution {
private:
  int findMin(vector<int>& colors, int exclude) {
    int min_cost = numeric_limits<int>::max();
    for (int i = 0; i < colors.size(); ++i) {
      if (i != exclude) min_cost = min(min_cost, colors[i]);
    }

    return min_cost;
  }

public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (!n) return 0;
    int k = costs[0].size();

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < k; ++j) {
        costs[i][j] += findMin(costs[i-1], j);
      }
    }

    return findMin(costs[n-1], k);
  }
};


// time: O(nk)

class Solution2 {
public:
  int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (!n) return 0;

    int k = costs[0].size();

    pair<int, int> min1, min2; // pair of <color index, cost>
    min1.second = numeric_limits<int>::max();
    min2.second = numeric_limits<int>::max();
    for (int j = 0; j < k; ++j) {
      if (costs[0][j] < min1.second) {
        min2.first = min1.first;
        min2.second = min1.second;
        min1.first = j;
        min1.second = costs[0][j];
      } else if (costs[0][j] < min2.second) {
        min2.first = j;
        min2.second = costs[0][j];
      }
    }

    for (int i = 1; i < n; ++i) {
      pair<int, int> future_min1, future_min2; // pair of <color index, cost>
      future_min1.second = numeric_limits<int>::max();
      future_min2.second = numeric_limits<int>::max();

      for (int j = 0; j < k; ++j) {
        if (j != min1.first) costs[i][j] += min1.second;
        else costs[i][j] += min2.second;

        if (costs[i][j] < future_min1.second) {
          future_min2.first = future_min1.first;
          future_min2.second = future_min1.second;
          future_min1.first = j;
          future_min1.second = costs[i][j];
        } else if (costs[i][j] < future_min2.second) {
          future_min2.first = j;
          future_min2.second = costs[i][j];
        }
      }

      min1 = future_min1;
      min2 = future_min2;
    }

    return min1.second;
  }
};

int main()
{
  Solution2 sol;
  vector<int> nums {};
}
