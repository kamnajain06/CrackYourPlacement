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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int flag = 0;
        while(root != NULL && !q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                v.push_back(node->val);
            }
            if(flag == 0) ans.push_back(v);
            else {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            flag = ~flag;
        }
        return ans;
    }
};