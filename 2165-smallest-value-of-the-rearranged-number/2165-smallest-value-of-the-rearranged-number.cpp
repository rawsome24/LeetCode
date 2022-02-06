class Solution {
public:
    long long smallestNumber(long long num) {
        if(num<=10 && num>=-10)
            return num;
        if(num<=100 && num>=-100 && num%10==0)
            return num;
        if(num>0)
        {    
            string pos = to_string(num);
            sort(pos.begin(),pos.end());
            if(pos[0]=='0'){
            for(int i=0; i<pos.length(); i++)
                if(pos[i]!='0'){swap(pos[0],pos[i]); break;}
            }
            stringstream ans(pos);
            long long x=0;
            ans>>x;
            return x;
        }
        else
        {
            string neg = to_string(num);
            sort(neg.begin(),neg.end(),greater<int>());
            stringstream ans(neg);
            long long x=0;
            ans>>x;
            return -x;
        }
        return 0;
    }
};