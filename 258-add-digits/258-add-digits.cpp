class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while(str.length()>1)
        {
            int sum = 0;
            for(auto  &it:str)
                sum +=it-'0';
            str = to_string(sum);
        }
        return stoi(str);
    }
};