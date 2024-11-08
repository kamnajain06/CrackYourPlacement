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
    bool flag = false;
    void traversal(TreeNode* root, int k, unordered_map<int,int> &mpp){
        if(root == NULL) return;
        if(mpp.find(k-root->val) != mpp.end()){
            flag = true;
            return;
        }
        mpp[root->val]++;
        if(!flag)traversal(root->left,k,mpp);
        if(!flag)traversal(root->right,k,mpp);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
         unordered_map<int,int> mpp;
        traversal(root,k,mpp);
        return flag;
    }
};