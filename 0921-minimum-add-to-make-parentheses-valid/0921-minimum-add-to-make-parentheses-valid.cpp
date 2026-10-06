class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0,neg=0;
        for(char ch: s){
            if(ch=='(') bal++;
            else{
                bal--;
                if(bal<0){
                    neg++;
                    bal=0;
                }
            }
        }
        return bal+neg;
    }
};