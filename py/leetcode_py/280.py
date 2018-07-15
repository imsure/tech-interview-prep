class Solution:
    def wiggleSort(self, nums):
        """
        Linear scan the input and compare each pair to see if it's in the correct
        order, if not, then just swap them.

        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        wiggle = False
        for i in range(len(nums) - 1):
            if not wiggle:
                if nums[i] > nums[i+1]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
                wiggle = True
            else:
                if nums[i] < nums[i+1]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
                wiggle = False


if __name__ == '__main__':
    sol = Solution()
    nums = [3,5,2,1,6,4]
    sol.wiggleSort(nums)
    print(nums)
