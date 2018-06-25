class Solution:
    def maxDistToClosest(self, seats):
        """
        Failed Attemp with two pointers!

        Initialize two pointers pointing to the first two sit seats. (if only one seat is taken,
        then the second pointer is -1).

        Scan the input linearly, for each empty seat, there are 3 cases:
        - empty seat is on the left of two pointers
        - empty seat is in between two pointers
        - empty seat is on the right of two pointers

        For the first case:
        update the max distance as the maximum of the current max distance and distance of empty seat
        to the seat pointed to by the first pointer.

        For the second case:
        update the max distance as the maximum of the current max distance and min of distances between empty seat
        to both seats pointed by the two pointers.

        For the third case:
        first update the first pointer using the value of the second pointer, then update
        the second pointer if there is any seat taken after the empty seat, then update
        the max distance as the maximum of the current max distance and min of distances between empty seat
        to both seats pointed by the two pointers.

        :type seats: List[int]
        :rtype: int
        """
        ones = [index for index in range(len(seats)) if seats[index] == 1]
        left = ones[0]
        right = ones[1] if len(ones) > 1 else -1
        next_one = 2

        if right == -1:  # special case
            return max(left - 0, len(seats) - 1 - left)

        max_dist = 0
        for index, seat in enumerate(seats):
            if seat == 1:
                continue

            if index < left:
                max_dist = max(max_dist, left - index)
            elif right == -1:
                max_dist = max(max_dist, index - left)
            elif left < index < right:
                max_dist = max(max_dist, min(index - left, right - index))
            else:
                left = right
                right = ones[next_one] if len(ones) > next_one else -1
                next_one += 1

                if right == -1:
                    max_dist = max(max_dist, index - left)
                else:
                    max_dist = max(max_dist, min(index - left, right - index))

        return max_dist

    def maxDistToClosest2(self, seats):
        """
        Another two-pointer approach:

        Use two pointers 'left' and 'right' to point to the closest person sitting on the left and right.
        Keep updating 'left' and 'right' as we move on and updating the max distance as the max between the current
        value and the min distances to the 'left' and 'right'.

        Special cases need to be taken care where no body sit on your left or right.

        :type seats: List[int]
        :rtype: int
        """
        left, right = -1, -1
        max_dist = 0
        for index, seat in enumerate(seats):
            if seat == 1:
                left = index
            else:
                if right == -1 or right < index:
                    i = index
                    while i < len(seats) and seats[i] == 0:
                        i += 1
                    if i < len(seats):
                        right = i
                    else:
                        right = -1

                if left == -1:
                    max_dist = max(max_dist, right - index)
                if right == -1:
                    max_dist = max(max_dist, index - left)
                else:
                    max_dist = max(max_dist, min(index - left, right - index))

        return max_dist

    def maxDistToClosest_two_pointers(self, seats):
        """
        Improved two-pointer approach:

        Use two pointers 'left' and 'right' to point to the closest person sitting on the left and right.
        Keep updating 'left' and 'right' as we move on and updating the max distance as the max between the current
        value and the min distances to the 'left' and 'right'.

        Special cases need to be taken care where no body sit on your left or right.

        :type seats: List[int]
        :rtype: int
        """
        seated = (i for i, seat in enumerate(seats) if seat == 1)
        left = None
        right = next(seated)

        max_dist = 0
        for i, seat in enumerate(seats):
            if seat == 1:
                left = i
            else:
                while right is not None and i > right:
                    right = next(seated, None)

                if left is not None and right is not None:
                    max_dist = max(max_dist, min(i - left, right - i))
                elif left is not None:
                    max_dist = max(max_dist, i - left)
                else:
                    max_dist = max(max_dist, right - i)

        return max_dist

    def maxDistToClosest_dp(self, seats):
        """
        DP approach:
        Build two tables: left and right where left[i] is the max distance between seat i and
        the closest person sitting on its left, vice versa for right[i]. Then the distance
        for seat i to closest person is the min of left[i] and right[i].

        DP formula is:

        left[i] = 0 if seats[i] == 1
        left[i] = infinity if i == 0 and seats[i] == 0
        left[i] = 1 + left[i-1] if seats[i] == 0 and i > 0

        right[i] = 0 if seats[i] == 1
        right[i] = infinity if i == n-1 and seats[i] == 0
        right[i] = 1 + right[i+1] if seats[i] == 0 and i >= 0

        :param seats: List[int]
        :return:
        """
        n = len(seats)
        left, right = [0] * n, [0] * n

        if seats[0] == 0:
            left[0] = n

        for i in range(1, n):
            if seats[i] == 0:
                left[i] = 1 + left[i-1]

        if seats[n-1] == 0:
            right[n-1] = n

        for i in range(n-2, -1, -1):
            if seats[i] == 0:
                right[i] = 1 + right[i+1]

        max_dist = 0
        for elem in zip(left, right):
            max_left, max_right = elem
            max_dist = max(max_dist, min(max_left, max_right))

        return max_dist

    def maxDistToClosest_groupby_empty_seats(self, seats):
        """
        Group seats by consecutive empty seats. For group with size of K, the max
        distance to the closest seated person is K // 2 + 1.

        For group that starts at 0 or ends at len(seats)-1, the max distance is K.

        :param seats:
        :return:
        """
        max_dist = 0
        i = 0
        while i < len(seats):
            start = i
            while i < len(seats) and seats[i] == 0:
                i += 1
            group_len = i - start
            if start == 0 or i == len(seats):
                max_dist = max(max_dist, group_len)
            else:
                max_dist = max(max_dist, (group_len - 1) // 2 + 1)

            i += 1

        return max_dist


sol = Solution()
print(sol.maxDistToClosest_two_pointers([1,0,0,0,1,0,1]))  # 2
print(sol.maxDistToClosest_two_pointers([1,0,0,0]))  # 3
print(sol.maxDistToClosest_two_pointers([0,1]))  # 1
print(sol.maxDistToClosest_two_pointers([1,1,0,1,1]))  # 1
print(sol.maxDistToClosest_two_pointers([1,1,1,0,1]))  # 1

print(sol.maxDistToClosest_dp([1,0,0,0,1,0,1]))  # 2
print(sol.maxDistToClosest_dp([1,0,0,0]))  # 3
print(sol.maxDistToClosest_dp([0,1]))  # 1
print(sol.maxDistToClosest_dp([1,1,0,1,1]))  # 1
print(sol.maxDistToClosest_dp([1,1,1,0,1]))  # 1

print(sol.maxDistToClosest_groupby_empty_seats([1,0,0,0,1,0,1]))  # 2
print(sol.maxDistToClosest_groupby_empty_seats([1,0,0,0]))  # 3
print(sol.maxDistToClosest_groupby_empty_seats([0,1]))  # 1
print(sol.maxDistToClosest_groupby_empty_seats([1,1,0,1,1]))  # 1
print(sol.maxDistToClosest_groupby_empty_seats([1,1,1,0,1]))  # 1