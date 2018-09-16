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
    def insert(self, root, val):
        if val < root.val:
            if root.left is None:
                root.left = TreeNode(val)
            else:
                self.insert(root.left, val)
        elif root.val < val:
            if root.right is None:
                root.right = TreeNode(val)
            else:
                self.insert(root.right, val)

    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        self.insert(root, val)
        return root


sol = Solution()