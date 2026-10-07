class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hashs[256]={0};
        int hasht[256]={0};
        if(s.size()!=t.size())  return false;
        for(int i=0;i<s.size();i++){
            if(hashs[s[i]]!= hasht[t[i]])   return false;
            hashs[s[i]]=i+1;
            hasht[t[i]]=i+1;
        }
        return true;
    }
};