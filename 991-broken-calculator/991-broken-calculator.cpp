class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = target, cnt=0;
        if(startValue>=target)return startValue-target;
        while(1)
        {
            if(ans==startValue)break;
            else if(ans+1==startValue){cnt++; break;}
            else if(ans%2==0 && ans>startValue)ans=ans/2;
            else ans=ans+1;
            cnt++;
        }
        return cnt;
    }
};