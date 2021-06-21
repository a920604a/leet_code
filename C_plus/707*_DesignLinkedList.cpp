class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    struct Node
    {
        int val;
        Node *next;

        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
    };

    Node *first;
    MyLinkedList() : first() {}

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        Node *cur = first;

        while (index)
        {
            if (!cur->next)
                return -1;
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *node = new Node(val);
        node->next = first;
        first = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *node = new Node(val);
        if (first == nullptr)
        {
            first = node;
            return;
        }
        Node *cur = first;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        Node *node = new Node(val);
        if (index == 0)
        {
            node->next = first;
            first = node;
        }
        else
        {

            Node *cur = first;
            index--;
            while (index)
            {
                if (!cur->next)
                    return;
                cur = cur->next;
                index--;
            }

            node->next = cur->next;
            cur->next = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index == 0)
        {
            Node *delnode = first;
            first = first->next;
            delete delnode;
        }
        else
        {
            Node *cur = first;
            index--;
            while (index)
            {
                cur = cur->next;
                index--;
            }
            if (index > 0)
                return;
            if (!cur->next || !cur->next->next)
            {
                cur->next = nullptr;
                return;
            }
            Node *delnode = cur->next;
            cur->next = cur->next->next;
            delete delnode;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */