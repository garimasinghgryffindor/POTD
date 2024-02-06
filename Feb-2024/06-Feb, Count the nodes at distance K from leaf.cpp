//Node Structure
/*struct Node
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    bool recur(Node * root, int k) {
        if(!root) return false;
        if(root->left == NULL && root->right == NULL) {
            if(k == 0) return true;
            else return false;
        }
        bool left = recur(root->left, k-1);
        bool right = recur(root->right, k-1);
        return left || right;
    }
    
    int postorder(Node *root, int k) {
        if(!root) return 0;
        int left = postorder(root->left, k);
        int right = postorder(root->right, k);
        bool ans = recur(root, k);
        return left + right + ans;
    }
    
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	int res = postorder(root, k);
    	return res;
    }
};
