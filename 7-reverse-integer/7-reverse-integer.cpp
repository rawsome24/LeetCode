class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        if(stoll(str)>-pow(2,31) && stoll(str)<pow(2,31)-1)
        {
            if(x<0)return -stoll(str);
            else return stoll(str);
        }
            
        else 
            return 0;
    }
};