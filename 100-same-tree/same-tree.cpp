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
    bool check( TreeNode* l,  TreeNode* r){
        if(l == NULL && r ==NULL) return true;
        if(l == NULL || r==NULL) return false;
        if(l->val !=r->val) return false;
        bool first = check(l->left, r->left);
        bool second = check(l->right, r->right);
        return first && second;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* left=p;
        TreeNode* right=q;
        return check(left, right);
    }
};