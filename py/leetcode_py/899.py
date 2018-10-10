class Solution:
    def orderlyQueue(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        if K > 1:
            return ''.join(sorted(S))

        T = S[1:] + S[0]
        ans = min(S, T)
        while T != S:
            T = T[1:] + T[0]
            ans = min(ans, T)

        return ans

    def orderlyQueue2(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        if K > 1:
            return ''.join(sorted(S))

        return min([S[i:] + S[:i] for i in range(0, len(S))])


sol = Solution()
print(sol.orderlyQueue2("cba", 1))  # "acb"
print(sol.orderlyQueue2("baaca", 3))  # "aaabc"
print(sol.orderlyQueue2("kuh", 1))  # "hku"
print(sol.orderlyQueue2("xitavoyjqiupzadbdyymyvuteolyeerecnuptghlzsynozeuuvteryojyokpufanyrqqmtgxhyycltlnusyeyyqygwupcaagtkuq", 1))
