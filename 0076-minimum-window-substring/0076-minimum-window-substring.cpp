class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        for(int i=0;i<t.size();i++) hash[t[i]]++;
        int l=0,r=0;
        int minsize=INT_MAX;
        int sidx=-1,cnt=0; 
        for(int r=0;r<s.size();r++){
            if(hash[s[r]]>0)    cnt++;
            hash[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minsize){
                    minsize=r-l+1;
                    sidx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)    cnt--;
                l++;
            }
        }
        return sidx == -1 ? "" :s.substr(sidx,minsize);
    }
};