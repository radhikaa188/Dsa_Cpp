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
    int ans= INT_MIN;
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        //terminating condition
        if(!root || ans!=INT_MIN) return ans;
        int left= kthSmallest(root->left,k);
        //double check
        if(ans!=INT_MIN) return ans;
        count++;
        if(k==count) {
            ans=root->val;
            return ans;
        }
        int right=kthSmallest(root->right,k);
        return ans;
    }
};