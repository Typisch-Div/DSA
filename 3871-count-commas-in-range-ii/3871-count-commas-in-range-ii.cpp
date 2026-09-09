class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)   return 0;
        long long ans=0;
        long long start= 1000;
        int comma=1;
        while(start<=n){
            long long end=start*1000;
            long long count=min(end-1,n)-start+1;
            ans+=count*comma;
            start=end;
            comma++;
        }
        return ans;
    }
};