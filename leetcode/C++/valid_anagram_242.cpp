#include "common.hpp"


// Hashmap

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> char2cnt;
    for (char c : s) char2cnt[c]++;

    for (char c : t) {
      if (!char2cnt.count(c)) return false;
      char2cnt[c]--;
      if (char2cnt[c] == 0) char2cnt.erase(c);
    }

    return char2cnt.empty();
  }
};


// sorting

class Solution2 {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
  }
};


// use array as map

class Solution3 {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int map[26] = {0};  // elements in int[] will not be zeroed by default like vector, stack ...
    for (char c : s) map[c - 'a']++;

    for (char c : t) {
      if (map[c - 'a'] == 0) return false;
      map[c - 'a']--;
    }

    return true;
  }
};


int main()
{
  Solution3 sol;
  cout << std::boolalpha << sol.isAnagram("anagram", "nagaram") << endl;
  cout << std::boolalpha << sol.isAnagram("rat", "car") << endl;
}
