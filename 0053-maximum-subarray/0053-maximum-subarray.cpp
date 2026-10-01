class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        if(n==1)    return nums[0];
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>ans) ans=sum;
            if(sum<0)   sum=0;
            
        }
        return ans;
    }
};