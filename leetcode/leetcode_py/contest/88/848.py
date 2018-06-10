class Solution:
    def _shift(self, c, shift):
        after = ord(c) + shift
        if after > ord('z'):
            after -= 26

        return chr(after)

    def shiftingLetters(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        S_list = [c for c in S]
        for index, shift in enumerate(shifts, start=1):
            for i in range(0, index):
                S_list[i] = self._shift(S_list[i], shift % 26)

        return ''.join(S_list)


    def shiftingLetters2(self, S, shifts):
        """
        :type S: str
        :type shifts: List[int]
        :rtype: str
        """
        import itertools
        itertools.accumulate
        S_list = [c for c in S]
        shifts2 = itertools.accumulate(shifts[::-1])
        shifts2 = list(shifts2)[::-1]
        for index, shift in enumerate(shifts2):
            S_list[index] = self._shift(S_list[index], shift % 26)

        return ''.join(S_list)


sol = Solution()
print(sol.shiftingLetters2('abc', [3,5,9]))
print(sol.shiftingLetters('mkgfzkkuxownxvfvxasy',
                          [505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513]))