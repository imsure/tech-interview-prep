#include "common.hpp"

// wrong attemp

class Solution {
public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    bool code = false, line_comment = false, block_comment = false;
    for (auto& line : source) {
      code = false; line_comment = false;
      int space_count = 0;
      string valid_line = "";
      for (int i = 0; i < line.size(); ++i) {
        if (block_comment) {
          if (line[i] == '*' && i+1 < line.size() && line[i+1] == '/') { block_comment = false; }
          else continue;
        } else if (line[i] == '/' && i+1 < line.size() && line[i+1] == '/') { line_comment = true; break; }
        else if (line[i] == '/' && i+1 < line.size() && line[i+1] == '*') { block_comment = true; }
        else if (!block_comment && !line_comment) {
          code = true;
          valid_line[valid_line.size()] = line[i];
          cout << "valid line: " << valid_line << endl;
        }
      }
      if (code) ans.push_back(line);
    }

    return ans;
  }
};


class Solution2 {
public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> ans;

    bool is_block = false;
    string tmp;
    for (auto& line : source) {
      string code;
      int i = 0;
      while (i < line.size()) {
        if (!is_block && line[i] == '/' && i+1 < line.size() && line[i+1] == '/') { // line comment
          break;
        } else if (!is_block && line[i] == '/' && i+1 < line.size() && line[i+1] == '*') { // block comment
          is_block = true;
          if (!code.empty()) { // there are code before the block comment
            tmp = code;
            code.clear();
          }
          i += 2;
        } else if (is_block && line[i] != '*' ||
                   (is_block && line[i] == '*' && i+1 < line.size() && line[i+1] != '/')) { // within block comment
          ++i;
          continue;
        } else if (is_block && line[i] == '*' && i+1 < line.size() && line[i+1] == '/') { // end of block comment
          is_block = false;
          code += tmp;
          tmp.clear();
          i += 2;
        } else { // code
          code.push_back(line[i]);
          ++i;
        }
      }
      if (!code.empty()) ans.push_back(code);
    }

    return ans;
  }
};


// simplified logic and better code quality

class Solution3 {
public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> ans;

    bool is_block = false;
    string code;
    for (auto& line : source) {
      int i = 0;
      while (i < line.size()) {
        if (!is_block && line[i] == '/' && i+1 < line.size() && line[i+1] == '/') { // line comment
          break;
        } else if (!is_block && line[i] == '/' && i+1 < line.size() && line[i+1] == '*') { // start of block comment
          is_block = true;
          ++i;
        } else if (is_block && line[i] == '*' && i+1 < line.size() && line[i+1] == '/') { // end of block comment
          is_block = false;
          ++i;
        } else if (!is_block) { // code
          code.push_back(line[i]);
        }
        ++i;
      }

      if (!is_block && !code.empty()) {
        ans.push_back(code);
        code.clear();
      }
    }

    return ans;
  }
};


int main()
{
  Solution3 sol;
  // vector<string> source {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
  // vector<string> source {"a/* block comment */b"};
  // vector<string> source {"a/*comment", "line", "more_comment*/b"};
  // vector<string> source {"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"};
  vector<string> source {"void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"};
  // vector<string> source {"/*/bcbc//*ebdb/*/bab/*/a/*//*/d/*///*de/*///*d*//dc*///*/cd//*ccd//*a//*caacad"}; // expected: bab

  auto ans = sol.removeComments(source);
  for (auto s : ans) {
    cout << s << endl;
  }
}
