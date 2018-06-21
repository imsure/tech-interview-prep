class Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        count = {}
        for ans in answers:
            count[ans] = count.get(ans, 0) + 1

        ret = 0
        for k, v in count.items():
            num_groups = v // (k + 1)
            remain = v % (k + 1)
            if remain > 0:
                num_groups += 1
            ret += (1 + k) * num_groups

        return ret


sol = Solution()
print(sol.numRabbits([1, 1, 2]))  # 5
print(sol.numRabbits([10, 10, 10]))  # 11
print(sol.numRabbits([]))  # 0
print(sol.numRabbits([1,0,1,0,0]))  # 5
print(sol.numRabbits([]))  # 0
