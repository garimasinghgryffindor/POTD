//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int mx = 0;
    // int res = 0;
    unordered_map<int, int> mp;
    void preorder(Node *root, int sum, int level) {
        if(!root) {
            if(level > mx) {
                mx = level;
            }
            mp[level] = max(mp[level], sum);
            return;
        }
        
        preorder(root->left, sum+root->data, level+1);
        preorder(root->right, sum+root->data, level+1);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        preorder(root, 0, 0);
        return mp[mx];
    }
};
