
## Insert a node at a specific position in a linked list
```cpp
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    if(position==0) {
        node->next = llist;
        llist = node;
        return llist;
    }
    SinglyLinkedListNode *pre = llist, *p = llist;
    while(position){
        position--;
        pre = p;
        p=p->next;        
    }
    if(p==nullptr){
        pre->next = node;
    }
    else{
        pre->next= node;
        node->next = p;
        
    }
    return llist;
}
```

## Inserting a Node Into a Sorted Doubly Linked List

```cpp
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode * node = new DoublyLinkedListNode(data);
    DoublyLinkedListNode * p = llist, *pre = llist;
    if(node->data < p->data){
        node->next = p;
        p->prev = node;
        llist = node;
        return llist;
    }
    while(p && p->data < node->data){
        
        pre = p;
        p = p->next;
        
    }
    node->prev = pre;
    pre->next = node;
    node->next = p;
    if(p)  p->prev = node;
    return llist;
    
}
```

## Linked Lists: Detect a Cycle

```cpp
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *slow = head, *fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast ) return true;
    }
    return false;
        
}
```

## Find Merge Point of Two Lists
```cpp
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    
    SinglyLinkedListNode *a = head1 , * b = head2;
    while(a != b){
        if(a== nullptr ) a = head2;
        else a=a->next;
        if(b == nullptr) b = head1;
        else b= b->next;
        
        if(a==b) return a->data;
    }
    return -1;
}
```

## Reverse a doubly linked list

```cpp
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if(!llist || !llist->next) return llist;
    DoublyLinkedListNode *pre = nullptr, * cur = llist, *post = cur->next;
    while(post){
        cur->next = pre;
        if(pre) pre->prev = cur;
        
        pre = cur;
        cur = post;
        post = post->next;      
    }
    cur->next = pre;
    if(pre) pre->prev = cur;
    return cur;  
}
```