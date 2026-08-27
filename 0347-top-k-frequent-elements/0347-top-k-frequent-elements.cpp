class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
       } 

        vector<vector<int>>bucket(nums.size()+1);
        for(auto& pair: mpp){
            int num =pair.first;
            int freq =pair.second;

            bucket[freq].push_back(num);
        }
        vector<int>ans;

        for(int freq = nums.size();freq>=1;freq--){
            for(int num:bucket[freq]){
                ans.push_back(num);
            }
            if(ans.size()==k){
                return ans;
            }
        }
        return ans;
    }
};