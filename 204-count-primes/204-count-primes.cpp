class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        if(n==0 || n==1 || n==2)return 0;
        vector<bool> isPrime(n+1, true);
        for(long long i=2; i<n; i++){
            if(isPrime[i]){
                cnt++;
                for(long long j=i*i; j<n; j=i+j)
                    isPrime[j]=false;
            }
        }
        return cnt;
    }
};