class Solution:
    def _findContestMatch(self, teams):
        n = len(teams)
        if n == 1:
            return teams

        teams = ['({},{})'.format(teams[i], teams[n - i - 1]) for i in range(0, n // 2)]
        return self._findContestMatch(teams)


    def findContestMatch(self, n):
        """
        Recursively match up a list of teams until the length of
        the teams becomes one.

        time: O(NlogN)
        space: O(NlogN)

        :type n: int
        :rtype: str
        """
        teams = ['({},{})'.format(i, n - i + 1) for i in range(1, n // 2 + 1)]
        teams = self._findContestMatch(teams)
        return teams[0]


    def findContestMatch2(self, n):
        """
        Iterative solution. Let teams[i] be the correct matchup string for
        i-th strongest team. The final answer would be teams[0].

        time: O(NlogN)
        space: O(NlogN)

        :type n: int
        :rtype: str
        """
        teams = [str(i) for i in range(1, n + 1)]
        while n > 0:
            # print(teams)
            for i in range(0, n // 2):
                teams[i] = '(' + teams[i] + ',' + teams[n - i - 1] + ')'
            n = n // 2

        return teams[0]


if __name__ == '__main__':
    sol = Solution()
    print(sol.findContestMatch(2))  # (1,2)
    print(sol.findContestMatch(4))  # ((1,4),(2,3))
    print(sol.findContestMatch(8))  # (((1,8),(4,5)),((2,7),(3,6)))
    # print(sol.findContestMatch(2 ** 12))

    print(sol.findContestMatch2(2))  # (1,2)
    print(sol.findContestMatch2(4))  # ((1,4),(2,3))
    print(sol.findContestMatch2(8))  # (((1,8),(4,5)),((2,7),(3,6)))