class Solution:
    def _find_next(self, first, second, S):
        for i in range(1, len(S)):
            third = int(S[:i])
            if third == first + second:
                return third

        return None

    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        if S.startswith('0'):
            return []

        ans = []
        for i in range(1, len(S)):
            first = int(S[:i])
            # print('first', first)
            for j in range(i+1, len(S)):
                second = int(S[i:j])
                # print('second', second)
                for k in range(j+1, len(S)+1):
                    third = int(S[j:k])
                    # print('third', third)
                    if third == first + second:
                        print(first, second, third)
                        ans.append(first)
                        ans.append(second)
                        ans.append(third)
                        if k == len(S):
                            return ans
                        ret = self._find_next(second, third, S[k:])
                        if ret is None:
                            ans = []
                            break
                        else:
                            ans.append(third)

        return ans


if __name__ == '__main__':
    sol = Solution()
    print(sol.splitIntoFibonacci('0123'))
    print(sol.splitIntoFibonacci('123456579'))
    print(sol.splitIntoFibonacci('11235813'))