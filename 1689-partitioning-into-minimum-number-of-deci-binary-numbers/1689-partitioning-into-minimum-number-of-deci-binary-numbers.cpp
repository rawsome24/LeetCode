class Solution {
public:
    int minPartitions(string n) {
        int mx = INT_MIN;
        for(int i=0; i<n.length(); i++)
            mx = max(mx,n[i]-'0');
        return mx;
    }
};