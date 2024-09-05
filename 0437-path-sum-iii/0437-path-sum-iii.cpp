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
    unordered_map<long long,int> mpp;
    void traversal(TreeNode* root, long long sum, long long targetSum, int &cnt){
        if(root == NULL) return;

        sum += root->val;
        
        if(mpp.find(sum-targetSum) != mpp.end()){
            cnt += mpp[sum - targetSum];
        } 
        mpp[sum]++;

        traversal(root->left, sum, targetSum, cnt);
        traversal(root->right, sum , targetSum, cnt);
        
        mpp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        mpp[0]=1;
        if(root == NULL) return 0;
        traversal(root,0,targetSum,cnt);
        return cnt;
    }
};