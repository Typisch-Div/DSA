class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0;
        int lastM = 0, lastP = 0, lastG = 0;

        for (int i = 0; i < garbage.size(); i++) {
            ans += garbage[i].size();

            for (char c : garbage[i]) {
                if (c == 'M') lastM = i;
                if (c == 'P') lastP = i;
                if (c == 'G') lastG = i;
            }
        }

        for (int i = 0; i < travel.size(); i++) {
            if (i < lastM) ans += travel[i];
            if (i < lastP) ans += travel[i];
            if (i < lastG) ans += travel[i];
        }

        return ans;
    }
};