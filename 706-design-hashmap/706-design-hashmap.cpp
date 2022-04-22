class MyHashMap {
public:
    vector<pair<int,int>>p;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i=0; i<p.size(); i++)
            if(p[i].first==key){p[i].first=key; p[i].second=value;return;}
        p.push_back({key,value});
    }
    
    int get(int key) {
        for(int i=0; i<p.size(); i++){
            if(p[i].first==key)return p[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        int j=-1;
        for(int i=0; i<p.size(); i++){
            if(key==p[i].first)j=i;
        }
        if(j==-1)return;
        for(int i=j; i<p.size()-1; i++){
            p[i] = p[i+1];
        }
        p.pop_back();
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */