# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

    def _preorder(self, nodes, node):
        if node is None:
            nodes.append(None)
            return
        nodes.append(node.val)
        self._preorder(nodes, node.left)
        self._preorder(nodes, node.right)

    def __str__(self):
        nodes = []
        self._preorder(nodes, self)
        return str(nodes)


class Solution:
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        if N % 2 == 0:
            return []

        ans = []
        if N <= 1:
            return [TreeNode(0)]

        for n in range(1, N, 2):
            ltrees = self.allPossibleFBT(n)
            rtrees = self.allPossibleFBT(N-1-n)
            for rtree in rtrees:
                for ltree in ltrees:
                    root = TreeNode(0)
                    root.left = ltree
                    root.right = rtree
                    ans.append(root)

        return ans


sol = Solution()
ans = sol.allPossibleFBT(7)
for root in ans:
    print(root)