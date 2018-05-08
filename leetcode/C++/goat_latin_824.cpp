#include "common.hpp"


class Solution {
private:
  string transform(string word, int index, vector<bool>& rule_table) {
    char first = word[0];
    if (rule_table[first]) word.append("ma");
    else {
      word.erase(0, 1);
      word.push_back(first);
      word.append("ma");
    }

    string suffix (index, 'a');
    word.append(suffix);
    return word;
  }

public:
  string toGoatLatin(string S) {
    string ans;
    string word;

    vector<bool> rule_table (128, false);
    rule_table['a'] = true;
    rule_table['e'] = true;
    rule_table['i'] = true;
    rule_table['o'] = true;
    rule_table['u'] = true;
    rule_table['A'] = true;
    rule_table['E'] = true;
    rule_table['I'] = true;
    rule_table['O'] = true;
    rule_table['U'] = true;

    int start = 0, index = 1;
    int found = S.find(' ', start);
    while (found != string::npos) {
      word = S.substr(start, found - start);
      ans += transform(word, index++, rule_table);
      ans += ' ';

      start = found + 1;
      found = S.find(' ', start);
    }

    // last word
    word = S.substr(start);
    ans += transform(word, index, rule_table);
    return ans;
  }
};


int main()
{
  Solution sol;
  cout << sol.toGoatLatin("I speak Goat Latin") << endl;
}
