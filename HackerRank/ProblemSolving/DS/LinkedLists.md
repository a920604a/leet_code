基礎題
## Print the Elements of a Linked List


```python
def printLinkedList(head):
    while head:
        print(head.data)
        head = head.next

```


## Insert a Node at the Tail of a Linked List

```python
def insertNodeAtTail(head, data):
    if head is None:
        return SinglyLinkedListNode(data)
    p = head
    while p.next:
        p=p.next
    p.next= SinglyLinkedListNode(data)
    return head
```

## Insert a node at the head of a linked list


```python
def insertNodeAtHead(llist, data):
    # Write your code here
    newHead = SinglyLinkedListNode(data)
    newHead.next = llist
    return newHead
```

## Insert a node at a specific position in a linked list

```python
def insertNodeAtPosition(llist, data, position):
    # Write your code here
    if position==0:
        head = SinglyLinkedListNode(data)
        head.next = llist
        return head
    
    node = SinglyLinkedListNode(data)
    position-=1
    p = llist
    while position:
        p=p.next
        position-=1    
    # if p.next is None:
    #     p.next = node
    #     return llist
    last = p.next
    p.next = node
    node.next = last
    return llist
```

## Delete a Node



```python
def deleteNode(llist, position):
    # Write your code here
    if position==0:
        return llist.next
    position-=1
    p = llist
    while position:
        position-=1
        p = p.next
    p.next = p.next.next
    return llist
```

## Print in Reverse

```python
if llist is None:
        return 
    p = llist
    rev = []
    while p:
        rev.append(p.data)
        p=p.next    
    rev = rev[::-1]
    [print(f) for f in rev]
```

recursive
```python 
def reversePrint(llist):
    # Write your code here
    if llist is None:
        return 
    else:
        reversePrint(llist.next)
        print(llist.data)

```

## Reverse a linked list

```python
def reverse(llist):
    # Write your code here
    # recursive
    # if llist is None:
    #     return 
    # if llist.next is None:
    #     return llist
    # node = reverse(llist.next)
    # llist.next.next = llist
    # llist.next = None
    # return node

    # iterative
    if llist is None:
        return llist
    if llist.next is None:
        return llist
    pre , cur = None, llist
    while cur.next:
        post = cur.next
        cur.next = pre
        pre = cur
        cur = post
        
    cur.next = pre
    return cur

```

## Compare two linked lists

```python
def compare_lists(llist1, llist2):
    
    while llist1 and llist2:
        if llist1.data != llist2.data:
            return 0
        llist1 = llist1.next
        llist2 = llist2.next
            
    if llist1 or llist2 :
        return 0
    return 1

```


## Merge two sorted linked lists

```python
def mergeLists(head1, head2):
    
    root = SinglyLinkedListNode(0)
    ans = root
    while head1 and head2:
        if head1.data < head2.data:
            root.next = head1
            head1 = head1.next
        else:
            root.next = head2
            head2 = head2.next
        root = root.next
    if head1:
        root.next = head1
    if head2:
        root.next = head2
    return ans.next
```
## Get Node Value

```python
def getNode(llist, positionFromTail):
    # Write your code here
    # iterative
    # pos = 0
    # p = llist
    # while p:
    #     p=p.next
    #     pos +=1
    
    # pos = pos-positionFromTail
    # pos-=1
    # p = llist
    # while pos:
    #     p=p.next
    #     pos-=1
    # return p.data

    # two pointer slow fast
    slow , fast = llist, llist
    while positionFromTail:
        fast = fast.next
        positionFromTail-=1
    while fast.next:
        slow = slow.next
        fast = fast.next
    return slow.data
```

## Delete duplicate-value nodes from a sorted linked list

```python
def removeDuplicates(llist):
    # Write your code here
    slow, fast = llist, llist
    while fast:
        if slow.data != fast.data:
            slow.next = fast
            slow = slow.next
        fast = fast.next
        
    slow.next = None
    return llist

```

## Cycle Detection

```python
def has_cycle(head):
    if head is None or head.next is None:
        return 0
    slow , fast = head, head
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
        if fast==slow:
            return 1
    return 0
```
## Find Merge Point of Two Lists

```python 
def findMergeNode(head1, head2):
    
    a, b = head1, head2
    while a!=b:        
        if a is None:
            a = head2
        else :
            a= a.next
        if b is None:
            b = head1
        else:
            b = b.next
    return a.data

```

## Inserting a Node Into a Sorted Doubly Linked List

```python

def sortedInsert(llist, data):
    # Write your code here
    node = DoublyLinkedListNode(data)
    if node.data < llist.data:
        llist.prev = node
        node.next = llist
        return node
    
    p, pre = llist, None
    while p and p.data< node.data:
        pre = p
        p=p.next
    
    if p is None:
        pre.next = node
        node.prev = pre
        return llist
    
    pre.next = node
    node.prev = pre
    node.next = p
    p.prev = node
    
    return llist
```





## Reverse a doubly linked list

```python
def reverse(llist):
    # Write your code here
    if llist is None or llist.next is None:
        return llist
    pre , cur = None, llist
    while cur.next:
        post = cur.next
        
        cur.next = pre
        if pre:
            pre.prev =cur
        
        pre = cur
        cur = post

    cur.next = pre
    pre.prev = cur
    return cur
```


