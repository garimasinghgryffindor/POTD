class Solution
{
    public:

    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int>res;
        int x = 0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                Node * tp = q.front();  q.pop();
                if(x == k) {
                    res.push_back(tp->data);
                }
                if(tp->left) {
                    q.push(tp->left);
                }
                if(tp->right) {
                    q.push(tp->right);
                }
            }
            
            if(x == k) break;
            x++;
        }
        
        return res;
    }
};




