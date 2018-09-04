# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def traverse_bst(self, root, parent):
        if root is None:
            return None

        l = self.traverse_bst(root.left, parent)
        new_root = TreeNode(root.val)
        if parent.val == -1:
            parent.val = new_root.val
            new_root = parent
        if l:
            l.right = new_root
        r = self.traverse_bst(root.right, parent)
        new_root.right = r
        if r:
            return r
        return new_root

    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        parent = TreeNode(-1)
        self.traverse_bst(root, parent)
        return parent
