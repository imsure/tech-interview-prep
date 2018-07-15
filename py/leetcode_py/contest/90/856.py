class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = []

        score = 0
        tmp = 0
        op = 'basic'
        comb = S[0] + S[1]

        i = 0
        while i < len(S) - 1:
            case = S[i] + S[i+1]
            if case == '()':
                score += 1
                i += 2
            elif case == '((':
                stack.append('(*')
            elif case == '))':
                elem = stack.pop()
                if len(elem) == 2:
                    tmp *= 2
                else:
                    pass
            else:  # )(
                stack.append('+(*')
                tmp = 0

        for i in range(len(S)-1, -1, -1):
            if S[i] == ')':
                stack.append(S[i])
            else:
                stack.pop()
                if score == 0:
                    score = 1
                else:
                    score = score * 2

    def _score(self, S):
        if S == '':
            return 0

        case = S[0] + S[1]
        if case == '()':
            return 1 + self._score(S[2:])
        elif case == '((':
            return 2 * self._score(S[1:])
        else:
            return

    def scoreOfParentheses2(self, S):
        """
        :type S: str
        :rtype: int
        """
        case = S[0] + S[1]
        if case == '()':
            return 1 + self._score(S[2:])
        else:
            return 2 * self._score(S[1:])


sol = Solution()
print(sol.scoreOfParentheses2('()()'))
print(sol.scoreOfParentheses2('()'))
print(sol.scoreOfParentheses2('(())'))