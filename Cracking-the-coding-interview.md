# Cracking the coding interview part 1 


###### tags: `interview` `algorithm`



[toc]


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

- 用array存取每個樹中每個節點，return 隨機元素 O(N) space O(N) time
- 用array存取每個樹中每個節點，return 隨機元素並刪除該元素 O(N) space O(N) time
- 可以用Inoreder traverse 標註樹中每個節點1...N，並隨機生成一個數字介於1到N之間，用binary search tree search t ofid the index O(N) time
- [Not working]
    - 1/3 odds traverse the current root
    - 1/3 odds traverse left 
    - 1/3 odds traverse right
    - 或是隨機決定深度

- 假設當初在建樹時有紀錄size，知道節點個數，針對上面方法做改善，O(logN) time

```java=
class TreeNode{
    private int data;
    public TreeNode left;
    public TreeNode right;
    private int size = 0;
    public TreeNode(int d){
        data = d;
        size = 1;
    }
    public TreeNode getRandomNote(){
        int leftSize = left ==null?0:left.size();
        Random random = new Random();
        int index = random.nextInt(size);
        if(index<leftSize){
            return left.getRandomNode();
           
        }
        else if (index==leftSize){
            return this;
        }
        else  return right.getRandomNode();
    }
    publoc void insertInOrder(int d){
        if(d<=data){
            if(left ==null){
                left = new TreeNode(d);
                
            }
            else{
                left.insertInOrder(d);
            }
        }
        else{
            if(right==null)
            {
                right = new TreeNode(d);
            }
            else{
                right.insertInOrder(d);
            }
        }
        size++;

    }
    public int size(){return size;}
    public int data() {return data;

    public TreeNode find(int d){
        if(d==data){
            return this;
        }
        else if(d<= data){
            return left != null? left.find(d): null;
        }
        else if(d>data){
            return right != null?right.find(d):null;
        }
        return null;
    }
}
```



O(logN)

```java=

class Tree{
    TreeNode root= nullptr;
    public int size() {return root ==null ?0 : root.size();}
    public TreeNode getRandomNode(){
        if(root==null) return null;

        Random random = new Random();
        int i = random.nextInt(size());
        return root.getIthNode(i);
    }
    public void insertInOrder(int value){
        if(root=null){
            root = new TreeNode(value);
        }
        else{
            root.insertInOrder(value);
        }
    }
}
class TreeNode{
    
    public TreeNode getIthNode(int i){
        int leftSize = left ==null ?0:left.size();
        if(i<leftSize){
            return left.getIthNode(i);
        }
        else if(i==leftSize){
            return this;
        }
        else{
            return right.getIthNode(i - (leftSize+1));
        }
    }
    public void insertInOrder(int d){
        if(d<=data){
            if(left ==null){
                left = new TreeNode(d);
                
            }
            else{
                left.insertInOrder(d);
            }
        }
        else{
            if(right==null)
            {
                right = new TreeNode(d);
            }
            else{
                right.insertInOrder(d);
            }
        }
        size++;
    }
    public int size(){return size;}
    public TreeNode find(int d){
        if(d==data){
            return this;
        }
        else if(d<= data){
            return left != null? left.find(d): null;
        }
        else if(d>data){
            return right != null?right.find(d):null;
        }
        return null;

    }
}
```
##### **Paths with Sum**: You are given a binary tree in which each node contains an integer value (which might be positive or negative). Design an algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).


- Leetcode 112. Path Sum
- Leetcode 113. Path Sum II
- Leetcode 437. Path Sum III
- Leetcode 666. Path Sum IV



437 Path Sum III 
Brute force O(N log N)in a balanced tree
```cpp=
int countPathsWithSumFromNode(TreeNode *node, int targetSum , int currentSum ){
        if(!node) return 0;
        
        currentSum += node->val;
        int totalPaths = 0;
        if (currentSum == targetSum) { // Found a path from the root
            totalPaths++;
        }
        
        totalPaths += countPathsWithSumFromNode(node->left, targetSum, currentSum);
        totalPaths += countPathsWithSumFromNode(node->right, targetSum, currentSum);
        return totalPaths;
            
        
    }
    int countPathsWithSum(TreeNode* root, int targetSum){
        if(!root) return 0;
        
        /* Count paths with sum starting from the root. */
        int pathsFromRoot = countPathsWithSumFromNode(root, targetSum, 0);
        
        /* Try the nodes on the left and right. */
        int pathsOnLeft = countPathsWithSum(root->left, targetSum);
        int pathsOnRight = countPathsWithSum(root->right, targetSum);
        return pathsFromRoot + pathsOnLeft + pathsOnRight;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        return countPathsWithSum(root, targetSum);
    }
  
```  

O(N) time
O(logN)in a balanced tree

