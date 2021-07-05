# Cracking the coding interview 


###### tags: `interview` `algorithm`



[toc]


## Data Structures

### Array and Strings 






##### **Is Unique**: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
assume ASCII string not Unicode string
```java=
boolean isUniqueChars(String str){
    if(str.length()>128) return false;
    
    boolean[] char_set = new boolean[128];
    
    for(int i =0;i<str.length();  ++i){
        int val = str.charAt(i);
        if(char_set[val]){ // Already found this char in string
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

```
time complexity O(n), space complexity O(1), but with additional data structures

```java=
boolean isUniqueChars(String str){
    int checker = 0;
    for(int i = 0;i<str.length() ; i++){
        int val = str.charAt(i) - 'a';
        if((checker & (1<<val) )>0) return false;
        checker |= (1<<val);
    }
    return true;
}
```
time complexity O(n^2), space complexity O(1), without additional data structures



##### **Check Permutation**: Given two strings,write a method to decide if one is a permutation of the other.

option 1 sorted the strings
```java=
String sort(Strings s){
    char[] content = s.toCharArray();
    java.util.Array.sort(content);
    return new String(content);
}
boolean permutation(String s, String t){
    if(s.legth()!=t.length()) return false;
    return sort(s).quals(sort(t));
}

```

option 2 check if the two strings have identical character counts.
```java=
boolean permutation(String s, String t){
    if(s.length() != t.length()){
        return false;
    }
    int [] letters = new int[128];
    
    char[] s_array = s.toCharArray();
    for(char c:s_array){
        letters[c]++;
    }
    
    for(int i=0;i<t.length();++i){
        int c = (int)t.charAt(i);
        letters[c]--;
        if(letters[c]<0) return false;
    }
    return true;
    
}

```



##### URLify: Write a method to replace all spaces in a string with '%20'. 
You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please use a character array so that you can perform this operation in place.)
```java=
EXAMPLE
Input: "Mr John Smith ", 13 
Output: "Mr%20John%20Smith"


void replaceSpaces(char[] str, int trueLength){
    int splaceCount = 0, index , i = 0;
    for(i = 0;i<trueLength ; ++i){
        if(str[i] == ' ') splaceCount++;
    }
    
    
    index = trueLength + splaceCount*2;
    if(trueLength < str.length) str[trueLength] = '\0'; //End array
    for(i = trueLength-1;i>=0;i--){
        if(str[i]==' '){
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index = index - 3;            
        }
        else{
            str[index-1] = sre[i];
            index--;
        }
    }
}

```
```cpp=
string replaceSpaces(string str, int trueLength){
    int splaceCount = 0, index , i = 0;
    for(i = 0;i<trueLength ; ++i){
        if(str[i] == ' ') splaceCount++;
    }


    index = trueLength + splaceCount*2;
    string ret;
    ret.reserve(index);
    for(i = trueLength-1;i>=0;i--){
        if(str[i]==' '){
            ret ="20%" + ret;
            index = index - 3;            
        }
        else{
            ret = str[i]+ret;
            index--;
        }
    }
    return ret;
}   

```








##### **Palindrome Permutation**: Given a string, write a function to check if it is a permutation of a palin­ drome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

1. use a hash table to count how many times each character appears.


```java=
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat'; "atc o eta·; etc.)
```


- Leetcode 125. Valid Palindrome




##### **One Away**: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.


```java=
EXAMPLE
pale, ple true 
pales, pale -> true 
pale, bale -> true 
pale, bae -> false

```




##### **String Compression**: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).
- leetcode 443. String Compression
- option 1 At each iteration, check if the current character is the same as the next character. If not, add its compressed version to the result. O(p+k^2)

```cpp=
class Solution {
public:
    int compress(vector<char>& chars) {
        // At each iteration, check if the current character is the same as the next character. If not, add its compressed version to the result.
        int ret = 0;
        string str = "";
        int countConsecutive = 0;
        for(int i=0;i<chars.size();++i){
            countConsecutive++;
            
            if( i+1 >=chars.size() || chars[i]!=chars[i+1]){
                if(countConsecutive>1) str += chars[i] + to_string(countConsecutive);
                else str += chars[i];
                
                countConsecutive = 0;
            }
                
        }
        cout<<str<<endl;
        chars = vector<char>(str.begin(), str.end());
        return str.size();
    }
};
```





##### **Rotate Matrix**: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

- 48. Rotate Image

```cpp=
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // option 1 O(n^2)
        if (matrix.size() == 0 || matrix[0].size()==0) return;
        int n= matrix.size();
        for (int layer = 0; layer < n / 2; layer++){
            int first= layer;
            int last= n - 1 - layer;
            for(int i = first; i < last; i++) {
                int offset = i - first;
                
                int top= matrix[first][i]; // save top
                
                // left -> top
                matrix[first][i] = matrix[last-offset][first];
                // bottom -> left
                matrix[last-offset][first] = matrix[last][last - offset];
                // right-> bottom
                matrix[last][last-offset] = matrix[i][last];
                // top -> right
                matrix[i][last] =top;
                
            }
        }        
    }
};
```


##### **Zero Matrix**: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

- Leetcode 73. Set Matrix Zeroes
```cpp=
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>> collect ; 
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0) collect.push_back(make_pair(i, j));
            }
        }
        
        for(auto a:collect){
            int x = a.first;  
            int y = a.second; 
            for(int i=0;i<n;++i) matrix[x][i] = 0;
            for(int i=0;i<m;++i) matrix[i][y] = 0;
        }
    }
};
```

##### **String Rotation**:Assume you have a method is Substring which checks if one word is a substring of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring (e.g.,"waterbottle" is a rotation of"erbottlewat").

- 將字串s1 = s1+s1 在判斷s2是否為s1子字串
```cpp=
bool rotateString(string s, string goal) {
        // option 1 O(len a + len b)
        // 將字串s1 = s1+s1 在判斷s2是否為s1子字串
        if(s.empty() && goal.empty()) return true;
        int a = s.size();
        s = s+s;
        if( a>0 &&a==goal.size() ){
            if(s.find(goal) != std::string::npos) return true;
        }
        return false;
        
    }
```

