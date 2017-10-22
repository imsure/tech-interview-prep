/*
 * Problem:
 *
 * Given an N*N matrix M where row/column indexes represents member ID and
 * M[i][j] == true means that member i is following member j where i != j.
 * M[j][i] == false means that member j is not following member i where i != j.
 * Note M[i][i] does not make sense here thus can be safely skipped.
 *
 * An influencer is defined as a member who is followed by everyone and who does
 * not follow anyone.
 *
 * Find all the influencers in M.
 */

#include "common.hpp"

// Approch 1: brute force.
// Scan the matrix row-wise, for each row i with all cell values equal to false
// (except the cell on the diagonal which shoud be skipped), scan the column i,
// if all the cell values equal to true (except the diagnal cell), then member i
// is a influencer, given the definition.
//
// Time complexity is O(N^2) as in worse case we have to scan the entire matrix.

// Approch 2: we shall make use of the definition of an influencer.
//
// Theorem: given the definition of the influencer, there can be at most one influencer
// given a matrix M.
//
// Proof: prove by contradiction. Suppose there are two influencers i and j,
// by definition, i is followed by everyone, thus i is followed by j. Since
// j is also an influencer, by definition, j cannot follow anyone, we've reached
// a contradiction.

// Given the above observation, we can idenfity the influencer (if any) in O(N) time.
// We just need to pick one row (say, row 0), scan all the cells (skipping the diagonal cell)
// and store all the column indexes j into array A where M[0][j] == true.
// There are two cases:
// - A is empty. That means 0 is not following anyone, then 0 is the only one that could
//   be an influencer (for anyone else to be an influencer, he must be followed by 0, but that's not the case).
//   Therefore we just need to scan the column 0 to see if all cells are true, if yes, then
//   0 is the influencer, otherwise no influencer.
// - A is not empty. Then those indexes in A can possibly be influencers. We can apply
//   two-pointer techinque to idenfity the only possbile influcener with a linear scan of A.
//   Let A.size = m and i = 0 and j = 1.
//   if m == 1, then we just need to scan column A[0] to see if A[0] is the influencer.
//   if m > 1, then we look at M[A[i]A[j]] and M[A[j]A[i]]. Four cases to consider:
//   - A[i] and A[j] do not follow each other, thus they both cannot be influencer. Let i = j+1 and j = i+1
//   - A[i] and A[j] follow each other, thus they both cannot be influencer. Let i = j+1 and j = i+1
//   - A[i] follows A[j] and A[j] does not follow A[i]. Let i = j and j = i+1.
//   - A[i] does not follow A[j] and A[j] follows A[i]. Let i stay unchanged and j = j+1.
//   - Repeat until i > m-1 or j > m-1.
//   - if i < m, then A[i] is possibly the influencer, scan column A[i] to find out,
//     otherwise there is no influcener.
//   - The invariate of the loop is that Pointer i should point to the only possible influencer.

