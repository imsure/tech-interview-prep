class Solution:
    def canTransform(self, start, end):
        """
        A bit naive solution, but in the right direction.

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

    def canTransform2(self, start, end):
        """
        A much improved solution: one pass + no extra space

        Position two pointers i and j at the beginning of `start` and `end`.
        Advance both pointers as long as the element they point to is 'X'. Stop advancing
        when either 'L' or 'R' is encountered.

        The following cases are enumerated:
        - i == j == len(start), return True
        - start[i] == end[j]
          * start[i] == end[j] == 'L',
            if i >= j, i += 1, j += 1, otherwise return False because 'L' can only move leftwards.
          * start[i] == end[j] == 'R',
            if i <= j, i += 1, j += 1, otherwise return False because 'R' can only move rightwords.
        - start[i] != end[j], return False,
          because this means some 'L' and some 'R' in `start` must cross each other to transform to `end`.

        :param start:
        :param end:
        :return:
        """
        m, n = len(start), len(end)
        if m != n:
            return False

        i = j = 0
        while True:
            while i < n and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1

            if i == j == n:
                return True
            elif i == n or j == n:
                return False

            if start[i] == end[j] == 'L':
                if i >= j:
                    i += 1
                    j += 1
                else:
                    return False
            elif start[i] == end[j] == 'R':
                if i <= j:
                    i += 1
                    j += 1
                else:
                    return False
            else:
                return False


sol = Solution()
print(sol.canTransform2('RXXLRXRXL', 'XRLXXRRLX'))  # True
print(sol.canTransform2('RXL', 'XRL'))  # True
print(sol.canTransform2('RXL', 'LXR'))  # False
print(sol.canTransform2('XLXRRXXRXX', 'LXXXXXXRRR'))  # True
print(sol.canTransform2('XXRXXLXLXLXXRXXLXLLX', 'XXXRLLLXXXXXXXRLLLXX'))  # True
print(sol.canTransform2('X', 'L'))  # False
