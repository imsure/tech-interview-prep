# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def _inorder(self, root, nodes):
        if root is None:
            return

        self._inorder(root.left, nodes)
        nodes.append(root.val)
        self._inorder(root.right, nodes)

    def increasingBST(self, root):
        """
        In order traversal, use extra space

        :type root: TreeNode
        :rtype: TreeNode
        """
        nodes = []
        self._inorder(root, nodes)
        new_root = TreeNode(-1)
        child = new_root
        for val in nodes:
            child.right = TreeNode(val)
            child = child.right

        return new_root.right


class Solution2:
    def _inorder(self, root):
        if root is None:
            return

        self._inorder(root.left)
        root.left = None  # make left subtree None since it's been processed
        self.node.right = root  # chain root to the current running node's right subtree
        self.node = root  # now root becomes the running node and we proceed to process its right subtree
        self._inorder(root.right)

    def increasingBST(self, root):
        """
        in place transform

        :type root: TreeNode
        :rtype: TreeNode
        """
        ans = self.node = TreeNode(None)
        self._inorder(root)
        return ans.right
