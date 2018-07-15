class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        words = s.split(sep=' ')
        for index, word in enumerate(words):
            # word = word.strip('.,:!-@&*^%$#~()_+=?|\/[]{}<>')
            new_word = ''
            for c in word:
                if c.isalnum():
                    new_word += c
            words[index] = new_word.lower()

        s2 = ''.join(words)
        # print(s2)
        return s2 == s2[::-1]

    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s_list = [c.lower() for c in s if c.isalnum()]
        return s_list == s_list[::-1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.isPalindrome('A man, a plan, a canal: Panama'))  # true
    print(sol.isPalindrome('race a car'))  # false
    print(sol.isPalindrome('ab@a'))  # true