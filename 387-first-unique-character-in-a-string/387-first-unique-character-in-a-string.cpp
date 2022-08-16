class Solution {
public:
    int firstUniqChar(string s) {
        map<char,pair<int,int>>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]].first=mp[s[i]].first+1;
            mp[s[i]].second = i; 
            // cout<<mp[s[i]].first<<" "<<mp[s[i]].second<<endl;
        }
        int ans = INT_MAX;
        // for(auto it=mp.begin(); it!=mp.end(); it++){
        //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
        // }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            // cout<<it->first<<" "<<it->second.first<<" "<<it->second.second;
            if(it->second.first==1){
                ans = min(ans, it->second.second);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};