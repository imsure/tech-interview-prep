class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        import sys
        max1 = -sys.maxsize
        max2, max3 = max1, max1

        for num in nums:
            if num > max1:
                max3 = max2
                max2 = max1
                max1 = num
            elif max2 < num < max1:
                max3 = max2
                max2 = num
            elif max3 < num < max2:
                max3 = num

        return max3 if max3 > -sys.maxsize else max1


if __name__ == '__main__':
    sol = Solution()
    print(sol.thirdMax([3, 2, 1]))  # 1
    print(sol.thirdMax([2, 1]))  # 2
    print(sol.thirdMax([2, 2, 3, 1]))  # 1
    print(sol.thirdMax([5, 2, 2]))  # 5
