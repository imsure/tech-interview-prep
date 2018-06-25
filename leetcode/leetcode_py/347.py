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

    def topKFrequent2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        import heapq
        freq_count = {}
        for num in nums:
            freq_count[num] = freq_count.get(num, 0) + 1

        heap = [(count, num) for num, count in freq_count.items()]
        heapq.heapify(heap)
        return [item[1] for item in heapq.nlargest(k, heap)]


sol = Solution()
print(sol.topKFrequent([1,1,1,2,2,3], 2))
print(sol.topKFrequent2([1,1,1,2,2,3], 2))

