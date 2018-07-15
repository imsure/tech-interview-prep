class Solution:
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) == 1:
            return str(nums[0])

        if len(nums) == 2:
            return '{}/{}'.format(nums[0], nums[1])

        ans = '{}/({}'.format(nums[0], nums[1])

        for i in range(2, len(nums)):
            ans += '/' + str(nums[i])

        ans += ')'

        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.optimalDivision([1000,100,10,2]))