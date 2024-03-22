/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution
{
    public:
    vector<int>res;
    
    void preorder(Node *root, int diagonalLevel) {
        if(!root) return;
        if(diagonalLevel == res.size()) {
            res.push_back(root->data);
        } else {
            res[diagonalLevel] += root->data;
        }
        
        preorder(root->left, diagonalLevel+1);
        preorder(root->right, diagonalLevel);
    }
    
    vector <int> diagonalSum(Node* root) {
        preorder(root, 0);
        return res;
    }
};
