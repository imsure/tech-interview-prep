class Solution:
    def lengthOfLIS(self, nums):
        """
        DP approach

        Time: O(n^2)
        Space: O(n^2)

        TLE

        :type nums: List[int]
        :rtype: int
        """
        import sys

        n = len(nums)
        if n == 0:
            return 0

        nums.insert(0, -sys.maxsize)

        T = []
        for i in range(n+1):
            T.append([0] * (n+2))

        for j in range(n, 0, -1):
            for i in range(0, j):
                if nums[i] >= nums[j]:
                    T[i][j] = T[i][j+1]
                else:
                    T[i][j] = max(T[i][j+1], 1 + T[j][j+1])

        return T[0][1]

    def lengthOfLIS2(self, nums):
        """
        DP approach 2: define dp[i] as LIS of nums[i...n] that starts with nums[i].
        DP formula: dp[i] = 1 + max{dp[j] | j > i and nums[j] > nums[i]}

        Time: O(n^2)
        Space: O(n)

        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0

        dp = [0] * n
        dp[n-1] = 1
        ans = 1
        for i in range(n-2, -1, -1):
            m = 0
            for j in range(i, n):
                if nums[j] > nums[i]:
                    m = max(m, dp[j])
            dp[i] = 1 + m
            ans = max(ans, dp[i])

        return ans

    def lengthOfLIS3(self, nums):
        """
        sorted list + binary search

        :param nums:
        :return:
        """
        import bisect
        lis = []

        for num in nums:
            insert_pos = bisect.bisect_left(lis, num)
            if insert_pos == len(lis):
                lis.append(num)
            else:
                lis[insert_pos] = num

        return len(lis)
