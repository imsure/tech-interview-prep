import heapq


class ExamRoom:

    def __init__(self, N):
        """
        :type N: int
        """
        self.N = N
        self.pq = []
        self.map1, self.map2 = {}, {}

        elem = [-N, 0, N-1]
        self.map1[0] = elem
        self.map2[N-1] = elem
        heapq.heappush(self.pq, elem)

    def seat(self):
        """
        :rtype: int
        """
        while self.pq:
            sz, start, end = heapq.heappop(self.pq)
            sz = -sz

            if start == -1:
                continue

            if start == 0:
                elem = [-(sz-1), 1, end]
                self.map1[1] = elem
                self.map2[end] = elem
                heapq.heappush(self.pq, elem)
                return 0

            if end == self.N-1:
                elem = [-(sz-1), start, self.N-2]
                self.map1[start] = elem
                self.map2[self.N-2] = elem
                heapq.heappush(self.pq, elem)
                return self.N-1

            pos = (start + end) // 2

            sz1 = pos - start
            # To compensate the odd # of empty seats with 1 because
            # 3 empty seats and 4 empty seats yield the same result, however
            # 3 empty seats has lower priority than 4 empty seats so we want
            # to give it the same priority so that we can pick the one with
            # lower start index.
            # e.g.,
            # 0123456789
            # 1000100001
            # Both 2 and 6 index are best candidates, but we want to pick index 2.
            if sz1 % 2:
                sz1 += 1
            elem1 = [-sz1, start, pos - 1]
            self.map1[start] = elem1
            self.map2[pos-1] = elem1
            heapq.heappush(self.pq, elem1)

            # see comments above
            sz2 = end - pos
            if sz2 % 2:
                sz2 += 1
            elem2 = [-sz2, pos+1, end]
            self.map1[pos+1] = elem2
            self.map2[end] = elem2
            heapq.heappush(self.pq, elem2)

            return pos

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        p_prev = p - 1
        p_next = p + 1

        start, end = p, p
        if p_prev in self.map2:
            start = self.map2[p_prev][1]
            self.map2[p_prev][1] = -1  # mark as invalid

        if p_next in self.map1:
            end = self.map1[p_next][2]
            self.map1[p_next][1] = -1

        merged = [-(end-start+1), start, end]
        self.map1[start] = merged
        self.map2[end] = merged
        heapq.heappush(self.pq, merged)


# Improved code quality
class ExamRoom2:

    def __init__(self, N):
        self.N = N
        self.pq = []
        self.map_start = {}
        self.map_end = {}
        self._put_elem(0, N-1)

    def _put_elem(self, start, end):
        if start > end:
            return

        if start == 0 or end == self.N - 1:
            priority = end - start
        else:
            priority = (end - start) // 2

        elem = [-priority, start, end]
        self.map_start[start] = elem
        self.map_end[end] = elem
        heapq.heappush(self.pq, elem)

    def seat(self):
        """
        :rtype: int
        """
        while self.pq:
            _, start, end = heapq.heappop(self.pq)

            if start == -1:
                continue

            self.map_start.pop(start)
            self.map_end.pop(end)
            if start == 0:  # edge case
                pos = start
                self._put_elem(start+1, end)
            elif end == self.N - 1:  # edge case
                pos = end
                self._put_elem(start, end-1)
            else:
                pos = (end + start) // 2
                self._put_elem(start, pos-1)
                self._put_elem(pos+1, end)

            return pos

    def leave(self, p):
        """
        :type p: int
        :rtype: void
        """
        start, end = p, p
        prev_elem = self.map_end.pop(p - 1, None)
        next_elem = self.map_start.pop(p + 1, None)

        if prev_elem:
            start = prev_elem[1]
            prev_elem[1] = -1  # mark as invalid
        if next_elem:
            end = next_elem[2]
            next_elem[1] = -1  # mark as invalid

        self._put_elem(start, end)


# Your ExamRoom object will be instantiated and called as such:
obj = ExamRoom2(10)
print(obj.seat())  # 0
print(obj.seat())  # 9
print(obj.seat())  # 4
# print(obj.seat())  # 2
obj.leave(0)
obj.leave(4)
print(obj.seat())  # 0
print(obj.seat())  # 4
print(obj.seat())  # 2
print(obj.seat())  # 6
print(obj.seat())  # 1
print(obj.seat())  # 3
print(obj.seat())  # 5
print(obj.seat())  # 7
print(obj.seat())  # 8
obj.leave(0)

