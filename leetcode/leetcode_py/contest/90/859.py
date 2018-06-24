class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False

        map_a, map_b = {}, {}
        flag = False
        for index, c in enumerate(A):
            map_a[c] = map_a.get(c, set())
            map_a[c].add(index)
            if len(map_a[c]) > 1:
                flag = True

        # print(map_a)

        for index, c in enumerate(B):
            if c not in map_a:
                return False
            if index in map_a[c]:
                map_a[c].remove(index)
                if len(map_a[c]) == 0:
                    map_a.pop(c)

        # print(map_a)
        if len(map_a) == 2:
            count = 0
            for key in map_a:
                count += len(map_a[key])

            if count == 2:
                return True
        elif len(map_a) == 0 and flag:
            return True

        return False


sol = Solution()
print(sol.buddyStrings('ab', 'ba'))
print(sol.buddyStrings('aa', 'aa'))
print(sol.buddyStrings('ab', 'ab'))
print(sol.buddyStrings('aaaaaaabc', 'aaaaaaacb'))