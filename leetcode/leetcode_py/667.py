class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        if k == 1:
            return [i for i in range(1, n + 1)]

        ans = [n]
        dec = True
        for diff in range(k, 0, -1):
            if dec:
                ans.append(ans[len(ans)-1] - diff)
                dec = False
            else:
                ans.append(ans[len(ans)-1] + diff)
                dec = True

        # print(ans)

        last = ans[len(ans)-1]
        if last - 2 > 0:
            ans.append(last - 2)
            for i in range(last - 3, 0, -1):
                ans.append(i)

        return ans

    def constructArray2(self, n, k):
        """
        We need k+1 numbers to generate k distinct differences.

        Put first (n-k-1) elements in order: [1, 2, ..., n-k-1],
        then for the remaining [n-k, n-k+1, ... , n-1, n], alternatively
        pick elements at head and tail to make a distinct difference:
        [n-k, n, n-k+1, n-1, ...].

        Finally append two list together.

        :type n: int
        :type k: int
        :rtype: List[int]
        """
        # ans = []
        # for i in range(1, n - k):
        #     ans.append(i)
        ans = list(range(1, n - k))

        head, tail = n - k, n
        while head < tail:
            ans.append(head)
            ans.append(tail)
            head += 1
            tail -= 1

        if head == tail:
            ans.append(head)

        return ans


sol = Solution()
print(sol.constructArray2(10, 9))
print(sol.constructArray2(3, 2))