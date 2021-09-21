## Tree: Height of a Binary Tree


```python
def height(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 0
    return 1+max(height(root.left), height(root.right))

```

## Binary Search Tree : Lowest Common Ancestor


```python
def lca(root, v1, v2):
    if root is None:
        return None
    if root.info == v1 or root.info ==v2:
        return root

    if root.info < v1 and root.info <v2:
        return lca(root.right, v1, v2)
    elif root.info > v1 and root.info > v2:
        return lca(root.left, v1, v2)
    else:
        return root
    
```

## Trees: Is This a Binary Search Tree?

```python

def isValid(root, mn, mx):
    if root is None:
        return True
    
    if root.data <= mn or root.data >=mx:
        return False
    return isValid(root.left, mn, root.data) and isValid(root.right, root.data, mx)
    
def checkBST(root):
    return isValid(root, 0,10000)
    

```


## Tree: Huffman Decoding



```python

def decodeHuff(root, s):
    #Enter Your Code Here
    ans=''
    curr=root
    for i in range(0,len(s)):
        if(s[i]=='0'):
            curr=curr.left
        else:
            curr=curr.right
        if(curr.left== None and curr.right== None):
            ans=ans+curr.data
            curr=root
    print(ans)
```
# Fail

## Balanced Forest

