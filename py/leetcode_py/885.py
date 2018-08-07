class Solution:
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        ans = 0
        i, j = 0, len(people) - 1
        while i < j:
            ans += 1
            if people[j] + people[i] <= limit:
                j -= 1
                i += 1
            else:
                j -= 1

        if i == j:
            ans += 1

        return ans


sol = Solution()
print(sol.numRescueBoats([1,2], 3))  # 1
print(sol.numRescueBoats([3,2,2,1], 3))  # 3
print(sol.numRescueBoats([3,5,3,4], 5))  # 4
