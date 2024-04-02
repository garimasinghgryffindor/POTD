/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
    int mint = INT_MAX;
    Node * prev = NULL;
    int absolute_diff(Node *root)
    {
        if(root==NULL)
            return mint;
        absolute_diff(root->left);
        
        if(prev!=NULL)
        {
            mint = min(mint , root->data - prev->data);
        }
        
        prev = root;
        
        absolute_diff(root->right);
        return mint;
    }
};