```java=
int countPathWithSum(TreeNode root, int targetSum){
        return countPathWitheSum(root, targetSum, 0, new HashMap<Integer, Integer>());
}
int countPathWitheSum(TreeNode root, int targetSum, int runningSum, HashMap<Integer, Integer> pathCount){
    if(node==null) return 0; // Base case
    /* Count paths with sum ending at the the current node */
    runningSum += node.data;
    int sum = runningSum -targetSum;
    int totalPaths = pathCount.getOrDefault(sum , 0);

    /*  If runningSum eaquls targetSum , then one additionl path starts at root. Add in this path */
    if(runningSum == targetSum) totalPaths++;

    /*  Increment pathCount, recurse, then decrement pathCount. */
    incrementHashTable(pathCount, runningSum, 1);
    totalPaths+= countPathWitheSum(root.left, targetSum, runningSum, pathCount);
    totalPaths+= countPathWitheSum(root.right, targetSum, runningSum, pathCount);
    incrementHashTable(pathCount, runningSum, -1);
    return totalPaths;
}

void incrementHashTable(HashMap<Integer, Integer> hashTable, int key, int delta){
        int newCount = hashTable.getOrDefault(key,0) + delta;
        if(newCount==0) hashTable.reome(key);
        else hashTable.put(key, newCount);
}
    
```

### Bit Manipulation
x^ 000000 = x
x^ 111111 = ~x
x^ x = 0
x | x = x

##### **Insertion**: You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i. You can assume that the bits j through i have enough space to fit all of M. That is, if M = 10011, you can assume that there are at least 5 bits between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.


```java=

int updateBits(int n, int m, int i , int ,j){
    // EXAMPLE
    //  input: N = 10000000000, M = 10011 , i=2 j= 6
    // output: N = 10001001100
    // 
    int allOnes = ~0; // will equal sequence of all 1s.

    // 1s before position j, then 0s. left = 11110000000
    int left = allOnes << (j+1);

    // 1's after position i . right = 00000000100 - 1 = 00000000011
    int right = ((1<<i)-1); 
    
    // All 1s, excepts for 0s between i and j , mask = 11110000011
    int mask = left | right;

    int n_cleared = n & mask; // clear bits j throught i/ n_cleared = 10000000000
    int m_shifted = m<<i;  // MOve m into correct position. , m_shifted = 00001001100


    //  10000000000 | 00001001100 = 10001001100
    return n_cleared | m_shifted; // OR them, and we-'re down.
}
```


##### **Binary to String**: Given a real number between O and 1 (e.g., 0.72) that is passed in as a double, print the binary representation. If the number cannot be represented accurately in binary with at most 32 characters, print "ERROR:'

- Leetcode 190. Reverse Bits
- Leetcode 1290. Convert Binary Number in a Linked List to Integer



```java=
String printBinary(double num){
    if(num>=1 || num<=0) return "ERROR";

    StringBuilder binary = new StringBuilder();
    binary.append(".");
    while(num>0){
        if(binary.length() >=32){
            return "ERROR";
        }

        double r = num*2;
        if(r>=1){
            binary.append(1);
            num = r-1;
        }
        else{
            binary.append(0);
            num = r;
        }
    }
    return binary.toString();
}

```



```java=

String printBinary(double num){
    if(num>=1 || num<=0) return "ERROR";

    StringBuilder binary = new StringBuilder();
    double frac = 0.5;
    binary.append(".");
    while(num>0){
        if(binary.length() > 32){
            return "ERROR";
        }
        
        if(num>=frac){
            binary.append(1);
            num -= frac;
        }
        else{
            binary.append(0)
        }
        frac /=2;
    }
    return binary.toString();
}
```


##### **Flip Bit to Win**: You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of ls you could create.

