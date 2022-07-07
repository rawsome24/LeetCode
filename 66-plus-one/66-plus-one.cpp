class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = (digits[0]+1)/10;
        digits[0] = (digits[0]+1)%10;
        for(int i=1; i<digits.size(); i++){
            if(carry){
                carry = (digits[i]+1)/10;
                digits[i] = (digits[i]+1)%10;
            }
        }
        if(carry)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};