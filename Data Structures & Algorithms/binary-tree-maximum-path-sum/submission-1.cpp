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
    int res = INT_MIN;

    int dfs(TreeNode* nn) {
        if(!nn) return 0;
        int mx=0, lv=0, rv=0;
        if(nn->left) lv = max(lv, dfs(nn->left));
        if(nn->right) rv = max(rv, dfs(nn->right));
        res = max(res, lv+rv+nn->val);
        mx = max(lv, rv);
        return max(0, mx+nn->val);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
