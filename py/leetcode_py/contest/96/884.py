class Solution:
    def decodeAtIndex(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        cur_len = 0
        word, count = '', 0
        for c in S:
            if c.isalpha():
                word += c
                cur_len += 1
            else:
                d = int(c)
                word *= d
                cur_len = len(word)

            if cur_len >= K:
                return word[K-1]

        return None

    def decodeAtIndex2(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        decoded = []
        cur_len = 0
        word = ''
        for c in S:
            if c.isalpha():
                word += c
            else:
                d = int(c)
                decoded.append((word, d))
                cur_len = (cur_len + len(word)) * d
                word = ''

            if cur_len >= K:
                break

        print(decoded)
        print(cur_len)

        period = 0
        for index, item in enumerate(decoded):
            if index < len(decoded) - 1:
                period = (period + len(item[0])) * item[1]
            else:
                period += len(item[0])

        print(period)

        remain = K % period
        print(remain)

        l = 0
        for item in decoded:
            word, count = item[0], item[1]
            l = (l + word) * count
            if l <= remain:
                pass


sol = Solution()
print(sol.decodeAtIndex2('leet2code3', 10))
# print(sol.decodeAtIndex2('ha22', 5))