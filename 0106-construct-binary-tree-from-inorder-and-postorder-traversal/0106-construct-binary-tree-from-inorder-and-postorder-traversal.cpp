class Solution {
public:
    unordered_map<int,int> mpp;
    TreeNode* buildProcess(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int currIndex = mpp[root->val];
        int leftNodes = currIndex - inStart;
        root->left = buildProcess(inorder, inStart, currIndex-1, postorder, postStart , postStart + leftNodes - 1);
        root->right = buildProcess(inorder, currIndex + 1, inEnd, postorder, postStart + leftNodes , postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        return buildProcess(inorder,0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};