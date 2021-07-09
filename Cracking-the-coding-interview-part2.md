# Cracking the coding interview part 2


###### tags: `interview` `algorithm`


[toc]

## C and C++
must know
- Classes and Inheritance
- Constructors and Destructors
- Virtual Functions
- Virtual Destructor
- Default Values 
- Operator Overloading
- Pointers and References
- Templates


##### **Last K Lines**: Write a method to print the last K lines of an input file using C++.

```cpp
void printLast10Lines(char * fileName){
    const int k = 10;
    ifstream file(fileName);
    string L[K];
    int size = 0;

    while(file.peek()!= EOF){
        getline(file, L[size % K]);
        size++;
    }
    int start = size> K ? (size%k) : 0;
    int count = min(K, size);

    for(int i = 0;i<count ;i++>){
        cout<<L[(start + i) % K] <<endl;
    }

}
```
#####  **Reverse String**: Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

- Leetcode 344. Reverse String

##### **Hash Table vs. STL Map**: Compare and contrast a hash table and an STL map. How is a hash table implemented? If the number of inputs is small, which data structure options can be used instead of a hash table?


In a hash table, a value is stored by calling a hash function on a key.
the hash table will be implemented with an array of linked lists, where each node in the linked list holds two pieces of data: the value and the original key.

##### Virtual Functions: How do virtual functions work in C++?

virtual function依賴於“vtable”或“Virtual Table”：如果類的任何函數被聲明為虛函數，則構造一個 vtable 來存儲該類的虛函數的地址。編譯器還添加了一個隱藏的 vptr 變量 在所有指向該類的vtable的類中，**如果在子類中沒有覆蓋虛函數，則子類的vtable在其父類中存儲該函數的地址**。vtable用於解析地址 調用虛函數時的函數，**C++中的動態綁定是通過vtable機制進行的**。

C++ non-virtual function調用在編譯時用靜態綁定解析，而virtual function調用在運行時用動態綁定解析。

##### Shallow vs. Deep Copy: What is the difference between deep copy and shallow copy? Explain how you would use each.

淺拷貝將所有成員值從一個對象複製到另一個對象。 深拷貝完成所有這些，並且還深拷貝任何指針對象。

```cpp
struct Test{
    char * ptr;
};

void shallow_copy(Test &src, Test &dest){
    dest.ptr = src.ptr;
}
void deep_copy(Test &src, Test & dest){
    dest.ptr = (char*)malloc(strlen(src.ptr)+1)
    strcpy(dest.ptr, src.ptr);
}

```
##### **Volatile**: What is the significance of the keyword "volatile" in C?

關鍵字 volatile 通知編譯器它所應用的變量的值可以從外部更改，而無需程式碼進行任何更新。 這可以由操作系統、硬體或另一個執行緒完成。 由於該值可能會意外更改，因此編譯器每次都會從記憶體中重新加載該值。

Volatile variables are not optimized, which can be very useful. Imagine this function:

```cpp
int opt = 1;
void Fn(void) {
    start:
        if(opt==1) goto start;
        else break;
}

// At first glance, our code appears to loop infinitely. The compiler may try to optimize it to:
void Fn(void) {
    start:
    int opt = 1;
    if(true) 
    goto start;
}
// This becomes an infinite loop. However, an external operation might write'O'to the location of variable opt, thus breaking the loop.
volatile int opt = 1;
void Fn(void) {
    start:
        if(opt==1) goto start;
        else break;
```
##### **Virtual Base Class**: Why does a destructor in base class need to be declared virtual?

Destructors are used to clean up memory and resources.
```cpp
class Foo{
    public:
        void f();
};
class Bar : public Foo{
    public:
        cvoid f();
}
Foo *p = new Bar();
p->f();
// Calling p->f() will result in a call to Foo: :f().
```

If Foo's destructor were not virtual, then Foo's destructor would be called, even when p is really of type Bar.
This is why we declare destructors to be virtual; we want to ensure that the destructor for the most derived class is called.

- 不要去繼承沒有 virtual destructor 的 class
- 在 class 裡寫到 virtual function 的時候就幫他加個 virtual destructor 以絕後患
##### **Copy Node**: Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure. The Node data structure contains two pointers to other Nodes.

