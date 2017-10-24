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

int main()
{
  Solution1 sol;
  // string lcs = sol.findLCS("abc", "abc");
  // string lcs = sol.findLCS("ABAZDC", "BACBAD"); // ABAD
  // string lcs = sol.findLCS("abc", "cba"); // a
  // string lcs = sol.findLCS("", "cba"); // ""
  // string lcs = sol.findLCS("qwertyuioplkjhgfdsa", "wryipljgda"); // wryipljgda
  string lcs = sol.findLCS("qwertyuioplkjhgfdsazxcvb", "wryipljgdaxv"); // wryipljgdaxv (take about 10 secs to finish)
  cout << "LCS: " << lcs << endl;
}
