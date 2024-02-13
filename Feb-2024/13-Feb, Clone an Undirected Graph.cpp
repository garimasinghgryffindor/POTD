//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // using map
        map<Node* , Node*> mp;
        // let us do a bfs traversal of this graph
        queue<Node *> q;
        q.push(node);
        
        while(!q.empty()) {
            Node* tp = q.front();  q.pop();
            mp[tp] = new Node(tp->val);
            
            for(auto x: tp->neighbors) {
                if(mp.find(x) == mp.end()) {
                    q.push(x);
                }
            }
        }
        
        // int sz = mp.size();
        
        for(auto x: mp) {
            Node *org = x.first, *dupe = x.second;
            for(auto y: org->neighbors) {
                (dupe->neighbors).push_back(mp[y]);
            }
        }
        
        return mp[node];
    }
};

