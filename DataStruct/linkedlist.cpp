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


class Node{
public:
    int val ;
    Node *prev, * next;
    Node(int x){
        val =x;
        prev= nullptr;
        next = nullptr;
    }
};
class DoubleLinkedList{
private:
    int size;
    Node *head, *tail;
public:
    
    DoubleLinkedList(){
        size = 0;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    // push back
    void push_back(int x){
        Node *node = new Node(x);
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    void push_front(int x){
        Node *node = new Node(x);
        node->next= head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    // pop back
    void pop_back(){
        Node *node = tail->prev;
        // int ret = node->val;
        if(node == head) return ;
        tail->prev = node->prev;
        tail->prev->next = tail;
        size--;
        // return node->val;
    }
    void pop_front(){
        Node *node = head->next;
        if(node == tail) return ;
        head->next = node->next;
        node->next->prev = head;
        size--;
        // return node->val;
    }
    int getSize() {return size;}
    void print(){
        Node *p = head->next;
        for(int i=0;i< size;++i){
            cout<<p->val<<" ";
            p=p->next;
        }
        cout<<endl;
    }
};

int main(){

    // LinkedList l;
    // l.Print();
    // l.Push_back(5);
    // l.Push_back(8);
    // l.Print();
    // l.Push_front(3);
    // l.Push_front(1);
    // l.Print();
    // // l.Pop_front();
    // // l.Pop_front();
    // // l.Pop_back();
    // // l.Pop_back();
    // l.Print();
    // l.Reverse();
    // l.Print();
    // l.Delete(3);
    // l.Print();
    // l.Clear();
    // l.Print();


    // DoubleLinkedList
    DoubleLinkedList* dl = new DoubleLinkedList();

    dl->push_back(1);
    dl->push_back(3);
    dl->push_back(5);
    dl->push_front(-1);
    dl->push_front(-3);
    dl->print();
    dl->pop_front();
    dl->pop_back();
    dl->print();

    return 0;

}