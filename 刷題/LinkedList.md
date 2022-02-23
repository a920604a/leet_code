---
title: Linked List
tags:  
    - Linked List
categories: 
    - CS
    - Data Structure
    
comments: false
---

## 題目

- 19 Remove Nth Node From End of List (Medium)
- 21 Merge Two Sorted Lists
- 23 Merge k Sorted Lists
- 141 Linked List Cycle (Easy)
- 142 Linked List Cycle II (Medium)
- 160 Intersection of Two Linked Lists
- 876 Middle of the Linked List (Easy)
- 2 Add Two Numbers (Medium)
- 25 Reverse Nodes in k-Group (Hard)
- 83 Remove Duplicates from Sorted List (Easy)
- 206 Reverse Linked List(Easy)
- 92 Reverse Linked List II (Medium)
- 234 Palindrome Linked List (Easy)
- 203 Remove Linked List Elements




補充
- 2095 Delete the Middle Node of a Linked List (Medium)
- 2130 Maximum Twin Sum of a Linked List (Medium)

## implement
```c++
#include<iostream>
using namespace std;

class ListNode{
    private:
        int val;
        ListNode *next;
        
    public:
        ListNode():val(0), next(nullptr){};
        ListNode(int x):val(x), next(nullptr){};
        friend class LinkedList;
};

class LinkedList{

    private:
        ListNode *first;

    public:
        LinkedList():first(){};
        void Print();
        void Push_back(int x);
        void Push_front(int x);
        void Pop_back();
        void Pop_front();
        void Delete(int x);
        void Clear();
        void Reverse();
};

void LinkedList::Print(){
    if(first==nullptr){
        std::cout<<"the list is empty"<<std::endl;
        return;
    }
    ListNode* cur = first;

    while(cur){
        std::cout<<cur->val<<" ";
        cur = cur->next;    
    }
    std::cout <<std::endl;
}

void LinkedList::Push_back(int x){
    ListNode* newnode = new ListNode(x);
    if(first==nullptr){
        first = newnode;
        return ;
    }
    ListNode* cur = first;

    while(cur->next){
        cur = cur->next;
    }
    cur->next = newnode;
}

void LinkedList::Push_front(int x){
    ListNode* newnode = new ListNode(x);
    if(first==nullptr){
        first = newnode;
        return ;
    }

    newnode->next = first;
    first = newnode;
}

void LinkedList::Pop_back(){
    if(first==nullptr){
        std::cout <<"the list is empty"<<std::endl;
        return ;
    }
    ListNode* cur = first;
    if(cur->next==nullptr){
        ListNode * delnode = cur;
        cur = cur->next;
        delete delnode;
        first = nullptr;
        return;    
    }
    ListNode* post = cur->next;
    while(post->next){
        post = post->next;
        cur = cur->next;
    }
    cur->next = nullptr;
    delete post;
}

void LinkedList::Pop_front(){
    if(first==nullptr){
        std::cout <<"the list is empty"<<std::endl;
        return ;
    }
    ListNode* cur = first;
    // if(cur->next==nullptr){
    //     ListNode * delnode = cur;
    //     cur = cur->next;
    //     delete delnode;
    //     first = cur;
    //     return;        
    // }
    ListNode * delnode = cur;
    cur = cur->next;
    delete delnode;
    first = cur;
}

void LinkedList::Delete(int x){
    if(first==nullptr){
        std::cout <<"the list is empty"<<std::endl;
        return ;
    }
    ListNode * cur = first;
    if(cur->val==x){
        ListNode * delnode = cur;
        cur = cur->next;
        delete delnode;
        first = cur;
        return;
    }
    ListNode * post = cur->next;
    while(post){
        if(post->val==x){
            break;
        }
        cur = cur->next;
        post = post->next;
    }
    if(post==nullptr) return;
    ListNode * delnode = post;
    cur->next=post->next;
    delete delnode;
    

}

void LinkedList::Clear(){
    if(first==nullptr){
        std::cout <<"the list is empty"<<std::endl;
        return;
    }
    if(first->next==nullptr){
        ListNode * delnode = first;
        first = first->next;
        delete delnode;
    }
    // ListNode * cur = first; // bad idea
    while(first){
        ListNode * delnode = first;
        first = first->next;
        delete delnode;
    }
}
void LinkedList::Reverse(){

    if(first==nullptr || first->next==nullptr) return;

    ListNode *pre = nullptr;
    ListNode *cur = first;
    ListNode *post = cur->next;

    while(post){
        cur->next = pre;
        pre = cur;
        cur = post;
        post = post->next;
    }
    cur->next = pre;
    first = cur;
}
int main(){

    LinkedList l;
    l.Print();

    
    l.Push_back(5);
    l.Push_back(8);
    l.Print();
    l.Push_front(3);
    l.Push_front(1);
    l.Print();
    // l.Pop_front();
    // l.Pop_front();
    // l.Pop_back();
    // l.Pop_back();
    l.Print();
    l.Reverse();
    l.Print();
    l.Delete(3);
    l.Print();
    l.Clear();
    l.Print();


    return 0;

}
```