class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        string ans="";
        for(char ch:s)  mpp[ch]++;
        while(!mpp.empty()){
            char maxchar=0;
            int maxfreq=0;
            for(auto it:mpp){
                if(it.second>maxfreq){
                    maxfreq=it.second;
                    maxchar=it.first;
                }
            }
            for(int i=0;i<maxfreq;i++){
                ans.push_back(maxchar);
            }
            mpp.erase(maxchar);
        }
        return ans;
    }
};