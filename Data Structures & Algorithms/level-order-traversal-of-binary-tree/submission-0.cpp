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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans.push_back({root->val});
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){curr.push_back(node->left->val); q.push(node->left);}
                if(node->right){curr.push_back(node->right->val); q.push(node->right);}
            }
            if(curr.size()>0)ans.push_back(curr);
        }
        return ans;
    }
};
