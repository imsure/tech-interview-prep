class Solution:
    def findUnsortedSubarray(self, nums):
        """
        Make a copy of the input array and sort it. Compare the two arrays
        to find the leftmost and rightmost elements that mismatch. The sub-array
        lying between them is the shortest unsorted sub-array.

        time: O(NlogN)
        space: O(N)

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

    def findUnsortedSubarray1(self, nums):
        """


        time: O(NlogN)
        space: O(N)

        :type nums: List[int]
        :rtype: int
        """
        nums_sorted = sorted(nums)
        same = [nums[i] == nums_sorted[i] for i in range(0, len(nums))]
        if all(same):
            return 0
        beg = same.index(False)
        end = len(nums) - same[::-1].index(False) - 1
        return end - beg + 1

    def findUnsortedSubarray2(self, nums):
        """
        The goal is to find out the correct positions ('start' and 'end') for
        the minimum and maximum elements of the unsorted sub-array.
        Assign 'start' = len(nums) and 'end' = 0 as the initial values.
        If 'start' >= 'end', that means the input is already sorted, thus we start
        with this assumption and find out the correct values of them incrementally.

        We make use of a stack: traverse the array from beginning to the end, whenever
        facing elements in ascending order, keep pushing their indices and values on the stack.
        If we see an element in descending order comparing to the previous elements, keeping
        popping elements from the stack and update 'start' = min('start', index of the top element)
        until it is in the correct order or the stack becomes empty.

        Do the same to find the 'end'. Just traversing the array from end to the beginning and
        use max function to update 'end'.

        Property must be held: elements in the stack are sorted already.

        time: O(N)
        space: O(N)

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

    def findUnsortedSubarray3(self, nums):
        """
        Slightly optimized base on findUnsortedSubarray2.
        As soon as 'start' == 0 or 'end' == len(nums) - 1, break the loop.

        time: O(N)
        space: O(N)
        """
        stack = []
        start, end = len(nums), 0  # assuming the input is already sorted
        for index, num in enumerate(nums):
            while stack and stack[-1][1] > num:
                # update start position of the unsorted subarray seen so far
                start = min(start, stack.pop()[0])
            if start == 0:
                break
            stack.append((index, num))

        for r_index, num in enumerate(nums[::-1]):
            index = len(nums) - r_index - 1
            while stack and stack[-1][1] < num:
                # update end position of the unsorted subarray seen so far
                end = max(end, stack.pop()[0])
            if end == len(nums) - 1:
                break
            stack.append((index, num))

        return end - start + 1 if end > start else 0

    def findUnsortedSubarray4(self, nums):
        """
        Traverse the input from beginning to the end, as long as the elements
        appear in ascending order, keep going until seeing first element that
        is out of order. Find the minimum element starting from this element
        until the end, this is the minimum element of the unsorted sub-array
        we are looking for. Then starting from the beginning of the input, find
        the first element that is larger than the minimum element, the position of
        this element is the 'start' position.

        The same idea applies to how to find 'end' position.

        time: O(N)
        space: O(1)
        """
        import sys
        min_elem = sys.maxsize
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                min_elem = min(min_elem, nums[i])

        if min_elem == sys.maxsize:  # entire array is already sorted
            return 0

        start = 0
        for i in range(0, len(nums)):
            if nums[i] > min_elem:
                start = i
                break

        max_elem = -sys.maxsize
        for i in range(1, len(nums)):
            if nums[-(i+1)] > nums[-i]:
                max_elem = max(max_elem, nums[-(i+1)])

        end = 0
        for i in range(1, len(nums)+1):
            if nums[-i] < max_elem:
                end = len(nums) - i
                break

        return end - start + 1

    def findUnsortedSubarray5(self, nums):
        """
        Slightly optimized version of the above solution.
        """
        import sys
        min_elem, max_elem= sys.maxsize, -sys.maxsize
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                min_elem = min(min_elem, nums[i])
            if nums[-(i+1)] > nums[-i]:
                max_elem = max(max_elem, nums[-(i+1)])

        if min_elem == sys.maxsize:  # entire array is already sorted
            return 0

        start, end = 0, len(nums) - 1
        while start < len(nums) and nums[start] <= min_elem:
            start += 1
        while end >= 0 and nums[end] >= max_elem:
            end -= 1

        return end - start + 1


if __name__ == '__main__':
    sol = Solution()
    print(sol.findUnsortedSubarray([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray2([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray2([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray2([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray2([1, 3, 5, 4, 2]))  # 4

    print(sol.findUnsortedSubarray3([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray3([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray3([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray3([1, 3, 5, 4, 2]))  # 4

    print(sol.findUnsortedSubarray4([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray4([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray4([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray4([1, 3, 5, 4, 2]))  # 4

    print(sol.findUnsortedSubarray5([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray5([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray5([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray5([1, 3, 5, 4, 2]))  # 4

    print(sol.findUnsortedSubarray1([2, 6, 4, 8, 10, 9, 15]))  # 5
    print(sol.findUnsortedSubarray1([1, 2, 3, 4]))  # 0
    print(sol.findUnsortedSubarray1([1, 3, 2, 2, 2]))  # 4
    print(sol.findUnsortedSubarray1([1, 3, 5, 4, 2]))  # 4
