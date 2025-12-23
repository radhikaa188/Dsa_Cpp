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
    unordered_map <int,int> idxStore;
    int preidx=0;

    TreeNode*build(vector<int>& preorder, vector<int>&inorder, int start, int end){
        //base case
        if(start>end) return NULL;
        //building the root
        int rootVal= preorder[preidx++];
        TreeNode*root = new TreeNode(rootVal);
        //pick from inorder vector
        int index=idxStore[rootVal];
        //call the left and right
        root->left=build(preorder,inorder,start,index-1);
        root->right=build(preorder,inorder,index+1,end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            idxStore[inorder[i]]=i;
        }
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};