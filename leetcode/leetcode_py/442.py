class Solution:
    def findDuplicates(self, nums):
        """
        Sort the array then linear scan.

        Time: O(NlogN)

        :type nums: List[int]
        :rtype: List[int]
        """
        nums = sorted(nums)
        ans = []
        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i + 1]:
                ans.append(nums[i])
                i += 2
            else:
                i += 1

        return ans

    def findDuplicates2(self, nums):
        """
        Map element to its count and pick those with count of 2.

        Time: O(N)
        Space: O(N)

        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        elem2count = {}
        for num in nums:
            elem2count[num] = elem2count.get(num, 0) + 1
            if elem2count[num] == 2:
                ans.append(num)

        return ans

    def findDuplicates3(self, nums):
        """
        Each num in the input array can also be used as index since array size is N
        and 1 <= num <= N. Thus two same num would be indexed to the same element.

        We can linear scan the array and for each num, see if the element it's indexing
        to is positive, if yes, alter to negative counterpart to indicate it's marked.
        Later on if the same num is encountered, we'd see this element being negative, that
        means this num is a duplicate.

        Time: O(N)
        Space: O(1)

        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for num in nums:
            index = abs(num) - 1
            if nums[index] > 0:
                nums[index] = -nums[index]
            else:
                ans.append(index + 1)

        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.findDuplicates([4,3,2,7,8,2,3,1]))
    print(sol.findDuplicates2([4,3,2,7,8,2,3,1]))
    print(sol.findDuplicates3([4,3,2,7,8,2,3,1]))