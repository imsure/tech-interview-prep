class TopVotedCandidate:
    """
    Pre-compute + binary search
    """

    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """
        import collections

        self.persons = persons
        self.times = times
        self.leads = {}
        lead_so_far = -1
        max_vote_so_far = 0
        counts = collections.defaultdict(lambda: 0)
        for p, t in zip(persons, times):
            counts[p] += 1
            if counts[p] >= max_vote_so_far:
                self.leads[t] = p
                max_vote_so_far = counts[p]
                lead_so_far = p
            else:
                self.leads[t] = lead_so_far
        # print(self.leads)

    # return the index of the largest time in self.times that is <= t
    def binary_search(self, t):
        lo, hi = 0, len(self.times) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.times[mid] > t:
                hi = mid - 1
            elif self.times[mid] < t:
                lo = mid + 1
            else:
                return mid

        return lo - 1

    def q(self, t):
        """
        :type t: int
        :rtype: int
        """
        index = self.binary_search(t)
        return self.leads[self.times[index]]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate([0,1,1,0,0,1,0], [0,5,10,15,20,25,30])
# print(obj.q(3))   # 0
# print(obj.q(12))  # 1
# print(obj.q(25))  # 1
# print(obj.q(15))  # 0
# print(obj.q(24))  # 0
# print(obj.q(8))   # 1

obj = TopVotedCandidate([0,0,0,0,1],[0,6,39,52,75])
print(obj.q(75))