```cpp
typedef map<Node* , Node*> NodeMap;


Node *copy_recursive(Node *cur, NodeMap & nodeMap){
    if(cur == nullptr){
        return nullptr;
    }

    NodeMap::iterator i = nodeMap.find(cur);
    if(i != nodeMap.end()){ // we've been here before, return the copy.
        return i->second;
    }
    Node *node = new Node;
    nodeMap[cur] = node;  //map current before traversing links
    node->ptr1 = copy_recursive(cur->ptr1, nodeMap);
    node->ptr2 = copy_recursive(cur->ptr2, nodeMap);
    return node;
}


Node *copy_recursive(Node *root){
    NodeMap nodeMap; //we will need an empty map
    return copy_recursive(root, nodeMap);
}


```

#####  **Smart Pointer**: Write a smart pointer class. A smart pointer is a data type, usually implemented with templates, that simulates a pointer while also providing automatic garbage collection. It automati­ cally counts the number of references to a SmartPointer<T*> object and frees the object of type T when the reference count hits zero.

it provides safety via automatic memory management. It avoids issues like dangling pointers, memory leaks and allocation failures

```cpp
// pseudocode
template <class T> class SmartPointer{
    T* obj;
    unsigned *ref_count;
}
SmartPointer(T *object){
/* We want to set the value of T* obj, and set the reference counter to 1.*/
}
SmartPointer(SmartPointer<T> & sptr){
/* This constructor creates a new smart pointer that points to an existing
* object. We will need to first set obj and ref_count to pointer to sptr's obj
* and ref_count. Then, because we created a new reference to obj, we need to
* increment ref_count.*/
}
~SmartPointer(SmartPointer <T>  sptr){
/* We are destroying a reference to the object. Decrement ref_count. If
14 * ref count is 0, then free the memory created by the integer and destroy the object */
}

onSetEquals(SmartPoint<T> ptrl, SmartPoint<T> ptr2) {

}
```

```cpp
template<class T> class SmartPointer{
    public:
        SmartPointer(T* ptr){
            ref = ptr;
            ref_count = (unsigned*)malloc(sizeof(unsigned));
            *ref_count = 1;
        }
        SmartPointer(SmartPointer<T> & sptr){
            ref = sptr.ref;
            ref_count = sptr_ref_count();
            ++(*ref_count);
        }
        /* Override the equal operator, so that when you set one smart pointer equal to  another the old smart pointer has its reference count decremented and the new smart pointer has its reference count incrememented. */

        SmartPointer<T> & operator=(SmartPointer<T> & sptr) {
            if(this == &sptr) return *thi;

            /* If already assigned to an object, remove one reference. */
            if (*ref_count > 0) {
                remove();
            }

            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++(*ref_count);
            return *this;
        }
        ~SmartPointer(){ 
            remove(); // Remove one reference to object.
        }

        T getValue(){ 
            return *ref;
        }

    protected:
        void remove(){ 
            --(*ref_count);
            if(*rer_count==0){
                delete ref;
                free(ref_count);
                ref = nullptr;
                ref_count = nullptr;
            }
        }

        T *ref ;
        unsigned *ref_count;
}
```


#####  **Malloc**: Write an aligned malloc and free function that supports allocating memory such that the memory address returned is divisible by a specific power of two.

```
EXAMPLE
align_malloc(1000, 128) will return a memory address that is a multiple of 128 and that points to memory of size 1000 bytes.
aligned_free() will free memory allocated by align_malloc.
```

```cpp
void* aligned_malloc(size_t required_bytes, size_t alignment) {
    int offset = alignment - 1;
    void* p= (void*) malloc(required_bytes + offset);
    void* q = (void*) (((size_t)(p) + offset) & =(alignment - 1));
    return q;
}
void* aligned_malloc(size_t required_bytes, size t alignment) {
    void* pl;// initial block
    void* p2; // aligned block inside initial block
    int offset= alignment - 1 + sizeof(void*);
    if ((pl= (void*)malloc(required_bytes + offset))==nullptr){
        return nullptr;
    }
    p2 = (void*)(((size_t)(pl) + offset) & =(alignment - 1));
    ((void **)p2)[-1] = pl;
    return p2;
}

void aligned_free(void *p2){
    /* for consistency, we use the same names as aligned_malloc*/
    void *p1 = ((void**)p2)[-1];
    free(p1);

}
```

