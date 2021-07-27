class LRUCache
{
private:
    list<pair<int, int> > l;
    unordered_map<int, list<pair<int, int> >::iterator> m;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        // cout<<"get"<<endl;
        auto it = m.find(key);
        if (it == m.end())
            return -1;
        // pop this node in the list add list's head
        // for(auto it: l) cout<<it.first<<" "<<it.second<<endl;
        l.splice(l.begin(), l, it->second);
        // cout<<"----splice--"<<endl;
        // for(auto it: l) cout<<it.first<<" "<<it.second<<endl;
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it != m.end())
            l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap)
        {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class Node
{
public:
    int key, val;
    Node *next, *prev;
    Node(int k, int v) : key(k), val(v) {}
};
class DoubleList
{
private:
    Node *head, *tail;
    int size;

public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node *x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    // 由於是雙向鏈接串列且給定目標Node節點，O(1)
    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    Node *removeFirst()
    {
        if (head->next == tail)
            return nullptr;
        Node *first = head->next;
        remove(first);
        return first;
    }
    int Getsize()
    {
        return size;
    }
};
class LRUCache
{
private:
    unordered_map<int, Node *> mp;
    DoubleList cache;
    int cap;
    // 將key 提升為最常使用
    void makeRecently(int key)
    {
        Node *x = mp[key];
        // 從鏈接串列刪除該節點
        cache.remove(x);
        // 重新插到串列尾部
        cache.addLast(x);
    }
    void addRecently(int key, int val)
    {
        Node *x = new Node(key, val);
        // 鏈接串列尾部就是最近使用的元素
        cache.addLast(x);
        mp[key] = x;
    }
    void deleteKey(int key)
    {
        Node *x = mp[key];
        cache.remove(x);
        mp.erase(key);
    }
    void removeLeastRecently()
    {
        Node *deleteNode = cache.removeFirst();
        int deleteKey = deleteNode->key;
        mp.erase(deleteKey);
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        // 每次拜訪需要將這元素變為最近使用，也就是說cache要支持任意位置元素插入與刪除
        // hash 搜詢快，但是其資料無順序
        // double linked list 插入刪除快，但搜尋慢。
        if (!mp.count(key))
            return -1;
        makeRecently(key);
        return mp[key]->val;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            // 刪除舊資料
            deleteKey(key);
            // 新插入資料為最近使用的資料
            addRecently(key, value);
            return;
        }

        if (cap == cache.Getsize())
        {
            removeLeastRecently();
        }
        // 添加最近使用的元素
        addRecently(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */