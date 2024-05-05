/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    map<int, int> mp;
    
    void inorder(Node*root, int level) {
        if(!root) return;
        inorder(root->left, level-1);
        mp[level] += root->data;
        inorder(root->right, level+1);
    }
    
    vector <int> verticalSum(Node *root) {
        inorder(root, 0);
        vector<int>res;
        for(auto x: mp) {
            res.push_back(x.second);
        }
        return res;
    }
};