### Linked Lists



快慢指針技巧，適合用在未知大小串列

##### **Remove Duplicate**: Write code to remove duplicates from an unsorted linked list .How would you solve this problem if a temporary buffer is not allowed?

- leetcode 82 83 


```cpp=
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // option 1 O(nlogn) time O(s) space
        // 1. 儲存重複節點的值
        // 2. 建立一個新的list 比較是否重複節點，不是則加入新串列
//         if(!head) return head;
//         ListNode *ret = new ListNode(-101);
//         set<int> s;
//         ListNode *p = head;
//         while(p->next){
//             if(p->val ==p->next->val) s.insert(p->val);
//             p=p->next;
//         }
//         p=ret;
//         ListNode *cur = head;
//         while(cur){
//             if(s.find(cur->val)==s.end() ) {
//                 p->next = new ListNode(cur->val);
//                 p=p->next;
                
//             }
//             cur=cur->next;
//         }
//         return ret->next;
        
        
        // option 2 O(n^2) time O(1) space
        if(!head || !head->next) return head;
        ListNode *ret = new ListNode(-1),  *p = ret;
        ret->next = head;
        while(p->next){
            ListNode *run =p->next;
            while(run->next && run->next->val ==run->val){
                run = run->next;
            }
            if(run==p->next) p=p->next;
            else p->next=run->next;
        }
        return ret->next;
    }
};
```

##### **Return Kth to Last**: Implement an algorithm to find the kth to last element of a singly linked list.

- Leetcode 19. Remove Nth Node From End of List


##### **Delete Middle Node**: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

- Leetcode 19. Remove Nth Node From End of List


##### **Partition**: Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

- Leetcode 86. Partition List

##### **Sum Lists**: You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

- Leetcode 2. 445. Add Two Numbers II


#### **Palindrome**: Implement a function to check if a linked list is a palindrome.


- Leetcode 234. Palindrome Linked List


##### **Intersection**: Given two (singly) linked lists, determine if the two lists intersect. Return the inter­ secting node. Note that the intersection is defined based on reference, not value.That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

- Leetcode 160. Intersection of Two Linked Lists





##### **Loop Detection**: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.


- 141. Linked List Cycle 
- 142. Linked List Cycle II

### Stacks and Queues

queue 常用在BFS或 實作cache



##### **Three in One**: Describe how you could use a single array to implement three stacks.

Approach 1: Fixed Division
- divide the array in three equal parts and allow the individual stack to grow in that limited space.
- similar design stack 
- use array to implement array push pop top isEmpty isFull


Approach 2: Flexible Divisions
- allow the stack blocks to be flexible in size. 



##### **Stack Min:** How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop and min should all operate in 0(1) time.

- Leetcode 155. Min Stack



##### **Stack of Plates**: Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetO-fStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).Implement a function popAt(int index)which performs a pop operation on aspecific sub-stack.


##### **Queue via Stacks**: Implement a MyQueue class which implements a queue using two stacks.
- Leetcode 225. Implement Stack using Queues
- Leetcode 232. Implement Queue using Stacks
 

##### **Sort Stack**: Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, pop, peek, and isEmpty．



##### **Animal Shelter**: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the"oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked list data structure.


### Trees and Graph
recursive
- pre-order and other forms of tree traversal are a form of DFS
- assumption that BFS is recursive.
- BFS that has an iterative solution involving a queue usually works best.
- Bidirectional Search operates by essentially running two simultaneous breadth-first searches.


##### **Route Between Nodes**: Given a directed graph, design an algorithm to find out whether there is a route between two nodes

```java=
enum State { Unvisited, Visited, Visiting; }
boolean search(Graph g, Node start, Node end) {
    if (start == end) return true;
    // operates as Queue
    LinkedList<Node> q = new Linkedlist<Node>();
    for (Node u : g.getNodes()) {
        u.state = State.Unvisited;
    }
    start.state =  State.Visiting;
    q.add(start);
    Node u;
    while (!q.isEmpty()) {
        u = q.removeFirst(); II i.e., dequeue() 
        if (u != null) {
            for (Node v : u.getAdjacent()) {
                if (v.state == State.Unvisited) {
                    if (v == end) {
                        return true;
                    } 
                    else {
                        v.state = State.Visiting;
                        q.add(v);
                    }
                }
            }
            u.stateState.Visited;
        }
    }
    return false;
}
```

##### **Minimal Tree**: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.

- Leetcode 108. Convert Sorted Array to Binary Search Tree
```cpp=
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
        
    }
};
```

##### **List of Depths**: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

- Leetcode 104. Maximum Depth of Binary Tree
- Leetcode 111. Minimum Depth of Binary Tree
- Leetcode 109. Convert Sorted List to Binary Search Tree
- Leetcode 114. Flatten Binary Tree to Linked List



```cpp=
int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
```


```cpp=
int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
    
```

```cpp=

TreeNode* sortedListToBST(ListNode* head) {
        // 先決定root，再分兩部分left, right
        if(!head) return nullptr;
        // use slow fast to determine root node
        ListNode *slow = head, *fast = head, *pre= nullptr;
        
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // partition
        if(pre!=nullptr)  pre->next = nullptr;
        else head = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
        
    }
    
```
    


##### **Check Balanced**: Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.

- Leetcode 110. Balanced Binary Tree
- Leetcode 1382. Balance a Binary Search Tree 


