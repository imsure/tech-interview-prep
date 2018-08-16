class Solution:
    def canTransform(self, start, end):
        """
        Collect indices for L in `start` and `end` as SL_1, SL_2, ..., SL_k and
        EL_1, EL_2, ..., EL_k. For each pair <SL_i, EL_i> (1 <= i <= k), verify if
        it's legal to move L from position SL_i to EL_i. It's legal iff:

        * SL_i >= EL_i since L can only move to left (i.e., to smaller indices)
        * sub-array start[EL_i, SL_i) is filled with 'X'

        Do the same for R.

        :type start: str
        :type end: str
        :rtype: bool
        """
        ns = len(start)
        ne = len(end)

        if ns != ne:
            return False

        rindex_start = [i for i, c in enumerate(start) if c == 'R']
        lindex_start = [i for i, c in enumerate(start) if c == 'L']
        rindex_end = [i for i, c in enumerate(end) if c == 'R']
        lindex_end = [i for i, c in enumerate(end) if c == 'L']

        if len(rindex_start) != len(rindex_end) or len(lindex_start) != len(lindex_end):
            return False

        start_list = list(start)
        for i, j in zip(rindex_start[::-1], rindex_end[::-1]):
            if j < i:
                return False

            for k in range(i+1, j+1):
                if start_list[k] != 'X':
                    return False
            start_list[i] = 'X'

        # end_list = list(end)
        for i, j in zip(lindex_start, lindex_end):
            if j > i:
                # print('false case 1')
                return False

            for k in range(j, i):
                if start_list[k] != 'X':
                    # print('false case 2, k = ', k)
                    return False
            start_list[i] = 'X'

        return True


sol = Solution()
print(sol.canTransform('RXXLRXRXL', 'XRLXXRRLX'))  # True
print(sol.canTransform('RXL', 'XRL'))  # True
print(sol.canTransform('RXL', 'LXR'))  # False
print(sol.canTransform('XLXRRXXRXX', 'LXXXXXXRRR'))  # True
print(sol.canTransform('XXRXXLXLXLXXRXXLXLLX', 'XXXRLLLXXXXXXXRLLLXX'))  # True
