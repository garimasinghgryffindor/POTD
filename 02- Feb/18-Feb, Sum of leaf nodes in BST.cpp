/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    int sum = 0;
    public:
        void preorder(Node *root) {
            if(!root) return;
            if(!root->left && !root->right) {
                sum+=root->data;
                return;
            }
            preorder(root->left);
            preorder(root->right);
        }
    
        int sumOfLeafNodes(Node *root ){
            preorder(root);
            return sum;
        }
};
