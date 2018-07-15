class Solution:
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        max_dist = 0
        pos_one = -1
        n = len(seats)

        ones = [index for index, seat in enumerate(seats) if seat == 1]
        # print(ones)

        for index, seat in enumerate(seats):
            if seat == 0:
                dist_left = n
                for i in range(index-1, -1, -1):
                    try:
                        i_left = ones.index(i)
                        dist_left = index - i
                        break
                    except ValueError:
                        pass
                dist_right = n
                for i in range(index+1, n):
                    try:
                        i_right = ones.index(i)
                        dist_right = i - index
                        break
                    except ValueError:
                        pass
                max_dist = max(max_dist, min(dist_left, dist_right))

        return max_dist

    def maxDistToClosest2(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        max_dist = 0
        n = len(seats)

        ones = [index for index, seat in enumerate(seats) if seat == 1]
        zeros = [index for index, seat in enumerate(seats) if seat == 0]

        index = 0
        for zero_pos in zeros:
            while index < len(ones) and zero_pos > ones[index]:
                index += 1

            if index == 0:
                max_dist = max(max_dist, ones[0] - zero_pos)
            elif index == len(ones):
                max_dist = max(max_dist, zero_pos - ones[index-1])
            else:
                dist_left = zero_pos - ones[index-1]
                dist_right = ones[index] - zero_pos
                max_dist = max(max_dist, min(dist_left, dist_right))

        return max_dist


sol = Solution()
print(sol.maxDistToClosest2([1,0,0,0,1,0,1]))
print(sol.maxDistToClosest2([1,0,0,0]))
print(sol.maxDistToClosest2([0,1]))