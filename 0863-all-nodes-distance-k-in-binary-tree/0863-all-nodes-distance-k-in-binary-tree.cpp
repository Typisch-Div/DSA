class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop();

            if (top->left) {
                parent[top->left->val] = top;
                q.push(top->left);
            }

            if (top->right) {
                parent[top->right->val] = top;
                q.push(top->right);
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        visited[target->val] = 1;

        while (k-- && !q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();

                if (top->left && !visited[top->left->val]) {
                    visited[top->left->val] = 1;
                    q.push(top->left);
                }

                if (top->right && !visited[top->right->val]) {
                    visited[top->right->val] = 1;
                    q.push(top->right);
                }

                if (parent.count(top->val) &&
                    !visited[parent[top->val]->val]) {
                    visited[parent[top->val]->val] = 1;
                    q.push(parent[top->val]);
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};