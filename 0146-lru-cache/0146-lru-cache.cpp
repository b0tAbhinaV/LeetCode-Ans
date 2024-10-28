class LRUCache {
public:
    class node{
        public: 
        int key;
        int value;
        node* prev;
        node* next;
        node(int key, int value){
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int capacity;
    unordered_map<int, node*> mpp;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delnode){
        node* delprev = delnode -> prev;
        node* delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            node* resnode = mpp[key];
            int res = resnode->value;
            mpp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node* currnode = mpp[key];
            currnode->value = value;
            deleteNode(currnode);
            addNode(currnode);
            //mpp[key] = head->next;
        }
        else{
            node* newNode = new node(key, value);
            if(mpp.size() == capacity){
                node* todel = tail->prev;
                mpp.erase(todel->key);
                deleteNode(todel);
                addNode(newNode);
                mpp[key] = head->next;
                delete todel;
            }
            else{
                addNode(newNode);
                mpp[key] = head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */