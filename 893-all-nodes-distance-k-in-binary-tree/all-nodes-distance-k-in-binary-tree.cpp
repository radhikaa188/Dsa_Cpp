/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void manageParent (TreeNode* root, unordered_map<TreeNode*,TreeNode*>&storeParent, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                storeParent[curr->left]=curr;
            }
            if(curr->right){
                q.push(curr->right);
                storeParent[curr->right]=curr;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>storeParent;
        manageParent(root, storeParent, target);

        unordered_map< TreeNode*, bool>visited;
        queue<TreeNode*>que;
        que.push(target);
        visited[target]=true;
        int level=0;
        while(!que.empty()){
            int size = que.size();
            if(level++ == k) break;
            
            for(int i=0; i<size; i++){
                TreeNode*temp=que.front();
                que.pop();
                if(temp->left && !visited[temp->left]){
                    visited[temp->left]= true;
                    que.push(temp->left);
                }
                if(temp->right && !visited[temp->right]){
                    visited[temp->right]= true;
                    que.push(temp->right);
                }
                if(storeParent[temp] && !visited[storeParent[temp]]){
                    visited[storeParent[temp]]= true;
                    que.push(storeParent[temp]);
                }
        }
        }
        vector<int>res;
        while(!que.empty()){
            TreeNode*nodes= que.front();
            que.pop();
            res.push_back(nodes->val);
        }
        return res;
    }
};