#include "common.hpp"

// Gradually move values from Arabic numeral to the Roman numeral
// given the baisc elements composing a Roman numeral:

/**
  M    1000            X   10
  CM    900            IX   9
  D     500            V    5
  CD    400            IV   4
  C     100            I    1
  XC     90
  L      50
  XL     40
*/

class Solution {
public:
  string intToRoman(int num) {
    string roman;

    while (num >= 1000) { // [1000,]
      roman.push_back('M');
      num -= 1000;
    }

    if (num >= 900) { // [900, 1000)
      roman.append("CM");
      num -= 900;
    }

    if (num >= 500) { // [500, 900)
      roman.push_back('D');
      num -= 500;
    }

    if (num >= 400) { // [400, 500)
      roman.append("CD");
      num -= 400;
    }

    while (num >= 100) { // [100, 400)
      roman.push_back('C');
      num -= 100;
    }

    if (num >= 90) { // [90, 100)
      roman.append("XC");
      num -= 90;
    }

    if (num >= 50) { // [50, 90)
      roman.push_back('L');
      num -= 50;
    }

    if (num >= 40) { // [40, 50)
      roman.append("XL");
      num -= 40;
    }

    while (num >= 10) { // [10, 40)
      roman.push_back('X');
      num -= 10;
    }

    if (num >= 9) { // [9, 10)
      roman.append("IX");
      num -= 9;
    }

    if (num >= 5) { // [5, 9)
      roman.push_back('V');
      num -= 5;
    }

    if (num >= 4) { // [4, 5)
      roman.append("IV");
      num -= 4;
    }

    while (num >= 1) { // [1, 4)
      roman.push_back('I');
      num -= 1;
    }

    return roman;
  }
};


// more concise code by using array smart

class Solution2 {
public:
  string intToRoman(int num) {
    string roman;
    vector<pair<int, string>> table {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
      {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (int i = 0; i < table.size(); ++i) {
      int v = table[i].first;
      string s = table[i].second;
      while (num >= v) {
        roman.append(s);
        num -= v;
      }
    }

    return roman;
  }
};


int main()
{
  Solution2 sol;
  cout << sol.intToRoman(3999) << endl; // MMMCMXCIX
  cout << sol.intToRoman(678) << endl; // DCLXXVIII
  cout << sol.intToRoman(8) << endl; // VIII
}
