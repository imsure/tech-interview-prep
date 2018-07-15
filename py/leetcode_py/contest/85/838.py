class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        ans = ''
        i = 0
        dominoes = list(dominoes)
        while i < len(dominoes):
            if dominoes[i] == '.':
                if i + 1 < len(dominoes) and dominoes[i+1] == 'L':
                    ans += 'L'
                else:
                    ans += '.'
                i += 1
            elif dominoes[i] == 'L':
                ans += 'L'
                i += 1
            else:  # 'R'
                if i + 1 < len(dominoes):
                    if dominoes[i+1] == '.':
                        if i + 2 < len(dominoes) and dominoes[i+2] == 'L':
                            ans += 'R.L'
                            i += 3
                        else:
                            ans += 'R'
                            dominoes[i+1] = 'R'
                            i += 1
                    else:
                        ans += 'R'
                        i += 1
                else:
                    ans += 'R'
                    i += 1

        return ans

    def pushDominoes2(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        i = 0
        dominoes = list(dominoes)
        while i < len(dominoes):
            if dominoes[i] == 'R':
                if i + 1 < len(dominoes) and dominoes[i+1] == '.':
                    if i + 2 < len(dominoes) and dominoes[i+2] == 'L':
                        pass
                    else:
                        dominoes[i+1] = 'R'
            i += 1




if __name__ == '__main__':
    sol = Solution()
    print(sol.pushDominoes(".L.R...LR..L.."))
    print(sol.pushDominoes("RR.L"))
    print(sol.pushDominoes("..R.."))

