#include "common.hpp"

// Brute Force (TLE)

class Solution {
private:
  bool isAnagram(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
  }

public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> letter_cnt;
    for (char c : p) letter_cnt[c]++;

    vector<int> ans;
    int i = 0;
    while (i < s.size()) {
      if (letter_cnt.count(s[i])) {
        auto str = s.substr(i, p.size());
        if (isAnagram(str, p)) {
          ans.push_back(i);
        }
      }
      ++i;
    }

    return ans;
  }
};


// Sliding Window + HashMap

class Solution2 {
private:
  bool isAnagram(unordered_map<char, int>& table) {
    for (auto& kv : table) {
      if (kv.second != 0) return false;
    }

    return true;
  }

public:
  vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};

    vector<int> ans;
    unordered_map<char, int> table;
    for (char c : p) table[c]++;

    int i;
    for (i = 0; i < p.size(); ++i) { // initialize window
      if (table.count(s[i])) table[s[i]]--;
    }
    if (isAnagram(table)) ans.push_back(0);

    while (i < s.size()) { // sliding window by one char at a time
      if (table.count(s[i - p.size()])) table[s[i - p.size()]]++;
      if (table.count(s[i])) {
        table[s[i]]--;
        if (isAnagram(table)) ans.push_back(i - p.size() + 1);
      }
      ++i;
    }

    return ans;
  }
};


// Sliding Window + Using Array as HashMap

class Solution3 {
private:
  bool isAnagram(int* t) {
    for (int i = 0; i < 26; ++i) {
      if (t[i]) return false;
    }

    return true;
  }

public:
  vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};

    vector<int> ans;
    int t1[26] = {0};
    bool t2[26] = {false};

    for (char c : p) {
      t1[c - 'a']++;
      t2[c - 'a'] = true;
    }

    int i = 0;
    while (i < p.size()) {
      if (t2[s[i] - 'a']) t1[s[i] - 'a']--;
      ++i;
    }

    if (isAnagram(t1)) ans.push_back(0);

    while (i < s.size()) {
      if (t2[s[i - p.size()] - 'a']) t1[s[i - p.size()] - 'a']++;
      if (t2[s[i] - 'a']) {
        t1[s[i] - 'a']--;
        if (isAnagram(t1)) ans.push_back(i - p.size() + 1);
      }
      ++i;
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  auto res = sol.findAnagrams("cbaebabacd", "abc"); // [0,6]
  // auto res = sol.findAnagrams("abab", "ab"); // [0,1,2]
  for (int n : res) cout << n << ' ';
  cout << '\n';
}
