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
    unordered_map<TreeNode*, TreeNode*> par;
    unordered_map<TreeNode*, int> depth;

    void dfs(TreeNode* nn, TreeNode* pp) {
        if(nn==NULL) return;
        par[nn] = pp;
        depth[nn] = depth[pp] + 1;
        dfs(nn->left, nn);
        dfs(nn->right, nn);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        depth[root] = 0;
        dfs(root, root);
        // cout<<depth[p]<<" "<<depth[q]<<endl;
        if(depth[p]>depth[q]) swap(p,q);
        while(depth[q]>depth[p]) q = par[q];
        // cout<<depth[p]<<" "<<depth[q]<<endl;
        while(p!=q){
            p = par[p];
            q = par[q];
        }
        return p;
    }
};
