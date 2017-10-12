#include "common.hpp"

// Linear scan the input vector, find the m consecutive words such that
// the total length of m words + (m-1) <= maxWidth and total length of
// m+1 words + m > maxWidth

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int n = words.size();

    if (n == 0 || maxWidth < 0) return ans;

    int line_start = 0, line_end = 1, cur_len = words[0].size();
    for (int i = 1; i < n; ++i) {
      if (cur_len <= maxWidth && (cur_len + words[i].size() + 1) > maxWidth) {
        // try to distribute extra whitespaces evenly.
        int wsize = maxWidth - cur_len; // # of whitespaces to pad
        string line = "";
        if (line_end == line_start + 1) line += words[line_start] + string(wsize, ' ');
        else {
          vector<int> wdist (line_end-line_start-1, 1 + wsize/(line_end-line_start-1));
          wsize = wsize % (line_end-line_start-1);
          for (int k = 0; k < wsize; ++k) {
            wdist[k]++;
          }

          for (int j = line_start; j < line_end; ++j) {
            if (j == line_end-1) line += words[j];
            else line += words[j] + string (wdist[j-line_start], ' ');
          }
        }
        ans.push_back(line);

        cur_len = words[i].size(); // reset
        line_start = line_end;
        line_end = i + 1;
      } else {
        cur_len += words[i].size() + 1;
        ++line_end;
      }
    }

    int wsize = maxWidth - cur_len; // # of whitespaces to pad
    string line = "";
    for (int j = line_start; j < line_end; ++j) {
      if (j == line_end-1) line += words[j] + string(wsize, ' ');
      else line += words[j] + " ";
    }
    ans.push_back(line);

    return ans;
  }
};


int main()
{
  Solution sol;
  // vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> words {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  vector<string> text = sol.fullJustify(words, 30);
  for (auto s : text) {
    cout << s << endl;
  }
}
