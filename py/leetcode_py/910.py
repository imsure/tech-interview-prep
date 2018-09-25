class Solution:
    def smallestRangeII(self, A, K):
        """
        Sort A. For i] < j, the smallest difference between A[i] and A[j] is the smaller
        one between (A[j] - A[i]) and abs(A[i] + K - (A[j] - K)), it doesn't make sense
        to lower A[i] while increasing A[j], that's only going to raising the gap further.

        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        n = len(A)

        left, right = A[0] + K, A[n-1] - K
        ans = A[n-1] - A[0]

        # For each element A[i] in between A[0] and A[n-1],
        for i in range(0, n-1):
            smaller = min(A[i+1] - K, left)
            larger = max(A[i] + K, right)
            ans = min(ans, larger - smaller)

        return ans


sol = Solution()
print(sol.smallestRangeII([1], 0)) # 0
print(sol.smallestRangeII([0,10], 2)) # 6
print(sol.smallestRangeII([1,3,6], 3)) # 3
print(sol.smallestRangeII([4,1,8,10], 3)) # 3
print(sol.smallestRangeII([10,7,1], 3)) # 3
print(sol.smallestRangeII([1,6,6,9], 2)) # 4
print(sol.smallestRangeII([7,8,8], 5)) # 1
print(sol.smallestRangeII([9,10,5,9], 5)) # 5
print(sol.smallestRangeII([4,8,2,7,2], 5)) # 6
