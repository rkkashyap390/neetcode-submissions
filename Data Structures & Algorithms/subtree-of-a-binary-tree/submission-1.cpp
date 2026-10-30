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
    bool dfs(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL) || (p->val!=q->val)) return false;
        return (dfs(p->left, q->left) & dfs(p->right, q->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int sv = subRoot->val;
        queue<TreeNode*> que;
        que.push(root);
        bool ans = false;
        while(!que.empty()){
            TreeNode* cur = que.front();
            que.pop();
            if(cur->val == sv){
                ans = ans | dfs(cur, subRoot);
            }
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        return ans;
    }
};
