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
    void preOrder(TreeNode* root, string st, vector<string> &ans){
        if(root == NULL) {
            return;
        }
        st += to_string(root->val);
        if(root->left == NULL && root->right == NULL) ans.push_back(st);
        st+="->";
        preOrder(root->left,st,ans);
        preOrder(root->right,st,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        preOrder(root,"",ans);
        return ans;
    }
};