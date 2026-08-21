class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo=0,hi=50000000000LL;
        int sz=coins.size();
        while(lo+1<hi){
            long long mid=lo+(hi-lo)/2LL;
            long long d=0;
            for(int i=1;i<(1 << (sz));i++){
                long long c=0;
                int p=0;
                for(int j=0;j<sz;j++){
                    if((1 << j)&i){
                        long long x=coins[j];
                        if(c)c=(c*x)/__gcd(c,x);
                        else c=coins[j];
                        p++;
                    }
                }
                if(p%2)d+=(mid/c);
                else d-=(mid/c);
            }
            if(d<k)lo=mid;
            else hi=mid;
        }
        return hi;
    }
};