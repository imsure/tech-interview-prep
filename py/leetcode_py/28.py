class Solution:
    def strStr(self, haystack, needle):
        """
        use python array slicing

        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0

        if len(needle) > len(haystack):
            return -1

        i = 0
        while i < len(haystack):
            if haystack[i:i+len(needle)] == needle:
                return i
            i += 1

        return -1


    def strStr2(self, haystack, needle):
        """
        two pointers

        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0

        if len(needle) > len(haystack):
            return -1

        for i in range(0, len(haystack)):
            p1 = i
            p2 = 0
            while p1 < len(haystack) and p2 < len(needle) and haystack[p1] == needle[p2]:
                p1 += 1
                p2 += 1

            if p2 == len(needle):
                return i

        return -1


if __name__ == '__main__':
    sol = Solution()

    print(sol.strStr('hello', 'll'))  # 2
    print(sol.strStr('aaaaa', 'bba'))  # -1
    print(sol.strStr('mississippi', 'issip'))  # 4

    print(sol.strStr2('hello', 'll'))  # 2
    print(sol.strStr2('aaaaa', 'bba'))  # -1
    print(sol.strStr2('mississippi', 'issip'))  # 4
