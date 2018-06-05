class Solution:
    def transform(self, S):
        s = ''
        i = len(S) - 1
        tag_count = 0
        while i >= 0:
            if S[i] != '#':
                s += S[i]
                i -= 1
            else:
                while i >= 0 and S[i] == '#':
                    tag_count += 1
                    i -= 1

                while i >= 0 and S[i] != '#' and tag_count > 0:
                    i -= 1
                    tag_count -= 1

        return s[::-1]

    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s, t = self.transform(S), self.transform(T)
        # print(s)
        # print(t)
        return s == t


if __name__ == '__main__':
    sol = Solution()
    print(sol.backspaceCompare('ab#c', 'ad#c'))  # true
    print(sol.backspaceCompare('ab##', 'c#d#'))  # true
    print(sol.backspaceCompare('a##c', '#a#c'))  # true
    print(sol.backspaceCompare('a#c', 'b'))  # false
    print(sol.backspaceCompare('bxj##tw', 'bxo#j##tw'))  # true
    print(sol.backspaceCompare('xywrrmp', 'xywrrmu#p'))  # true
