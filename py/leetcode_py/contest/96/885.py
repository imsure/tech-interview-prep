class Solution:
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort(reverse=True)

        i, j = 0, len(people) - 1

        count = 0
        while i < j:
            if people[i] + people[j] <= limit:
                count += 1
                i += 1
                j -= 1
            else:
                count += 1
                i += 1

        if i == j:
            count += 1

        return count


sol = Solution()
print(sol.numRescueBoats([1,2], 3))
print(sol.numRescueBoats([3,2,2,1], 3))
print(sol.numRescueBoats([3,5,3,4], 5))
