class Solution:
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        if len(A) == 1:
            return 0

        A.sort()
        lo, hi = 0, len(A) - 1
        while lo < hi:
            if A[hi] - A[lo] > K:
                A[hi] -= K
                A[lo] += K
            elif A[hi] - A[lo] < K:
                if lo == 0:
                    A[hi] += K
                    A[lo] += K
                else:
                    A1 = [A[lo-1], A[lo]+K, A[hi]+K, A[hi+1]]
                    A2 = [A[lo-1], A[lo]-K, A[hi]-K, A[hi+1]]
                    if max(A2) - min(A2) > max(A1) - min(A1):
                        A[lo] += K
                        A[hi] += K
                    else:
                        A[lo] -= K
                        A[hi] -= K
            else:
                if lo == 0:
                    A[hi] += K
                    A[lo] += K
                else:
                    A1 = [A[lo-1], A[lo]+K, A[hi]-K, A[hi+1]]
                    A2 = [A[lo-1], A[lo]+K, A[hi]+K, A[hi+1]]
                    if max(A2) - min(A2) > max(A1) - min(A1):
                        A[lo] += K
                        A[hi] -= K
                    else:
                        A[lo] += K
                        A[hi] += K

            lo += 1
            hi -= 1

        if lo == hi:
            A1 = [A[lo-1], A[lo]+K, A[lo+1]]
            A2 = [A[lo-1], A[lo]-K, A[lo+1]]
            if max(A2) - min(A2) > max(A1) - min(A1):
                A[lo] += K
            else:
                A[lo] -= K

        A.sort()
        # print(A)
        return A[len(A)-1] - A[0]


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