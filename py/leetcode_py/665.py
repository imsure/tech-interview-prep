class Solution:
    def checkPossibility(self, nums):
        """
        Wrong solution!

        For i in [0...n-2], compare nums[i] with nums[i+1],
        for a non-decreasing array to exist, there can be at most
        one case where nums[i] > nums[i+1].

        :type nums: List[int]
        :rtype: bool
        """
        sorted_list = []
        greater_than_count = 0
        for i in range(0, len(nums) - 1):
            if nums[i] > nums[i+1]:
                greater_than_count += 1
                for num in sorted_list:
                    if num > nums[i+1]:
                        return False
                sorted_list = []
            else:
                sorted_list.append(nums[i])

            if greater_than_count > 1:
                return False

        return True

    def checkPossibility2(self, nums):
        """
        Make a copy of the array as nums_copy.
        For i in [0...n-2], compare nums[i] with nums[i+1], if nums[i] > nums[i+1],
        we have two choices to make the array non-decreasing:
        1) lower nums[i] to nums[i+1]
        2) raise nums[i+1] to nums[i]

        if each of the above action cannot make the array non-decreasing, then return False,
        otherwise return True.

        Time: O(n)
        space: O(n)

        :type nums: List[int]
        :rtype: bool
        """
        nums_copy = nums[:]
        for i in range(0, len(nums) - 1):
            if nums[i] > nums[i+1]:
                nums_copy[i] = nums[i+1]
                if all(nums_copy[i] <= nums_copy[i+1] for i in range(len(nums_copy)-1)):
                    return True
                nums_copy[i] = nums[i]
                nums_copy[i+1] = nums[i]
                if all(nums_copy[i] <= nums_copy[i+1] for i in range(len(nums_copy)-1)):
                    return True
                return False

        return True  # fall through here if len(nums) == 1

    def checkPossibility3(self, nums):
        """
        For i in [0...n-2], compare nums[i] with nums[i+1], if nums[i] > nums[i+1],
        we have two choices to make the array non-decreasing:
        1) lower nums[i] to nums[i+1]
        2) raise nums[i+1] to nums[i]

        if each of the above action cannot make the array non-decreasing, then return False,
        otherwise return True.

        Time: O(n)
        space: O(1)

        :type nums: List[int]
        :rtype: bool
        """
        for i in range(0, len(nums) - 1):
            if nums[i] > nums[i+1]:
                tmp = nums[i]
                nums[i] = nums[i+1]
                if all(nums[i] <= nums[i+1] for i in range(len(nums)-1)):
                    return True
                nums[i] = tmp
                nums[i+1] = nums[i]
                if all(nums[i] <= nums[i+1] for i in range(len(nums)-1)):
                    return True
                return False

        return True  # fall through here if len(nums) == 1


if __name__ == '__main__':
    sol = Solution()
    print(sol.checkPossibility2([4,2,3]))  # True
    print(sol.checkPossibility2([4,2,1]))  # False
    print(sol.checkPossibility2([3,4,2,3]))  # False
    print(sol.checkPossibility2([2,3,3,2,4]))  # True

    print(sol.checkPossibility3([4,2,3]))  # True
    print(sol.checkPossibility3([4,2,1]))  # False
    print(sol.checkPossibility3([3,4,2,3]))  # False
    print(sol.checkPossibility3([2,3,3,2,4]))  # True
