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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        deque<TreeNode*> par, child;
        par.push_back(root);
        while(!par.empty()){
            int n = par.size();
            for(int i=0; i<n; i++){
                TreeNode* cpar = par.front();
                par.pop_front();
                swap(cpar->left, cpar->right);
                if(cpar->left) par.push_back(cpar->left);
                if(cpar->right) par.push_back(cpar->right);
            }
        }
        return root;
    }
};
