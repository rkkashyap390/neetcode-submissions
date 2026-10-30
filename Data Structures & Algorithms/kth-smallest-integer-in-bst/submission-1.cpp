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
    vector<int> val;
    void dfs(TreeNode* nn){
        if(!nn) return;
        dfs(nn->left);
        val.push_back(nn->val);
        dfs(nn->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return val[k-1];
    }
};
