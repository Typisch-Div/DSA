class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int l=0;
        int cnt=0;
        for(int r=0;r<k;r++){
            if(blocks[r]=='W')  cnt++;
        }
        int ans=cnt;
        int r=k;
        while(r<n){
            if(r-l+1>k){
                if(blocks[r]=='W')  cnt++;
                if(blocks[l]=='W')  cnt--;
                l++;
                ans=min(ans,cnt);
                r++;
            }
        }
        return ans;
    }
};