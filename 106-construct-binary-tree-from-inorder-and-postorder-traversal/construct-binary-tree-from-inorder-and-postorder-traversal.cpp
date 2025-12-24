/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(0) : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map <int,int> idxStore;
    int postidx;   

    TreeNode*build(vector<int>& inorder, vector<int>&postorder, int start, int end){   
    //base case
        if(start>end || postidx<0) return NULL;
        //building the root
        int rootVal= postorder[postidx--];
        
        TreeNode*root = new TreeNode(rootVal);
        //pick from inorder vector
        int index=idxStore[rootVal];
        //call the left and right
        root->right=build(inorder,postorder,index+1,end);
        root->left=build(inorder,postorder,start,index-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         for(int i=0; i<inorder.size(); i++){
            idxStore[inorder[i]]=i;
        }
        postidx= postorder.size()-1;
        return build( inorder,postorder, 0, inorder.size()-1);
    }
};