```cpp=

int getHeight(TreeNode *root){
        if(!root) return 0;
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
    int checkHeight(TreeNode* root){
        if (root == nullptr) return -1;
        int leftHeight = checkHeight(root->left);
        if (leftHeight ==INT_MIN) return INT_MIN; // Pass error up
        int rightHeight = checkHeight(root->right);
        if (rightHeight == INT_MIN) return INT_MIN; // Pass error up
        
        // What do we use for an error code? The height of a null tree is generally defined to be -1, so that's not a great idea for an error code. Instead, we' ll use Integer. MIN_VALUE.
        int heightDiff = leftHeight - rightHeight;
        if(heightDiff>1) return INT_MIN;
        else return max(leftHeight, rightHeight)+1;
    }
    
    
    
    
    
    bool isBalanced(TreeNode* root) {
        // option 1 O(N log N) time
        // 1. get left child tree hight and right child tree height
        // if(!root) return true;
        // int heightDiff = getHeight(root->left) - getHeight(root->right);
        // if(abs(heightDiff)>1 )return false;
        // else return isBalanced(root->left) && isBalanced(root->right);
        
        // option 2 O(N) time and O(Height) space
        return checkHeight(root) != INT_MIN;
        
 
    }
    
    
```
    
    
    
    
    



##### **Validate BST**: Implement a function to check if a binary tree is a binary search tree.

Traversal issue
- Leetcode 94. Binary Tree Inorder Traversal
- Leetcode 144. Binary Tree Preorder Traversal
- Leetcode 145. Binary Tree Postorder Traversal



- Solution #1: In-Order Traversal
    - 用array 按照in-order拜訪順序去儲存原先的tree。並判斷array 是否為遞增，若否，則該BST為無效BST
    - 也可以簡化不用array，因為一次只比較array的兩個值。
- Solution #2: The Min / Max Solution


```java=
int index = 0;
void copyBST(TreeNode root, int[] array) {
    if(root==null) return ;
    copyBST(root.left, array);
    array[index] = root.data;
    index++;
    copyBST(root.right, array);

}
boolean checkBST(TreeNode root) {
    int [] array = new ont[root.size];
    
    copyBST(root, array);
    
    
    for(int i=1;i<array.length;++i){
        if(array[i-1]>array[i] ) return false;
    }
    return true;
}

```


```java=
Integer last_printed = null;

boolean checkBST(TreeNode n) {
    if(n==null) return true;
    
    //  Check  recurse left
    if (!checkBST(n.left)) return false;
    
    // Check current
    if (last_printed != null && n.data =< last_printed){
        return false;
    }
    
    last_printed = n.data;
    
    //  Check recurse right
    if (!checkBST(n.right)) return false;
    
    return true;
    
    
    
}


```

```java=
// O(n) time and O(logN) space
boolean checkBST(TreeNode n) {

    return checkBST(n, null, null);
}

boolean checkBST(TreeNode n, Integer min, Intefet max){
    if(n==null) return true;
    
    
    // check this level 
    if( (min!=null && n.data<=min) || (max!=null && n.data>max) ){
        return false;
    }
    
    // check left child and right child
    if(!checkBST(n.left, min, n.data) || !checkBST(n.right, n.data, max)){
        return false;
    }
    
    
    
    return true;
}
```

##### **Successor**: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a binary search tree. You may assume that each node has a link to its parent.

- Leetcode 285. Inorder Successor in BST
- Leetcode 510. Inorder Successor in BST II
 
 
pseudcode

```cpp=
Node inorderSucc(Node n){
    if(n has a right subtree){
        return leftmost child of right subtree;
    }
    else{
        while (n is a right child of n.parent){
            n = n.parent; // Go up
        }
        return n.parent;
    }
}

```

```java=
TreeNode inorderSucc(TreeNode n) {
    if(n==null) return null;
    if(n.right!=null){
        return leftMostChild(n.right);
    }
    else{
        TreeNode q = n;
        TreeNode x = q.parent;
        while( x!=null && x.left=q){
            q = x;
            x = x.parent;
        }
        return x;
    }    
    

}


TreeNode leftMostChild(TreeNode n){
    if(n==null) return null;
    
    while(n.left!=null){
        n=n.left;
    }
    return n;
}

```


```cpp=
Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        Node *res = nullptr;
        if (node->right) {
            res = node->right;
            while (res && res->left) res = res->left;
        } else {
            res = node->parent;
            while (res && res->val < node->val) res = res->parent;
        }
        return res;

```

##### **Build Order**: You are given a list of projects and a list of dependencies (which is a list of pairs of projects, where the second project is dependent on the first project). All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error.



##### **First Common Ancestor**: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.

- Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
- Leetcode 236. Lowest Common Ancestor of a Binary Tree


- Solution #1: With Links to Parents
- Solution #2: With Links to Parents (Better Worst-Case Runtime)
- Solution #3: Without Links to Parents
- Solution #4: Optimized

```java=
// O(d) time, d is the depth of the deeper node.
TreeNode * commonAncestor(TreeNode p, TreeNode q){
    int delta = depth(p)- depth(q);
    TreeNode first = delta>0?q:p; // get shallower node
    TreeNode second = delta>0?p:q; // get deeper node

    second = goUpBy(second, Math.abs(delta)); 
    /* Find where paths intersect. */
    while(first !=second && first!=null && second !=null){
        first = first.parent;
        second = second.parent;
    }
    return first==null || second == null ? null:first;
    
}
TreeNdoe goUpBy(TreeNode node , int delta){
    while(delta >0 && node!=null){
        node = node.parent;
        delta--;
    }
    return node;
}
int depth(TreeNode node){
    int depth = 0;
    while(node !=null){
        node = node.parent;
        depth++;
    }
    return depth;
}
```

```java=
// O(t) time , t is the size of the subtree for the first common ancestor

TreeNode commonAncestor(TreeNode root, TreeNOde p, TreeNode q){
    if(!covers(root, p) || !covers(root, q)){
        return null;
    }
    else if( covers(p,q)) return p;
    else if (covers(q,p)) return q;
    TreeNode sibling = getSibling(p);
    TreeNode parent = p.parent;
    while(!covers(sibling, q)){
        sibling = getSibling(parent);
        parent = parent.parent;
    }
    return parent;
}
bool covers(TreeNode root, TreeNode p){
    if(root == null) return false;
    if( root==p ) return true;
    return covers(root.left, p) || covers(root.right, p);
}
TreeNode getSibling(TreeNode node){
    if(node==null || node.parent = null ) return null;
    TreeNode parent = node.parent;
    return parent.left ==node ?parent.right :parent.left;
}
```


