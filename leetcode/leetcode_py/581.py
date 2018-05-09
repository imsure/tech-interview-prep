class Solution:
    def findUnsortedSubarray(self, nums):
        """
        Make a copy of the input array and sort it. Compare the two arrays
        to find the leftmost and rightmost elements that mismatch. The sub-array
        lying between them is the shortest unsorted sub-array.

        :type nums: List[int]
        :rtype: int
        """
        s = 0
        e = len(nums) - 1
        sorted_nums = sorted(nums)
        while s < e:
            if nums[s] != sorted_nums[s] and nums[e] != sorted_nums[e]:
                return e - s + 1
            if nums[s] == sorted_nums[s]:
                s += 1
            if nums[e] == sorted_nums[e]:
                e -= 1

        return 0

    def findUnsortedSubarray2(self, nums):
        """
        Use a stack to keep track of consecutive sorted sub-array starting
        from the beginning element. If the current element is >= the top of the
        stack, push the index of it on the stack and move on to the next element.
        Otherwise, keep popping elements from the stack until the element on top
        is <= the current one. The index of the top element indicates the start (index+1) of the
        shortest unsorted sub-array we are looking for.

        Do the same from the end of the array to find the end index.

        Property must be held: elements in the stack are sorted already, if no element in the stack,
        then we must sort the array from beginning or end.

        :type nums: List[int]
        :rtype: int
        """
        stack = []
        start, end = len(nums), 0  # assuming the input is already sorted
        for index, num in enumerate(nums):
            while stack and stack[-1][1] > num:
                # update start position of the unsorted subarray seen so far
                start = min(start, stack.pop()[0])
            stack.append((index, num))

        for r_index, num in enumerate(nums[::-1]):
            index = len(nums) - r_index - 1
            while stack and stack[-1][1] < num:
                # update end position of the unsorted subarray seen so far
                end = max(end, stack.pop()[0])
            stack.append((index, num))

        return end - start + 1 if end > start else 0


if __name__ == '__main__':
    sol = Solution()
    print(sol.findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray2([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray2([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray2([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray2([1, 3, 5, 4, 2]))  # 4
