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
    pair<int, int> dfs(TreeNode* root){
        if(!root) return{0,0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int h1 = left.first;
        int d1 = left.second;
        int h2 = right.first;
        int d2 = right.second;
        int height = 1+max(h1, h2);
        int diameter = max(d1,max(d2, h1+h2));
        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
      pair<int, int>ans =  dfs(root);
       return ans.second;
    }
};