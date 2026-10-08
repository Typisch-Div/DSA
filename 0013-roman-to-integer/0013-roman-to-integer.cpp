class Solution {
public:
    int val(char ch){
        if(ch=='I') return 1;
        if(ch=='V') return 5;
        if(ch=='X') return 10;
        if(ch=='L') return 50;
        if(ch=='C') return 100;
        if(ch=='D') return 500;
        if(ch=='M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int previous = val(s[0]);
        int ans = previous;

        for(int i = 1; i < s.size(); i++) {
            int current = val(s[i]);

            if(current > previous)
                ans += current - 2 * previous;
            else
                ans += current;

            previous = current;
        }

        return ans;
    }
};