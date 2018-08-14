class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        if len(dislikes) == 0:
            return True

        dset = set()
        for elem in dislikes:
            dset.add((elem[0], elem[1]))

        g1, g2 = set(), set()
        for elem in dislikes:
            p1, p2 = elem
            if p1 in g1 and p2 in g2:
                continue
            elif p1 in g2 and p2 in g1:
                continue
            elif p1 in g1:
                for p in g2:
                    pass


sol = Solution()
print(sol.possibleBipartition(4, [[1,2],[1,3],[2,4]]))