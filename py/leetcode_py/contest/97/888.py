class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        adict = {}
        for word in A.split(' '):
            adict[word] = adict.get(word, 0) + 1

        bdict = {}
        for word in B.split(' '):
            bdict[word] = bdict.get(word, 0) + 1

        ans = []
        for w, c in adict.items():
            if c == 1 and w not in bdict:
                ans.append(w)

        for w, c in bdict.items():
            if c == 1 and w not in adict:
                ans.append(w)

        return ans


sol = Solution()
print(sol.uncommonFromSentences("this apple is sweet", "this apple is sour"))
print(sol.uncommonFromSentences("apple apple", "banana"))