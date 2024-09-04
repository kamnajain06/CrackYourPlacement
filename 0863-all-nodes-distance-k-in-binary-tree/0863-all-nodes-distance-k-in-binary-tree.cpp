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
public:
    void make_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                    mpp[temp->left]=temp;
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                    mpp[temp->right]=temp;
                }
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mpp;
        make_parent(root,mpp);

        vector<int> ans;

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL && visited.find(temp->left) == visited.end()){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right != NULL && visited.find(temp->right) == visited.end()){
                    q.push(temp->right);
                    visited[temp->right]= true;
                }
                if(mpp.find(temp) != mpp.end() && visited.find(mpp[temp]) == visited.end()){
                    q.push(mpp[temp]);
                    visited[mpp[temp]] = true;
                }
            }
            dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};