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
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return delFun(root);
        TreeNode* dummy = root;
        while(root){
            if(key<root->val){
                if(root->left && root->left->val == key){
                    root->left=delFun(root->left);
                    break;
                }else{
                    root= root->left;
                }
            }
            else{
                if(root->right && root->right->val == key){
                    root->right=delFun(root->right);
                    break;
                }else{
                    root= root->right;
                }
            }
        }
            return dummy;
    }
    TreeNode* delFun(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* leftChild= root->left;
        TreeNode* lastLeft = findLeft(root->right);
        lastLeft->left=leftChild;
        return root->right;
    }
    TreeNode* findLeft(TreeNode*node){
        while(node->left){
            node=node->left;
        }
        return node;
    }
};