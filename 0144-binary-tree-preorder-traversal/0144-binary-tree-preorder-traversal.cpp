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
    void preorderTraversal(TreeNode* root, vector<int>&ans){
        if (root == nullptr)
            return;
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right != nullptr && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right != cur) {
                    pred->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pred->right = nullptr;
                    cur = cur->right;
                }
            }
        }
    }
    vector<int> preorderTraversal(TreeNode* root ) {
        vector<int>ans;
        preorderTraversal(root,ans);
        return ans;
    }
};