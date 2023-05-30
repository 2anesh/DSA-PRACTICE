class MyHashSet {
public:
    vector<int>mp;
    int siz;
    MyHashSet() {
        siz=1e6+1;
        mp.resize(siz);
    }
    
    void add(int key) {
        mp[key]=1;
    }
    
    void remove(int key) {
        mp[key]=0;
    }
    
    bool contains(int key) {
        return mp[key];
    }
};
