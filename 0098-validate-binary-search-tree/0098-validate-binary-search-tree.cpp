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
    bool flag = true;
    void inorder(TreeNode* root, vector<int> &trav){
        if(root == NULL) return;
        inorder(root->left,trav);
        if(!trav.empty()){
            int n = trav.size();
            if(trav[n-1] >= root->val){
                flag = false;
                return;
            }
        }
        trav.push_back(root->val);
        inorder(root->right,trav);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> trav;
        inorder(root,trav);
        return flag;
    }
};