class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        licensePlate = licensePlate.lower()
        base = {}
        for c in licensePlate:
            if c.isalpha():
                base[c] = base.get(c, 0) + 1

        import sys
        ans = ''
        min_len = sys.maxsize
        for word in words:
            target = {}
            for c in word:
                target[c] = target.get(c, 0) + 1

            match = True
            for base_k, base_v in base.items():
                if base_k not in target or target[base_k] < base_v:
                    match = False

            if match and len(word) < min_len:
                ans = word
                min_len = min(min_len, len(word))

        return ans


sol = Solution()
print(sol.shortestCompletingWord("1s3 PSt", ["step", "steps", "stripe", "stepple"]))
print(sol.shortestCompletingWord("1s3 456", ["looks", "pest", "stew", "show"]))
