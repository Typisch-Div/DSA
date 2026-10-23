class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int num:nums){
            if(num<0)   neg.push_back(num);
            else    pos.push_back(num);
        }
        int j=0,k=0;
        for(int i=0;i<n;i++){
            nums[i]=i%2 ? neg[j++] : pos[k++];
        }
        return nums;

    }
};