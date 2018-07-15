class Solution:
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
        from collections import Counter

        ans = 0
        while True:
            position = [i + j for i, j in zip(position, speed)]
            counter = {}
            for index, pos in enumerate(position):
                # if pos >= target: pos = target
                if pos in counter:
                    counter[pos][0] += 1
                    counter[pos][1].append(index)
                else:
                    counter[pos] = [1, [index]]

            # print(position)
            # print(speed)
            # print(ans)

            for k, v in counter.items():
                if k >= target:
                    ans += 1
                    for index in v[1]:
                        position[index] = 0
                        speed[index] = 0
                elif v[0] >= 2:
                    min_speed = min([speed[index] for index in v[1]])
                    for index in v[1]:
                        speed[index] = min_speed

            if all([i == 0 for i in position]):
                break

        return ans


sol = Solution()
# print(sol.carFleet(12, [10,8,0,5,3], [2,4,1,1,3]))
print(sol.carFleet(20, [6,2,17], [3,9,2]))