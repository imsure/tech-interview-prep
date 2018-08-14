class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        if len(dislikes) == 0:
            return True

        map = {}
        for elem in dislikes:
            p1, p2 = elem
            map[p1] = map.get(p1, set())
            map[p1].add(p2)

        # print(map)
        g1 = {dislikes[0][0]}
        g2 = {dislikes[0][1]}
        for elem in dislikes[1:]:
            p1, p2 = elem
            if p1 in g1 and p2 in g2:
                continue

            if p1 in g2 and p2 in g1:
                continue

            if p1 in g1:
                for p in g2:
                    if p in map and p2 in map[p]:
                        return False
                g2.add(p2)
                continue
            elif p1 in g2:
                for p in g1:
                    if p in map and p2 in map[p]:
                        return False
                g1.add(p2)
                continue
            elif p2 in g2:
                for p in g1:
                    if p in map and p1 in map[p]:
                        return False
                g1.add(p1)
                continue
            elif p2 in g1:
                for p in g2:
                    if p in map and p1 in map[p]:
                        return False
                g2.add(p1)
                continue

            p1g1ok = True
            for p in g1:
                if p in map and p1 in map[p]:
                    p1g1ok = False
                    break
            if p1g1ok:
                g1.add(p1)
                for p in g2:
                    if p in map and p2 in map[p]:
                        return False
                g2.add(p2)
            else:  # p1 cannot be put into g1
                for p in g2:
                    if p in map and p1 in map[p]:
                        return False
                g2.add(p1)
                for p in g1:
                    if p in map and p2 in map[p]:
                        return False
                g1.add(p2)

        return True


sol = Solution()
print(sol.possibleBipartition(4, [[1,2],[1,3],[2,4]]))
print(sol.possibleBipartition(3, [[1,2],[1,3],[2,3]]))
print(sol.possibleBipartition(5, [[1,2],[2,3],[3,4],[4,5],[1,5]]))
print(sol.possibleBipartition(10, [[5,9],[5,10],[5,6],[5,7],[1,5],[4,5],[2,5],[5,8],[3,5]]))  # true
print(sol.possibleBipartition(10, [[4,7],[4,8],[2,8],[8,9],[1,6],[5,8],[1,2],[6,7],[3,10],[8,10],[1,5],[7,10],[1,10],[3,5],[3,6],[1,4],[3,9],[2,3],[1,9],[7,9],[2,7],[6,8],[5,7],[3,4]]))