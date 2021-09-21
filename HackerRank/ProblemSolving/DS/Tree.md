基礎題
## Tree: Preorder Traversal



```python
def preorder(root, ret):
    
    if root is None:
        return
    ret.append(root.info)
    preorder(root.left, ret)
    preorder(root.right, ret)
    return ret
    
def preOrder(root):
    #Write your code here
    # option 1 O(n) space
    # ret = []
    # preorder(root, ret)
    # [print(r, end=' ') for r in ret]
    
    # option 2 
    if root is None:
        return 
    print(root.info, end =' ')
    preOrder(root.left)
    preOrder(root.right)

```


## Tree: Postorder Traversal

```python
def postOrder(root):
    #Write your code here
    if root is None:
        return
    
    postOrder(root.left)
    postOrder(root.right)
    print(root.info, end =' ')


```

## Tree: Inorder Traversal

```python
def inOrder(root):
    #Write your code here
    
    if root is None:
        return

    inOrder(root.left)
    print(root.info, end = ' ')
    inOrder(root.right)


```

## Tree: Height of a Binary Tree

```python
def height(root):
    # DFS + stack
    # if root is None:
    #     return 0
    # if root.left is None and root.right is None:
    #     return 0
    
    # return 1+ max(height(root.left), height(root.right))
    
    # BFS + queue 
    if root is None:
        return 0
    q = []
    q.append(root)
    h = -1
    while q:
        size =len(q)
        for i in range(size):
            p = q.pop(0)
            if p.left:
                q.append(p.left)
            if p.right:
                q.append(p.right)
        h+=1
    return h
            
```


## Tree: Level Order Traversal

```python
def levelOrder(root):
    #Write your code here
    # if root is None:
    #     return
    # q = []
    # q.append(root)
    # while q:
    #     size = len(q)
    #     for i in range(size):
    #         p = q.pop(0)
    #         print(p.info, end=' ')
    #         if p.left:
    #             q.append(p.left)
    #         if p.right:
    #             q.append(p.right)

    # option 
    if root is None:
        return
    q = []
    q.append(root)
    while q:
        p = q.pop(0)
        print(p.info, end=' ')
        if p.left:
            q.append(p.left)
        if p.right:
            q.append(p.right)


```


## Binary Search Tree : Insertion



```python
def insert(self, val):
        #Enter you code here.
        if self.root is None:
            self.root = Node(val)
            return 
        pre, root = None, self.root
        while root:
            if val < root.info:
                pre = root
                root = root.left
            else:
                pre = root
                root = root.right
        
        if pre.info > val:
            pre.left = Node(val)
        elif pre.info < val:
            pre.right = Node(val)

```



## Tree: Huffman Decoding


```python

def decodeHuff(root, s):
    #Enter Your Code Here
    i  = 0
    ret = ""
    while i< len(s):
        cur= root
        path = []
        while cur.left and cur.right:
            p = int(s[i])
            if p==0:
                cur =cur.left
            elif p==1:
                cur = cur.right
            i +=1
        ret += cur.data
    print(ret)
    return ret
```


## Binary Search Tree : Lowest Common Ancestor


```python

def lca(root, v1, v2):
  #Enter your code here
    if root is None :
        return root  
    if root.info==v1 or root.info==v2 or (root.info > min(v1, v2) and root.info < max(v1,v2)):
        return root
    elif root.info > v1 and root.info > v2:
        return lca(root.left, v1,v2)
    elif root.info < v1 and root.info < v2:
        return lca(root.right, v1,v2)
```






# Fail
## Tree : Top View


```python
def topView(root):
    #Write your code here

    # level -order
    if root is None:
        return
    uniq_lvls = []
    q = Queue()
    q.put((root, 0))
    while not q.empty():
        p = q.get()
        if p[1] not in (i[1] for i in uniq_lvls):
            uniq_lvls.append(p)
        if p[0].left:
            q.put( (p[0].left, p[1] - 1))        
        if p[0].right:
            q.put( (p[0].right, p[1] + 1))   
    # print(uniq_lvls)     
    for x in sorted(uniq_lvls, key = lambda e:e[1]):
        print(x[0].info, end = ' ')


```

## Is This a Binary Search Tree?

```python
def check_binary_search_tree(root, mn, mx):
    if root is None:
        return True
    if mn>= root.data:
        return False
    if mx <= root.data:
        return False
    return check_binary_search_tree(root.left, mn, root.data) and check_binary_search_tree(root.right, root.data, mx)
def check_binary_search_tree_(root):
    
    if root is None:
        return True
    return check_binary_search_tree(root, 0, 10000)

```

## Swap Nodes [Algo]

