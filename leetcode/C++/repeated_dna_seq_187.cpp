#include "common.hpp"

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<string, int> map;

    for (int i = 0; i + 9 < s.size(); ++i) {
      map[s.substr(i, 10)]++;
    }

    for (auto& kv : map) {
      if (kv.second > 1) ans.push_back(kv.first);
    }

    return ans;
  }
};


// encode 'A', 'C', 'G' and 'T' with 2bits so we can use int as key
// to save memory.

class Solution2 {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    unordered_map<int, int> table;
    unordered_map<char, int> mapping;

    mapping['A'] = 0;
    mapping['C'] = 1;
    mapping['G'] = 2;
    mapping['T'] = 3;

    int key;
    for (int i = 0; i + 9 < s.size(); ++i) {
      key = 0;
      for (int j = 0; j < 10; ++j) {
        key |= mapping[s[i+j]] << (2 * j);
      }
      if (++table[key] == 2) ans.push_back(s.substr(i, 10));
    }

    return ans;
  }
};


// the above solution is still not optimized coz it does a lot of redundant computation.
// key observation: let s = 'AAAAACCCCCT', the first 10-letter substr is "AAAAACCCCC" which
// is encoded as an int in the binary format of 00000000000101010101, the second 10-letter
// substr is "AAAACCCCCT" which is 00000000010101010111, which can be computed by
// left-shifting the one computed for "AAAAACCCCC", then OR with 11 to place T at the end, then
// AND 0xFFFFF so that we only count for the first 20-bit of the integer.

class Solution3 {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if (s.size() < 11) return ans;

    unordered_map<int, int> map;
    vector<int> encode (127);

    encode['A'] = 0;
    encode['C'] = 1;
    encode['G'] = 2;
    encode['T'] = 3;

    int i = 0, key = 0;
    while (i < 10) {
      key |= encode[s[i]] << (i * 2);
      ++i;
    }
    map[key]++;

    for (i = 1; i + 9 < s.size(); ++i) {
      key = (key >> 2) | (encode[s[i+9]] << 18);
      if (++map[key] == 2) ans.push_back(s.substr(i, 10));
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  // vector<string> ans = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  // vector<string> ans = sol.findRepeatedDnaSequences("ACGCCGTTC");
  vector<string> ans = sol.findRepeatedDnaSequences("AAAAAAAAAAA");
  for (auto s : ans) cout << s << endl;
}
