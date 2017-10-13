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

class Solution2 {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int n = words.size();

    if (n == 0 || maxWidth < 0) return ans;

    // find out words[i] to words[i+k-1] that fit within one line
    for (int i = 0, k, len; i < n; i += k) {
      for (k = 0, len = 0; i + k < n && len + words[i+k].size() <= maxWidth - k; ++k) {
        len += words[i+k].size();
      }
      // fill words[i] to words[i+k-1] to the current line
      string line = "";
      if (k == 1) line += words[i] + string(maxWidth - len, ' '); // line contains a single word
      else {
        // figure out the distribution of whitespaces
        int wsize = maxWidth - len;
        vector<int> wdist (k-1, wsize / (k-1));
        for (int m = 0; m < wsize % (k-1); ++m) {
          wdist[m]++;
        }
        for (int j = i; j < i + k; ++j) {
          if (i + k >= n) line += words[j] + " "; // last line
          else line += words[j] + string(wdist[j-i], ' ');
        }

        if (i + k >= n) line += string(maxWidth-len-k, ' ');
      }
      ans.push_back(line);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  // vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
  // vector<string> words {"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."};
  vector<string> words {"What","must","be","shall","be."};
  vector<string> text = sol.fullJustify(words, 12);
  for (auto s : text) {
    cout << s << endl;
  }
}
