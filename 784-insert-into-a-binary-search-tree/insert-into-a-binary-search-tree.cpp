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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* temp= new TreeNode(val);
            return temp;
        }
        if(val > root->val){
            TreeNode*right = insertIntoBST(root->right, val);
            root->right=right;
        }else{
            TreeNode*left = insertIntoBST(root->left, val);
            root->left=left;
        }
        return root;
    }
};