class LRUCache {
public:
    struct ListNode {
        ListNode* next;
        ListNode* prev;
        int key;
        int value;
        ListNode(int ky, int vl){
            this->key = ky;
            this->value = vl;
        }
    };

    unordered_map<int,ListNode*>mp;
    int maxSize;
    ListNode* head = new ListNode(-1,-1);
    ListNode* tail = new ListNode(-1,-1);
    
    LRUCache(int capacity) {
        maxSize = capacity;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }

    void addAtFront(ListNode* nd){
        ListNode* temNext = head->next;
        nd->prev = head;
        head->next = nd;
        nd->next = temNext;
        temNext->prev = nd;
    }

    ListNode* removeTail(){
        ListNode* prev = tail->prev;
        ListNode* newPrev = prev->prev;
        newPrev->next = tail;
        tail->prev = newPrev;
        return prev;
    }

    ListNode* removeNode(ListNode* node){
        ListNode* prevNode = node->prev;
        ListNode* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        return node;
    }
    
    int get(int key) {
        if (!mp.contains(key)) return -1;
        ListNode* nd = mp[key];
        removeNode(nd);
        addAtFront(nd);
        return nd->value;
    }
    
    void put(int key, int value) {
        bool keyExists = mp.contains(key);
        if(keyExists){
            ListNode* node = mp[key];
            node->value = value;
            ListNode* removedNd = removeNode(node);
            addAtFront(removedNd);
        }else{
            ListNode* newNd = new ListNode(key,value);
            addAtFront(newNd);
            mp[key] = newNd;
            if(mp.size()>maxSize){
                ListNode* rn = removeTail();
                mp.erase(rn->key);
            }
        }
    }
};
