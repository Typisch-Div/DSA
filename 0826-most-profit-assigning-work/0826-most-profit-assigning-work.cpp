class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        long long sum=0;
        for(int i=0;i<worker.size();i++){
            int maxpro=0;
            int j=0;
            
            while(j<difficulty.size()){
                if(worker[i]>=difficulty[j]){
                    maxpro=max(maxpro,profit[j]);
                }
                j++;
            }
            sum+=maxpro;
        }
        return sum;
    }
};