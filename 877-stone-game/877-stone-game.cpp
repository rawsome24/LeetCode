class Solution {
public:
    bool stoneGame(vector<int>& v) {
        int suma = 0, sumb = 0, i = 0;
        while(v.empty()==false){
            if(i%2==0){
                if(v[0]>v[v.size()-1])
                {
                    suma+=v[0]; 
                    v.erase(v.begin()+0);
                }
                else if(v[0]<v[v.size()-1]){
                    suma+=v[v.size()-1];
                    v.pop_back();
                }
                else if(v[0]==v[v.size()-1])
                    return true;
            }
            else{
                if(v[0]>v[v.size()-1])
                {
                    sumb+=v[0]; 
                    v.erase(v.begin()+0);
                }
                else if(v[0]<v[v.size()-1]){
                    sumb+=v[v.size()-1];
                    v.pop_back();
                }
            }
            i++;
        }
        return suma>sumb;
    }
};