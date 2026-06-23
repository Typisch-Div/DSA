class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>occurence(26,0);
        int n=s.size();
        int ans=0;
        int r=0,l=0;
        while(r<n){
            occurence[s[r]-'a']++;
            while(occurence[s[r]-'a']>2){
                occurence[s[l]-'a']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;  
        }
        return ans;
    }
};