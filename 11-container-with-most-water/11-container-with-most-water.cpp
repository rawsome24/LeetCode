class Solution {
public:
    int maxArea(vector<int>& h) {
        int i=0, j=h.size()-1;
        int mx = 0;
        while(i<j){
            mx = max(mx, min(h[i], h[j])*(j-i));
            if(h[i]>h[j])
                j--;
            else if(h[j]>h[i])
                i++;
            else
                i++, j--;
        }
        return mx;
    }
};