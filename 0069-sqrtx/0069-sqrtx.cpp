class Solution {
public:
    int mySqrt(int x) {
        int l=1,r=x;
        if(x==0 || x==1)    return x;
        while(l<=r){
            int m=l+(r-l)/2;
            long long square = static_cast<long long>(m) * m;
            if(square <=x)  l=m+1;
            else    r=m-1;
        }
        return r;
    }
};