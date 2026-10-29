class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int x : asteroids) {
            if (x > 0)
                ans.push_back(x);
            else {
                while ( !ans.empty() && ans.back() < abs(x)  && ans.back() > 0)
                    ans.pop_back();
                if ( !ans.empty() && ans.back() == abs(x) )
                    ans.pop_back();
                else if (ans.empty() || ans.back() < 0)
                    ans.push_back(x);
            }
        }
        return ans;
    }
};