class Solution:
    def n_sum(self, nums, target, N, result, results):
        if len(nums) < N or N < 2 or nums[0] * N > target or nums[-1] * N < target:
            return

        if N == 2:
            lo, hi = 0, len(nums) - 1
            while lo < hi:
                s = nums[lo] + nums[hi]
                if s == target:
                    results.append(result + [nums[lo], nums[hi]])
                    while lo < hi and nums[lo] == nums[lo+1]:
                        lo += 1
                    lo += 1
                elif s < target:
                    lo += 1
                else:
                    hi -= 1
        else:
            for i in range(len(nums) - N + 1):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                self.n_sum(nums[i+1:], target - nums[i], N - 1, result + [nums[i]], results)

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        results = []
        self.n_sum(nums, target, 4, [], results)
        return results
