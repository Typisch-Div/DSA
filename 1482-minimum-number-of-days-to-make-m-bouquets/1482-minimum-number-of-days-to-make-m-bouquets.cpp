class Solution {
public:
    bool chk(vector<int>& bloomDay, int m, int k,int day){
        int fl=0, boq=0;
        for(int bloom:bloomDay){
            if(bloom<=day){
                fl++;
                if(fl==k){
                    boq++;
                    fl=0;
                }   
            }
            else    fl=0;
        }
        return boq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL*m*k)>bloomDay.size())   return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end()) ;
        while(l<r){
            int day=l+(r-l)/2;
            if(chk(bloomDay,m,k,day))   r=day;
            else l=day+1;
        }
        return l;
    }
};