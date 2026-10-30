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
    int K, ans;
    void dfs(TreeNode* nn){
        if(!nn) return;
        dfs(nn->left);
        K--;
        if(K==0) {
            ans = nn->val;
            return;
        }
        dfs(nn->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        K = k;
        dfs(root);
        return ans;
    }
};