#####  **2D Alloc**: Write a function in C called my2DA1loc which allocates a two-dimensional array.Minimize the number of calls to malloc and make sure that the memory is accessible by the notation arr[i][j].


```cpp
int** my2DA1loc(int rows, int cols) {
    int** rowptr;
    int i ;
    rowptr = (int**) malloc(rows * sizeof(int*));
    for(i=0;i<rows;i++) {
        rowptr[i] = (int*) malloc(cols * sizeof(int));
    }
    return rowptr;
}

void my2DDealloc(int** rowptr, int rows) {
    for (i = 0; i < rows; i++) {
        free(rowptr[i]);
    }
    free(rowptr);

}

int** my2DA1loc(int rows, int cols) {
    int i ;
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int **rowptr = (int**)malloc(header + data);
    if(rowptr==nullptr) return nullptr;

    int *buf = (int*)(rowptr  + rows);
    for(int i=0;i<rows;++i){
        rowptr[i] = buf + i*cols;
    }
    return rowptr;

```

## Object-Oriented Design
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

## Java

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

## Databases
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
 
## Threads and Locks

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




## Testing

1. **Mistake**: Find the mistake(s) in the following code:
2. **Random Crashes**: You are given the source to an application which crashes when it is run. After running it ten times in a debugger, you find it never crashes in the same place. The application is single threaded, and uses only the C standard library. What programming errors could be causing this crash? H ow would you test each one
3. **Chess Test**: We have the following method used in a chess game:boolean can MoveTo(int x, int y).This method is part of the Piece class and returns whether or not the piece can move to position (x, y). Explain how you would test this method.
4. **No Test Tools**: How would you load test a webpage without using any test tools?
5. **Test a Pen**: How would you test a pen?
6. **Test an ATM**: How would you test an ATM in a distributed banking system?

## System Design and Scalability
1. Stock Data: Imagine you are building some sort of service that will be called by up to 1,000 client applications to get simple end-of-day stock price information (open, close, high, low). You may assume that you already have the data, and you can store it in any format you wish. How would you design the client-facing service that provides the information to client applications?You are respon­ sible for the development, rollout, and ongoing monitoring and maintenance of the feed. Describe the different methods you considered and why you would recommend your approach. Your service can use any technologies you wish, and can distribute the information to the client applications in any mechanism you choose.
2. Social Network: How would you design the data structures for a very large social network like Face­ book or LinkedIn? Describe how you would design an algorithm to show the shortest path between two people (e.g., Me -> Bob -> Susan -> Jason -> You).
3. Web Crawler: If you were designing a web crawler, how would you avoid getting into infinite loops?
4. Duplicate URLs: You have 10 billion URLs. How do you detect the duplicate documents? In this case, assume "duplicate" means that the URLs are identical.
5. Cache: Imagine a web server for a simplified search engine. This system has 100 machines to respondtosearchqueries,whichmaythencalloutusingprocessSearch(string query)to another cluster of machines to actually get the result. The machine which responds to a given query is chosen at random, so you cannot guarantee that the same machine will always respond to the same request. The method proc essSearch is very expensive. Design a caching mechanism for the most recent queries. Be sure to explain how you would update the cache when data changes.
6. Sales Rank: A large eCommerce company wishes to list the best-selling products, overall and by category.Forexample,oneproductmightbethe#1056thbest-sellingproductoverallbutthe#13th best-selling product under "Sports Equipment" and the #24th best-selling product under "Safety." Describe how you would design this system.
7. Personal Financial Manager: Explain how you would design a personal financial manager (like Mint.com). This system would connect to your bank accounts, analyze your spending habits, and make recommendations.
8. Pastebin: Design a system like Pastebin, where a user can enter a piece of text and get a randomly generated URL to access it.



## Moderate

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







## Hard


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