```java=

TreeNode commonAncestor(TreeNode root, TreeNOde p, TreeNode q){
    if(!covers(root, p) || !covers(root, q)){
        return null;
    }

    return ancestorHelper(root, p, q);

}

TreeNode ancestorHelper(TreeNode root, TreeNOde p, TreeNode q){
    if(root ==null || root==p || root==q){
        return root;
    }

    boolean pIsOnLeft = covers(root.left, p);
    boolean qIsOnLeft = covers(root.left, q);
    if(pIsOnLeft !=qIsOnLeft) return root;

    TreeNode childSide = pIsOnLeft?root.left:root.right;
    return ancestorHelper(childSide, p, q);

    
}
bool covers(TreeNode root, TreeNode p){
    if(root == null) return false;
    if( root==p ) return true;
    return covers(root.left, p) || covers(root.right, p);
}
```


```java=
class Result{
    public TreeNode node;
    public boolean isAncestor;
    public Result(TreeNode n , boolean isAnc){
        node = n;
        isAncestor =isAnc;
    }
}
TreeNode commonAncestor(TreeNode root, TreeNode p, TreeNode q){
        Result r = commonAncestorHelper(root,p,q);
        if(r.isAncestor){
            return r.ndoe;
        }
        return null;
    }

}

Result commonAncestorHelper(TreeNode root, TreeNode p, TreeNode q){
    if(root==null) return new Result(null, false);
    if(root==p || root==q){
        return new Result(root, true);
    }

    Result rx = commonAncestorHelper(root.left, p, q);
    if(ry.isAncestor){
        return ry;
    }

    if(rx.node !=null && ry.node !=null){
        return new Result(root, true);
    }
    else if(root ==p || root==q){
        boolean isAncestor = rx.node !=null || ry.node==null;
        return new Rsult(root, isAncestor);
    }
    else{
        return new Result(rx.node !=null?rx.node:ry.node, false);
    }
}

```

##### **BST Sequences**: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary search tree with distinct elements, print all possible arrays that could have led to this tree.

- Leetcode 449. Serialize and Deserialize BST
- Leetcode 297. Serialize and Deserialize Binary Tree





##### **Check Subtree**: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an algorithm to determine if T2 is a subtree of Tl. A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.

- Leetcode 700. Search in a Binary Search Tree
- Leetcode 572. Subtree of Another Tree


##### **Random Node**: You are implementing a binary tree class from scratch which, in addition to insert, find, and delete, has a method getRandomNode() which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm for getRandomNode, and explain how you would implement the rest of the methods.


##### **Paths with Sum**: You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

### Bit Manipulation
x^ 000000 = x
x^ 111111 = ~x
x^ x = 0
x | x = x

1. **Insertion**: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
2. **Binary to String**: Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:'
3. **Flip Bit to Win**: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of ls you could create.
4. **Next Number**: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.
5. **Debugger**: Explain what the following code does: ((n & (n-1)) == 0).
6. **Conversion**: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
7. **Pairwise Swap**: Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).
8. **Draw Line**: A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (xl, y) to ( x2, y)


### Math and Logic Puzzles

1. **The Heavy Pill**: You have 20 bottles of pills. 19 bottles have 1.0 gram pills, but one has pills of weight 1.1 grams. Given a scale that provides an exact measurement, how would you find the heavy bottle? You can only use the scale once.
2. **Basketball**: You have a basketball hoop and someone says that you can play one of two games.
Game 1: You get one shot to make the hoop.
Game 2: You get three shots and you have to make two of three shots.
If p is the probability of making a particular shot, for which values of p should you pick one game or the other?
3. **Dominos**: There is an 8x8 chessboard in which two diagonally opposite corners have been cut off. You are given 31 dominos, and a single domino can cover exactly two squares. Can you use the 31 dominos to cover the entire board? Prove your answer (by providing an example or showing why it's impossible).
4. **Ants on a Triangle**: There are three ants on different vertices of a triangle. What is the probability of collision (between any two or all of them) if they start walking on the sides of the triangle? Assume that each ant randomly picks a direction, with either direction being equally likely to be chosen, and that they walk at the same speed.
Similarly, find the probability of collision with n ants on an n-vertex polygon
5. **Jugs of Water**: You have a five-quart jug, a three-quart jug, and an unlimited supply of water (but no measuring cups). How would you come up with exactly four quarts of water? Note that the jugs areoddlyshaped,suchthatfillingupexactly"half"ofthejugwouldbeimpossible
6. **Blue-Eyed Island**: A bunch of people are living on an island, when a visitor comes with a strange order: all blue-eyed people must leave the island as soon as possible. There will be a flight out at 8:00 pm every evening. Each person can see everyone else's eye color, but they do not know their own (nor is anyone allowed to tell them). Additionally, they do not know how many people have blue eyes, although they do know that at least one person does. How many days will it take the blue-eyed people to leave?
7. **The Apocalypse**: In the new post-apocalyptic world, the world queen is desperately concerned about the birth rate. Therefore, she decrees that all families should ensure that they have one girl or else they face massive fines. If all families abide by this policy-that is, they have continue to have children until they have one girl, at which point they immediately stop-what will the gender ratio of the new generation be? (Assume that the odds of someone having a boy or a girl on any given pregnancy is equal.) Solve this out logically and then write a computer simulation of it.
8. **The Egg Drop Problem**: There is a building of 100 floors. If an egg drops from the Nth floor or above, it will break. If it's dropped from any floor below, it will not break. You're given two eggs. Find N, while minimizing the number of drops for the worst case.
9. **100 Lockers**: There are 100 closed lockers in a hallway. A man begins by opening all 100 lockers. Next, he closes every second locker. Then, on his third pass, he toggles every third locker (closes it if it is open or opens it if it is closed). This process continues for 100 passes, such that on each pass i, the man toggles every ith locker. After his 100th pass in the hallway, in which he toggles only locker #100, how many lockers are open?
10. **Poison**: You have 1000 bottles of soda, and exactly one is poisoned. You have 10 test strips which can be used to detect poison. A single drop of poison will turn the test strip positive permanently. You can put any number of drops on a test strip at once and you can reuse a test strip as many times as you'd like (as long as the results are negative). However, you can only run tests once per day and it takes seven days to return a result. How would you figure out the poisoned bottle in as few days as possible?



### Recursion and Dynamic Programming
* Recursive algorithms can be very space inefficient.
* All recursive algorithms can be implemented iteratively, although sometimes the code to do so is much more complex. 

1. **Triple Step**: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.
2. **Robot in a Grid**: Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.
3. **Magic Index**: A magic index in an array A[ 0••• n -1] is defined to be an index such that A[ i] = i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
4. **Power Set**: Write a method to return all subsets of a set.
5. **Recursive Multiply**: Write a recursive function to multiply two positive integers without using the *operator.You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations.
6. **Towers of Hanoi**: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).You have the following constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto another tower.
(3) A disk cannot be placed on top of a smaller disk.
Write a program to move the disks from the first tower to the last using stacks.
7. **Permutations without Dups**: Write a method to compute all permutations of a string of unique characters.
8. **Permutations with Dups**: Write a method to compute all permutations of a string whose charac­ ters are not necessarily unique. The list of permutations should not have duplicates.
9. **Parens**: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n pairs of parentheses.
10. **Paint Fill**: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.
11. **Coins**: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing n cents.
12. **Eight Queens**: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.
13. **Stack of Boxes**: You have a stack of n boxes, with widths wi, heights hi, and depths di. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to compute the height of the tallest possible stack. The height of a stack is the sum of the heights of each box.
14. **Boolean Evaluation**: Given a boolean expression consisting of the symbols 0 (false), 1 (true), & (AND), I (OR), and /\ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.


