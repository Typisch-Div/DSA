class Solution {
public:
    int lb(vector<int>& nums,int l,int r, int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)    l=mid+1;
            else    r=mid-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)    return {-1,-1};
        int l=0,r=n-1;
        int strt=lb(nums,l,r,target);
        int end=lb(nums,l,r,target+1)-1;
        if(strt<n && nums[strt]==target)    return{strt,end};
        return {-1,-1};
    }
};