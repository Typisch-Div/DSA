class Solution {
public:
    int cntvalid(vector<int>& nums, int limit){
        int total=0;
        int valid=0;
        for(int x:nums){
            if (x <= limit) {
                valid++;
            } else {
                valid = 0;
            }
            total += valid;
        }
        return total;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return cntvalid(nums,right)-cntvalid(nums,left-1);
    }
};