### Sorting and Searching

1. **Sorted Merge**: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.
2. **Group Anagrams**: Write a method to sort an array of strings so that all the anagrams are next to each other.
3. **Search in Rotated Array**: Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.
4. **Sorted Search, No Size**: You are given an array-like data structure Listy which lacks a size method. It does, however, have an elementAt(i) method that returns the element at index i in 0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data structure only supports positive integers.) Given a Listy which contains sorted, positive integers, find the index at which an element x occurs. If x occurs multiple times, you may return any index.
5. **Sparse Search**: Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string.
6. **Sort Big File**: Imagine you have a 20 GB file with one string per line. Explain how you would sort the file.
7. **Missing Int**: Given an input file with four billion non-negative integers, provide an algorithm to generate an integer that is not contained in the file. Assume you have 1 GB of memo ry available for this task.
FOLLOW UP
What if you have only 10 MB of memory? Assume that all the values are distinct and we now have no more than one billion non-negative integers.
8. **Find Duplicates**: You have an array with all the numbers from 1 to N, where N is at most 32,000. The array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory available, how would you print all duplicate elements in the array?
9. **Sorted Matrix Search**: Given an M x N matrix in which each row and each column is sorted in ascending order, write a method to find an element.
10. **Rank from Stream**:Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a numberx (the number of values less than or equal tox). lmplement the data structures and algorithms to support these operations. That is, implement the method track ( int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal tox (not includingx itself).
11. **Peaks and Valleys**: In an array of integers, a"peak" is an element which is greater than or equal to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent inte­ gers. For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array of integers, sort the array into an alternating sequence of peaks and valleys.




## Other
### C and C++
must know
- Classes and Inheritance
- Constructors and Destructors
- Virtual Functions
- Virtual Destructor
- Default Values 
- Operator Overloading
- Pointers and References
- Templates


1. **Last K Lines**: Write a method to print the last K lines of an input file using C++.
2. **Reverse String**: Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.
3. **Hash Table vs. STL Map**: Compare and contrast a hash table and an STL map. How is a hash table implemented? If the number of inputs is small, which data structure options can be used instead of a hash table?
4. Virtual Functions: How do virtual functions work in C++?
5. Shallow vs. Deep Copy: What is the difference between deep copy and shallow copy? Explain how you would use each.
6. **Volatile**: What is the significance of the keyword "volatile" in C?
7. **Virtual Base Class**: Why does a destructor in base class need to be declared virtual?
8. **Copy Node**: Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure. The Node data structure contains two pointers to other Nodes.
9. **Smart Pointer**: Write a smart pointer class. A smart pointer is a data type, usually implemented with templates, that simulates a pointer while also providing automatic garbage collection. It automati­ cally counts the number of references to a SmartPointer<T*> object and frees the object of type T when the reference count hits zero.
10. **Malloc**: Write an aligned malloc and free function that supports allocating memory such that the memory address returned is divisible by a specific power of two.
11. **20Alloc**: Write a function in C called my2DA1loc which allocates a two-dimensional array.Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr[i][j ].

### Java

- Overloading vs. Overriding
- Collection Framework

1. **Private Constructor**: In terms of inheritance, what is the effect of keeping a constructor private?
2. **Return from Finally**: In Java, does the finally block get executed if we insert a return statement inside the try block of a try-catch-finally?
3. **Final, etc.**: What is the difference between final, finally, and finalize?
4. **Generics vs. Templates**: Explain the difference between templates in C++ and generics in Java.
5. **TreeMap, HashMap, LinkedHashMap**: Explain the differences between TreeMap, HashMap, and LinkedHashMap. Provide an example of when each one would be best.
6. **Object Reflection**: Explain what object reflection is in Java and why it is useful.
7. **Lambda Expressions**: There is a class Country that has methods `getContinent()` and `getPopulation()`. Write a function int `getPopulation(List<Country> countries, String continent)` that computes the total population of a given continent, given a  list of all countries and the name of a continent.
8. **Lambda Random**: Using Lambda expressions, write a function `List<Integer> getRandomSubset(List<Integer> list)` that returns a random subset of arbitrary size. All subsets (including the empty set) should be equally likely to be chosen

### Databases
must know
- SQL Syntax and Variations
- Denormalized vs. Normalized Databases
- SQL Statements
- Small Database Design

1. **Multiple Apartments**: Write a SOL query to get a list of tenants who are renting more than one apartment.
2. **Open Requests**: Write a SQL query to get a list of all buildings and the number of open requests (Requests in which status equals 'Open')
3. Close All Requests: Building #11 is undergoing a major renovation. Implement a query to close all requests from apartments in this building.
4. **Joins**: What are the different types of joins? Please explain how they differ and why certain types are better in certain situations.
5. **Denormalization**: What is denormalization? Explain the pros and cons.
6. **Entity-Relationship Diagram**: Draw an entity-relationship diagram for a database with companies, people, and professionals (people who work for companies).
7. **Design Grade Database**: Imagine a simple database storing information for students' grades. Design what this database might look like and provide a SQL query to return a list of the honor roll students (top 10%), sorted by their grade point average
 
### Threads and Locks

- Threads in Java
- Synchronization and Locks
- DeadlocksandDeadlockPrevention

1. **Thread vs. Process**: What's the difference between a thread and a process?
2. **Context Switch**: How would you measure the time spent in a context switch?
3. **Dining Philosophers**: In the famous dining philosophers problem, a bunch of philosophers are sitting around a circular table with one chopstick between each of them. A philosopher needs both chopsticks to eat, and always picks up the left chopstick before the right one. A deadlock could potentially occur if all the philosophers reached for the left chopstick at the same time. Using threads and locks, implement a simulation of the dining philosophers problem that prevents dead­ locks.
4. **Deadlock-Free Class**: Design a class which provides a lock only if there are no possible deadlocks.
5. **Call In Order**: Suppose we have the following code:
public class Foo {
public Foo() { ... }
public void first() { ... } public void second() { ... } public void third() { ... }
}
The same instance of Foo will be passed to three different threads. ThreadA will call first, threads will call second, and thread( will call third. Design a mechanism to ensure that first is called before second and second is called before third.
6. **Synchronized Methods**: You are given a class with synchronized method A and a normal method B. If you have two threads in one instance of a program, can they both execute A at the same time? Can they execute A and B at the same time?
7. **FizzBuzz**: In the classic problem FizzBuzz, you are told to print the numbers from 1 to n. However, when the number is divisible by 3, print"Fizz''. When it is divisible by 5, print"Buzz''. When it is divis­ ible by 3 and 5, print "FizzBuzz''. In this problem, you are asked to do this in a multithreaded way. Implement a multithreaded version of FizzBuzz with four threads. One thread checks for divisibility of 3 and prints "Fizz''. Another thread is responsible for divisibility of 5 and prints"Buzz''. A third thread is responsible for divisibility of 3 and 5 and prints"FizzBuzz''. A fourth thread does the numbers.




### Testing

1. **Mistake**: Find the mistake(s) in the following code:
2. **Random Crashes**: You are given the source to an application which crashes when it is run. After running it ten times in a debugger, you find it never crashes in the same place. The application is single threaded, and uses only the C standard library. What programming errors could be causing this crash? H ow would you test each one
3. **Chess Test**: We have the following method used in a chess game:boolean can MoveTo(int x, int y).This method is part of the Piece class and returns whether or not the piece can move to position (x, y). Explain how you would test this method.
4. **No Test Tools**: How would you load test a webpage without using any test tools?
5. **Test a Pen**: How would you test a pen?
6. **Test an ATM**: How would you test an ATM in a distributed banking system?

### Object-Oriented Design
1. **Deck of Cards**: Design the data structures for a generic deck of cards. Explain how you would subclass the data structures to implement blackjack.
2. **Call Center**: Imagine you have a call center with three levels of employees: respondent, manager, and director. An incoming telephone call must be first allocated to a respondent who is free. If the respondent can't handle the call, he or she must escalate the call to a manager. If the manager is not free or not able to handle it, then the call should be escalated to a director. Design the classes and data structures for this problem. Implement a method dispatchCall() which assigns a call to the first available employee.
3. **Jukebox**: Design a musical jukebox using object-oriented principles.
4. **Parking Lot**: Design a parking lot using object-oriented principles.
5. **Online Book Reader**: Design the data structures for an online book reader system.
6. **Jigsaw**: Implement an NxN jigsaw puzzle. Design the data structures and explain an algorithm to solve the puzzle. You can assume that you have a fitsWith method which, when passed two puzzle edges, returns true if the two edges belong together.
7. **Chat Server**: Explain how you would design a chat server. In particular, provide details about the various backend components, classes, and methods. What would be the hardest problems to solve?
8. **Othello**: Othello is played as follows: Each Othello piece is white on one side and black on the other. When a piece is surrounded by its opponents on both the left and right sides, or both the top and bottom, it is said to be captured and its color is flipped. On your turn, you must capture at least one of your opponent's pieces. The game ends when either user has no more valid moves. The win is assigned to the person with the most pieces. Implement the object-oriented design for Othello.
9. **Circular Array**: Implement a CircularArray class that supports an array-like data structure which can be efficiently rotated. If possible, the class should use a generic type (also called a template), and shouldsupportiterationviathestandardfor (Obj o : circularArray)notation.
10. **Minesweeper**: Design and implement a text-based Minesweeper game. Minesweeper is the classic single-player computer game where an NxN grid has B mines (or bombs) hidden across the grid. The remaining cells are either blank or have a number behind them. The numbers reflect the number of bombs in the surrounding eight cells. The user then uncovers a cell. If it is a bomb, the player loses. If it is a number, the number is exposed. If it is a blank cell, this cell and all adjacent blank cells (up to and including the surrounding numeric cells) are exposed. The player wins when all non-bomb cells are exposed. The player can also flag certain places as potential bombs. This doesn't affect game play, other than to block the user from accidentally clicking a cell that is thought to have a bomb. (Tip for the reader: if you're not familiar with this game, please play a few rounds online first.)
11. **File System**: Explain the data structures and algorithms that you would use to design an in-memory
file system. Illustrate with an example in code where possible.
12. **Hash Table**: Design and implement a hash table which uses chaining (linked lists) to handle colli­ sions.

### System Design and Scalability
1. Stock Data: Imagine you are building some sort of service that will be called by up to 1,000 client applications to get simple end-of-day stock price information (open, close, high, low). You may assume that you already have the data, and you can store it in any format you wish. How would you design the client-facing service that provides the information to client applications?You are respon­ sible for the development, rollout, and ongoing monitoring and maintenance of the feed. Describe the different methods you considered and why you would recommend your approach. Your service can use any technologies you wish, and can distribute the information to the client applications in any mechanism you choose.
2. Social Network: How would you design the data structures for a very large social network like Face­ book or LinkedIn? Describe how you would design an algorithm to show the shortest path between two people (e.g., Me -> Bob -> Susan -> Jason -> You).
3. Web Crawler: If you were designing a web crawler, how would you avoid getting into infinite loops?
4. Duplicate URLs: You have 10 billion URLs. How do you detect the duplicate documents? In this case, assume "duplicate" means that the URLs are identical.
5. Cache: Imagine a web server for a simplified search engine. This system has 100 machines to respondtosearchqueries,whichmaythencalloutusingprocessSearch(string query)to another cluster of machines to actually get the result. The machine which responds to a given query is chosen at random, so you cannot guarantee that the same machine will always respond to the same request. The method proc essSearch is very expensive. Design a caching mechanism for the most recent queries. Be sure to explain how you would update the cache when data changes.
6. Sales Rank: A large eCommerce company wishes to list the best-selling products, overall and by category.Forexample,oneproductmightbethe#1056thbest-sellingproductoverallbutthe#13th best-selling product under "Sports Equipment" and the #24th best-selling product under "Safety." Describe how you would design this system.
7. Personal Financial Manager: Explain how you would design a personal financial manager (like Mint.com). This system would connect to your bank accounts, analyze your spending habits, and make recommendations.
8. Pastebin: Design a system like Pastebin, where a user can enter a piece of text and get a randomly generated URL to access it.



### Moderate

1. **Number Swapper**: Write a function to swap a number in place (that is, without temporary variables).
2. **Word Frequencies**: Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm multiple times?
3. **Intersection**: Given two straight line segments (represented as a start point and an end point), compute the point of intersection, if any.
4. **Tic Tac Win**: Design an algorithm to figure out if someone has won a game of tic-tac-toe.
5. **Factorial Zeros**: Write an algorithm which computes the number of trailing zeros in n factorial.
6. **Smallest Difference**: Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.
7. **Number Max**: Write a method that finds the maximum of two numbers. You should not use if-else or any other comparison operator.
8. **English Int**: Given any integer, print an English phrase that describes the integer (e.g., "One Thou­ sand, Two Hundred Thirty Four").
9. **Operations**: Write methods to implement the multiply, subtract, and divide operations for integers. The results of all of these are integers. Use only the add operator.
10. **Living People**: Given a list of people with their birth and death years, implement a method to compute the year with the most number of people alive. You may assume that all people were born between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should be included in that year's count. For example, Person (birth= 1908, death= 1909) is included in the counts for both 1908 and 1909.
11. Diving Board: You are building a diving board by placing a bunch of planks of wood end-to-end. There are two types of planks, one of length shorter and one of length longer. You must use exactly K planks of wood. Write a method to generate all possible lengths for the diving board.
12. XMLEncoding: Since XML is very verbose, you are given away of encoding it where each taggets mapped to a pre-defined integer value.
13. Bisect Squares: Given two squares on a two-dimensional plane, find a line that would cut these two squares in half. Assume that the top and the bottom sides of the square run parallel to the x-axis.
14. Best Line: Given a two-dimensional graph with points on it, find a line which passes the most number of points.
15. Master Mind: The Game of Master Mind is played as follows:
The computer has four slots, and each slot will contain a ball that is red (R). yellow (Y). green (G) or blue (B). For example, the computer might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).
You, the user, are trying to guess the solution. You might, for example, guess Y RGB.
When you guess the correct color for the correct slot, you get a "hit:' If you guess a color that exists but is in the wrong slot, you get a "pseudo-hit:' Note that a slot that is a hit can never count as a pseudo-hit.
For example, if the actual solution is RGBY and you guess GGRR, you have one hit and one pseudo-hit. Write a method that, given a guess and a solution, returns the number of hits and pseudo-hits.
16. Sub Sort: Given an array of integers, write a method to find indices m and n such that if you sorted elements m through n, the entire array would be sorted. Minimize n - m (that is, find the smallest such sequences).
17. Contiguous Sequence: You are given an array of integers (both positive and negative). Find the contiguous sequence with the largest sum. Return the sum.
18. Pattern Matching: You are given two strings, pattern and value.The pattern string consists of just the letters a and b, describing a pattern within a string. For example, the string catcatgocatgo matches the pattern aabab (where cat is a and go is b). It also matches patterns like a, ab, and b. Write a method to determine if value matches pattern.
19. Pond Sizes: You have an integer matrix representing a plot of land, where the value at that location represents the height above sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally, or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.
20. T9: On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit mapped to a set of O - 4 letters. Implement an algorithm to return a list of matching words, given a sequence of digits. You are provided a list of valid words (provided in whatever data structure you'd like). 
21. Sum Swap: Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the two arrays the same sum.
22. Langton's Ant: An ant is sitting on an infinite grid of white and black squares. It initially faces right.
At each step, it does the following:
(1) At a white square, flip the color of the square, turn 90 degrees right (clockwise), and move forward one unit.
(2) At a black square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move forward one unit.
Write a program to simulate the first K moves that the ant makes and print the final board as a grid. Note that you are not provided with the data structure to represent the grid. This is something you must design yourself. The only input to your method is K. You should print the final grid and return nothing.Themethodsignaturemightbesomethinglikevoid printKMoves(int K).
23. Rand7 from Rands: Implement a method rand7() given rand5(). That is, given a method that generates a random number between O and 4 (inclusive), write a method that generates a random number between O and 6 (inclusive).
24. Pairs with Sum: Design an algorithm to find all pairs of integers within an array which sum to a specified value.
25. LRU Cache: Design and build a "least recently used" cache, which evicts the least recently used item. The cache should map from keys to values (allowing you to insert and retrieve a value associated with a particular key) and be initialized with a max size. When it is full, it should evict the least recently used item.
26. Calculator: Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses), compute the result.







