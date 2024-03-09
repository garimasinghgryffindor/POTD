/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool height(Node* root, int&heightMax, int curr) {
        if(!root) return true;
        
        if(!root->left && !root->right) {
            if(heightMax == -1) {
                heightMax = curr;
            } else {
                return curr == heightMax;
            }
        }
        
        if(height(root->left, heightMax, curr+1) == false) return false;
        if(height(root->right, heightMax, curr+1) == false) return false;
        return true;
    }
    
    bool check(Node *root)
    {
        //Your code here
        int heightMax = -1;
        height(root, heightMax, 0);
    }
};
