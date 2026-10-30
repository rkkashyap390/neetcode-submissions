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
    bool valid(TreeNode* node, int mn, int mx) {
        if(!node) return true;
        int nv = node->val;
        if(nv>=mx || nv<=mn) return false;

        bool curr = true;
        if(node->left) curr &= valid(node->left, mn, nv);
        if(node->right) curr &= valid(node->right, nv, mx);
        
        // int cmn = mn, cmx = mx;
        // if(node->left) curr &= (node->val>node->left->val & valid(node->left));
        // if(node->right) curr &= (node->val<node->right->val & valid(node->right));
        // cout<<node->val<<" "<<curr<<endl;
        return curr;
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return valid(root, INT_MIN, INT_MAX);
        // bool ans = true;
        // if(root->left) ans &= valid(root->left, root->val, root->val);
        // if(root->right) ans &= valid(root->right, root->val, root->val);
        // return ans;
    }
};
