/**
 * Classical Knapsack Problem:
 *
 * Given a list of n items, where each item i has weight w_i and value v_i.
 * We are also given an upper bound of weight W. Find a subset of items of
 * maximium total value such that total weight is at most W.
 */

#include "common.hpp"

// DP approach: for any item i, depending on the optimal solution upto item i-1,
// item i is either in the optimal solution upto i or not, thus this problem is
// a natural fit to DP coz the problem can be decomposed into smaller sub-problems
// where there is a relation between optimal solutions to sub-problems and optimal
// solution of the original problem.

// We can fill a table T of size (n+1)x(W+1) where T[i][w] represents the max value
// of any subset of items [1...i] of total weight at most w. There is a sequential structure
// of the optimal solution can be imposed: T[i][w] = max(T[i-1][w-w_i] + v_i, T[i-1][w]) meaning
// that the optimal solution T[i][w] either contains item i or not. Thus if we fill
// the table bottom up, the value at T[n][W] would be the optimal solution we try to find.

class Solution {
private:
  void recover(vector<vector<int>>& T, vector<int>& weights, vector<int>& vals,
               vector<int>& items, int i, int w) {
    if (!i || !w || !T[i][w]) return;
    if (T[i][w] - vals[i-1] == T[i-1][w-weights[i-1]]) {
      items.push_back(i);
      recover(T, weights, vals, items, i-1, w - weights[i-1]);
    } else {
      recover(T, weights, vals, items, i-1, w);
    }
  }

public:
  pair<vector<int>, int> knapSack(vector<int>& weights, vector<int>& vals, int W) {
    pair<vector<int>, int> ans; // <subset of items, max value>

    int N = weights.size();
    vector<vector<int>> T (N+1, vector<int>(W+1, 0));
    for (int i = 1; i <= N; ++i) {
      for (int w = 1; w <= W; ++w) {
        if (w < weights[i-1]) T[i][w] = T[i-1][w];
        else T[i][w] = max(T[i-1][w-weights[i-1]] + vals[i-1], T[i-1][w]);
      }
    }

    vector<int> items;
    recover(T, weights, vals, items, N, W);
    ans.first = items;
    ans.second = T[N][W];
    return ans;
  }
};

int main()
{
  vector<int> weights {5, 4, 3};
  vector<int> values {10, 7, 5};
  int W = 7;

  // vector<int> weights {5, 4, 6, 3};
  // vector<int> values {10, 40, 30, 50};
  // int W = 10;

  // vector<int> weights {3,4,2,6,7,3,5};
  // vector<int> values {7,9,5,12,14,6,12};
  // int W = 15;

  Solution sol;
  pair<vector<int>, int> ans = sol.knapSack(weights, values, W);
  cout << "optimal items: ";
  for (auto i : ans.first) cout << i << ' ';
  cout << "\noptimal value: " << ans.second << endl;
}