class Solution {
public:
  vector<int> findInfluencers(vector<vector<bool>>& M) {
    vector<int> ans;
    int N = M.size();
    if (N < 2) return ans;

    vector<int> tmp;
    // scan cells on row 0, skipping M[0][0]
    for (int i = 1; i < N; ++i) {
      if (M[0][i] == true) tmp.push_back(i);
    }

    if (!tmp.size()) { // no one is following member 0
      for (int i = 1; i < N; ++i) { // scan column 0, skipping M[0][0]
        if (M[i][0] == false) return ans;
      }
      ans.push_back(0);
    } else {
      int i = 0, j = 1, m = tmp.size();
      while (i < m && j < m) {
        if (M[tmp[i]][tmp[j]] && M[tmp[j]][tmp[i]]) {
          i = j + 1;
          j = i + 1;
        } else if (!M[tmp[i]][tmp[j]] && !M[tmp[j]][tmp[i]]) {
          i = j + 1;
          j = i + 1;
        } else if (M[tmp[i]][tmp[j]] && !M[tmp[j]][tmp[i]]) {
          i = j;
          j = j + 1;
        } else if (!M[tmp[i]][tmp[j]] && M[tmp[j]][tmp[i]]) {
          j = j + 1;
        }
      }
      // cout << "i = " << i << ", j = " << j << endl;

      if (i < m) {
        for (int k = 0; k < N; ++k) { // scan column 0, skipping M[0][0]
          if (k != tmp[i] && M[k][tmp[i]] == false) return ans;
        }
        ans.push_back(tmp[i]);
      }
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  // test case 1: member 2 is influencer
  vector<bool> r0_1 {false, true, true, true};
  vector<bool> r1_1 {false, false, true, true};
  vector<bool> r2_1 {false, false, false, false};
  vector<bool> r3_1 {true, false, true, false};

  vector<vector<bool>> M1 {r0_1, r1_1, r2_1, r3_1};
  vector<int> ans1 = sol.findInfluencers(M1);
  cout << "Test case 1 - influcener is:\n";
  for (auto n : ans1) cout << n << endl;

  // test case 2: no influencer
  vector<bool> r0_2 {false, true, true, true};
  vector<bool> r1_2 {false, false, true, true};
  vector<bool> r2_2 {false, false, false, true};
  vector<bool> r3_2 {true, false, true, false};

  vector<vector<bool>> M2 {r0_2, r1_2, r2_2, r3_2};
  vector<int> ans2 = sol.findInfluencers(M2);
  cout << "Test case 2 - influcener is:\n";
  for (auto n : ans2)  cout << n << endl;

  // test case 3: no influencer
  vector<bool> r0_3 {false, true, true, true};
  vector<bool> r1_3 {false, false, true, true};
  vector<bool> r2_3 {false, false, false, false};
  vector<bool> r3_3 {true, false, false, false};

  vector<vector<bool>> M3 {r0_3, r1_3, r2_3, r3_3};
  vector<int> ans3 = sol.findInfluencers(M3);
  cout << "Test case 3 - influcener is:\n";
  for (auto n : ans3)  cout << n << endl;

  // test case 4: 3 is influencer
  vector<bool> r0_4 {false, true, true, true};
  vector<bool> r1_4 {false, false, true, true};
  vector<bool> r2_4 {false, false, false, true};
  vector<bool> r3_4 {false, false, false, false};

  vector<vector<bool>> M4 {r0_4, r1_4, r2_4, r3_4};
  vector<int> ans4 = sol.findInfluencers(M4);
  cout << "Test case 4 - influcener is:\n";
  for (auto n : ans4)  cout << n << endl;

  // test case 5: 0 is influencer
  vector<bool> r0_5 {false, false, false, false};
  vector<bool> r1_5 {true, false, true, true};
  vector<bool> r2_5 {true, false, false, true};
  vector<bool> r3_5 {true, false, false, false};

  vector<vector<bool>> M5 {r0_5, r1_5, r2_5, r3_5};
  vector<int> ans5 = sol.findInfluencers(M5);
  cout << "Test case 5 - influcener is:\n";
  for (auto n : ans5)  cout << n << endl;

  // test case 6: no influencer
  vector<bool> r0_6 {false, false, false, false};
  vector<bool> r1_6 {true, false, true, true};
  vector<bool> r2_6 {false, false, false, true};
  vector<bool> r3_6 {true, false, false, false};

  vector<vector<bool>> M6 {r0_6, r1_6, r2_6, r3_6};
  vector<int> ans6 = sol.findInfluencers(M6);
  cout << "Test case 6 - influcener is:\n";
  for (auto n : ans6)  cout << n << endl;

  // test case 7: corner case 1
  vector<vector<bool>> M7;
  vector<int> ans7 = sol.findInfluencers(M7);
  cout << "Test case 7 - influcener is:\n";
  for (auto n : ans7)  cout << n << endl;

  // test case 8: corner case 2
  vector<vector<bool>> M8 {vector<bool> {false}};
  vector<int> ans8 = sol.findInfluencers(M8);
  cout << "Test case 8 - influcener is:\n";
  for (auto n : ans8)  cout << n << endl;

  // test case 9: corner case 3, 1 is influencer
  vector<vector<bool>> M9 {vector<bool> {false, true}, vector<bool> {false, false}};
  vector<int> ans9 = sol.findInfluencers(M9);
  cout << "Test case 9 - influcener is:\n";
  for (auto n : ans9)  cout << n << endl;
}
