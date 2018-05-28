class Solution:
    def customSortString(self, S, T):
        """
        Map each char in T to its count.
        Then linear scan S, for each char c in S, lookup c in the map, if exist,
        output the number of c that matches its count in the returned string. Then
        remove key c from the map.
        In the end, output the remaining keys in the map to the returned string.

        :type S: str
        :type T: str
        :rtype: str
        """
        count = dict()
        for c in T:
            count[c] = count.get(c, 0) + 1

        ans = ''
        for c in S:
            n = count.pop(c, None)
            if n is not None:
                ans += c * n

        for k, v in count.items():
            ans += k * v

        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.customSortString('cba', 'abcd'))  # cbad
    print(sol.customSortString('cbafg', 'abcd'))  # cbad

