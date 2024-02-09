class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node *prev;
        node *next;
        //constuctor
        node (int key_,int val_){
            key = key_;
            val = val_;
        }
    };
    node *head  = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int, node*> mpp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev= head;
    }
    void addnode(node *newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head; 
        temp->prev = newnode;
        head->next = newnode;
    }
    
    void deletenode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    int get(int key_) {
        if(mpp.find(key_)!=mpp.end()){
            node *resnode = mpp[key_];
            int ans = resnode->val; 
            mpp.erase(key_); 
            deletenode(resnode);         
            addnode(resnode);
            mpp[key_] = head->next;
            return ans;
        }
        return -1;
    }


    void put(int key_, int val_) {
        if(mpp.find(key_)!=mpp.end()){
            node *resnode = mpp[key_];
            mpp.erase(key_);
            deletenode(resnode);
        }

        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key_,val_));
        mpp[key_] = head->next;
    }   
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */