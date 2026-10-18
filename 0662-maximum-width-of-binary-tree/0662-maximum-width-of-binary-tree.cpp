/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        int ans=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(q.size()>0){
            int curlevel=q.size();
            unsigned long long endidx=q.back().second;
            unsigned long long startidx=q.front().second;
            ans=max(ans,(int)(endidx-startidx+1));
            for(int i=0;i<curlevel;i++){
                auto cur=q.front();
                q.pop();
                if(cur.first->left)    q.push({cur.first->left,cur.second*2+1});
                if(cur.first->right)    q.push({cur.first->right,cur.second*2+2});
            }
        }
        return ans;
    }
};