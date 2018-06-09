class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        ans = ''

        map1 = [0] * 256
        for c in s:
            map1[ord(c)] += 1

        map2 = {}
        for k, v in enumerate(map1):
            map2.setdefault(v, []).append(k)

        for i in range(n, 0, -1):
            if i in map2:
                for c in map2[i]:
                    ans += chr(c) * i

        return ans

    def frequencySort2(self, s):
        """
        :type s: str
        :rtype: str
        """
        from collections import Counter
        counter = Counter(s)
        counts = counter.most_common()
        return ''.join([c * n for (c, n) in counts])


sol = Solution()
print(sol.frequencySort2('tree'))
print(sol.frequencySort2('cccaaa'))
print(sol.frequencySort2('cccaaa'))
print(sol.frequencySort2('Aabb'))
