class Solution:

  def threeSum(self, nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    n = len(nums)
    nums.sort()
    ans = []

    for i in range(n - 2):
      if i > 0 and nums[i] == nums[i - 1]:  # skip duplicates
        continue

      head, tail = i + 1, n - 1
      while head < tail:
        twosum = nums[head] + nums[tail]
        if twosum == -nums[i]:
          ans.append([nums[i], nums[head], nums[tail]])
          while head < tail and nums[head] == nums[head + 1]:
            head += 1
          while head < tail and nums[tail] == nums[tail - 1]:
            tail -= 1
          head += 1
          tail -= 1
        elif twosum < -nums[i]:
          head += 1
        else:
          tail -= 1

    return ans
