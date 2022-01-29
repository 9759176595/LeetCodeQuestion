class MyHashMap {
    vector<int> _v;
public:
    MyHashMap(): _v(1000001,-1) {
        
    }
    
    void put(int key, int value) {
        _v[key]=value;
    }
    
    int get(int key) {
        return _v[key];
    }
    
    void remove(int key) {
        _v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
