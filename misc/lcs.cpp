/**
 * Problem: Find the  Longest Common Subsequence of the two given string S and T.
 *
 * Note that a subsequence of a string s is obtained by deleting 0 or more
 * characters (not necessarily to be consecutive) from s.
 *
 * e.g., for S = "ABAZDC" and T = "BACBAD", the LCS would be "ABAD"
 *
 */

#include "common.hpp"

// Approach 1: brute force
// Then for each subsequence in S from longest to shortest, see if it
// is also a subsequence of T, if we find one, return it immediately.
// If we've exhausted all subsequences of S, then return empty string.

// time: let S.size() = n and T.size = m, total would be O(2^n + 2^m + 2^n) = O(2^(n+1) + 2^m),
//       so it's exponential time
// space: O(2^n + 2^m), size of power set

class Solution1 {
private:
  void recSubseqs(string sofar, string rest, unordered_set<string>& subseqsSet,
                  unordered_map<int, vector<string>>& subseqsMap, bool useSet) {
    if (rest.empty()) { // have exhausted all elements
      if (sofar.empty()) return;

      if (useSet) subseqsSet.insert(sofar);
      else subseqsMap[sofar.size()].push_back(sofar);
      return;
    }
    // each time isolate one element from the given set

    // recursively find subsets that contains the isolated element
    recSubseqs(sofar + rest[0], rest.substr(1), subseqsSet, subseqsMap, useSet);
    // recursively find subsets that do not contain the isolated element
    recSubseqs(sofar, rest.substr(1), subseqsSet, subseqsMap, useSet);
  }

  void findAllSubseq(string s, unordered_set<string>& subseqsSet,
                     unordered_map<int, vector<string>>& subseqsMap, bool useSet) {
    recSubseqs("", s, subseqsSet, subseqsMap, useSet);
  }

public:
  string findLCS(string S, string T) {
    if (!S.size() || !T.size()) return "";

    unordered_set<string> subseqs_T;
    unordered_map<int, vector<string>> subseqs_S; // key: length of subseqs so we can iterate subseqs from longest to shortest
    findAllSubseq(T, subseqs_T, subseqs_S, true); // time: 2^T.size()
    findAllSubseq(S, subseqs_T, subseqs_S, false); // time: 2^S.size()

    // cout << "subsequences of T: " << T << endl;
    // for (auto seq : subseqs_T) {
    //   cout << seq << endl;
    // }

    // cout << "subsequences of S (longest to shortest): " << S << endl;
    // for (int i = S.size(); i > 0; --i) {
    //   for (int j = 0; j < subseqs_S[i].size(); ++j) cout << subseqs_S[i][j] << endl;
    // }

    // time: 2^S.size()
    for (int i = S.size(); i > 0; --i) {
      for (int j = 0; j < subseqs_S[i].size(); ++j) if (subseqs_T.count(subseqs_S[i][j])) return subseqs_S[i][j];
    }

    return "";
  }
};


// DP approach
// time & space: O(m*n)

class Solution2 {
private:
  void recover(vector<vector<int>>& dp_table, int row, int col,
               string& S, string& T, stringstream& lcs) {
    if (!row || !col) return;

    if (S[row-1] == T[col-1]) {
      recover(dp_table, row-1, col-1, S, T, lcs);
      lcs << S[row-1];
    } else {
      if (dp_table[row][col] == dp_table[row][col-1]) recover(dp_table, row, col-1, S, T, lcs);
      else recover(dp_table, row-1, col, S, T, lcs);
    }
  }

public:
  string findLCS(string S, string T) {
    if (!S.size() || !T.size()) return "";

    int n = S.size();
    int m = T.size();
    // DP table is a 2D array of dimension (n+1)x(m+1)
    vector<vector<int>> dp_table (n+1, vector<int>(m+1, 0));

    // fill the table row-wise
    for (int r = 1; r <= n; ++r) {
      for (int c = 1; c <= m; ++c) {
        if (S[r-1] == T[c-1]) dp_table[r][c] = 1 + dp_table[r-1][c-1]; // e.g., "fec" and "feacbc"
        else dp_table[r][c] = max(dp_table[r][c-1], dp_table[r-1][c]);
      }
    }

    for (int r = 0; r <= n; ++r) {
      for (int c = 0; c <= m; ++c) {
        cout << dp_table[r][c] << ' ';
      }
      cout << endl;
    }

    stringstream lcs;
    recover(dp_table, n, m, S, T, lcs);
    string ans = lcs.str();

    // std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution1 sol;
  // string lcs = sol.findLCS("abc", "abc");
  // string lcs = sol.findLCS("abc", "cab");
  // string lcs = sol.findLCS("ABAZDC", "BACBAD"); // ABAD
  // string lcs = sol.findLCS("abc", "cba"); // a
  // string lcs = sol.findLCS("", "cba"); // ""
  // string lcs = sol.findLCS("qwertyuioplkjhgfdsa", "wryipljgda"); // wryipljgda
  // string lcs = sol.findLCS("qwertyuioplkjhgfdsazxcvb", "wryipljgdaxv"); // wryipljgdaxv (take about 10 secs to finish)
  // cout << "LCS: " << lcs << endl;

  Solution2 sol2;
  // string lcs = sol2.findLCS("abc", "cab");
  string lcs = sol2.findLCS("qwertyuioplkjhgfdsazxcvb", "wryipljgdaxv"); // wryipljgdaxv (take about 8ms to finish)
  cout << "LCS: " << lcs << endl;
}
