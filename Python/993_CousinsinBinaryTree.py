# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        isX = False
        isY = False
        q = []
        q.append(root)
        while q:
            size = len(q)
            for i in range(size):
                p = q[0]
                q.pop(0)
                if p.val == x:
                    isX = True
                if p.val == y:
                    isY = True
                if p.left and p.right:
                    left = p.left.val
                    right = p.right.val
                    if (left == x and right == y) or (left == y and right == x):
                        return False
                if p.left:
                    q.append(p.left)
                if p.right:
                    q.append(p.right)
            if isX & isY:
                return True
            if isX | isY:
                return False

        return False