### Hard


1. Add Without Plus: Write a function that adds two numbers. You should not use+ or any arithmetic operators.
2. Shuffle: Write a method to shuffle a deck of cards. It must be a perfect shuffle-in other words, each of the 52! permutations of the deck has to be equally likely. Assume that you are given a random number generator which is perfect.
3. Random Set: Write a method to randomly generate a set of m integers from an array of size n. Each element must have equal probability of being chosen.
4. Missing Number: An array A contains all the integers from Oto n, except for one number which is missing. In this problem, we cannot access an entire integer in A with a single operation. The elements of A are represented in binary, and the only operation we can use to access them is "fetch the jth bit of A[ i ],"which takes constant time. Write code to find the missing integer. Can you do it inO(n) time?
5. Letters and Numbers: Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.
6. Count of 2s: Write a method to count the number of 2s that appear in all the numbers between O and n (inclusive).
7. Baby Names: Each year, the government releases a list of the 10000 most common baby names and their frequencies(the number of babies with that name). The only problem with this is that some names have multiple spellings. For example,"John" and ''.Jon" are essentially the same name but would be listed separately in the list. Given two lists, one of names/frequencies and the other of pairs of equivalent names, write an algorithm to print a new list of the true frequency of each name. Note that if John and Jon are synonyms,and Jon and Johnny are synonyms, then John and Johnny are synonyms.(It is both transitive and symmetric.) In the final list, any name can be used as the "real" name.
8. Circus Tower: A circus is designing a tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons,each person must be both shorter and lighter than the person below him or her. Given the heights and weights of each person in the circus,write a method to compute the largest possible number of people in such a tower.
9. Kth Multiple: Design an algorithm to find the kth number such that the only prime factors are 3, 5, and 7. Note that 3, 5, and 7 do not have to be factors,but it should not have any other prime factors. For example,the first several multiples would be(in order) 1,3,5,7,9,15, 21.
10. Majority Element: A majority element is an element that makes up more than half of the items in an array. Given a positive integers array, find the majority element. If there is no majority element, return-1. Do this inO(N) time and 0(1) space.
11. WordDistance:Youhavealargetextfilecontainingwords.Givenanytwowords,findtheshortest distance(in terms of number of words) between them in the file. If the operation will be repeated many times for the same file(but different pairs of words),can you optimize your solution?
12. BiNode: Consider a simple data structure called BiNode, which has pointers to two other nodes. 
```cpp=
public class BiNode {
    public BiNode nodel, node2;
    public int data;
}
```
The data structure BiNode could be used to represent both a binary tree (where nodel is the left node and node2 is the right node) or a doubly linked list (where nodel is the previous node and node2 is the next node). Implement a method to convert a binary search tree (implemented with BiNode) into a doubly linked list. The values should be kept in order and the operation should be performed in place (that is, on the original data structure).
13. Re-Space: Oh, no! You have accidentally removed all spaces, punctuation, and capitalization in a lengthy document. A sentence like "I reset the computer. It still didn't boot!" became "iresetthecomputeritstilldidntboot''. You'll deal with the punctuation and capi­ talization later; right now you need to re-insert the spaces. Most of the words are in a dictionary but a few are not. Given a dictionary (a list of strings) and the document (a string), design an algorithm to unconcatenate the document in a way that minimizes the number of unrecognized characters.
14. Smallest K: Design an algorithm to find the smallest K numbers in an array.
15. Longest Word: Given a list of words, write a program to find the longest word made of other words in the list.
16. The Masseuse: A popular masseuse receives a sequence of back-to-back appointment requests and is debating which ones to accept. She needs a 15-minute break between appointments and therefore she cannot accept any adjacent requests. Given a sequence of back-to-back appoint­ ment requests (all multiples of 15 minutes, none overlap, and none can be moved), find the optimal (highest total booked minutes) set the masseuse can honor. Return the number of minutes.
17. Multi Search: Given a string band an array of smaller strings T, design a method to search b for each small string in T.
18. Shortest Supersequence: You are given two arrays, one shorter (with all distinct elements) and one longer. Find the shortest subarray in the longer array that contains all the elements in the shorter array. The items can appear in any order.
19. Missing Two: You are given an array with all the numbers from 1 to N appearing exactly once, except for one number that is missing. How can you find the missing number in O(N) time and 0(1) space? What if there were two numbers missing?
20. Continuous Median: Numbers are randomly generated and passed to a method. Write a program to find and maintain the median value as new values are generated.
21. Volume of Histogram: Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it could hold if someone poured water across the top. You can assume that each histogram bar has width 1.
22. Word Transformer: Given two words of equal length that are in a dictionary, write a method to transform one word into another word by changing only one letter at a time. The new word you get in each step must be in the dictionary.
23. Max Black Square: Imagine you have a square matrix, where each cell (pixel) is either black or white Design an algorithm to find the maximum subsquare such that all four borders are filled with black pixels.
24. Max Submatrix: Given an NxN matrix of positive and negative integers, write code to find the submatrix with the largest possible sum.
25. Word Rectangle: Given a list of millions of words,design an algorithm to create the largestpossible rectangle of letters such that every row forms a word (reading left to right) and every column forms a word (reading top to bottom). The words need not be chosen consecutively from the list but all rows must be the same length and all columns must be the same height.
26. Sparse Similarity: The similarity of two documents (each with distinct words) is defined to be the size of the intersection divided by the size of the union. For example, if the documents consist of integers, the similarity of { 1, 5, 3} and { 1, 7, 2, 3} is 0. 4, because the intersection has size 2 and the union has size 5.
We have a long list of documents (with distinct values and each with an associated ID) where the similarity is believed to be "sparse:'That is, any two arbitrarily selected documents are very likely to have similarity 0. Design an algorithm that returns a list of pairs of document IDs and the associated similarity.
Print only the pairs with similarity greater than 0. Empty documents should not be printed at all. For simplicity, you may assume each document is represented as an array of distinct integers.







