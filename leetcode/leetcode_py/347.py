class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import Counter
        counter = Counter(nums)
        return [item[0] for item in counter.most_common(k)]


sol = Solution()
print(sol.topKFrequent([1,1,1,2,2,3], 2))
