class MyHashSet {
public:
 bool mySet[1000001]={};
    MyHashSet() {
        
    }
    
    void add(int key) {
        mySet[key]=1;
    }
    
    void remove(int key) {
        mySet[key]=0;
    }
    
    bool contains(int key) {
        return mySet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */