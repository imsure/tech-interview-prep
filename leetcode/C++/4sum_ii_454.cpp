#include "common.hpp"

// hashmap solution

// time: O(n^2)
// space: O(n^2)
class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int len_A = A.size();
    int len_B = B.size();
    int len_C = C.size();
    int len_D = D.size();

    unordered_map<int, int> group_by_2sum;
    int i, j, sum;
    for (i = 0; i < len_A; ++i) {
      for (j = 0; j < len_B; ++j) {
        sum = A[i] + B[j];
        if (group_by_2sum.find(sum) == group_by_2sum.end()) {
          group_by_2sum[sum] = 1;
        } else {
          group_by_2sum[sum] += 1;
        }
      }
    }

    int counter = 0;
    for (i = 0; i < len_C; ++i) {
      for (j = 0; j < len_D; ++j) {
        sum = C[i] + D[j];
        if (group_by_2sum.find(-sum) != group_by_2sum.end()) {
          counter += group_by_2sum[-sum];
        }
      }
    }

    return counter;
  }
};

int main()
{
  vector<int> A {1,2};
  vector<int> B {-2,-1};
  vector<int> C {-1,2};
  vector<int> D {0,2};
  Solution sol;
  cout << sol.fourSumCount(A, B, C, D) << endl;
}
