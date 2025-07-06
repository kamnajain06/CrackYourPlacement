/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 1;
        
        int leftData = root->left ? root->left->data : 0;
        int rightData = root->right ? root->right->data : 0;
        
        if(leftData + rightData == root->data && isSumProperty(root->left) && isSumProperty(root->right)){
            return 1;
        }
        return 0;
    }
};