- [Length of the Longest Consecutive 1s in Binary Representation](https://www.geeksforgeeks.org/length-longest-consecutive-1s-binary-representation/?ref=lbp)

- [Find longest sequence of 1’s in binary representation with one flip](https://www.geeksforgeeks.org/find-longest-sequence-1s-binary-representation-one-flip/)

```java=
// brute force
// EXAMPLE 
// input : 1175 (or: 11011101111) seq =  [0,4,1,3,1,2,21] reading bfrom right to left
// output 8
// O(b) time and O(b) space , where b in the length of the sequence.
int longestSequence(int n){
    if(n==-1) return Integer.BYTES*8;
    ArrayList<Integer> sequences = getAlternatingSequeces(n);
    return findLongestSequence(sequences);
}
/* Return a list of the sizes of the sequences. The sequence starts off with the
 number of 0s (which might be 0) and then alternates with the counts of each value
 */
ArrayList<Integer> getAlternatingSequeces(int n){
    ArrayList<Integer> sequences = new ArrayList<Integer>();

    int searchingFor = 0;
    int counter = 0;

    for(int i=0;i<Integer.BYTES*8 ;++i){
        if((n&1)!=searchingFor){
            sequences.add(counter);
            searchingFor = n&1;
            counter = 0;
        }
        counter++;
        n >>>=1;
    }
    sequences.add(counter);
    return sequences; //seq =  [0,4,1,3,1,2,21] 
}
/* Given the lengths of alternating sequences of 0s and ls, find the longest one
 we can build. */
int findLongestSequence(ArrayList<Integer> seq){
    int maxSeq = 1;
    for(int i=0;i<seq.size();i+=2){
        int zerosSeq = seq.get(i);
        int onesSeqRight = i-1 >=0 ? seq.get(i-1):0;
        int onesSeqLeft = i+1 <seq.size() ? seq.get(i+1) : 0 ;

        int thisSeq =0;
        if(zerosSeq == 1){  // can merge
            thisSeq = onesSeqLeft +1 + onesSeqRight;
        }
        if(zerosSeq>1){ // just add a zero to either side
            thisSeq = 1+ Math.max(onesSeqRight, onesSeqLeft);
        }
        else if(zerosSeq==0){ // No zero, but take either size
            thisSeq = Math.max(onesSeqRight, onesSeqLeft);
        }
        maxSeq = Math.max(thisSeq, maxSeq);
    }
    return maxSeq;
}
```



```java=

// O(b) time  but O(1) space
// When we see a zero, update previous Length:
// If the next bit is a 1, previous Length should be set to current Length.
// If the next bit is a 0, then we can't merge these sequences together. So, set previous Length to 0.

int flipBit(int a){
    /* If all 1s , this is already the longest sequence */
    if(~a==0) return Integer.BYTES*8;

    int currentLength =  0;
    int previousLength = 0;
    int maxLength = 1 ;

    while(a!=0){
        if((a&1) == 1){
            currentLength++;
        }
        else if((a&1)==0){
            previousLength = (a&2)==0?0:currentLength;
            currentLength  = 0;
        }

        maxLength = Math.max(previousLength + currentLength +1 , maxLength);
        a >>>=1;
    }
    return  maxLength;
}
```

##### **Next Number**: Given a positive integer, print the next smallest and the next largest number that have the same number of 1 bits in their binary representation.

```java=

// Bit Manipulation for Get Next Number
// EXAMPLE 13948 = 1101101111100
// step 1 Flip rightmost non-trailing zero => 11011011111100
// step 2 Clear bits to the right of p from befor, c0 = 2, c1 = 5, p=7 => 11011010000000
// a = 1<<p;
// b=a-1;
// mask = ~b;
// n=n&mask;
// equal to 
// n &= ~((1<<p)-1)
// step 3 Add in c1-1 ones => 11011010001111 
// a = 1<< (c1-1);
// b= a-1;
// n = n| b;
// equal to
// n |= (1<<(c1-1)) -1;

int getNext(int n){
    /* compute c0 and c1 */
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while( ((c&1)==0) && (c!=0) ){
        c0++;
        c >>= 1;
    }
    while( (c&1) ==1){
        c1++;
        c >>= 1 ;
    }


    /* Error: if n == 11..1100...00, then there is no bigger number with the same number of 1s*/
    if(c0+c1 ==31 || c0+c1 ==0){
        return -1;
    }
    int p = c0+c1; //position of rightmost non-trailing zeros

    n |= (1<<p); //Flip rightmost non-trailing zeros
    n &= ~((1<<p)-1 ) ; // Clear all bits to the right of p
    n |= (1<< (c1-1))-1 ; // Insert (c1-1) ones on the right

    return n;
}


// Bit Manipulation for Get Previous Number
// steps 1 initialize number p = 7 , c1 =2, c0 = 5
// 10011110000011
// steps 2 & 3 clear bits 0 through p
// 10011100000000
// int a= ~0;
// int b = a<<(p+1);
// n &=b;
// steps 4 Insert c1+1 ones immediately to the right of position p.
// int a = 1<< (c1+1);
// int b = a-1;
// int c = b<<(c0-1);
// n|=c;
// 10011101110000
int getPrec(int n){
    int temp = n;
    int c0 = 0; // the size of block of zeros immediately to the left of the trailing ones
    int c1 = 0;  // c1 is the number of trailing ones
    while( ( temp&1)==1){
        c1++;
        temp>>=1;
    }

    if(temp==0)return -1;

    while( ((temp&1)==0 ) && (temp!=0)){
        c0++;
        temp>>=1;
    }
    
    
    

    int p = c0+c1;
    n &= ((~0) << (p+1)); // clears from bits p onwards

    int mask = (1<<(c1+1))-1;  //Sequence of (c1+1) ones

    n|= mask <<(c0-1);

    return n
}

// Arithmetic Approach for Get Next Number
// c0 is the number of trailing zeros, c1 is the size of the one block immediately followind, and  p=c0+c1,
//  we can word our solution from eariler as follows
// step 1 set the Pth bit to 1
// step 2 set all bits following p to 0
// step 3 set bits 0 through c1-2 to 1. This will be c1-1 total bits
// n+= 2^c0 -1 
// 
int getNextArith(int n){
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while( ((c&1)==0) && (c!=0) ){
        c0++;
        c >>= 1;
    }
    while( (c&1) ==1){
        c1++;
        c >>= 1 ;
    }

    return n + (1 << c0) + (1 << (c1 - 1)) - 1;
}


// Arithmetic Approach for Get Previous Number
//  c1 is the number of trailing ones , c0 is the size of the zero block immediately following, 
// and p = c0+c1
// step 1 set the Pth bit to 1
// step 2 set all bits following p to 0
// step 3 set bits 0 through c1-2 to 1. This will be c1-1 total bits


int getPrevArith(int n){
    int temp = n;
    int c0 = 0; // the size of block of zeros immediately to the left of the trailing ones
    int c1 = 0;  // c1 is the number of trailing ones
    while( ( temp&1)==1){
        c1++;
        temp>>=1;
    }

    if(temp==0)return -1;

    while( ((temp&1)==0 ) && (temp!=0)){
        c0++;
        temp>>=1;
    }

    return n - (1 << c1) - (1 << (c0 - 1)) + 1;
    
    
}
```
##### **Debugger**: Explain what the following code does: ((n & (n-1)) == 0).


- A&B==0
- A and B never have a 1 bit in the same place.
- 當你減一，都是看在最低有效位，如果是一變成零。如果是零，你必須借位更大一位的bit，當你遞增地向高位，遞增同時遇到零變成１，直到遇到１，並將他變為０



##### **Conversion**: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.


-  XOR 


```java=
int bitSwapRequired(int a, int b){
    int count = 0;
    for(int c = a^b ; c!=0 ; c =c >>1){
        count += (c&1);
    }
    return count;
}


// c = c & (c - 1) will clear the least significant bit in c


int bitSwapRequired(int a, int b){
    int count = 0;
    for(int c = a^b ; c!=0 ; c  = c &(c-1)){
        count ++;
    }
    return count;
}


```

##### **Pairwise Swap**: Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

we take a number n and move the odd bits over by 1
mask all odd bits with 10101010 in binary(which is 0xAA), then shift them right by 1 to put them in the even spots.
fro the even bits , we do an equivalent operation.
```java=
0xa =  1010 , 0x5 = 0101

int swapOddEvenBits(int x){
    return ( ((x& 0xaaaaaaaa)>>>1 ) | ((x& 0x55555555)<<1) );
}
```

##### **Draw Line**: A monochrome screen is stored as a single array of bytes, allowing eight consecutive pixels to be stored in one byte. The screen has width w, where w is divisible by 8 (that is, no byte will be split across rows). The height of the screen, of course, can be derived from the length of the array and the width. Implement a function that draws a horizontal line from (xl, y) to ( x2, y)


A naive solution to the problem is straightforward: iterate in a for loop from xl to x2, setting each pixel along the way

A better solution is to recognize that if xl and x2 are far away from each other, several full bytes will be contained between them. 
These full bytes can be set one at a time by doing screen[byte_pos] 0xFF.
he residual start and end of the line can be set using masks.

```java=
void drawLine(byte[] screen , int width, int x1, int x2, int y){
    int start_offset = x1%8;
    int first_full_byte = x1 / 8;

    if(start_offset !=0){
        first_full_byte++;
    }
    int end_offset = x2%8;
    int last_full_byte = x2/8;
    if(end_offsetet!=7){
        last_full_byte--;
    }

    // set full bytes
    for(int b = first_full_byte ; b<=last_full_byte; ++b){
        screen[(width/8)*y + b] = (byte) 0xFF;
    }

    // create masks for start and end of line
    byte start_mask = (byte)(0xFF >> start_offset);
    byte end_mask = (byte) ~(0xFF >> (end_offset + 1));

    // set start and end of lines
    if( (x1/8) == (x1/8)){ // xl and x2 are in the same byte
        byte mask= (byte) (start_mask & end_mask);
        screen[(width/ 8) * y + (xl / 8)] I= mask;
    }
    else{
        if (start_offset != 0) {
            int byte_number =(width/ 8) * y + first_full_byte - 1; 
            screen[byte_number] I= start_mask;
        }
        if(end_offset !=7){
            int byte_number =(width/ 8) * y + last_full_byte + 1;
            screen[byte_number] I= end_mask;
        }
    }
}
```


### Math and Logic Puzzles

##### **The Heavy Pill**: You have 20 bottles of pills. 19 bottles have 1.0 gram pills, but one has pills of weight 1.1 grams. Given a scale that provides an exact measurement, how would you find the heavy bottle? You can only use the scale once.

we must weigh multiple pills at the same time.
用平均法去排除


- **Basketball**: You have a basketball hoop and someone says that you can play one of two games.
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


##### **Triple Step**: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.


- Leetcode 70. Climbing Stairs
- Leetcode 509. Fibonacci Number



##### **Robot in a Grid**: Imagine a robot sitting on the upper left corner of grid with r rows and c columns. The robot can only move in two directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.


- Leetcode 62. Unique Paths
- Leetcode 63. Unique Paths II
- Leetcode 64. Minimum Path Sum




##### **Magic Index**: A magic index in an array A[ 0••• n -1] is defined to be an index such that A[ i] = i. Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.

brute force 
```java=

// brute force 
int magicSlow(int []array){
    for(int i=0;i<array.legth ; i++){
        if(array[i]==i){
            return i;
        }
    }
    return -1;
}
```




binary search
```java=
// assume elements are distinct 
int magicFast(int []array){
    return magicFast(array, 0 ,array.length-1);   
}
int magicFast(int []array , int start, int end){
    if(end<start) return -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(array[mid]==mid) return mid;
        else if(array[min]>mid ) end = mid-1;
        else start = mid+1;
    }
}

// assume elements are not  distinct 
int magicFast(int []array){
    return magicFast(array, 0 ,array.length-1);   
}
int magicFast(int []array , int start, int end){
    if(end<start) return -1;

    int midIndex = start + (end-start)/2;
    int midValue = array[midindex];
    if (midValue ==midIndex) {
        return midIndex;
    }

    /* Search Left */
    int leftindex = Math.min(midindex - 1, midValue);
    int left =magicFast(array, start, leftindex);
    if(left>0) return left;

    /* Search Right */
    int rightindex = Math.max(midindex + 1, midValue);
    int right = magicFast(array, rightlndex, end);
    return right;

}
```

##### **Power Set**: Write a method to return all subsets of a set.

- Leetcode 78. Subsets
- Leetcode 90. Subsets II





5. **Recursive Multiply**: Write a recursive function to multiply two positive integers without using the *operator.You can use addition, subtraction, and bit shifting, but you should minimize the number of those operations.


```java=
int minProduct(int a, int b){
    int bigger = a<b?b:a;
    int smaller = a<b?a:b;
    return minProductHelper(smaller, bigger);
}

int minProductHelper(int smaller, int bigger){
    if(smaller==0) return 0;
    else if(smaller ==1) return bigger;

    int s = smaller >>1 
    int side1 = minProduct(s, bigger);
    int side2 = side1;
    if(smaller %2==1) side2 = minProductHelper(smaller-s , bigger);
    return side1+side2;
}
```

memo 


```java=

int minProduct(int a, int b, int []memo){
    int bigger = a<b?b:a;
    int smaller = a<b?a:b;
    int memo[] = new int[smaller +1 ];
    return minProductHelper(smaller, bigger, memo);
}

int minProductHelper(int smaller, int bigger, int []memo){
    if(smaller==0) return 0;
    else if(smaller ==1) return bigger;
    else if(memo[smaller]>0) return memo[smaller];

    int s = smaller >>1 
    int side1 = minProduct(s, bigger, memo);
    int side2 = side1;
    if(smaller %2==1) side2 = minProductHelper(smaller-s , bigger, memo);
    memo[smaller] = side1 + side2 ; 

    return memo[smaller];
}
```


O(log s) time, s is the smaller of two numbers.
```java=

int minProduct(int a, int b){
    int bigger = a<b?b:a;
    int smaller = a<b?a:b;
    return minProductHelper(smaller, bigger);
}

int minProductHelper(int smaller, int bigger){
    if(smaller==0) return 0;
    else if(smaller ==1) return bigger;

    int s = smaller >>1 
    int halfProd =  minProduct(s, bigger);
    int side2 = side1;
    if(smaller %2==0) return  halfProd + halfProd;;
    else retrun  halfProd + halfProd + bigger;

    
}
```

##### **Towers of Hanoi**: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one).You have the following constraints:
(1) Only one disk can be moved at a time.
(2) A disk is slid off the top of one tower onto another tower.
(3) A disk cannot be placed on top of a smaller disk.
Write a program to move the disks from the first tower to the last using stacks.


- [Towers of Hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/)


```java=

void main(String [] args){
    int n = 3;
    Tower[] towers = new Tower[n];
    for(int i = 0;i<3;++i){
        towers[i] = new Tower(i);
    }

    for(int i=n-1;i>=0;i--){
        towers[0].add(i);
    }
    towers[0].moveDisk(n, towers[2], towers[1]);
}

class Tower{
    private Stack<Integer> disks;
    private int index;public Tower(int i ){
        disks = new Stack<Integer>();
        index = i;
    }
    public int index(){
        return index;
    }

    public void add(int d){
        if(!disks.isEmpty() && disks.peek()<=d){
            System.out.println("Error placing disk" + d);
        }
        else{
            disks.push(d);
        }
    }
    public void moveTopTo(Tower t){
        int top = disks.top();
        t.add(top);
    }
    public void moveDisks(int n, Tower destination, Tower buffer){
        if(n>0){
            moveDisks(n-1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n-1 , destination, this);
        }
    }
}

```


##### **Permutations without Dups**: Write a method to compute all permutations of a string of unique characters.

Approach 1: Building from permutations of first n-1 characters.


```java=

Arraylist<String> getPerms(String str) {
    if (str == null) return null;
    Arraylist<String> permutations new ArrayList<String>();
    if (str.length() == 0) {//base case
        permutations. add('"');
        return permutations;
    }

    char first= str.charAt(0); // get the first char
    String remainder= str.substring(l); // remove the first char
    Arraylist<String> words= getPerms(remainder);
    for(String word :words){
        for(int j =0;j<word.length(); j++){
            String s = insertCharAt(word, first, j);
            permutations.add(s);
        }
    }
    return permutations;
}
/* Insert char c at index i in word. */
String insertCharAt(String word, char c, int i) {
    String start= word.substring(0, i);
    String end= word.substring(i);
    return start+ c + end;
}
```

Approach 2: Building from permutations of all n-1 character substrings.
```java=

Arraylist<String> getPerms(String str) {
    Arraylist<String> result = new Arraylist<String>();
    getPerms("", str, result);
    return  result;

}


void getPerms(String prefix, String remainder, Arraylist<String> result) {
    if (remainder.length()== 0) result.add(prefix);

    int len = remainder.length();
    for (int i= 0; i < len; i++) {
        String before = remainder.substring(0, i);
        String after = remainder.substring(i+1, len);
        char c =remainder.charAt(i);
        getPerms(prefix+c, before+after, result);
    }
}
```

- Leetcode 46. Permutations


##### **Permutations with Dups**: Write a method to compute all permutations of a string whose charac­ ters are not necessarily unique. The list of permutations should not have duplicates.

- Leetcode 47. Permutations II
用vector 或是 hash 去判斷是否拜訪過


```java=
Arraylist<String> printPerms(String s) {
    Arraylist<String> result;
    HashMap<Character, Integer> map = buidFreqTable(s);
    printPerms(map, "", s.length(), result);

    return result;
}

HashMap<Character, Integer> buidFreqTable{
    HashMap<Character, Integer> map= new HashMap<Character, Integer>();
    for (char c : s.toCharArray()) {
        if(!map.containsKey(c)){
            map.put(c,0);
        }
        map.put(c, map.get(c) + 1);
    }
    return map;
}

void printPerms(HashMap<Character, Integer> map, String prefix, int remaining,Arraylist<String> result){
    /* Base case. Permutation has been completed. */
    if (remaining== 0) {{
        result.add(prefix);
        return;
    }

    /* Try remaining letters for next char, and generate remaining permutations. */
    for (Character c : map.keySet()) {
        int count = map.get(c).toInt();
        if(count>0){
            map.put(c, count-1);
            printPerms(map, prefix+c, remaining-1, result)
            map.put(c, count);
        }
    }
}
```



##### **Parens**: Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n pairs of parentheses.

- Leetcode 20. Valid Parentheses
- Leetcode 22. Generate Parentheses



##### **Paint Fill**: Implement the "paint fill" function that one might see on many image editing programs. That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original color.


- Leetcode 733. Flood Fill


##### **Coins**: Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents), and pennies (1 cent), write code to calculate the number of ways of representing n cents.

- Leetcode 322. Coin Change



```java=
int makeChanges(int amount , int []denoms, int index){
    if(index > denoms.length-1) return 1; //last denom

    int denomAmount =denoms[index];
    int ways = 0 ;

    for(int i=0;i* denomAmount <= amount;++i){
        int amountRemaining = amount - i*denomAmount;
        ways += makeChanges(amountRemaining, denoms, index+1);
    }
    return ways;
}

int makeChanges(int n){
    int[] denoms = {25,10,5,1};
    return makeChanges(n, denoms, 0);
}


// memo

int makeChanges(int amount , int []denoms, int index, int[][] map){
    if(map[amount][index] >0) return map[amount][index];

    if(index > denoms.length-1) return 1; //last denom

    int denomAmount =denoms[index];
    int ways = 0 ;

    for(int i=0;i* denomAmount <= amount;++i){
        int amountRemaining = amount - i*denomAmount;
        ways += makeChanges(amountRemaining, denoms, index+1);
    }
    map[amount][index] = ways;
    return ways;
}

int makeChanges(int n){
    int[] denoms = {25,10,5,1};
    int[][] map = new int[n+1][denoms.length];
    return makeChanges(n, denoms, 0);
}


```




##### **Eight Queens**: Write an algorithm to print all ways of arranging eight queens on an 8x8 chess board so that none of them share the same row, column, or diagonal. In this case, "diagonal" means all diagonals, not just the two that bisect the board.

- Leetcode 51. N-Queens
- Leetcode 52. N-Queens II

```java=

int GRID_SIZE = 8 ;

void placeQueens(int row, Integer[] columns, ArrayList<Integer[]> results){
    if(row == GRID_SIZE){
        results.add(columns.clone());
    }
    else{
        for(int col = 0; col<GRID_SIZE;col++){
            if(checkValid(columns, row, col)){
                columns[row] = col; //place queen
                placeQueens(row+1, columns, results);
            }
        }
    }
}


boolean checkValid(Integer[] columns, int row1, int column1){
    for(int row2 = 0;row2 < row1 ; row2++){
        int column2 = columns[row2];


        if(column1 == column2){
            return false;
        }

        int columnDistance = Math.abs(column2- column1);

        int rowDistance = row1 - row2;
        if(columnDistance== rowDistance) return false;
    }
    return true;
}
```
##### **Stack of Boxes**: You have a stack of n boxes, with widths wi, heights hi, and depths di. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly larger than the box above it in width, height, and depth. Implement a method to compute the height of the tallest possible stack. The height of a stack is the sum of the heights of each box.




##### **Boolean Evaluation**: Given a boolean expression consisting of the symbols 0 (false), 1 (true), & (AND), I (OR), and /\ (XOR), and a desired boolean result value result, implement a function to count the number of ways of parenthesizing the expression such that it evaluates to result.


### Sorting and Searching

##### **Sorted Merge**: You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B. Write a method to merge B into A in sorted order.


- Leetcode 88. Merge Sorted Array
- Leetcode 21. Merge Two Sorted Lists
- Leetcode 23. Merge k Sorted Lists
##### **Group Anagrams**: Write a method to sort an array of strings so that all the anagrams are next to each other.

sort or use hash 
- Leetcode 242. Valid Anagram
- Leetcode 49. Group Anagrams



##### **Search in Rotated Array**: Given a sorted array of n integers that has been rotated an unknown number of times, write code to find an element in the array. You may assume that the array was originally sorted in increasing order.

- Leetcode 189. Rotate Array
- Leetcode 796. Rotate String




##### **Sorted Search, No Size**: You are given an array-like data structure Listy which lacks a size method. It does, however, have an elementAt(i) method that returns the element at index i in 0( 1) time. If i is beyond the bounds of the data structure, it returns -1. (For this reason, the data structure only supports positive integers.) Given a Listy which contains sorted, positive integers, find the index at which an element x occurs. If x occurs multiple times, you may return any index.


exponential search
- Leetcode 35. Search Insert Position






##### **Sparse Search**: Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string.


```java=
EXAMPLE
INPUT: ball , {"at","","","","ball","","","car","","","dad","",""}
OUTPUT: 4 




int search(String [] strings, String str, int first, int last){
    if(first > last) return -1;

    int mid = (last + first )/2;

    if(strings[mid].isEmpty()){
        int left = mid -1;
        int right = mid +1;

        while(true){
            if(left < first && right > last){
                return -1;
            }
            else if(right <=last && !strings[right].isEmpty()){
                mid = right;
                break;
            }
            else if(left >=first && !strings[left].isEmpty()){
                mid = left;
                break;
            }
            right++;
            left--;
        }
    }
    if(str.equals(strings[mid])){ //found it
        return mid;
    }
    else if(strings[mid].compareTo(str)<0){ //search right
        return search(strings, str, mid+1, last);
    }
    else{ //search left
        return search(strings, str, first, mid-1);
    }

}

int search(String[] strings, String str){
    if(strings == null || str == null || str=="") return -1;

    return search(strings, str,0, str.length-1);
}```






##### **Sort Big File**: Imagine you have a 20 GB file with one string per line. Explain how you would sort the file.


- it suggests that they don't want you to bring all the data into memory.
- We'll divide the file into chunks, which are x megabytes each, where x is the amount of memory we have available. Each chunk is sorted separately and then saved back to the file system.
- Once all the chunks are sorted, we merge the chunks, one by one. At the end, we have a fully sorted file.
- This algorithm is known as external sort.


##### **Missing Int**: Given an input file with four billion non-negative integers, provide an algorithm to generate an integer that is not contained in the file. Assume you have 1 GB of memo ry available for this task.

```java=
FOLLOW UP
What if you have only 10 MB of memory? Assume that all the values are distinct and we now have no more than one billion non-negative integers.



long numberOflnts = ((long) Integer.MAX_VALUE) + 1;
byte[] bitfield new byte [(int) (numberOfints / 8)];
String filename = ................
void findOpenNumber() throws FileNotFoundException {
    Scanner in = new Scanner(new FileReader(filename));
    while (in.hasNextint()) {
        int n = in.nextlnt ();
        /* Finds the corresponding number in the bitfield by using the OR operator to
        * set the nth bit of a byte (e.g., 10 would correspond to the 2nd bit of
        * index 2 in the byte array). */
        bitfield[n/8] I=1«(n%8);
    }
    for (int i= 0; i < bitfield.length; i++) {
        for (int j= 0; j < 8; j++) {
            /* Retrieves the individual bits of each byte. When 0 bit is found, print
                * the corresponding value. */
            if ((bitfield[i] & (1 << j)) == 0) {
                System.out.println (i * 8 + j);
                return ;
            }
        }
    }
}


// Follow Up: What if we have only 10 MB memory?
int findOpenNumber(String filename) throws FileNotFoundException {
    int rangeSize = (1 << 20); // 2A20 bits (2A17 bytes)
    /* Get count of number of values within each block. */
    int[] blocks = getCountPerBlock(filename, rangeSize);

    /* Find a block with a missing value. */
    int blocklndex findBlockWithMissing(blocks, rangeSize);
    if (blocklndex < 0) return -1;

    /* Create bit vector for items within this range. */
    byte[] bitVector = getBitVectorForRange(filename, blockindex, rangeSize);

    /* Find a zero in the bit vector */
    int offset findZero(bitVector);
    if (offset <0) return -1;

    /* Compute missing value. */
    return blockindex * rangeSize + offset;
}


/* Get count of items within each range. */
int[] getCountPerBlock(String filename, int rangeSize) throws FileNotFoundException {

    int arraySize = Integer.MAX_VALUE / rangeSize + 1;
    int[] blocks = new int[arraySize];
    Scanner in = new Scanner (new FileReader(filename));
    while (in.hasNextint()) {
        int value = in.nextint();
        blocks[value / rangeSize]++;
    }
    in.close();
    return blocks;
}

/* Find a block whose count is low. */
int findBlockWithMissing(int[] blocks, int rangeSize) {
    for (int i= 0; i < blocks.length; i++) {
        if (blocks[i] <rangeSize){
            return i;
        }
    }
    return -1;
}

/* Create a bit vector for the values within a specific range. */
byte[] getBitVectorForRange(String filename, int blockindex, int rangeSize) throws FileNotFoundException {
    int startRange = blockindex * rangeSize;
    int endRange = startRange + rangeSize;
    byte[] bitVector = new byte[rangeSize/Byte.SIZE];

    Scanner in = new Scanner(new FileReader(filename));
    while (in.hasNextint()) {
        int value = in.nextint();
        /* If the number is inside the block that's missing numbers, we record it */
        if (startRange <= value && value <endRange) {
            int offset = value - startRange;
            int mask = (1 <<(offset% Byte.SIZE));
            bitVector[offset / Byte.SIZE) I= mask;
        }
    }
    in.close();
    return bitVector;
}

/*Find bit index that is 0 within byte. */
int findZero(byte b) {
    for (int i= 0; i < Byte.SIZE; i++) {
        int mask= 1 << i;
        if ((b & mask)== 0) {
            return i ;
        }
    }
    return -1;
}

/*Find a zero within the bit vector and return the index. */
int findZero(byte[] bitVector) {
    for (int i= 0; i < bitVector.length; i++) {
        if (bitVector[i] =! -0) {//If not all ls
            int bitindex= findZero(bitVector[i]);
            return i *Byte.SIZE+ bitindex;
        }
    }
    return -1; 
}
```
- Leetcode 268. Missing Number
- Leetcode 1539. Kth Missing Positive Number
- Leetcode 41. First Missing Positive



##### **Find Duplicates**: You have an array with all the numbers from 1 to N, where N is at most 32,000. The array may have duplicate entries and you do not know what N is. With only 4 kilobytes of memory available, how would you print all duplicate elements in the array?


- Leetcode 1089. Duplicate Zeros
- Leetcode 217. Contains Duplicate
- Leetcode 219. Contains Duplicate II
- Leetcode 220. Contains Duplicate III
- Leetcode 287. Find the Duplicate Number
- Leetcode 26. Remove Duplicates from Sorted Array
- Leetcode 83. Remove Duplicates from Sorted List
- Leetcode 82. Remove Duplicates from Sorted List II

```java=

void checkDuplicates(int[] array) {
    BitSet bs = new BitSet(32000);
    for (int i= 0; i < array.length; i++) {
        int num = array[i];
        int num0 = num - 1; //bitset starts at 0, numbers start at 1
        if (bs.get(num0)) {
            System.out.println(num);
        }
        else{
            bs.sgt(num0);
        }
    }
}

class BitSet {
    int [] bitset;
    public BitSet(int size){
        bitset = new int[(size>>5) +1 ]; //divid by 32
    }

    boolean get(int pos){
        int wordNumber = (pos >> 5); // divide by 32
        int bitNumber = (pos & 0x1F); // mod 32
        return (bitset[wordNumber] & (1 << bitNumber)) != 0;
    }

    void set(int pos){
        int wordNumber = (pos >> 5); // divide by 32
        int bitNumber = (pos & 0x1F); // mod 32
        bitset[wordNumber] I= 1 << bitNumber;
    }

```


##### **Sorted Matrix Search**: Given an M x N matrix in which each row and each column is sorted in ascending order, write a method to find an element.


binary search or 雙指標並從左下或右上開始搜尋
- Leetcode 74. Search a 2D Matrix 
- Leetcode 240. Search a 2D Matrix II


##### **Rank from Stream**:Imagine you are reading in a stream of integers. Periodically, you wish to be able to look up the rank of a numberx (the number of values less than or equal tox). lmplement the data structures and algorithms to support these operations. That is, implement the method track ( int x), which is called when each number is generated, and the method getRankOfNumber(int x), which returns the number of values less than or equal tox (not includingx itself).

- Leetcode 496. Next Greater Element I
- Leetcode 503. Next Greater Element II
- Leetcode 1019. Next Greater Node In Linked List
- Leetcode 739. Daily Temperatures




##### **Peaks and Valleys**: In an array of integers, a"peak" is an element which is greater than or equal to the adjacent integers and a "valley" is an element which is less than or equal to the adjacent inte­ gers. For example, in the array {5, 8, 6, 2, 3, 4, 6}, {8, 6} are peaks and {5, 2} are valleys. Given an array of integers, sort the array into an alternating sequence of peaks and valleys.




