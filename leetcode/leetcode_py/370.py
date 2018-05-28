class Solution:
    def getModifiedArray(self, length, updates):
        """
        Brute force: TLE

        Time: O(KN), K = len(updates), N = length

        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        array = [0] * length
        for op in updates:
            start, end, inc = op[0], op[1], op[2]
            cond1 = 0 <= start < length
            cond2 = 0 <= end < length
            if cond1 and cond2:
                for i in range(start, end + 1):
                    array[i] += inc

        return array

    def getModifiedArray2(self, length, updates):
        """
        Two passes: 1st pass only make changes to the array at the start and end of
        each update operation; 2nd pass then use propagate changes to the entire array.

        Specifically, given an 'array', for each operation [start, end, inc], let:
        array[start] += inc
        array[end + 1] += inc

        Then linear scan the array:
        array[i] += array[i-1]

        Time: O(K+N), K = len(updates), N = length

        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        array = [0] * length
        for op in updates:
            start, end, inc = op[0], op[1], op[2]
            cond1 = 0 <= start < length
            cond2 = 0 <= end < length
            if cond1 and cond2:
                array[start] += inc
                if end + 1 < length:
                    array[end + 1] += -inc

        for i in range(1, length):
            array[i] += array[i-1]

        return array


if __name__ == '__main__':
    sol = Solution()
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]
    print(sol.getModifiedArray(5, updates))
    print(sol.getModifiedArray2(5, updates))

    updates = [[2,4,6],[5,6,8],[1,9,-4]]
    print(sol.getModifiedArray(10, updates))
    print(sol.getModifiedArray2(10, updates))
