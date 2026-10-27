class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mpp;
        for(char &ch: jewels)   mpp[ch]=1;
        int cnt=0;
        for(char &ch: stones){
            if(mpp.count(ch))   cnt++;
        }
        return cnt;
    }
};