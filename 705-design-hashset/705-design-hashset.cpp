class MyHashSet {
public:
    vector<int>v;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bool flag = false;
        for(auto it:v){
            if(it==key){flag=true;break;}
        }
        if(flag==false)v.push_back(key);
    }
    
    void remove(int key) {
       v.erase(std::remove(v.begin(), v.end(), key),v.end());
    }
    
    bool contains(int key) {
        for(auto it:v)
            if(it==key)return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */