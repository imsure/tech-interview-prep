#include "../common.hpp"

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

int main()
{
  Solution sol;
  vector<string> source {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};

  auto ans = sol.removeComments(source);
  for (auto s : ans) {
    cout << s << endl;
  }
}
