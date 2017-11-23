#### Approach #1 Dynamic Programming [Accepted]

**Intuition and Algorithm**

Let `dp[x][i][j]` be the answer for the substring `S[i...j]` where
`S[i] == S[j] == 'a'+x`. Note that since we only have 4 characters `a,
b, c, d`, thus `0 <= x < 4`. The DP formula goes as follows:

* If `S[i] != 'a'+x`, then `dp[x][i][j] = dp[x][i+1][j]`, note that
  here we leave the first character `S[i]` in the window out due to
  our definition of `dp[x][i][j]`.

* If `S[j] != 'a'+x`, then `dp[x][i][j] = dp[x][i][j-1]`, leaving the
  last character `S[j]` out.

* If `S[i] == S[j] == 'a'+x`, then `dp[x][i][j] = 2 +
  dp[0][i+1][j-1] + dp[1][i+1][j-1] + dp[2][i+1][j-1] +
  dp[3][i+1][j-1]`. When the first and last characters are the same, we
  need to count all the distinct palindromes (for each of `a,b,c,d`) within
  the sub-window `S[i+1][j-1]` plus the `2` palindromes contributed by
  the first and last characters.
  
Let `n` be the length of the input string `S`, The final answer would
be `dp[0][0][n-1] + dp[1][0][n-1] + dp[2][0][n-1] + dp[3][0][n-1]`
mod `1000000007`.

**C++**

```C++
class Solution {
public:
  int countPalindromicSubsequences(string S) {
    int n = S.size();
    int mod = 1000000007;
    auto dp_ptr = new vector<vector<vector<int>>>(4, vector<vector<int>>(n, vector<int>(n)));
    auto& dp = *dp_ptr;

    for (int i = n-1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        for (int k = 0; k < 4; ++k) {
          char c = 'a' + k;
          if (j == i) {
            if (S[i] == c) dp[k][i][j] = 1;
            else dp[k][i][j] = 0;
          } else { // j > i
            if (S[i] != c) dp[k][i][j] = dp[k][i+1][j];
            else if (S[j] != c) dp[k][i][j] = dp[k][i][j-1];
            else { // S[i] == S[j] == c
              if (j == i+1) dp[k][i][j] = 2; // "aa" : {"a", "aa"}
              else { // length is > 2
                dp[k][i][j] = 2;
                for (int m = 0; m < 4; ++m) { // count each one within subwindows [i+1][j-1]
                  dp[k][i][j] += dp[m][i+1][j-1];
                  dp[k][i][j] %= mod;
                }
              }
            }
          }
        }
      }
    }

    int ans = 0;
    for (int k = 0; k < 4; ++k) {
      ans += dp[k][0][n-1];
      ans %= mod;
    }

    return ans;
  }
};
```

**Example Walkthrough**

Indeed this is a hard problem to solve and thoroughly understanding
its solution is also challenging. Maybe the best way to understand the
above approach is to walkthrough some simple examples to help build up
intuitions.


**Complexity Analysis**

* Time complexity : $$O(n^2)$$ where $$n$$ is the length of the input
  string $$S$$. It takes quadratic time to fill up the DP table.
  
* Space complexity : $$O(n^2)$$ where $$n$$ is the length of the input
  string $$S$$. The DP table takes quadratic space.
  
Note that we ignore the constant factor $$4$$ in the above analysis.


**Conclusion**

As we look back, this problem reveals a key attribute which indicates
that dynamic programming might be a good fit: `overlapping
sub-problems` as we recall the DP formula. By practicing more
problems, we can build up this kind of intuition.


*Credit*: the above solution is inspired by
[this post](https://discuss.leetcode.com/topic/111241/c-o-n-2-time-o-n-memory-with-explanation)
written by @elastico. His solution is space optimized. However, I found
that my approach is relatively easy to understand for people who found
this problem hard to approach.
