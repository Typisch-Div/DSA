class Solution {
public:
    bool chk(vector<int>& piles, int h,int m){
        long long sum=0;
        for(int pile : piles){
            sum+=(pile+m-1)/m;
            if(sum>h)   return false;
        }
        return sum<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        if(n==h)    return r;
        while(l<r){
            int m=l+(r-l)/2;
            if(chk(piles,h,m))  r=m;
            else    l=m+1;
        }
        return l;
    }
};