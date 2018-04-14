#include "common.hpp"

// For color code 'X1Y1X2Y2X3Y3', find the color code 'Z1Z1Z2Z2Z3Z3' where
// 'ZiZi' is the closest shorthanded color code to 'XiYi'.

// To find 'ZiZi' for 'XiYi', just increment/decrement 'XiYi' til Xi == Yi, pick
// the smallest among the results from both ways.

// Time: O(1), all loops have constant intertions
// Space: O(1)

// TODO: implement a better solution which round the value of color code to the nearest multiple of 17.


class Solution {
private:
  string find_closest_shorthand(string code, vector<int>& hex2int, vector<int>& int2hex) {
    if (code[0] == code[1]) return code;

    int code_val = hex2int[code[0]] * 16 + hex2int[code[1]];
    int start = code_val;
    int dist_left, dist_right;
    string code_left, code_right;
    while (++start < 256) {
      char c1 = int2hex[start / 16];
      char c2 = int2hex[start % 16];
      if (c1 == c2) {
        code_left.push_back(c1);
        code_left.push_back(c2);
        dist_left = (start - code_val) * (start - code_val);
        break;
      }
    }

    start = code_val;
    while (--start >= 0) {
      char c1 = int2hex[start / 16];
      char c2 = int2hex[start % 16];
      if (c1 == c2) {
        code_right.push_back(c1);
        code_right.push_back(c2);
        dist_right = (start - code_val) * (start - code_val);
        break;
      }
    }

    if (dist_left < dist_right) return code_left;
    return code_right;
  }

public:
  string similarRGB(string color) {
    string ans {'#'};

    vector<int> hex2int (255, 0);
    for (char c = '0'; c <= '9'; ++c) hex2int[c] = c - '0';
    for (char c = 'a'; c <= 'f'; ++c) hex2int[c] = c - 'a' + 10;

    vector<int> int2hex (16, 0);
    for (int i = 0; i <= 15; ++i) {
      if (i < 10) int2hex[i] = i + '0';
      else int2hex[i] = i - 10 + 'a';
    }

    for (int i = 1; i < 7; i += 2) {
      string code = color.substr(i, 2);
      string shorthand = find_closest_shorthand(code, hex2int, int2hex);
      ans.append(shorthand);
    }

    return ans;
  }
};


int main()
{
  Solution sol;
  cout << sol.similarRGB("#09f166") << endl;
}
