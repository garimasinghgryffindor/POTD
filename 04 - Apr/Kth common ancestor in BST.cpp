//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    public:
    
    /*You are required to complete below function */
    Node *utils(Node* root, vector<int>&ans, int x, int y) {
        if(!root) return NULL;
        if(root->data == x || root->data == y) {
            ans.push_back(root->data);
            return root;
        }
        if(root->data > x && root->data > y) {
            ans.push_back(root->data);
            return utils(root->left, ans, x, y);
        }
        if(root->data < y && root->data < x) {
            ans.push_back(root->data);
            return utils(root->right, ans, x, y);
        }
        ans.push_back(root->data);
        return root;
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int>ans;
        Node * nd = utils(root, ans, x, y);
        if(k == 1) return nd->data;
        if(ans.size() < k) return -1;
        return ans[ans.size()-k];
        
    }
};
