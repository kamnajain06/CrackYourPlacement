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
    unordered_map<int, int> mpp;
    TreeNode* buildProcess(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd){
        if(preEnd < preStart || inEnd < inStart) return NULL;
        TreeNode* root = new TreeNode(preOrder[preStart]);
        int currIndex = mpp[root->val];
        int leftNodes = currIndex - inStart;
        root->left = buildProcess(preOrder, preStart + 1, preStart + leftNodes, inOrder, inStart, currIndex-1);
        root->right = buildProcess(preOrder, preStart + leftNodes + 1, preEnd, inOrder, currIndex + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        for(int i=0; i<inOrder.size(); i++){
            mpp[inOrder[i]] = i;
        }
        return buildProcess(preOrder,0,preOrder.size()-1, inOrder, 0, inOrder.size()-1);
    }
};