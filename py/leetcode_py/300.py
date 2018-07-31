class Solution:
    def lengthOfLIS(self, nums):
        """
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
        TLE

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
