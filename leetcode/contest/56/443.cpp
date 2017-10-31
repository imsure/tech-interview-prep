#include "../common.hpp"

class Solution {
public:
  int compress(vector<char>& chars) {
    char cur = chars[0];
    int i = 0, rep_count = 1;
    while (i < chars.size()) {
      rep_count = 1;
      while (i+rep_count < chars.size() && chars[i+rep_count] == cur) ++rep_count;
      if (rep_count == 1) {
        i += rep_count; // next char
        cur = chars[i];
        continue;
      } else { // more than 1
        int j = rep_count;
        stack<char> digits;
        while (j) {
          digits.push('0' + j%10);
          j = j / 10;
        }
        int sz = digits.size();
        while (!digits.empty()) {
          chars[++i] = digits.top();
          digits.pop();
        }

        // remove the remainings
        chars.erase(chars.begin() + i + 1, chars.begin() + i + rep_count - sz);
        //cout << "after earas...\n";
        //for (char c : chars) cout << c << ' ';
        ++i;
        cur = chars[i];
        //cout << "i = " << i << endl;
      }
    }

    return chars.size();
  }
};

int main()
{
  Solution sol;
  // vector<char> chars {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  // vector<char> chars {'a'};
  vector<char> chars {'a', 'b', 'b', 'b', 'b', 'b',  'b', 'b', 'b', 'b', 'b', 'b'};
  cout << sol.compress(chars) << endl;
  for (char c : chars) cout << c << ' ';
  cout << endl;
}
