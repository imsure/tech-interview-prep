class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        ans = ""
        step = 0
        flag = False
        index_ = -1
        for i in range(0, len(S)):
            if flag and i < index_ + step:
                continue
            else:
                flag = False
                step = 0

            if i in indexes:
                index = indexes.index(i)
                index_ = i
                if S[i:].startswith(sources[index]):
                    ans += targets[index]
                    flag = True
                    step = len(sources[index])
                else:
                    ans += S[i]
            else:
                ans += S[i]

        return ans

if __name__ == '__main__':
    sol = Solution()
    print(sol.findReplaceString("abcd", [0,2], ["a","cd"], ["eee","ffff"]))